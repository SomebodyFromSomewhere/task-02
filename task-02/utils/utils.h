#pragma once

#ifndef UTILS_H
#define UTILS_H

void executionTime(clock_t start, std::string function_name = "NULL");
std::vector<int> splitInt(std::string& s, char delimeter);
std::vector<std::string> splitString(std::string& s, char delimeter);

#endif // UTILS_h