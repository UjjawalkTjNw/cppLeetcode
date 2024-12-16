#include <iostream>
#include <fstream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    ifstream inputFile("numbers.txt"); // Input file with numbers
    unordered_set<int> seenNumbers;   // Set to track unique numbers
    vector<int> duplicates;           // Vector to store duplicate numbers

    int number;
    while (inputFile >> number) {
        if (seenNumbers.find(number) != seenNumbers.end()) {
            // If number is already in set, it's a duplicate
            duplicates.push_back(number);
        } else {
            // Otherwise, add it to the set
            seenNumbers.insert(number);
        }
    }

    inputFile.close();

    cout << "Duplicate numbers:" << endl;
    for (int dup : duplicates) {
        cout << dup << endl;
    }

    return 0;
}
