/*
 * Sample for Kalman filter for Arduino library https://github.com/nut-code-monkey/KalmanFilter-for-Arduino
 * Created by Max Lunin http://max.lunin.info : <nut.code.monkey@gmail.com> on 27.09.13.
 * as part of Arduino automatization described at http://exotic-garden-at-home.blogspot.com
 * Released into the public domain.
 */

#include "KalmanFilter.h"

KalmanFilter kalmanFilter;

double getSomeValue()  {
    // return values in range 0..1023  
    return analogRead(A0);
}

void setup() {

    kalmanFilter.setState( getSomeValue() );
//    kalmanFilter.setCovariance(0.1); // optional
    
    Serial.begin(9600);
}

void loop() {

    double value = getSomeValue();
    
    kalmanFilter.correct(value);
    double correctedValue = kalmanFilter.getState();
    
    Serial.print(value); Serial.print(" | "); Serial.println(correctedValue);
}
