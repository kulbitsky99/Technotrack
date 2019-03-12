#pragma once
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>              
#include <assert.h>

// #define mytype float
typedef float mytype;

#define NEW(SIZE, LINE)						\
	do							\
	{							\
		new ((LINE)) mytype[(SIZE)];			\
	}							\
	while(0)

#define DELETE(PTR, LINE)					\
	do							\
	{							\
		operator delete[]((PTR), (LINE));		\
	}							\
	while(0)




class Vector
{
        private:
                mytype * data_;
                int capacity_;
        public:
                Vector();
                Vector(int capacity_);
                Vector(const Vector & v);
                ~Vector();
                mytype & at(int index);
                mytype &operator[] (int index);
                Vector operator+(const Vector & other) const;
                Vector& operator =(Vector rhs);
                static void* operator new [] (size_t size, int line);
                static void operator delete[] (void* ptr, int line);

                void swap(Vector & rhs);
                //________________________________________________//
                friend  std::ostream & operator<<(std::ostream& stream, const Vector& v);
                friend  std::istream & operator>>(std::istream& stream, Vector& v);
};

