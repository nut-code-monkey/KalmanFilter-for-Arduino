/*
 * kalmanFilter.h - Library for simple Kalman filter
 *
 * Created by Max Lunin http://max.lunin.info : <nut.code.monkey@gmail.com> on 27.09.13.
 * as part of Arduino automatization described at http://exotic-garden-at-home.blogspot.com
 * Released into the public domain.
 */

/*
    // Usage :
    KalmanFilter kalmanFilter; // create with default parameters

    kalmanFilter.setState(startValue);
    kalmanFilter.setCovariance(0.1);

    while (true)
    {
        double value = getValueFromSensor();
        kalmanFilter.correct(value);
        double correctedValue = kalmanFilter.getState();
    }
*/

#ifndef Kalman_Kalman_h
#define Kalman_Kalman_h

#include "Arduino.h"

// http://en.wikipedia.org/wiki/Kalman_filter

class KalmanFilter {
public:
    double getState() const;
    void setState(double state);
    
    void setCovariance(double covariance);
    
    KalmanFilter(double q = 1, double r = 1, double f = 1, double h = 1);
    
    void correct(double data);

public:
    double getCovariance() const;
    double getX0() const;
    double getP0() const;
    double getF() const;
    double getQ() const;
    double getH() const;
    double getR() const;
    
private:
    double x0; // predicted state
    double p0; // predicted covariance
    double F; // factor of real value to previous real value
    double Q; // measurement noise
    double H; // factor of measured value to real value
    double R; // environment noise
    double state;
    double covariance;
};

#endif
