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
static constexpr int N_TARGET_READINGS = 2;
long reportIntervalUs = 10000;

class SingleCounter {
public:
    bool is_counted_;
    std::atomic<int>& total_count_ref_;
    // SingleCounter() : 
    //     is_counted_(false) {};
    SingleCounter(std::atomic<int>& count_ref) : 
        is_counted_(false), total_count_ref_(count_ref) {};

    SingleCounter(SingleCounter&) = delete;
    SingleCounter& operator=(SingleCounter&) = delete;
    SingleCounter(SingleCounter&&) = default;
    SingleCounter& operator=(SingleCounter&&) = default;

    bool trip() {
        if(is_counted_){
            log() << "tripped\n";
            return total_count_ref_ == N_TARGET_READINGS;        
        }
        is_counted_ = true;
        total_count_ref_++;
        return total_count_ref_ == N_TARGET_READINGS;        
    }

    void reset() {
        is_counted_ = false;
    }
};

class CounterManager {
    public:
    std::atomic<int> total_count_{0};

    std::vector<SingleCounter> counters_{};

    CounterManager() {};

    SingleCounter& issue_new_counter() {
        // counters_.emplace_back();
        counters_.emplace_back(total_count_);

        return counters_.back();
    }

    void reset_all_counters() {
        for (auto& c : counters_) {
            c.reset();
        }
        total_count_ = 0;
    }

    bool at_target() {
        log() << "total: " << total_count_;
        return total_count_ == N_TARGET_READINGS;
    }
};

CounterManager global_counter_manager;

ImuMonitor::ImuMonitor(StateFieldRegistry& sfr) : sfr_(sfr) {
}

void ImuMonitor::setup() {
  #ifndef NATIVE
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
  const int n_bno_readings = 2;
  bno08x.enableReport(SH2_LINEAR_ACCELERATION, reportIntervalUs);
  bno08x.enableReport(SH2_ACCELEROMETER, reportIntervalUs);
//   bno08x.enableReport(SH2_GRAVITY);
//   bno08x.enableReport(SH2_GYROSCOPE_CALIBRATED);
//   bno08x.enableReport(SH2_ROTATION_VECTOR);
//   bno08x.enableReport(SH2_GYRO_INTEGRATED_RV);
//   bno08x.enableReport(SH2_GAME_ROTATION_VECTOR);
//   bno08x.enableReport(SH2_ARVR_STABILIZED_RV);

  static_assert(N_TARGET_READINGS == n_bno_readings);

  log() << "Setup complete" << '\n';
//   bno08x.enableReport(SH2_MAGNETIC_FIELD_CALIBRATED);
  #endif
};


void ImuMonitor::execute() {
    log() << "IMU EXE\n";
    #ifndef NATIVE
    // Create a single sensor value container

    // Poll the BNO085 sensor for data
    while ( !global_counter_manager.at_target() ) {
        delayMicroseconds(1000);
        log() << "try\n";
        sh2_SensorValue_t sensorValue;
        bool is_new_event = bno08x.getSensorEvent(&sensorValue);
        if(!is_new_event) {
            continue;
        }
        log() << "Sensor event" << '\n';
        switch (sensorValue.sensorId) {
            case SH2_LINEAR_ACCELERATION:
                log() << "LIN_ACC\n";
                static SingleCounter& lin_acc_counter = global_counter_manager.issue_new_counter();
                if(lin_acc_counter.trip()) {
                    goto loop_done;
                }

                sfr_.imu_linear_acc_vec_f = {
                    sensorValue.un.linearAcceleration.x,
                    sensorValue.un.linearAcceleration.y,
                    sensorValue.un.linearAcceleration.z
                };
                break;

            case SH2_ACCELEROMETER:
                log() << "ACC\n";
                static SingleCounter& acc_counter = global_counter_manager.issue_new_counter();
                if(acc_counter.trip()) {
                    goto loop_done;
                }

                sfr_.imu_acc_vec_f = {
                    sensorValue.un.accelerometer.x,
                    sensorValue.un.accelerometer.y,
                    sensorValue.un.accelerometer.z
                };
                break;

            case SH2_GYROSCOPE_CALIBRATED:
                static SingleCounter& gyr_counter = global_counter_manager.issue_new_counter();
                if(gyr_counter.trip())
                    goto loop_done;

                sfr_.imu_gyr_vec = {
                    sensorValue.un.gyroscope.x,
                    sensorValue.un.gyroscope.y,
                    sensorValue.un.gyroscope.z
                };
                break;

            case SH2_ROTATION_VECTOR:
                static SingleCounter& rv_counter = global_counter_manager.issue_new_counter();
                if(rv_counter.trip())
                    goto loop_done;

                sfr_.imu_rot_vec_quat = {
                    sensorValue.un.rotationVector.i,
                    sensorValue.un.rotationVector.j,
                    sensorValue.un.rotationVector.k,
                    sensorValue.un.rotationVector.real
                };
                break;

            case SH2_GAME_ROTATION_VECTOR:
                static SingleCounter& gm_rv_counter = global_counter_manager.issue_new_counter();
                if(gm_rv_counter.trip())
                    goto loop_done;

                sfr_.imu_game_rot_vec_quat = {
                    sensorValue.un.gameRotationVector.i,
                    sensorValue.un.gameRotationVector.j,
                    sensorValue.un.gameRotationVector.k,
                    sensorValue.un.gameRotationVector.real
                };
                break;

            case SH2_GYRO_INTEGRATED_RV:
                static SingleCounter& gi_rv_counter = global_counter_manager.issue_new_counter();
                if(gi_rv_counter.trip())
                    goto loop_done;

                sfr_.imu_gyro_int_rot_vec_quat = {
                    sensorValue.un.gyroIntegratedRV.i,
                    sensorValue.un.gyroIntegratedRV.j,
                    sensorValue.un.gyroIntegratedRV.k,
                    sensorValue.un.gyroIntegratedRV.real
                };
                break;

            case SH2_ARVR_STABILIZED_RV:
                static SingleCounter& ar_rv_counter = global_counter_manager.issue_new_counter();
                if(ar_rv_counter.trip())
                    goto loop_done;

                sfr_.imu_ar_stab_rot_vec_quat = {
                    sensorValue.un.arvrStabilizedRV.i,
                    sensorValue.un.arvrStabilizedRV.j,
                    sensorValue.un.arvrStabilizedRV.k,
                    sensorValue.un.arvrStabilizedRV.real
                };
                break;


            default:
                // Handle unknown sensor events if needed
                break;
        }
        log() << "Switch done\n";
    }
    loop_done:
    log() << "Done";

    global_counter_manager.reset_all_counters();

    // Print linear acceleration data
    // log_printf("Linear Acceleration: ");
    // log_printf("X = ");
    // log_printf(sfr_.imu_linear_acc_vec_f.x());
    // log() << "Linear acceleration: " << sfr_.imu_linear_acc_vec_f;
    // Serial.print(", Y = ");
    // Serial.print(sfr_.imu_linear_acc_vec_f.y());
    // Serial.print(", Z = ");
    // Serial.println(sfr_.imu_linear_acc_vec_f.z());

    // Serial.print("Accelerometer: ");
    // Serial.print("X = ");
    // Serial.print(sfr_.imu_acc_vec_f.x());
    // Serial.print(", Y = ");
    // Serial.print(sfr_.imu_acc_vec_f.y());
    // Serial.print(", Z = ");
    // Serial.println(sfr_.imu_acc_vec_f.z());
    #endif

    // // Calibration data
    // uint8_t calibrationStatus;
    // bno08x.getCalibrationStatus(&calibrationStatus);
    // sys_cal.set(calibrationStatus & 0x03);
    // gyro_cal.set((calibrationStatus >> 2) & 0x03);
    // accel_cal.set((calibrationStatus >> 4) & 0x03);
    // mag_cal.set((calibrationStatus >> 6) & 0x03);
}