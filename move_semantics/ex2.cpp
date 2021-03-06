#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <assert.h>

typedef float mytype; 

class Vector
{
        public:
                mytype * data_;
                int capacity_;
                Vector();
                explicit Vector(int capacity_);
                Vector(const Vector & v);
                ~Vector();
                mytype & at(int index);
		const mytype & at(int index) const;
		mytype &operator[] (int index);
                const mytype &operator[] (int index) const;
                Vector operator+(const Vector & other) const;
                Vector& operator =(Vector rhs);
                void swap(Vector & rhs);
                //________________________________________________//
                friend  std::ostream & operator<<(std::ostream& stream, const Vector& v);
                friend  std::istream & operator>>(std::istream& stream, Vector& v);
};

void f(const Vector& v)
{
	for(int i = 0; i < v.capacity_; i++)
	{
		std::cout << v.data_[i] << " ";
		std::cout << std::endl;
	}
}

int main()
{
	Vector v(10);
	Vector v2 = 10;
	f(2);
//	std::cout << "v[3] = " << v[3] << std::endl;
}


Vector :: Vector() :
        data_           (nullptr),
        capacity_             (0)
{
	std::cout << "Default constructor created nullptr pointer:)" << std::endl;
}

Vector :: Vector(int capacity) :
        data_                 (new mytype [capacity * sizeof(mytype)]),
        capacity_                                           (capacity)
{
	std::cout << "Constructor created successfully vector of capacity = " << capacity_<< std::endl;
	std::cout << "The beginning of data is = "<< data_ << std::endl;
}

Vector :: Vector(const Vector & v) :
        data_                 (new mytype [v.capacity_ * sizeof(mytype)]),
        capacity_                                           (v.capacity_)
{
        for(int i = 0; i < v.capacity_; i++)
                data_[i] = v.data_[i];
	std::cout << "Constructor copied vector in brackets into proper one successfully" << std::endl;
}
Vector :: ~Vector()
{
        operator delete[]( data_, __LINE__);//calling of function?
	std::cout << "Destructor deleted vector with data pointer = " << data_ << std::endl;
        data_ = nullptr;// not to call dtor again at the end of the function
}

//_______________________________________________//
mytype & Vector :: at(int index)
{
//	std::cout << "I was in at() and my index is " << index << std::endl;
        assert(index >= 0 && index <= capacity_);
        return data_[index];
}

const mytype & Vector :: at(int index) const 
{
//	std::cout << "I was in const at() and my index is " << index << std::endl;
        assert(index >= 0 && index <= capacity_);
        return data_[index];
}


mytype & Vector :: operator[] (int index)
{
//	std::cout << "I was in op[] and my index is " << index << std::endl;
        return at(index);
}



const mytype & Vector :: operator[] (int index) const
{
//	std::cout << "I was in const op[] and my index is " << index << std::endl;
        return at(index);
}

Vector Vector::operator+(const Vector & other) const
{
        assert(capacity_ == other.capacity_);
        Vector result(capacity_);
        for(int i = 0; i < capacity_; i++)
                result.data_[i] = this -> data_[i] + other.data_[i];
        return result;
}

Vector& Vector :: operator=(Vector rhs)
{
        Vector :: swap(rhs);
        return *this;
}
void Vector :: swap(Vector & rhs)
{
        std::swap(capacity_, rhs.capacity_);
        std::swap(data_, rhs.data_);
}

std::ostream & operator<<(std::ostream & stream, const Vector & v)
{
        std::cout << "Vector = ( ";
        for(int i = 0; i < v.capacity_; i++)
        {
                std::cout << v.data_[i] << " ";
        }
        std::cout << ")";
        return stream;
}

std::istream & operator>>(std::istream & stream, Vector & v)
{
        for(int i = 0; i < v.capacity_; i++)
        {
                std::cin >> v.data_[i];
        }
        return stream;
}

