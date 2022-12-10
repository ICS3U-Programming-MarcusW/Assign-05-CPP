// Copyright (c) 2022 Immaculata HS All rights reserved.
// Created by: Marcus Wehbi
// Date: Dec 1 2022
// This program calculates the surface area and the volume of a cone
// This program also calculates the surface area and volume of a square pyramid

// Include the libraries
#include <cmath>
#include <iomanip>
#include <iostream>

// Function to calculate the surface area of a cone
// Get radius and height parameters through main
float SurfaceCone(float radius, float height) {
    // Initialize variables as floats
    float slantHeight, surfaceArea;
    // Calculate the slant height
    slantHeight = sqrt((radius * radius) + (height * height));
    // Calculate the surface area using the slant height
    surfaceArea = M_PI * radius * (radius + slantHeight);
    // Return the surface area
    return surfaceArea;
}

// Function to calculate the volume of a cone
// Get radius and height parameters through main
float VolumeCone(float radius, float height) {
    // Initialize volume as a float
    float volume;
    // Calculate the volume using the formula
    volume = M_PI * (radius * radius) * (height / 3);
    // Return the volume
    return volume;
}

// Function to calculate the surface area of a square pyramid
// Get base edge and height parameters through main
float SurfacePyramid(float baseEdge, float height) {
    // Initialize the surface area
    float surfaceArea;
    // Calculate the surface area using formula
    surfaceArea = (baseEdge * baseEdge) + (2 * baseEdge) *
    sqrt(((baseEdge * baseEdge) / 4) + (height * height));
    // Return the surface area
    return surfaceArea;
}

// Function to calculate the volume of a square pyramid
// Get base edge and height parameters through main
float VolumePyramid(float baseEdge, float height) {
    // Initialize the volume as a float
    float volume;
    // Calculate the volume of a pyramid using the formula
    volume = (baseEdge * baseEdge) * (height / 3);
    // Return the volume
    return volume;
}

// Function to receive input from user, call functions to complete calculations
// and output the surface areas and volumes of cones and square pyramids
int main() {
    // Initialize variable to see if the user wants to play again as a string
    std::string playAgain;
    // Explain what the program does
    std::cout << "This program displays the volume and surface";
    std::cout << " area of cones and square pyramids." << std::endl;
    // Use a do while loop to continue the program as long as the user wants
    do {
        // Initialize units as strings
        std::string userUnitsCone, userRadiusCone, userHeightCone;
        // Initialize the float variables
        float radiusCone, heightCone, surfaceAreaCone, volumeCone;
        // Tell the user which we will begin with
        std::cout << "We will start with cones." << std::endl;

        // Get the units form ths user
        std::cout << "Enter the units for this cone: ";
        std::cin >> userUnitsCone;

        // Get the radius of the cone form the user
        std::cout << "Enter the radius for your cone: ";
        std::cin >> userRadiusCone;
        // Get the height of the cone from the user
        std::cout << "Enter the height for your cone: ";
        std::cin >> userHeightCone;

        // Use try catch for any erroneous input
        try {
            // Convert the radius and height to floats for calculations
            // **Error check
            radiusCone = stof(userRadiusCone);
            heightCone = stof(userHeightCone);
        } catch (std::invalid_argument) {
            // Message for invalid input
            std::cout << "Please enter a valid number." << std::endl;
        }
        // Make sure the radius and height are greater than 0
        if (radiusCone <= 0 || heightCone <= 0) {
            // Message if they are not greater than 0
            std::cout << "Both the radius and the height must be positive";
            std::cout << " numbers." << std::endl;
        } else {
            // Otherwise, continue with the program
            // Call function to calculate the surface area of a cone
            surfaceAreaCone = SurfaceCone(radiusCone, heightCone);
            // Call function to calculate the surface area of a cone
            volumeCone = VolumeCone(radiusCone, heightCone);
            // Display the surface area of the cone rounded to two decimals
            std::cout << "The surface area of this cone is "
            << std::fixed << std::setprecision(2) << surfaceAreaCone
            << userUnitsCone << "^2" << std::endl;
            // Display the volume fo the cone rounded to two decimals
            std::cout << "The volume of this cone is "
            << std::fixed << std::setprecision(2) << volumeCone
            << userUnitsCone << "^3" << std::endl;
        }

        // Initialize strings for the square pyramid
        std::string userUnitsPyramid, userBaseEdgePyramid, userHeightPyramid;
        // Initialize floats for the the square pyramid calculations
        float baseEdge, heightPyramid, surfaceAreaPyramid, volumePyramid;

        std::cout << "Now We will calculate square pyramids." << std::endl;
        // Get the units for the pyramid from the user
        std::cout << "Enter the units for this square pyramid: ";
        std::cin >> userUnitsPyramid;

        // Get the base edge of the pyramid from the user
        std::cout << "Enter the base edge for your square pyramid: ";
        std::cin >> userBaseEdgePyramid;
        // Get the height of the pyramid from the user
        std::cout << "Enter the height for your square pyramid: ";
        std::cin >> userHeightPyramid;

        // Use try catch for any erroneous input
        try {
            // Convert the base edge and height to floats for calculation
            // **Error check
            baseEdge = stof(userBaseEdgePyramid);
            heightPyramid = stof(userHeightPyramid);
        } catch (std::invalid_argument) {
            // Message for invalid input
            std::cout << "Please enter a valid number." << std::endl;
        }
        // Make sure the base edge and height are both greater than zero
        if (baseEdge <= 0 || heightPyramid <= 0) {
            // Message if they are not
            std::cout << "Both the base edge and the height must be positive";
            std::cout << " numbers." << std::endl;
        } else {
            // Otherwise continue with program
            // Call function to calculate the surface area of a pyramid
            surfaceAreaPyramid = SurfacePyramid(baseEdge, heightPyramid);
            // Call function to calculate the volume of a pyramid
            volumePyramid = VolumePyramid(baseEdge, heightPyramid);
            // Display the surface area of the square pyramid
            std::cout << "The surface area of this square pyramid is "
            << std::fixed << std::setprecision(2) << surfaceAreaPyramid <<
            userUnitsPyramid << "^2" << std::endl;
            // Display the volume of the square pyramid
            std::cout << "The volume of this square pyramid is "
            << std::fixed << std::setprecision(2) << volumePyramid <<
            userUnitsPyramid << "^3" << std::endl;
        }
        // Ask the user if they would like to play again
        std::cout << "Would you like to use this program again";
        std::cout << " (enter 'y' if yes)? ";
        std::cin >> playAgain;
        // While the user indicates yes, replay the program
    } while (playAgain == "y");
    // Finally statement to thank the user for playing
    std::cout << "Thank you for using this program." << std::endl;
}
