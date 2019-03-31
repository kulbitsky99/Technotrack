#pragma once
#include <iostream>
#include <fstream>

enum types
{
	BAD_ERRSTAT = 1,
	BAD_TYPEID = 2
};

static std::string Description[] = 
{
	"DO YOU REALLY THINK THAT SOMEONE IS BETTER THAN MENTOR VADIM SOKOLOV??? If a had an opportunity, I would call all destructors to eliminate such a silly program. GOD DAMN BOY!!!", 	
	"Invalid identification of type happened."	
};

class myMesg
{
	public://problem!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		int type_;
                int line_;
                std::string filename_;
                std::string function_;

		myMesg();
		myMesg(int type, int line, std::string filename, std::string function);
		~myMesg();
};

class myExcept
{
	private:
		myMesg msg_;
	public:
		myExcept(myMesg msg);
		~myExcept();
		void write_report();

};


myMesg::myMesg() :
	type_             (0),
	line_             (0),
	filename_         (""),
	function_         ("")
{}

myMesg::myMesg(int type, int line, std::string filename, std::string function) :
        type_             (type),
        line_             (line),
        filename_         (filename),
        function_         (function)
{}

myExcept::myExcept(myMesg msg) :
	msg_              (msg)
{}

myMesg::~myMesg()
{}
myExcept::~myExcept()
{}

void myExcept::write_report()
{
	std::fstream log("report.txt", std::ios_base::app);
	log << "___Here is all the information about catched exception!___" << std::endl;
	log << std::endl; 
	log << "Exception of " << msg_.type_ << " type happened." << std::endl;
	switch(msg_.type_)
	{
		case 1:
			log << Description[0] << std::endl;
			break;
		case 2:
			log << Description[1] << std::endl;
			break;
		default:
			log << "There is no description of such type. Check it out!" << std::endl;
			break;	
	}
	log << "Exception threw from the {" << msg_.filename_ << "} file, ";
	log << "{" << msg_.function_ << "} function and " << msg_.line_ << " line." << std::endl;
	log << std::endl;
	log.close();
}

