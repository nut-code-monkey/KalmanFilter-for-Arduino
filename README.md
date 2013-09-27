KalmanFilter-for-Arduino
========================

Simple one varable Kalman filter library for Arduino

Install:
--------
Import 'KalmanFilter' directory as Arduino library:

Arduino.app -> Sketch -> Import Library... -> Add Library


Usage:
------

Initialize filter:
```
#include "KalmanFilter.h"

KalmanFilter filter; // create with default parameters
filter.setState( defaultValue ); // setup vith default value
```
And use:
```
double value = getValueFromSensor();

filter.correct( value ); // add new value from sensor
double correctedValue = filter.getState(); // get corrected value
```
Output:
-------
![kalman filter](https://raw.github.com/nut-code-monkey/KalmanFilter-for-Arduino/master/kalman.png)
