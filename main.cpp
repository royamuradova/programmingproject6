#include <iostream>
#include <iomanip>
using namespace std;

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32);
}

int main() {
    // Display the table header
    cout << "Fahrenheit\tCelsius" << endl;
    cout << "------------------------" << endl;

    // Generate the table
    for (int fahrenheit = 0; fahrenheit <= 20; ++fahrenheit) {
        double celsius = fahrenheitToCelsius(fahrenheit);
        cout << setw(10) << fahrenheit << "\t" << fixed << setprecision(2) << celsius << endl;
    }

    return 0;
}
