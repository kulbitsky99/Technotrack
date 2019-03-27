#include "except.hpp"

int main()
{
	try
	{
		// myExcept exc(1, "FIRST EXCEPTION", __LINE__, __FILE__, __func__);
		throw myExcept(1, "FIRST EXCEPTION", __LINE__, __FILE__, __func__);
	}
	catch(myExcept & exc)
	{
		exc.write_report();	
	}
}


