#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <time.h>
#include <vector>
#include <Windows.h>
#include "utils/utils.h"

std::vector<std::vector<int>> graph_array;
int lines, columns;

std::vector<std::vector<int>> readFromFile(std::string file_name) {
	std::ifstream file(file_name);
	file >> lines;
	file >> columns;
	std::vector<std::vector<int>> graph_array(lines, std::vector <int>(columns));
	int vertex;
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			char ch;
			file >> ch;
			if (ch == '.')
			{
				vertex = 0;
			}
			else
			{
				vertex = 1;
			}
			graph_array[i][j] = vertex;
		}
	}
	return graph_array;

}

//for debug
void displayArray(std::vector<std::vector<int>>& graph_array) {
	for (int i = 0; i < graph_array.size(); i++)
	{
		for (int j = 0; j < graph_array[i].size(); j++)
		{
			std::cerr << graph_array[i][j] << '|';
		}
		std::cerr << std::endl;
	}
	Sleep(500); //add delay to see steps in DFS
	system("CLS");
}

void DFS(int x, int y) {
	displayArray(graph_array);
	int current_value = graph_array[y][x], max_x = graph_array[0].size(), max_y = graph_array.size();
	// check right
	if (x + 1 < max_x) {
		if (graph_array[y][x + 1] == 1)
		{
			DFS(x + 1, y);
			graph_array[y][x] = 0;
		}
		else if (current_value == 1) {
			graph_array[y][x] = 0;
		}
	}
	else if (current_value == 1) {
		graph_array[y][x] = 0;
	}

	// check up
	if (y - 1 >= 0) {
		if (graph_array[y - 1][x] == 1)
		{
			DFS(x, y - 1);
			graph_array[y][x] = 0;
		}
		else if (current_value == 1) {
			graph_array[y][x] = 0;
		}
	}
	else if (current_value == 1) {
		graph_array[y][x] = 0;
	}

	// check left
	if (x - 1 >= 0) {
		if (graph_array[y][x - 1] == 1)
		{
			DFS(x - 1, y);
			graph_array[y][x] = 0;
		}
		else if (current_value == 1) {
			graph_array[y][x] = 0;
		}
	}
	else if (current_value == 1) {
		graph_array[y][x] = 0;
	}

	// check down
	if (y + 1 < max_y) {
		if (graph_array[y + 1][x] == 1)
		{
			DFS(x, y + 1);
			graph_array[y][x] = 0;
		}
		else if (current_value == 1) {
			graph_array[y][x] = 0;
		}
	}
	else if (current_value == 1) {
		graph_array[y][x] = 0;
	}
}

int main()
{
	clock_t start = clock();
	graph_array = readFromFile("INPUT.txt");
	int N = 0;
	int x = 0, y = 0, max_x = graph_array.size(), max_y = graph_array[0].size();
	displayArray(graph_array);
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (graph_array[i][j] != 0)
			{
				DFS(j, i);
				N++;
				displayArray(graph_array);
			}
		}
	}
	std::cerr << N << std::endl;
	executionTime(start, "MAIN");
	return 0;
}