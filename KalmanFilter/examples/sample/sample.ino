
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

