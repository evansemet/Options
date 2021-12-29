// File Name: readFile.h
//
//
// Last edited 12/28/2021


#ifndef OPTIONS_READFILE_H
#define OPTIONS_READFILE_H


#include "blackScholes.h"
#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>


class readFile {


private:


    double
        totalFairMarketValue = 0,
        totalDelta = 0,
        totalVega = 0,
        totalTheta = 0,
        totalRho = 0,
        totalEpsilon = 0,
        totalLambda = 0,
        totalGamma = 0,
        totalVanna = 0,
        totalCharm = 0,
        totalVomma = 0,
        totalVeta = 0,
        totalVarphi = 0,
        totalSpeed = 0,
        totalZomma = 0,
        totalColor = 0,
        totalUltima = 0,
        totalDualDelta = 0,
        totalDualGamma = 0;


public:


    // Reads all positions from the given file
    void readFromFile(std::vector<std::vector<double>> information);


    // Updates the totals for all greeks and fair market value
    void sumGreeks(std::map<std::string, double> values);


    // Prints out all data about options portfolio
    void print();


};

#endif //OPTIONS_READFILE_H
