#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void):
	Form("ShrubberyCreationForm", 145, 137), _target("")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):
	Form("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src):
	Form(src), _target(src.getTarget())
{
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	rhs.getTarget();
	std::cout << "Can't copy anything" << std::endl;
	return *this;
}

const std::string &ShrubberyCreationForm::getTarget(void) const
{
	return this->_target;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	std::ofstream	myfile;
	std::string		fileName = this->_target + "_shrubbery";

	this->checkExecutability(executor);
	myfile.open(fileName.c_str(), std::ios::out);
	myfile << "		. . ." << std::endl;
	myfile << "	.        .  .     ..    ." << std::endl;
	myfile << ".                 .         .  ." << std::endl;
	myfile << "				." << std::endl;
	myfile << "				.                .." << std::endl;
	myfile << ".          .            .              ." << std::endl;
	myfile << ".            '.,        .               ." << std::endl;
	myfile << ".              'b      *" << std::endl;
	myfile << ".              '$    #.                .." << std::endl;
	myfile << ".    .           $:   #:               ." << std::endl;
	myfile << "..      .  ..      *#  @):        .   . ." << std::endl;
	myfile << "			.     :@,@):   ,.**:'   ." << std::endl;
	myfile << ".      .,         :@@*: ..**'      .   ." << std::endl;
	myfile << "		'#o.    .:(@'.@*\"'  ." << std::endl;
	myfile << ".  .       'bq,..:,@@*'   ,*      .  ." << std::endl;
	myfile << "			,p$q8,:@)'  .p*'      ." << std::endl;
	myfile << "	.     '  . '@@Pp@@*'    .  ." << std::endl;
	myfile << "	.  . ..    Y7'.'     .  ." << std::endl;
	myfile << "				:@):." << std::endl;
	myfile << "				.:@:'." << std::endl;
	myfile << "			.::(@:.                     GoldTree" << std::endl;
	myfile.close();
	std::cout << "Created in " << this->_target << "_shrubbery" << std::endl;
}

/* std::ostream &	operator<<( std::ostream & ostr, ShrubberyCreationForm const & instance) */
/* { */
/* 	ostr << "The value of ShrubberyCreationForm is..." << std::endl; */
/* 	return ostr; */
/* } */
