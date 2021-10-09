#include <random>
#include <fstream>
#include <iostream>

int main() {
	int lines = 20, columns = 20;
	std::ofstream file("INPUT.txt");
	file << lines << ' ' << columns << std::endl;
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			int n = std::rand() % 100;
			if (n < 50)
			{
				file << '.';
			}
			else {
				file << '#';
			}
		}
		file << std::endl;
	}
	file.close();
	return 0;
}