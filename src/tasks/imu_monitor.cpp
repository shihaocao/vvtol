#include <state_field_registry.hpp>
#include <task.hpp>
#include <imu_monitor.hpp>

#ifdef NATIVE
#include <chrono>
#endif

#include <vector>
#include <atomic>

#ifndef NATIVE
#include <Adafruit_BNO08x.h>
#endif

#ifndef NATIVE
Adafruit_BNO08x bno08x;
const uint8_t BNO085_ADDRESS = 0x4A;
#endif
int n_readings;


class SingleCounter {
public:
    bool is_counted_;
    std::atomic<int>& total_count_ref_;
    SingleCounter(std::atomic<int>& count_ref) : 
        is_counted_(false),
        total_count_ref_(count_ref) {};

    bool trip() {
        if(is_counted_){
            return false;        }
        is_counted_ = true;
        total_count_ref_++;
        return true;
    }

    void reset() {
        is_counted_ = false;
    }
};

class CounterManager {
    public:
    int total_target_count_ = 0;
    std::atomic<int> total_count_{0};

    std::vector<SingleCounter> counters_{};

    CounterManager() {};

    SingleCounter issue_new_counter() {
        SingleCounter temp{
            total_count_
        };
        auto it = counters_.emplace_back(total_count_);
        return it;
    }

    void reset_all_counters() {
        for (auto c : counters_) {
            c.reset();
        }
    }

    bool at_target() {
        return total_target_count_ == total_count_;
    }
};

CounterManager global_counter_manager;

ImuMonitor::ImuMonitor(StateFieldRegistry& sfr) : sfr_(sfr) {
}

void ImuMonitor::setup() {
  // Set the SCL and SDA pins for I2C communication
  Wire2.setSCL(24);
  Wire2.setSDA(25);

  // Initialize I2C
  Wire2.begin();

  // Try to initialize!
  if (!bno08x.begin_I2C(BNO085_ADDRESS, &Wire2)) {
    Serial.println("Failed to find BNO08x chip");
    while (1) { delay(10); }
  }
  Serial.println("BNO08x Found!");

  for (int n = 0; n < bno08x.prodIds.numEntries; n++) {
    Serial.print("Part ");
    Serial.print(bno08x.prodIds.entry[n].swPartNumber);
    Serial.print(": Version :");
    Serial.print(bno08x.prodIds.entry[n].swVersionMajor);
    Serial.print(".");
    Serial.print(bno08x.prodIds.entry[n].swVersionMinor);
    Serial.print(".");
    Serial.print(bno08x.prodIds.entry[n].swVersionPatch);
    Serial.print(" Build ");
    Serial.println(bno08x.prodIds.entry[n].swBuildNumber);
  }

  // Enable all desired sensor reports
  n_readings = 6;
  bno08x.enableReport(SH2_LINEAR_ACCELERATION);
  bno08x.enableReport(SH2_ACCELEROMETER);
//   bno08x.enableReport(SH2_GRAVITY);
//   bno08x.enableReport(SH2_ROTATION_VECTOR);
//   bno08x.enableReport(SH2_GYROSCOPE_CALIBRATED);
//   bno08x.enableReport(SH2_MAGNETIC_FIELD_CALIBRATED);

};


void ImuMonitor::execute() {
    // Create a single sensor value container
    sh2_SensorValue_t sensorValue;

    // Poll the BNO085 sensor for data
    while (bno08x.getSensorEvent(&sensorValue) && global_counter_manager.at_target()) {
        switch (sensorValue.sensorId) {
            case SH2_LINEAR_ACCELERATION:
                static SingleCounter lin_acc_counter = global_counter_manager.issue_new_counter();
                if(!lin_acc_counter.trip())
                    break;

                sfr_.linear_acc_vec_f = {
                    sensorValue.un.linearAcceleration.x,
                    sensorValue.un.linearAcceleration.y,
                    sensorValue.un.linearAcceleration.z
                };
                break;

            case SH2_ACCELEROMETER:
                static SingleCounter acc_counter = global_counter_manager.issue_new_counter();
                if(!acc_counter.trip())
                    break;

                sfr_.imu_acc_vec_f = {
                    sensorValue.un.accelerometer.x,
                    sensorValue.un.accelerometer.y,
                    sensorValue.un.accelerometer.z
                };
                break;

            default:
                // Handle unknown sensor events if needed
                break;
        }
    }

    // Print linear acceleration data
    Serial.print("Linear Acceleration: ");
    Serial.print("X = ");
    Serial.print(sfr_.linear_acc_vec_f.x);
    Serial.print(", Y = ");
    Serial.print(sfr_.linear_acc_vec_f.y);
    Serial.print(", Z = ");
    Serial.println(sfr_.linear_acc_vec_f.z);

    Serial.print("Accelerometer: ");
    Serial.print("X = ");
    Serial.print(sfr_.imu_acc_vec_f.x);
    Serial.print(", Y = ");
    Serial.print(sfr_.imu_acc_vec_f.y);
    Serial.print(", Z = ");
    Serial.println(sfr_.imu_acc_vec_f.z);
    // // Calibration data
    // uint8_t calibrationStatus;
    // bno08x.getCalibrationStatus(&calibrationStatus);
    // sys_cal.set(calibrationStatus & 0x03);
    // gyro_cal.set((calibrationStatus >> 2) & 0x03);
    // accel_cal.set((calibrationStatus >> 4) & 0x03);
    // mag_cal.set((calibrationStatus >> 6) & 0x03);
}