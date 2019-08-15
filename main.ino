#include "RPLidar.h"
#include "lewansoul.h"

RPLidar lidar;
LewanSoul lss;

#define RPLIDAR_MOTOR 3 // PWM pin connected to MOTOCTRL signal

// runs once when rover is powered up
void setup() {
    lidar.begin(Serial);
    pinMode(RPLIDAR_MOTOR, OUTPUT);
    lss.setup(); // takes over Serial!! (need two serial ports?)
}

// runs constantly as long as rover is powered
void loop() {
    if (IS_OK(lidar.waitPoint())) {
        float distance = lidar.getCurrentPoint().distance; // distance in mm
        float angle    = lidar.getCurrentPoint().angle; // angle in degrees
        bool  startBit = lidar.getCurrentPoint().startBit; // whether this point belongs to a new scan
        byte  quality  = lidar.getCurrentPoint().quality; // quality of the current measurement
        // TODO: connect to mrpt object avoidance
    } else {
        analogWrite(RPLIDAR_MOTOR, 0); // stop the lidar motor
        // try to detect lidar device
        rplidar_response_device_info_t info;
        if (IS_OK(lidar.getDeviceInfo(info, 100))) {
            // detected lidar device
            lidar.startScan();
            // start motor rotating at max allowed speed
            analogWrite(RPLIDAR_MOTOR, 255);
            delay(1000);
        }
    }
}
