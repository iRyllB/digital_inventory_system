#include <string>
#include <fstream>
using namespace std;

// FILE EXISTENCE CHECKER
bool fileExists(const string& filename) {
    ifstream file(filename);
    return file.good();
}

// FILE NAME GENERATOR
string generateUniqueFilename(const string& baseName) {
    int index = 0;
    string filename;

    do {
        if (index == 0) {
            filename = baseName + ".txt";
        } else {
            filename = baseName + "(" + to_string(index) + ").txt";
        }
        index++;
    } while (fileExists(filename));  // <-- loop while filename exists

    return filename;  // <-- return after loop finishes
}
