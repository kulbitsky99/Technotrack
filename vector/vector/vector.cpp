#include "vector.h"

std::fstream fout("info.txt", std::ios_base::out);

Vector :: Vector() :
	data_  		(nullptr),
	capacity_ 	      (0)
{
	fout << "Default constructor created nullptr pointer:)" << std::endl;
}

Vector :: Vector(int capacity) :
	data_                 (new mytype [capacity * sizeof(mytype)]),
	capacity_                                           (capacity)
{
	fout << "Constructor created successfully vector of capacity = " << capacity_<< std::endl;
	fout << "The beginning of data is = "<< data_ << std::endl;
}

Vector :: Vector(const Vector & v) :
	data_                 (new mytype [v.capacity_ * sizeof(mytype)]),
	capacity_                                           (v.capacity_)
{
	for(int i = 0; i < v.capacity_; i++)
		data_[i] = v.data_[i];
	fout << "Constructor copied vector in brackets into proper one successfully" << std::endl;
}

Vector :: ~Vector()
{
	operator delete[]( data_, __LINE__);//calling of function?
	fout << "Destructor deleted vector with data pointer = " << data_ << std::endl;
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

static void* Vector :: operator new [] (size_t size, int line)
{
	fout << "I was here" << std::endl;
        fout << "New called in " << line << " line with size = " << size << std::endl;
	return new char [size];
}

static void Vector :: operator delete[] (void* ptr, int line)
{
        fout << "Delete called in " << line << " line" << std::endl;
        delete static_cast<mytype*>(ptr);
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





