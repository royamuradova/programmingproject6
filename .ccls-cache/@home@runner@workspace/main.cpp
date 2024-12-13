#include <iostream>
using namespace std;

// Function to calculate the area of the rectangle
double calculateArea(double length, double width) {
    return length * width;
}

// Function to calculate the perimeter of the rectangle
double calculatePerimeter(double length, double width) {
    return 2 * (length + width);
}

// Function to validate user input
double getPositiveInput(string prompt) {
    double value;
    do {
        cout << prompt;
        cin >> value;
        if (value <= 0) {
            cout << "Error: Please enter a positive value." << endl;
        }
    } while (value <= 0);
    return value;
}

int main() {
    char choice;
    do {
        // Input: Get length and width
        double length = getPositiveInput("Enter the length of the rectangle: ");
        double width = getPositiveInput("Enter the width of the rectangle: ");

        // Processing: Calculate area and perimeter
        double area = calculateArea(length, width);
        double perimeter = calculatePerimeter(length, width);

        // Output: Display results
        cout << "Area: " << area << endl;
        cout << "Perimeter: " << perimeter << endl;

        // Check if the user wants to calculate another rectangle
        cout << "Do you want to process another rectangle? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Goodbye!" << endl;
    return 0;
}
