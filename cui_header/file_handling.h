#ifndef FILE_HANDLING_H
#define FILE_HANDLING_H

#include <string>

// Checks if a file exists
bool fileExists(const std::string& filename);
std::string generateUniqueFilename(const std::string& baseName);

#endif // FILE_HANDLING_H
