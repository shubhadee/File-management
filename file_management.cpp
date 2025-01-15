#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <limits>

using namespace std;

void writeToFile(const string& filename) {
    try {
        ofstream outFile(filename, ios::out);
        if (!outFile) {
            throw runtime_error("Error creating file!");
        }

        cout << "Enter data to write to the file: ";
        string data;
        getline(cin, data); 

        outFile << data << endl;
        outFile.close();

        cout << "Data written successfully.\n";
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

void appendToFile(const string& filename) {
    try {
        ofstream outFile(filename, ios::app);
        if (!outFile) {
            throw runtime_error("Error opening file for appending!");
        }

        cout << "Enter data to append to the file: ";
        string data;
        getline(cin, data);

        outFile << data << endl;
        outFile.close();

        cout << "Data appended successfully.\n";
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

void readFromFile(const string& filename) {
    try {
        ifstream inFile(filename, ios::in);
        if (!inFile) {
            throw runtime_error("Error opening file for reading!");
        }

        cout << "File contents:\n";
        string line;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

void updateFileContent(const string& filename) {
    try {
        ofstream outFile(filename, ios::out | ios::trunc);
        if (!outFile) {
            throw runtime_error("Error opening file for updating!");
        }

        cout << "Enter new data to replace the file's content: ";
        string data;
        getline(cin, data);

        outFile << data << endl;
        outFile.close();

        cout << "File content updated successfully.\n";
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

int main() {
    string filename;
    cout << "Enter the filename: ";
    getline(cin, filename); 

    int choice;
    do {
        cout << "\nFile Management Tool:\n";
        cout << "1. Write to File\n";
        cout << "2. Append to File\n";
        cout << "3. Read from File\n";
        cout << "4. Update File Content\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        while (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number: ";
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        try {
            switch (choice) {
                case 1:
                    writeToFile(filename);
                    break;
                case 2:
                    appendToFile(filename);
                    break;
                case 3:
                    readFromFile(filename);
                    break;
                case 4:
                    updateFileContent(filename);
                    break;
                case 5:
                    cout << "Exiting program.\n";
                    break;
                default:
                    throw invalid_argument("Invalid choice. Please try again.");
            }
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    } while (choice != 5);

    return 0;
}
