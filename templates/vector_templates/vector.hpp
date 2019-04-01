#include "vector.h"

std::fstream fout("info.txt", std::ios_base::out);

template <typename T>
Vector <T> :: Vector() :
	data_  		(nullptr),
	capacity_ 	      (0)
{
	fout << "Default constructor created nullptr pointer:)" << std::endl;
}

template <typename T>
Vector <T> :: Vector(int capacity) :
	data_                 (new T [capacity * sizeof(T)]),
	capacity_             (capacity)
{
	fout << "Constructor created successfully vector of capacity = " << capacity_<< std::endl;
	fout << "The beginning of data is = "<< data_ << std::endl;
}

template <typename T>
Vector <T> :: Vector(const Vector <T> & v) :
	data_                 (new T [v.capacity_ * sizeof(T)]),
	capacity_             (v.capacity_)
{
	for(int i = 0; i < v.capacity_; i++)
		data_[i] = v.data_[i];
	fout << "Constructor copied vector in brackets into proper one successfully" << std::endl;
}

template <typename T>
Vector <T> :: ~Vector()
{
	operator delete[]( data_, __LINE__);//calling of function?
	fout << "Destructor deleted vector with data pointer = " << data_ << std::endl;
	data_ = nullptr;// not to call dtor again at the end of the function
}

//_______________________________________________//

template <typename T>
T & Vector <T> :: at(int index)
{
	assert(index >= 0 && index <= capacity_);
	return data_[index];
}

template <typename T>
T & Vector <T> :: operator[] (int index)
{
	return at(index);
}

template <typename T>
Vector <T> Vector <T>::operator+(const Vector <T> & other) const
{
	assert(capacity_ == other.capacity_);
	Vector <T> result(capacity_);
	for(int i = 0; i < capacity_; i++)
		result.data_[i] = this -> data_[i] + other.data_[i];
	return result;
}

template <typename T>
Vector <T> & Vector <T> :: operator=(Vector <T> rhs)
{
	Vector :: swap(rhs);
	return *this;
}

template <typename T>
static void* Vector <T> :: operator new [] (size_t size, int line)
{
	fout << "I was here" << std::endl;
        fout << "New called in " << line << " line with size = " << size << std::endl;
	return new char [size];
}

template <typename T>
static void Vector <T> :: operator delete[] (void* ptr, int line)
{
        fout << "Delete called in " << line << " line" << std::endl;
        delete static_cast<T*>(ptr);
}

template <typename T>
void Vector <T> :: swap(Vector <T> & rhs)
{
	std::swap(capacity_, rhs.capacity_);
	std::swap(data_, rhs.data_);
}

template <typename T>
std::ostream & operator<<(std::ostream & stream, const Vector <T> & v)
{
	std::cout << "Vector = ( ";
	for(int i = 0; i < v.capacity_; i++)
	{
		std::cout << v.data_[i] << " ";
	}
	std::cout << ")";
	return stream;
}

template <typename T>
std::istream & operator>>(std::istream & stream, Vector <T> & v)
{
	for(int i = 0; i < v.capacity_; i++)
	{
		std::cin >> v.data_[i];
	}
	return stream;
}

//template<>
//Vector<float>::Vector(int );
