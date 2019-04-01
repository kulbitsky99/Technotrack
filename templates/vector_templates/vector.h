#pragma once
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>              
#include <assert.h>

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



/*template<typename T>
class Vector;
template <typename T>  std::ostream & operator<<(std::ostream& stream, const Vector <T> & v);
template <typename T>  std::istream & operator>>(std::istream& stream, Vector <T> & v);*/


template < typename T >

class Vector
{
        private:
                T * data_;
                int capacity_;
        public:
                Vector();
                Vector(int capacity);
                Vector(const Vector <T> & v);
                ~Vector();
                T & at(int index);
                T &operator[] (int index);
                Vector operator+(const Vector <T> & other) const;
                Vector& operator =(Vector <T> rhs);
		static void* operator new [] (size_t size, int line);
		static void operator delete[] (void* ptr, int line);

                void swap(Vector <T> & rhs);
                //________________________________________________//
                /*friend std::ostream & operator<< <>(std::ostream& stream, const Vector<T> & v);
		friend std::istream & operator>> <>(std::istream& stream, Vector<T> & v);*/
                template <typename T1> friend  std::istream & operator>>(std::istream& stream, Vector <T1> & v);
		template <typename T1> friend  std::ostream & operator<<(std::ostream& stream, const Vector <T1> & v);
};


