#include "except.hpp"

void deeper();
void deeper_and_deeper();

int main()
{
	try
	{
		deeper();
	}	
	catch(myExcept & exc)
	{
		exc.write_report();	
	}
	catch(...)
	{
		std::fstream log("report.txt", std::ios_base::app);
		log << "Exception of undefined type catched!" << std::endl;
		log << std::endl;
		log.close();
	}
	std::fstream log("report.txt", std::ios_base::app);
	log << "________________________________________________________" << std::endl;
	log.close();
	return 0;
}


void deeper_and_deeper()
{
	try
	{
	throw 1;
	}
	catch(const char & symb)
        {
                std::cout << "If I called this, crazy magic happened!" << std::endl;
        }

	try
	{
	bool True = false;
	if(True != true)
		throw myExcept(myMesg(BAD_TYPEID,  __LINE__, __FILE__, __func__));
	}
	catch(int a)
	{
		std::cout << "If I called this, crazy magic happened!" << std::endl;
	}
}
void deeper()
{
	try
	{
	std::string BEST_MENTOR = "SOMEONE";
	if(BEST_MENTOR != "VADIM SOKOLOV")
		throw myExcept(myMesg(BAD_ERRSTAT,  __LINE__, __FILE__, __func__));
	}
	catch(const char & symb)
        {
                std::cout << "If I called this, crazy magic happened!" << std::endl;
        }
	try
	{
		deeper_and_deeper();
	}
	catch(const char & symb)
        {
                std::cout << "If I called this, crazy magic happened!" << std::endl;
        }


}


