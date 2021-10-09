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
void getLinesAndColumns(std::ifstream& inpt_file, int& lines, int& columns) {
	std::string str;
	std::getline(inpt_file, str);
	std::vector<int> tmp = splitInt(str, ' ');
	lines = tmp[0];
	columns = tmp[1];
}

std::vector<std::vector<int>> getGraph(std::ifstream& file, int lines, int colomns) {
	std::vector<std::vector<int>> graph_array(lines, std::vector <int>(colomns));
	std::string str;
	std::vector<std::string> tmp;
	int vertex;
	for (int i = 0; i < lines; i++)
	{
		std::getline(file, str);
		tmp = splitString(str, ' ');
		for (int j = 0; j < tmp[0].size(); j++)
		{
			if (tmp[0][j] == '.')
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

void readFromFile(std::string file_name, std::vector<std::vector<int>>& graph_array) {
	std::ifstream file(file_name);
	getLinesAndColumns(file, lines, columns);
	graph_array = getGraph(file, lines, columns);
}

void displayGraph(std::vector<std::vector<int>>& graph_array) {
	for (int i = 0; i < graph_array.size(); i++)
	{
		for (int j = 0; j < graph_array[i].size(); j++)
		{
			std::cerr << graph_array[i][j] << '|';
		}
		std::cerr << std::endl;
	}
	//Sleep(1000);
	system("CLS");
	//std::cerr << "-----------" << std::endl;
}

void DFS(int x, int y) {
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
	if (y - 1 > 0) {
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
	if (x - 1 > 0) {
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
	readFromFile("INPUT.txt", graph_array);
	int N = 0;
	int x = 0, y = 0, max_x = graph_array.size(), max_y = graph_array[0].size();
	displayGraph(graph_array);
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (graph_array[i][j] != 0)
			{
				DFS(j, i);
				N++;
				displayGraph(graph_array);
			}
		}
	}
	std::cerr << N << std::endl;
	executionTime(start, "MAIN");
	return 0;
}