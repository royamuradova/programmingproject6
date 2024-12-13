#include <iostream>
#include <iomanip>
using namespace std;

// Function to get a valid score from the user
double getJudgeScore(int judgeNumber) {
    double score;
    do {
        cout << "Enter score for judge " << judgeNumber << " (0-10): ";
        cin >> score;
        if (score < 0 || score > 10) {
            cout << "Error: Score must be between 0 and 10. Please try again." << endl;
        }
    } while (score < 0 || score > 10);
    return score;
}

// Function to find the highest score
double findHighest(double scores[], int size) {
    double highest = scores[0];
    for (int i = 1; i < size; i++) {
        if (scores[i] > highest) {
            highest = scores[i];
        }
    }
    return highest;
}

// Function to find the lowest score
double findLowest(double scores[], int size) {
    double lowest = scores[0];
    for (int i = 1; i < size; i++) {
        if (scores[i] < lowest) {
            lowest = scores[i];
        }
    }
    return lowest;
}

// Function to calculate the average score
double calculateAverage(double scores[], int size, double highest, double lowest) {
    double total = 0;
    for (int i = 0; i < size; i++) {
        total += scores[i];
    }
    return (total - highest - lowest) / (size - 2); // Subtract the highest and lowest
}

int main() {
    const int NUM_JUDGES = 5;
    double scores[NUM_JUDGES];

    // Input: Get scores from the user
    for (int i = 0; i < NUM_JUDGES; i++) {
        scores[i] = getJudgeScore(i + 1);
    }

    // Processing
    double highest = findHighest(scores, NUM_JUDGES);
    double lowest = findLowest(scores, NUM_JUDGES);
    double finalScore = calculateAverage(scores, NUM_JUDGES, highest, lowest);

    // Output: Display the final score
    cout << fixed << setprecision(2);
    cout << "The contestant's final score is: " << finalScore << endl;

    return 0;
}
