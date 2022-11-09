// Copyright(c) 2022 Patrice Pat-Odita All rights reserved.
//
// Created by: Patrice Pat-odita
// Created on: Nov 9,  2022
// This program asks the user to guess a
// number and loops the program if guessed wrong.

#include <iostream>
#include <random>

int main() {
    // Generates random number
    int randomNumber;
    std::random_device rseed;
    std::mt19937 rgen(rseed());
    // mersenne_twister
    std::uniform_int_distribution<int> idist(0, 9);
    // [0,100]
    randomNumber = idist(rgen);
    // std::cout << randomNumber << std::endl;
    // local avaiable
    int counter = 0;
    int userNumber;
    std::string userNumString;

    while (true) {
        // get the user number as a string
        std::cout << "Enter a whole number between 0 and 9: ";
        std::cin >> userNumString;
        try {
            // convert from string to int
            userNumber = std::stoi(userNumString);

            if (userNumber < 0 || userNumber > 9) {
                // increment the counter
                counter++;
                if (userNumber == randomNumber) {
                    std::cout << userNumber << " is correct, good job!";
                    break;
                } else {
                    std::cout << userNumber << " is incorrect.";
                    std::cout << std::endl;
                    std::cout << "Tracking ";
                    std::cout << counter << " times through the loop";
                    std::cout << std::endl;
                }
            } else {
                std::cout << "This number is not between 0 and 9\n";
            }
            // Tells the user that they didn't input an integer
        } catch (std::invalid_argument) {
            std::cout << userNumString << " is invaild";
            std::cout << std::endl;
        }
    }
}
