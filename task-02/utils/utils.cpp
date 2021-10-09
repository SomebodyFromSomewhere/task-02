#include <stdio.h>
#include <iostream>
#include <time.h>
#include <vector>
#include <sstream>
#include <string>

void executionTime(clock_t start, std::string function_name = "NULL") {
	clock_t end = clock();
	double seconds = (double)(end - double(start)) / CLOCKS_PER_SEC;
	if (function_name == "NULL")
	{
		printf("[TIME]%f SECONDS ELAPSED\n", seconds);
	}
	else {
		std::cerr << "[TIME][" << function_name << "]" << seconds << " SECONDS ELAPSED" << std::endl;
	}
}

std::vector<int> splitInt(std::string& s, char delimeter) {
	std::stringstream ss(s);
	std::string item;
	std::vector<int> tokens;
	while (std::getline(ss, item, delimeter))
	{
		tokens.push_back(std::stoi(item));
	}
	return tokens;
}

std::vector<std::string> splitString(std::string& s, char delimeter) {
	std::stringstream ss(s);
	std::string item;
	std::vector<std::string> tokens;
	while (std::getline(ss, item, delimeter))
	{
		tokens.push_back(item);
	}
	return tokens;
}