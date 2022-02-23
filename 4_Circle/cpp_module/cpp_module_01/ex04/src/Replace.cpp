#include "Replace.hpp"
#include <iostream>

Replace::Replace(void)
{
}

Replace::~Replace(void)
{
}

bool Replace::setFile(std::string fileName)
{
	if (this->_inputFileStream.is_open())
		this->_inputFileStream.close();
	if (fileName == "")
		return false;
	this->_inputFileStream.open(fileName);
	if (!this->_inputFileStream)
		return false;
	this->_fileName = fileName;
	std::cout << "Input file set to " << fileName << std::endl;
	return true;
}

bool Replace::replace(std::string stringToReplace, std::string replacement)
{
	std::string result;
	size_t toReplaceLen = stringToReplace.length();

	if (stringToReplace == "" || replacement == "")
		return false;
	result.assign(std::istreambuf_iterator<char>(this->_inputFileStream), std::istreambuf_iterator<char>());
	for (size_t i = 0; i < result.length(); i++)
	{
		if (result.compare(i, toReplaceLen, stringToReplace) == 0)
		{
			result.erase(i, toReplaceLen);
			result.insert(i, replacement);
		}
	}
	outputToFile(result);
	return true;
}

void Replace::outputToFile(std::string fileContent)
{
	std::ofstream outputFileStream;
	std::string outputFileName = this->_fileName;

	outputFileName += ".replace";
	outputFileStream.open(outputFileName);
	std::cout << "Writing modified content to file " << outputFileName << std::endl;
	outputFileStream << fileContent;
}