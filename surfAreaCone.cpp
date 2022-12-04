// Copyright (c) 2022 Immaculata HS All rights reserved.
// Created by: Marcus Wehbi
// Date : Dec 1 2022
// This program asks the user for a minimum and a maximum to create a range
// It then displays all of the perfect numbers that are within that range
// Then it asks the user for a second range
// It then displays all of the Armstrong numbers that are within that range

// Include the libraries
#include <cmath>
#include <iomanip>
#include <iostream>

// Function to calculate the power of two numbers passed through from the
// isArmstrong function
// The number is raised to the number of digits in that number
float SurfaceCone(float radius, float height) {
    float slantHeight, surfaceArea;
    slantHeight = sqrt((radius * radius) + (height * height));
    surfaceArea = M_PI * radius * (radius + slantHeight);
    return surfaceArea;
}

// Function(calculator) to se if a number is perfect
// It will return a boolean expression to the if statement in the main function
float VolumeCone(float radius, float height) {
    float volume;
    volume = M_PI * (radius * radius) * (height / 3);
    return volume;
}

// Function(calculator) to se if a number is an Armstrong number
// It will return a boolean expression to the if statement in the main function
float SurfacePyramid(float baseEdge, float height) {
    float surfaceArea;
    surfaceArea = (baseEdge * baseEdge) + (2 * baseEdge) *
    sqrt(((baseEdge * baseEdge) / 4) + (height * height));
    return surfaceArea;
}

// Function(calculator) to se if a number is an Armstrong number
// It will return a boolean expression to the if statement in the main function
float VolumePyramid(float baseEdge, float height) {
    float volume;
    volume = (baseEdge * baseEdge) * (height / 3);
    return volume;
}

int main() {
    std::string playAgain;
    std::cout << "This program displays the volume and surface";
    std::cout << " area of cones and square pyramids." << std::endl;
    do {
        // Initialize the range inputs as strings and integers
        std::string userUnitsCone, userRadiusCone, userHeightCone;
        float radiusCone, heightCone, surfaceAreaCone, volumeCone;

        std::cout << "We will start with cones." << std::endl;

        // Get the start of the range for the perfect numbers identifier
        std::cout << "Enter the units for this cone: ";
        std::cin >> userUnitsCone;

        // Get the end of the range for the perfect numbers identifier
        std::cout << "Enter the radius for your cone: ";
        std::cin >> userRadiusCone;

        std::cout << "Enter the height for your cone: ";
        std::cin >> userHeightCone;

        // Use try catch for any erroneous input
        try {
            // Convert them to floats to check if the user inputted decimals
            // **Error check
            radiusCone = stof(userRadiusCone);
            heightCone = stof(userHeightCone);
        } catch (std::invalid_argument) {
            // Message for invalid input
            std::cout << "Please enter a valid number." << std::endl;
        }

        if (radiusCone <= 0 || heightCone <= 0) {
            std::cout << "Both the radius and the height must be positive";
            std::cout << " numbers." << std::endl;
        } else {
            surfaceAreaCone = SurfaceCone(radiusCone, heightCone);
            volumeCone = VolumeCone(radiusCone, heightCone);
            std::cout << "The surface area of this cone is "
            << std::fixed << std::setprecision(2) << surfaceAreaCone
            << userUnitsCone << "^2" << std::endl;

            std::cout << "The volume of this cone is "
            << std::fixed << std::setprecision(2) << volumeCone
            << userUnitsCone << "^3" << std::endl;
        }

        std::string userUnitsPyramid, userBaseEdgePyramid, userHeightPyramid;
        float baseEdge, heightPyramid, surfaceAreaPyramid, volumePyramid;

        std::cout << "Now We will calculate square pyramids." << std::endl;

        // Get the start of the range for the perfect numbers identifier
        std::cout << "Enter the units for this square pyramid: ";
        std::cin >> userUnitsPyramid;

        // Get the end of the range for the perfect numbers identifier
        std::cout << "Enter the radius for your square pyramid: ";
        std::cin >> userBaseEdgePyramid;

        std::cout << "Enter the height for your square pyramid: ";
        std::cin >> userHeightPyramid;

        // Use try catch for any erroneous input
        try {
            // Convert them to floats to check if the user inputted decimals
            // **Error check
            baseEdge = stof(userBaseEdgePyramid);
            heightPyramid = stof(userHeightPyramid);
        } catch (std::invalid_argument) {
            // Message for invalid input
            std::cout << "Please enter a valid number." << std::endl;
        }

        if (baseEdge <= 0 || heightPyramid <= 0) {
            std::cout << "Both the base edge and the height must be positive";
            std::cout << " numbers." << std::endl;
        } else {
            surfaceAreaPyramid = SurfacePyramid(baseEdge, heightPyramid);
            volumePyramid = VolumePyramid(baseEdge, heightPyramid);
            std::cout << "The surface area of this square pyramid is "
            << std::fixed << std::setprecision(2) << surfaceAreaPyramid <<
            userUnitsPyramid << "^2" << std::endl;

            std::cout << "The volume of this square pyramid is "
            << std::fixed << std::setprecision(2) << volumePyramid <<
            userUnitsPyramid << "^3" << std::endl;
        }
        std::cout << "Would you like to use this program again";
        std::cout << " (enter 'y' if yes)? ";
        std::cin >> playAgain;
    } while (playAgain == "y");
    std::cout << "Thank you for using this program." << std::endl;
}
