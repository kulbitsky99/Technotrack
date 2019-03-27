#pragma once
#include <iostream>
#include <fstream>

class myExcept
{
	private:
		int type_;
		int line_;
		std::string message_;// complete class message with all these fields
		std::string filename_;
		std::string function_;
	public:
		myExcept();
		myExcept(int type, std::string message, int line, std::string filename, std::string function);
		~myExcept();
		void write_report();

};


myExcept::myExcept() :
	type_             (0),
	line_             (0),
	message_          (""),
	filename_         (""),
	function_         ("")
{}

myExcept::myExcept(int type, std::string message, int line, std::string filename, std::string function) :
        type_             (type),
        line_             (line),
        message_          (message),
        filename_         (filename),
        function_         (function)
{}

myExcept::~myExcept()
{}
void myExcept::write_report()
{
	std::fstream log("report.txt", std::ios_base::out);// create attractive view of report
	log << "ATTENTION! EXCEPTION HAPPENED!" << std::endl;
	log << "type of mistake - " << type_ << std::endl;
	log << "short message about it: " << message_ << std::endl;
	log << "line of throwing " << line_ << std::endl;
	log << "file, where throwing happened " << filename_ << std::endl;
	log << "function, where throwing happened " << function_ << std::endl;
	log.close();
}

