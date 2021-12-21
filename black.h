// File Name: black.h
//
//
// Last edited: 12/20/2021


#ifndef OPTIONS_BLACK_H
#define OPTIONS_BLACK_H


#include "blackScholes.h"


class black {


private:


    double
    F, // Future price
    K, // Strike price
    r, // Risk-free rate (government bond yield)
    t, // Time to maturity (represented as percentage of a year)
    o; // Volatility


public:


    // Takes inputs to set the private variables for the class
    void initializer(double futurePrice, double strikePrice, double riskFree, double time, double volatility);


    // Calculates the d1 value for the Black model
    double d1() const;


    // Calculates the d2 value for the Black model
    double d2() const;


    // Calculates the standard normal probability density function
    static double phi(double x);


    // Calculates the standard normal cumulative probability density function
    // Credit: https://stackoverflow.com/questions/2328258/cumulative-normal-distribution-function-in-c-c
    static double PHI(double x);


    // Calculates the current fair value price for a call option using the Black model
    double fairValueCall() const;


    // Calculates the current fair value price for a call option using the Black model
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


    // Calculates the gamma for an option
    double gamma() const;


    // Calculates the vanna for an option
    double vanna() const;


    // Calculates the vomma for an option
    double vomma() const;


    // Adds all greek values for a call option to a map and returns said map
    std::map<std::string, double> callGreeks() const;


    // Adds all greek values for a put option to a map and returns said map
    std::map<std::string, double> putGreeks() const;


};


#endif //OPTIONS_BLACK_H