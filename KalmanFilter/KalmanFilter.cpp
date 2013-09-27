/*
 * Kalman.cpp - Arduino Library for simple Kalman filter
 *
 * Created by Max Lunin http://max.lunin.info : <nut.code.monkey@gmail.com> on 27.09.13.
  * as part of Arduino automatization described at http://exotic-garden-at-home.blogspot.com
 * Released into the public domain.
 */

#include "KalmanFilter.h"

KalmanFilter::KalmanFilter(double q, double r, double f, double h) {
    F = f;
    Q = q;
    H = h;
    R = r;
}

double KalmanFilter::getX0() const {
    return x0;
}

double KalmanFilter::getP0() const {
    return p0;
}

double KalmanFilter::getF() const {
    return F;
}

double KalmanFilter::getQ() const {
    return Q;
}

double KalmanFilter::getH() const {
    return H;
}

double KalmanFilter::getR() const {
    return R;
}

double KalmanFilter::getState() const {
    return state;
}

void KalmanFilter::setState(double state) {
    this->state = state;
}

double KalmanFilter::getCovariance() const {
    return covariance;
}

void KalmanFilter::setCovariance(double covariance) {
    this->covariance = covariance;
}

void KalmanFilter::correct(double data) {
    x0 = F*state;
    p0 = F*F*covariance + Q;
    
    //measurement update - correction
    double K = (H*p0)/(H*p0*H + R);
    state = x0 + K*(data - H*x0);
    covariance = (1 - K*H)*p0;
}
