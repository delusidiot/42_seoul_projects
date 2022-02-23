#ifndef __REPLACE_HPP__
# define __REPLACE_HPP__

#include <fstream>

class Replace
{
private:
	std::string		_stringToReplace;
	std::string		_replacement;
	std::string		_fileName;
	std::ifstream	_inputFileStream;
public:
	Replace(void);
	~Replace(void);

	bool setFile(std::string fileName);
	bool replace(std::string stringToReplace, std::string replacement);
	void outputToFile(std::string fileContent);

};

#endif