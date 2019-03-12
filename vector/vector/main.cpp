#include "vector.h"

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
//        fout.close();
        return 0;
}

