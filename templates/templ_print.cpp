#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstddef>
#include <cassert>


void print(const char * str);
template < typename T, typename ... Other>
void print(const char * str, T arg, Other ... args);

int main()
{
//	print("int # double #", 10, 5.6);
	print("int #, double #, double trouble # !", 10, 25.5, 666.6);
	std::cout << "I'm here";
	return 0;
}
void print(const char * str)
{
	std::cout << "/";
	puts(str);
}
template <typename T, typename ... Other>
void print(const char * str, T arg, Other ... args)
{
//	std::cout << std::count(str, str + strlen(str), '#') << "_______" <<(sizeof...(args) + 1) << std::endl;
	assert(std::count(str, str + strlen(str), '#') == (sizeof...(args) + 1));
	while(*str)
	{
		if(*str != '#')
		{
			putchar(*str);
			str++;
		}
		else
		{
			std::cout << arg;
			str++;
			if(sizeof...(args))
			{
				print(str, args);
			}
			else
			{
				print(str);
			}

		}
	}
}
