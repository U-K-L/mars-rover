#include "RPLidar.h"
#include "lewansoul.h"

RPLidar lidar;
LewanSoul lss;

#define RPLIDAR_MOTOR 3 // PWM pin connected to MOTOCTRL signal

// servo ids
#define WFL 25
#define WML 21
#define WBL 20
#define WFR 27
#define WMR 22
#define WBR 28
#define SFL 23
#define SBL 24
#define SFR 29
#define SBR 26

// runs once when rover is powered up
void setup() {
/*    lidar.begin(Serial);
    pinMode(RPLIDAR_MOTOR, OUTPUT);*/
    lss.setup(); // takes over Serial!! (need two serial ports?)
}

void moveForward(float speed)
{
    SpinAt(WFL,speed);
    SpinAt(WML,speed);
    SpinAt(WBL,speed);
    SpinAt(WFR,speed);
    SpinAt(WMR,speed);
    SpinAt(WBR,speed);
}
void moveBackward(float speed)
{
    SpinAt(WFL,-speed);
    SpinAt(WML,-speed);
    SpinAt(WBL,-speed);
    SpinAt(WFR,-speed);
    SpinAt(WMR,-speed);
    SpinAt(WBR,-speed);
}
// runs constantly as long as rover is powered
void loop() {
    /*if (IS_OK(lidar.waitPoint())) {
        float distance = lidar.getCurrentPoint().distance; // distance in mm
        float angle    = lidar.getCurrentPoint().angle; // angle in degrees
        bool  startBit = lidar.getCurrentPoint().startBit; // whether this point belongs to a new scan
        byte  quality  = lidar.getCurrentPoint().quality; // quality of the current measurement
        // TODO: connect to object avoidance (SLAM)
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
    }*/
}

