#include "vector.h"

std::fstream fout("info.txt", std::ios_base::out);

Vector :: Vector() :
	data_  		(nullptr),
	capacity_ 	      (0)
{
//	fout.open("info.txt", std::ios_base::out);
	fout << "Default constructor created nullptr pointer:)" << std::endl;
//	fout.close();
}

Vector :: Vector(int capacity_) :
	data_         (new mytype [sizeof(mytype) * capacity_, __LINE__]),
	capacity_                  (capacity_)
{
	/*
	for(int i(0); i < capacity_; i++)
	{
		data_[i] = 0.0f;
	}
	*/
//	fout.open("info.txt", std::ios_base::out);
	fout << "Constructor created successfully vector of capacity = " << capacity_<< std::endl;
	fout << "The beginning of data is = "<< data_ << std::endl;
//	fout.close();
}

Vector :: Vector(const Vector & v) :
	data_         (new mytype [sizeof(mytype) * v.capacity_, __LINE__]),
	capacity_                  (v.capacity_)
{
	for(int i = 0; i < v.capacity_; i++)
		data_[i] = v.data_[i];
//	fout.open("info.txt", std::ios_base::out);
	fout << "Constructor copied vector in brackets into proper one successfully" << std::endl;
//	fout.close();
}

Vector :: ~Vector()
{
	operator delete[]( data_, __LINE__);//calling of function?
	// delete[] data_;
//	fout.open("info.txt", std::ios_base::out);
	fout << "Destructor deleted vector with data pointer = " << data_ << std::endl;
	data_ = nullptr;// not to call dtor again at the end of the function
//	fout.close();
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

void* Vector :: operator new[](size_t size, int line)
{
	fout << "I was here" << std::endl;
//	fout.open("info.txt", std::ios_base::out);
        fout << "New called in " << line << " line with size = " << size << std::endl;
//	fout.close();
        return new char [size]();
}

void Vector :: operator delete[] (void* ptr, int line)
{
//	fout.open("info.txt", std::ios_base::out);
        fout << "Delete called in " << line << " line" << std::endl;
//	fout.close();
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

/*void operator delete[](void* ptr, int line)
{
	delete (mytype*)ptr;
}*/




