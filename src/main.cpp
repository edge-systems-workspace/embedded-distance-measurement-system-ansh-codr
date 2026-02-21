#include <Arduino.h>

/**
 * @file main.cpp
 * @brief Embedded distance measurement using HC-SR04 ultrasonic sensor.
 * @author ansh-codr
 * @date 2026-02-21
 */

int TRIG_pin = 9;
int ECHO_pin = 10;

long duration;
float distance;

void setup() {
    Serial.begin(9600);

    pinMode(TRIG_pin, OUTPUT);
    pinMode(ECHO_pin, INPUT);

    Serial.println("Ultrasonic Sensor System Initialized");
}

void loop() {
    digitalWrite(TRIG_pin, LOW);
    delayMicroseconds(2);

    digitalWrite(TRIG_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_pin, LOW);

    duration = pulseIn(ECHO_pin, HIGH);

    distance = duration * 0.034 / 2;

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    delay(500);
}