#include <iostream>
#include <fstream>

typedef float mytype;
std::fstream fout("info.txt", std::ios_base::out);

class Vector
{
        private:
                mytype * data_;
                int capacity_;
        public:
                static void* operator new[](std::size_t size, int line)
		{
			std::cout << "I was here" << std::endl;
			std::cout << "New was called in line " << line << std::endl;
			return ::operator new(size);
		}

};

int main()
{
        Vector* p2 = new (__LINE__) Vector[5];
	delete[] p2;
        fout.close();
}










/*Vector :: Vector() :
        data_           (nullptr),
        capacity_             (0)
{
        fout << "Default constructor created nullptr pointer:)" << std::endl;
}

Vector :: Vector(int capacity) :
        capacity_                  (capacity)
{
	data_ = new mytype [capacity];
        fout << "Constructor created successfully vector of capacity = " << capacity_<< std::endl;
        fout << "The beginning of data is = "<< data_ << std::endl;
}*/


