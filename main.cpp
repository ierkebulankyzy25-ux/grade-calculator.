#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    const int numScores = 5;
    string studentName = "";
    int studentCount = 0;
    double sumOfAverages = 0.0;

    cout << "Student name (or end to finish): ";
    getline(cin, studentName);

    while (studentName != "end") {
        int scoreSum = 0;

        // Read scores for the current student
        for (int scoreIndex = 1; scoreIndex <= numScores; scoreIndex++) {
            int currentScore = 0;
            bool validScore = false;

            // Loop inside loop: re-prompt until a valid integer in 0..100 is entered
            while (!validScore) {
                cout << "Score " << scoreIndex << ": ";
                if (cin >> currentScore) {
                    if (currentScore >= 0 && currentScore <= 100) {
                        validScore = true;
                    } else {
                        cout << "Invalid score. Enter a value from 0 to 100." << endl;
                    }
                } else {
                    cout << "Invalid score. Enter a value from 0 to 100." << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
            }

            scoreSum += currentScore;
        }

        // Clear any leftover newline before reading the next student name
        cin.ignore(1000, '\n');

        double studentAverage = static_cast<double>(scoreSum) / numScores;
        char letterGrade = 'F';

        if (studentAverage >= 90.0) {
            letterGrade = 'A';
        } else if (studentAverage >= 75.0) {
            letterGrade = 'B';
        } else if (studentAverage >= 60.0) {
            letterGrade = 'C';
        } else {
            letterGrade = 'F';
        }

        cout << studentName << ": average " << fixed << setprecision(1)
             << studentAverage << ", grade " << letterGrade << endl;

        studentCount++;
        sumOfAverages += studentAverage;

        cout << "Student name (or end to finish): ";
        getline(cin, studentName);
    }

    if (studentCount == 0) {
        cout << "No students entered" << endl;
    } else {
        double classAverage = sumOfAverages / studentCount;
        cout << "Students entered: " << studentCount << endl;
        cout << "Class average: " << fixed << setprecision(1)
             << classAverage << endl;
    }

    return 0;
}
