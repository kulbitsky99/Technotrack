#include <iostream>
// class-specific allocation functions
typedef long long int mytype;
struct X {
    static void* operator new(std::size_t sz)
    {
        std::cout << "custom new for size " << sz << '\n';
        return ::operator new(sz);
    }

    static void* operator new[](std::size_t sz)
    {      
	std::cout << "custom new for size " << sz << '\n';
	return ::operator new(sz);
    }

};

int main() {
     X* p1 = new X;
     delete p1;
     mytype* p2 = new mytype[10];
     delete[] p2;
}

