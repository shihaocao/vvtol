#include <state_field_registry.hpp>
#include <task.hpp>
#include <imu_monitor.hpp>

#ifdef NATIVE
#include <chrono>
#endif

#include <vector>
#include <atomic>

#ifndef NATIVE
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#endif

#ifndef NATIVE
Adafruit_BNO055 bno_imu = Adafruit_BNO055(55, 0x28, &Wire2);
#endif

ImuMonitor::ImuMonitor(StateFields &sfr) : sfr_(sfr)
{
}

void ImuMonitor::setup()
{
#ifndef NATIVE
  Wire2.setSCL(24);
  Wire2.setSDA(25);

  // Initialize I2C
  Wire2.begin();
  if (!bno_imu.begin())
  {
    // debug print
    log() << "NOT FUNCTIONAL!";
  }

  // absolute fusion mode
  bno_imu.setMode(adafruit_bno055_opmode_t::OPERATION_MODE_NDOF);

  /** Remap Axis Settings to P1 per the BNO055 spec. */
  bno_imu.setAxisRemap(Adafruit_BNO055::adafruit_bno055_axis_remap_config_t::REMAP_CONFIG_P1);
  bno_imu.setAxisSign(Adafruit_BNO055::adafruit_bno055_axis_remap_sign_t::REMAP_SIGN_P1);

#ifdef LOAD_CALI
  /** Load a specific set of sensor offsets */
  unsigned char offsets[22] = {242, 255, 214, 255, 243, 255, 250, 254, 0, 255, 105, 0, 255, 255, 1, 0, 255, 255, 232, 3, 146, 2}; // calibrated from scao bno_imu @ 06/14
  bno_imu.setSensorOffsets(offsets);
#endif
  // set mode just in case
  bno_imu.setMode(adafruit_bno055_opmode_t::OPERATION_MODE_NDOF);

  // NOT NECESSARY MODIFY SHIHAO FORK IF DEFAULT INITIALIZATION IS REQUIRED

  /* Use external crystal for better accuracy */
  bno_imu.setExtCrystalUse(true);

  log() << "Setup complete" << '\n';
  //   bno08x.enableReport(SH2_MAGNETIC_FIELD_CALIBRATED);
#endif
};

void ImuMonitor::execute()
{
  // log() << "IMU EXE\n";
#ifndef NATIVE
  // linear_acc_vec is acceleration without gravity
  sensors_event_t linear_acc_vec,
      // acc_vec includes gravity
      acc_vec,
      // gravity vector
      grav_vec,
      // orientation in euler angles
      euler_vec,
      // gyroscope, angular acceleration vector
      gyr_vec,
      // magnetometer vector
      mag_vec;

  // poll actual i2c device, and fill containers
  bno_imu.getEvent(&linear_acc_vec, Adafruit_BNO055::VECTOR_LINEARACCEL);
  bno_imu.getEvent(&acc_vec, Adafruit_BNO055::VECTOR_ACCELEROMETER);
  bno_imu.getEvent(&gyr_vec, Adafruit_BNO055::VECTOR_GYROSCOPE);
  bno_imu.getEvent(&euler_vec, Adafruit_BNO055::VECTOR_EULER);

  bno_imu.getEvent(&grav_vec, Adafruit_BNO055::VECTOR_GRAVITY);
  bno_imu.getEvent(&mag_vec, Adafruit_BNO055::VECTOR_MAGNETOMETER);

  sfr_.imu_linear_acc_vec_f = {
      linear_acc_vec.acceleration.x,
      linear_acc_vec.acceleration.y,
      linear_acc_vec.acceleration.z};

  sfr_.imu_acc_vec_f = {
      acc_vec.acceleration.x,
      acc_vec.acceleration.y,
      acc_vec.acceleration.z};

  sfr_.imu_gyr_vec = {
      gyr_vec.acceleration.x,
      gyr_vec.acceleration.y,
      gyr_vec.acceleration.z};

  sfr_.imu_euler_vec = {
      euler_vec.orientation.x,
      euler_vec.orientation.y,
      euler_vec.orientation.z,
  };

  // poll for quatnernion
  imu::Quaternion local_quat = bno_imu.getQuat();

  sfr_.imu_quat = {
      local_quat.w(),
      local_quat.x(),
      local_quat.y(),
      local_quat.z()};

  // log() << sfr_.imu_gyr_vec;

#endif
  // mag_cal.set((calibrationStatus >> 6) & 0x03);
}