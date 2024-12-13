#include <iostream>
#include <cmath> // for ceil()
#include <iomanip>
using namespace std;

// Function to get a positive number from the user
double getPositiveInput(string prompt, double minValue) {
    double value;
    do {
        cout << prompt;
        cin >> value;
        if (value < minValue) {
            cout << "Error: Value must be at least " << minValue << ". Please try again." << endl;
        }
    } while (value < minValue);
    return value;
}

// Function to calculate the total wall space
double calculateWallSpace(int rooms) {
    double totalWallSpace = 0;
    for (int i = 1; i <= rooms; i++) {
        totalWallSpace += getPositiveInput("Enter square footage for room " + to_string(i) + ": ", 0);
    }
    return totalWallSpace;
}

int main() {
    const int SQFT_PER_GALLON = 110;
    const int LABOR_HOURS_PER_GALLON = 8;
    const double LABOR_COST_PER_HOUR = 25.0;

    // Input
    int rooms = getPositiveInput("Enter the number of rooms to be painted: ", 1);
    double totalWallSpace = calculateWallSpace(rooms);
    double pricePerGallon = getPositiveInput("Enter the price of paint per gallon (minimum $10): ", 10.0);

    // Calculations
    double gallonsRequired = ceil(totalWallSpace / SQFT_PER_GALLON);
    double laborHours = (totalWallSpace / SQFT_PER_GALLON) * LABOR_HOURS_PER_GALLON;
    double paintCost = gallonsRequired * pricePerGallon;
    double laborCost = laborHours * LABOR_COST_PER_HOUR;
    double totalCost = paintCost + laborCost;

    // Output
    cout << fixed << setprecision(2);
    cout << "\nPaint Job Estimate:" << endl;
    cout << "------------------------" << endl;
    cout << "Gallons of paint required: " << gallonsRequired << endl;
    cout << "Hours of labor required: " << laborHours << endl;
    cout << "Cost of paint: $" << paintCost << endl;
    cout << "Labor charges: $" << laborCost << endl;
    cout << "Total cost of job: $" << totalCost << endl;

    return 0;
}
