// File Name: blackScholes.h
//
//
// Last edited: 12/20/2021


#ifndef OPTIONS_BLACKSCHOLES_H
#define OPTIONS_BLACKSCHOLES_H


#include <cmath>
#include <map>
#include <string>


const double Pi(3.141592653589793238462643), e(2.718281828459045235360287);


class blackScholes {


private:


    double
    S, // Stock price
    K, // Strike price
    r, // Risk-free rate (government bond yield)
    q, // Annual dividend yield
    t, // Time to maturity (represented as percentage of a year)
    o; // Volatility


public:


    // Takes inputs to set the private variables for the class
    void initializer(double stockPrice, double strikePrice, double riskFree, double divYield, double time, double volatility);


    // Calculates the d1 value for the Black Scholes model
    double d1() const;


    // Calculates the d2 value for the Black Scholes model
    double d2() const;


    // Calculates the standard normal probability density function
    static double phi(double x);


    // Calculates the standard normal cumulative probability density function
    // Credit: https://stackoverflow.com/questions/2328258/cumulative-normal-distribution-function-in-c-c
    static double PHI(double x);


    // Calculates the current fair value price for a call option using the Black Scholes model
    double fairValueCall() const;


    // Calculates the current fair value price for a put option using the Black Scholes model
    double fairValuePut() const;


    // Calculates the delta for a call option
    double deltaCall() const;


    // Calculates the delta for a put option
    double deltaPut() const;


    // Calculates the vega for an option
    double vega() const;


    // Calculates the theta for a call option
    double thetaCall() const;


    // Calculates the theta for a put option
    double thetaPut() const;


    // Calculates the rho for a call option
    double rhoCall() const;


    // Calculates the rho for a put option
    double rhoPut() const;


    // Calculates the epsilon for a call option
    double epsilonCall() const;


    // Calculates the epsilon for a put option
    double epsilonPut() const;


    // Calculates the lambda for a call option
    double lambdaCall() const;


    // Calculates the lambda for a put option
    double lambdaPut() const;


    // Calculates the gamma for an option
    double gamma() const;


    // Calculates the vanna for an option
    double vanna() const;


    // Calculates the charm for a call option
    double charmCall() const;


    // Calculates the charm for a put option
    double charmPut() const;


    // Calculates the vomma for an option
    double vomma() const;


    // Calculates the veta for an option
    double veta() const;


    // Calculates the varphi for an option
    double varphi() const;


    // Calculates the speed for an option
    double speed() const;


    // Calculates the zomma for an option
    double zomma() const;


    // Calculates the color for an option
    double color() const;


    // Calculates the ultima for an option
    double ultima() const;


    // Calculates the dual delta for a call option
    double dualDeltaCall() const;


    // Calculates the dual delta for a put option
    double dualDeltaPut() const;


    // Calculates the dual gamma for an option
    double dualGamma() const;


    // Adds all greek values for a call option to a map and returns said map
    std::map<std::string, double> callGreeks() const;


    // Adds all greek values for a put option to a map and returns said map
    std::map<std::string, double> putGreeks() const;


};


#endif //OPTIONS_BLACKSCHOLES_H