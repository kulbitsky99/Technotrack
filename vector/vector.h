#pragma once
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>              
#include <assert.h>

#define mytype float

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
                void* operator new[] (size_t size, int line);
                void operator delete[] (void* ptr, int line);

                void swap(Vector & rhs);
                //________________________________________________//
                friend  std::ostream & operator<<(std::ostream& stream, const Vector& v);
                friend  std::istream & operator>>(std::istream& stream, Vector& v);
};

