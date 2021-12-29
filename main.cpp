// File Name: main.cpp
//
//
// Last edited 12/28/2021


#include "readFile.h"
#include "exampleFile.h"
#include <chrono>


int main() {
    readFile portfolio;
    auto start = std::chrono::high_resolution_clock::now();
    portfolio.readFromFile(EXAMPLE_INFO);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "\n" << duration.count() << "\n";
    return 0;
}
