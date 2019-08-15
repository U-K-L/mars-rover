#include "RPLidar.h"
#include "lewansoul.h"

RPLidar lidar;
LewanSoul servo;

#define RPLIDAR_MOTOR 3 // PWM pin connected to MOTOCTRL signal

// runs once when rover is powered up
void setup() {
    lidar.begin(Serial);
    pinMode(RPLIDAR_MOTOR, OUTPUT)
}

// runs constantly as long as rover is powered
void loop() {
    ;
}
