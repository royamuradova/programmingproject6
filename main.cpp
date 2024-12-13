#include <iostream>
#include <string>
using namespace std;

// Function to get the number of accidents for a region
int getAccidents(string region) {
    int accidents;
    do {
        cout << "Enter the number of accidents in the " << region << " region: ";
        cin >> accidents;
        if (accidents < 0) {
            cout << "Error: Accident number cannot be negative. Please try again." << endl;
        }
    } while (accidents < 0);
    return accidents;
}

// Function to find the region with the fewest accidents
string findSafestRegion(int north, int south, int east, int west, int central) {
    int minAccidents = north;
    string safestRegion = "North";

    if (south < minAccidents) {
        minAccidents = south;
        safestRegion = "South";
    }
    if (east < minAccidents) {
        minAccidents = east;
        safestRegion = "East";
    }
    if (west < minAccidents) {
        minAccidents = west;
        safestRegion = "West";
    }
    if (central < minAccidents) {
        minAccidents = central;
        safestRegion = "Central";
    }
    return safestRegion + " (" + to_string(minAccidents) + " accidents)";
}

int main() {
    // Get accident data for all regions
    int north = getAccidents("North");
    int south = getAccidents("South");
    int east = getAccidents("East");
    int west = getAccidents("West");
    int central = getAccidents("Central");

    // Find and display the safest region
    string safestRegion = findSafestRegion(north, south, east, west, central);
    cout << "The safest region is: " << safestRegion << endl;

    return 0;
}
