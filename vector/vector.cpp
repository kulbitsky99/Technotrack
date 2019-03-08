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
		Vector(int cap);
		Vector(const Vector & v);
		~Vector();
		mytype & at(int index);
		mytype &operator[] (int index);
		Vector operator+(const Vector & other) const;
		Vector& operator =(Vector rhs);
//		void* operator new(size_t size, const char * file, int line);
		void swap(Vector & rhs);
		//________________________________________________//
		friend  std::ostream & operator<<(std::ostream& stream, const Vector& v);
		friend  std::istream & operator>>(std::istream& stream, Vector& v);
};

Vector :: Vector() :
	data_  		(nullptr),
	capacity_ 	      (0)
{
	std::cout << "Default constructor created nullptr pointer:)" << std::endl;
}

Vector :: Vector(int cap) :
	data_         (new mytype[cap]),
	capacity_                 (cap)
{
	std::cout << "Constructor created vector of capacity = " << cap << std::endl;
	std::cout << "The beginning of data is = "<< data_ << std::endl;
}

Vector :: Vector(const Vector & v) :
	data_         (new mytype [v.capacity_]),
	capacity_                 (v.capacity_)
{
	for(int i = 0; i < v.capacity_; i++)
		data_[i] = v.data_[i];
	std::cout << "Constructor copied vector in brackets into proper one" << std::endl;
}

Vector :: ~Vector()
{
	delete [] data_;
	std::cout << "Destructor deleted vector with data pointer = " << data_ << std::endl;
	data_ = nullptr;// not to call dtor again at the end of the function
}
//_______________________________________________//
mytype & Vector :: at(int index)
{
	assert(index >= 0 && index <= capacity_);
	return data_[index];
}
mytype & Vector :: operator[] (int index)
{
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

/*void* Vector :: operator new(size_t size, const char * file, int line)
{
	return new char [size];
}*/

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

int main()
{
	Vector v(5);
	std::cout << v << std::endl;
	Vector other(5);
	std::cin >> other;
	v = v + other;
	std::cout << v << std::endl;
	Vector v_copy(v);
	std::cout << v_copy << std::endl;
	return 0;
}	



