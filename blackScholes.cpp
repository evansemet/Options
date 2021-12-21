// File Name: blackScholes.cpp
//
//
// Last edited: 12/20/2021


#include "blackScholes.h"


// Takes inputs to set the private variables for the class
void blackScholes::initializer(double stockPrice, double strikePrice, double riskFree, double divYield, double time, double volatility) {
    S = stockPrice;
    K = strikePrice;
    r = riskFree;
    q = divYield;
    t = time;
    o = volatility;
}


// Calculates the d1 value for the Black Scholes model
double blackScholes::d1() const {
    return (log(S / K) + (r - q + o * o / 2) * t) / (o * sqrt(t));
}


// Calculates the dw value for the Black Scholes model
double blackScholes::d2() const {
    return d1() - o * sqrt(t);
}


// Calculates the standard normal probability density function
double blackScholes::phi(double x) {
    return pow(e, -x * x / 2) / sqrt(2 * Pi);
}


// Calculates the standard normal cumulative probability density function
// Credit: https://stackoverflow.com/questions/2328258/cumulative-normal-distribution-function-in-c-c
double blackScholes::PHI(double x) {
    double L, K, w ;
    /* constants */
    double const a1 = 0.31938153, a2 = -0.356563782, a3 = 1.781477937;
    double const a4 = -1.821255978, a5 = 1.330274429;

    L = fabs(x);
    K = 1.0 / (1.0 + 0.2316419 * L);
    w = 1.0 - 1.0 / sqrt(2 * Pi) * exp(-L * L / 2) * (a1 * K + a2 * K * K + a3 * pow(K,3) + a4 * pow(K, 4) + a5 * pow(K, 5));

    if (x < 0 ){
        w= 1.0 - w;
    }
    return w;
}


// Calculates the current fair value price for a call option using the Black Scholes model
double blackScholes::fairValueCall() const {
    return S * pow(e, -q * r) * PHI(d1()) - pow(e, -r * t) * K * PHI(d2());
}


// Calculates the current fair value price for a put option using the Black Scholes model
double blackScholes::fairValuePut() const {
    return pow(e, -r * t) * K * PHI(-d2()) - S * pow(e, -q * r) * PHI(-d1());
}


// Calculates the delta for a call option
double blackScholes::deltaCall() const {
    return pow(e, -q * r) * PHI(d1());
}


// Calculates the delta for a put option
double blackScholes::deltaPut() const {
    return -pow(e, -q * r) * PHI(-d1());
}


// Calculates the vega for an option
double blackScholes::vega() const {
    return S * pow(e, -q * t) * phi(d1()) * sqrt(t);
}


// Calculates the theta for a call option
double blackScholes::thetaCall() const {
    return -pow(e, -q * r) * (S * phi(d1()) * o) / (2 * sqrt(t))
    -r * K * pow(e, -r * t) * PHI(d2()) + q * S * pow(e, -q * r) * PHI(d1());
}


// Calculates the theta for a put option
double blackScholes::thetaPut() const {
    return -pow(e, -q * r) * (S * phi(d1()) * o) / (2 * sqrt(t))
           + r * K * pow(e, -r * t) * PHI(-d2()) - q * S * pow(e, -q * r) * PHI(-d1());
}


// Calculates the rho for a call option
double blackScholes::rhoCall() const {
    return K * t * pow(e, -r * t) * PHI(d2());
}


// Calculates the rho for a put option
double blackScholes::rhoPut() const {
    return -K * t * pow(e, -r * t) * PHI(-d2());
}


// Calculates the epsilon for a call option
double blackScholes::epsilonCall() const {
    return -S * t * pow(e, -q * t) * PHI(d1());
}


// Calculates the epsilon for a put option
double blackScholes::epsilonPut() const {
    return S * t * pow(e, -q * t) * PHI(-d1());
}


// Calculates the lambda for a call option
double blackScholes::lambdaCall() const {
    return deltaCall() * S / fairValueCall();
}


// Calculates the lambda for a put option
double blackScholes::lambdaPut() const {
    return deltaPut() * S / fairValuePut();
}


// Calculates the gamma for an option
double blackScholes::gamma() const {
    return pow(e, -q * t) * (phi(d1()) / (S * o * sqrt(t)));
}


// Calculates the vanna for an option
double blackScholes::vanna() const {
    return -pow(e, -q * t) * phi(d1()) * d2() / o;
}


// Calculates the charm for a call option
double blackScholes::charmCall() const {
    return q * pow(e, -q * t) * PHI(d1()) - pow(e, -q * t) * phi(d1())
    * (2 * (r - q) * t - d2() * o * sqrt(t)) / (2 * t * o * sqrt(t));
}


// Calculates the charm for a put option
double blackScholes::charmPut() const {
    return -q * pow(e, -q * t) * PHI(d1()) - pow(e, -q * t) * phi(d1())
    * (2 * (r - q) * t - d2() * o * sqrt(t)) / (2 * t * o * sqrt(t));
}


// Calculates the vomma for an option
double blackScholes::vomma() const {
    return vega() * d1() * d2() / o;
}


// Calculates the veta for an option
double blackScholes::veta() const {
    return -S * pow(e, -q * t) * phi(d1()) * sqrt(t)
    * (q + ((r - q) * d1()) / (o * sqrt(t)) - (1 + d1() * d2()) / (2 * t));
}


// Calculates the varphi for an option
double blackScholes::varphi() const {
    double exp(-1.0 / (2 * o * o * t) * pow(log(K / S) - ((r - q) - o * o / 2) * t, 2));
    return pow(e, -r * t) / K * pow(1.0 / (sqrt(2 * Pi * o * o * t)), exp);
}


// Calculates the speed for an option
double blackScholes::speed() const {
    return -gamma() / S * (d1() / (o * sqrt(t)) + 1);
}


// Calculates the zomma for an option
double blackScholes::zomma() const {
    return gamma() * (d1() * d2() - 1) / o;
}


// Calculates the color for an option
double blackScholes::color() const {
    return -pow(e, -q * r) * phi(d1()) / (2 * S * t * o * sqrt(t))
    * (2 * q * t + 1 + (2 * (r - q) * t - d2() * o * sqrt(t)) / (o * sqrt(t)) * d1());
}


// Calculates the ultima for an option
double blackScholes::ultima() const {
    return - vega() / (o * o) * (d1() * d2() * (1 - d1() * d2()) + d1() * d1() + d2() * d2());
}


// Calculates the dual delta for a call option
double blackScholes::dualDeltaCall() const {
    return -pow(e, -r * t) * PHI(d2());
}


// Calculates the dual delta for a put option
double blackScholes::dualDeltaPut() const {
    return pow(e, -r * t) * PHI(-d2());
}


// Calculates the dual gamma for an option
double blackScholes::dualGamma() const {
    return pow(e, -r * t) * phi(d2()) / (K * o * sqrt(t));
}


// Adds all greek values for a call option to a map and returns said map
std::map<std::string, double> blackScholes::callGreeks() const {
    std::map<std::string, double> collection = {{"Fair Value", fairValueCall()},
                                                {"Delta", deltaCall()},
                                                {"Vega", vega()},
                                                {"Theta", thetaCall()},
                                                {"Rho", rhoCall()},
                                                {"Epsilon", epsilonCall()},
                                                {"Lambda", lambdaCall()},
                                                {"Gamma", gamma()},
                                                {"Vanna", vanna()},
                                                {"Charm", charmCall()},
                                                {"Vomma", vomma()},
                                                {"Veta", veta()},
                                                {"Varphi", varphi()},
                                                {"Speed", speed()},
                                                {"Zomma", zomma()},
                                                {"Color", color()},
                                                {"Ultima", ultima()},
                                                {"Dual Delta", dualDeltaCall()},
                                                {"Dual Gamma", dualGamma()}};
    return collection;
}


// Adds all greek values for a put option to a map and returns said map
std::map<std::string, double> blackScholes::putGreeks() const {
    std::map<std::string, double> collection = {{"Fair Value", fairValuePut()},
                                                {"Delta", deltaPut()},
                                                {"Vega", vega()},
                                                {"Theta", thetaPut()},
                                                {"Rho", rhoPut()},
                                                {"Epsilon", epsilonPut()},
                                                {"Lambda", lambdaPut()},
                                                {"Gamma", gamma()},
                                                {"Vanna", vanna()},
                                                {"Charm", charmPut()},
                                                {"Vomma", vomma()},
                                                {"Veta", veta()},
                                                {"Varphi", varphi()},
                                                {"Speed", speed()},
                                                {"Zomma", zomma()},
                                                {"Color", color()},
                                                {"Ultima", ultima()},
                                                {"Dual Delta", dualDeltaPut()},
                                                {"Dual Gamma", dualGamma()}};
    return collection;
}