#include <string>
#include <fstream>

bool fileExists(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();
}

// FILE NAME GENERATOR
std::string generateUniqueFilename(const std::string& baseName) {
    int index = 0;
    std::string filename;

    do {
        if (index == 0) {
            filename = baseName + ".txt";
        } else {
            filename = baseName + "(" + std::to_string(index) + ").txt";
        }
        index++;
    } while (fileExists(filename));  // <-- loop while filename exists

    return filename;  // <-- return after loop finishes
}
