// File Name: readFile.cpp
//
//
// Last edited 12/28/2021


#include "readFile.h"


// Reads all positions from the given file
void readFile::readFromFile(std::vector<std::vector<double>> file) {
    double callPut, stockPrice, strikePrice, riskFree, divYield, time, volatility;

    for (size_t i(0); i < file.size(); ++i){
        callPut = file[i][0];
        stockPrice = file[i][1];
        strikePrice = file[i][2];
        riskFree = file[i][3];
        divYield = file[i][4];
        time = file[i][5];
        volatility = file[i][6];

        blackScholes position;
        position.initializer(stockPrice, strikePrice, riskFree, divYield, time, volatility);
        std::map<std::string, double> values = callPut == 1 ? position.callGreeks() : position.putGreeks();
        sumGreeks(values);
    }

    print();
}


// Updates the totals for all greeks and fair market value
void readFile::sumGreeks(std::map<std::string, double> values) {
    totalFairMarketValue += values["Fair Value"];
    totalDelta += values["Delta"];
    totalVega += values["Vega"];
    totalTheta += values["Theta"];
    totalRho += values["Rho"];
    totalEpsilon += values["Epsilon"];
    totalLambda += values["Lambda"];
    totalGamma += values["Gamma"];
    totalVanna += values["Vanna"];
    totalCharm += values["Charm"];
    totalVomma += values["Vomma"];
    totalVeta += values["Veta"];
    totalVarphi += values["Varphi"];
    totalSpeed += values["Speed"];
    totalZomma += values["Zomma"];
    totalColor += values["Color"];
    totalUltima += values["Ultima"];
    totalDualDelta += values["Dual Delta"];
    totalDualGamma += values["Dual Gamma"];
}


// Prints out all data about options portfolio
void readFile::print() {
    std::cout << "Fair Market Value of Portfolio: " << totalFairMarketValue << "\n";

    std::cout << "\nFirst Order Greeks:\n";
    std::cout << "TotalDelta: " << totalDelta << "\n";
    std::cout << "TotalVega: " << totalVega << "\n";
    std::cout << "Total Theta: " << totalTheta << "\n";
    std::cout << "Total Rho: " << totalRho << "\n";
    std::cout << "Total Epsilon: " << totalEpsilon << "\n";
    std::cout << "Total Lambda: " << totalLambda << "\n";

    std::cout << "\nSecond Order Greeks:\n";
    std::cout << "Total Gamma: " << totalGamma << "\n";
    std::cout << "Total Vanna: " << totalVanna << "\n";
    std::cout << "Total Charm: " << totalCharm << "\n";
    std::cout << "Total Vomma: " << totalVomma << "\n";
    std::cout << "Total Veta: " << totalVeta << "\n";
    std::cout << "Total Varphi: " << totalVarphi << "\n";

    std::cout << "\nThird Order Greeks:\n";
    std::cout << "Total Speed: " << totalSpeed << "\n";
    std::cout << "Total Zomma: " << totalZomma << "\n";
    std::cout << "Total Color: " << totalColor << "\n";
    std::cout << "Total Ultima: " << totalUltima << "\n";
    std::cout << "Total Dual Delta: " << totalDualDelta << "\n";
    std::cout << "Total Dual Gamma: " << totalDualGamma << "\n";
}