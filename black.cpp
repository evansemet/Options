// File Name: black.cpp
//
//
// Last edited: 12/20/2021


#include "black.h"


// Takes inputs to set the private variables for the class
void black::initializer(double futurePrice, double strikePrice, double riskFree, double time, double volatility) {
    F = futurePrice;
    K = strikePrice;
    r = riskFree;
    t = time;
    o = volatility;
}


// Calculates the d1 value for the Black model
double black::d1() const {
    return (log(F / K) + o * o / 2 * t) / (o * sqrt(t));
}


// Calculates the d2 value for the Black model
double black::d2() const {
    return d1() - o * sqrt(t);
}


// Calculates the standard normal probability density function
double black::phi(double x) {
    return blackScholes::phi(x);
}


// Calculates the standard normal cumulative probability density function
// Credit: https://stackoverflow.com/questions/2328258/cumulative-normal-distribution-function-in-c-c
double black::PHI(double x) {
    return blackScholes::PHI(x);
}


// Calculates the current fair value price for a call option using the Black model
double black::fairValueCall() const {
    return pow(e, -r * t) * (F * PHI(d1()) - K * PHI(d2()));
}


// Calculates the current fair value price for a call option using the Black model
double black::fairValuePut() const {
    return pow(e, -r * t) * (K * PHI(-d2()) - F * PHI(-d1()));
}


// Calculates the delta for a call option
double black::deltaCall() const {
    return pow(e, -r * t) * PHI(d1());
}


// Calculates the delta for a put option
double black::deltaPut() const {
    return -pow(e, -r * t) * PHI(-d1());
}


// Calculates the vega for an option
double black::vega() const {
    return F * pow(e, -r  * t) * phi(d1()) * sqrt(t);
}


// Calculates the theta for a call option
double black::thetaCall() const {
    return -F * pow(e, -r * t) * phi(d1()) * o / (2 * sqrt(t))
    -r * K * pow(e, -r * t) * PHI(d2()) + r * F * pow(e, -r * t) * PHI(d1());
}


// Calculates the theta for a put option
double black::thetaPut() const {
    return -F * pow(e, -r * t) * phi(d1()) * o / (2 * sqrt(t))
    + r * K * pow(e, -r * t) * PHI(-d2()) - r * F * pow(e, -r * t) * PHI(-d1());
}


// Calculates the rho for a call option
double black::rhoCall() const {
    return -t * pow(e, -r * t) * (F * PHI(d1()) - K * PHI(d2()));
}


// Calculates the rho for a put option
double black::rhoPut() const {
    return -t * pow(e, -r * t) * (K * PHI(-d2()) - F * PHI(-d1()));
}


// Calculates the gamma for an option
double black::gamma() const {
    return pow(e, -r * t) * phi(d1()) / (F * o * sqrt(t));
}


// Calculates the vanna for an option
double black::vanna() const {
    return -pow(e, -r * t) * phi(d1()) * d2() / o;
}


// Calculates the vomma for an option
double black::vomma() const {
    return vega() * d1() * d2() / o;
}


// Adds all greek values for a call option to a map and returns said map
std::map<std::string, double> black::callGreeks() const {
    std::map<std::string, double> collection = {{"Fair Value", fairValueCall()},
                                                {"Delta", deltaCall()},
                                                {"Vega", vega()},
                                                {"Theta", thetaCall()},
                                                {"Rho", rhoCall()},
                                                {"Gamma", gamma()},
                                                {"Vanna", vanna()},
                                                {"Vomma", vomma()}};
    return collection;
}


// Adds all greek values for a put option to a map and returns said map
std::map<std::string, double> black::putGreeks() const {
    std::map<std::string, double> collection = {{"Fair Value", fairValuePut()},
                                                {"Delta", deltaPut()},
                                                {"Vega", vega()},
                                                {"Theta", thetaPut()},
                                                {"Rho", rhoPut()},
                                                {"Gamma", gamma()},
                                                {"Vanna", vanna()},
                                                {"Vomma", vomma()}};
    return collection;
}