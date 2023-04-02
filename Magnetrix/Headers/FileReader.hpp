#pragma once


class FileReader
{
public:
	FileReader();
	FileReader(std::string path);
	~FileReader();
	void openFile(std::string path);
	void closeFile();
	void getText(int grid[10][10]);

private:
	std::ifstream file;
};