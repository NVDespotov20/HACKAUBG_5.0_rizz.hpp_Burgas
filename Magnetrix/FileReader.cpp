#include <pch.hpp>
#include "FileReader.hpp"

FileReader::FileReader()
{
}

FileReader::FileReader(std::string path)
{
	openFile(path);
}

FileReader::~FileReader()
{
	closeFile();
}

void FileReader::openFile(std::string path)
{
	closeFile();

	file.open(path);
	

	if (!file.is_open())
	{
		std::cout << "File not loaded path: " << path;
	}
}

void FileReader::closeFile()
{
	if (file.is_open())
		file.close();
}

void FileReader::getText(int grid[10][10])
{
	if (!file.is_open())
		return;

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			file >> grid[i][j];
}