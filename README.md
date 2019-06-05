KalmanFilter-for-Arduino
========================

Simple one varable Kalman filter library for Arduino

Install:
--------
Import 'KalmanFilter' directory as Arduino library:

Arduino.app -> Sketch -> Import Library... -> Add Library

Or copy paste this project into your libraries folder.

Usage:
------

Initialize filter:
```cpp
#include "KalmanFilter.h"

KalmanFilter filter; // create with default parameters
filter.setState( defaultValue ); // setup vith default value
```
And use:
```cpp
double value = getValueFromSensor();

filter.correct( value ); // add new value from sensor
double correctedValue = filter.getState(); // get corrected value
```
Output:
-------
![kalman filter](https://raw.github.com/nut-code-monkey/KalmanFilter-for-Arduino/master/kalman.png)

 
## Support my creation of open source software:
[![Flattr this git repo](http://api.flattr.com/button/flattr-badge-large.png)](https://flattr.com/submit/auto?user_id=sebnil&url=https://github.com/sebnil/KalmanFilter-for-Arduino)

<a href='https://ko-fi.com/A0A2HYRH' target='_blank'><img height='36' style='border:0px;height:36px;' src='https://az743702.vo.msecnd.net/cdn/kofi2.png?v=0' border='0' alt='Buy Me a Coffee at ko-fi.com' /></a>