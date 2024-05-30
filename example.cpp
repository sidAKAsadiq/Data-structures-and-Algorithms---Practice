#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    // Open the file for reading
    ifstream inputFile("file3.txt");

    if (!inputFile.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    // Variables to store counts
    int letterCount = 0;
    int wordCount = 0;
    int lineCount = 0;

    string line;

    // Loop through each line in the file and count lines
    while (getline(inputFile, line)) {
        lineCount++;
    }

    // Close the file
    inputFile.close();

    // Open the file again for counting letters and words
    ifstream inputFile2("file3.txt");

    // Loop through each line in the file
    while (getline(inputFile2, line)) {
        // Loop through each character in the line and count letters
        for (char& c : line) {
            if (isalnum(c)) {
                letterCount++;
            }
        }

        // Use a stringstream to count words in the line
        stringstream ss(line);
        string word;
        while (ss >> word) {
            wordCount++;
        }
    }

    // Close the file
    inputFile2.close();

    // Output the counts
    cout << "Number of letters: " << letterCount << endl;
    cout << "Number of words: " << wordCount << endl;
    cout << "Number of lines: " << lineCount << endl;

    return 0;
}
