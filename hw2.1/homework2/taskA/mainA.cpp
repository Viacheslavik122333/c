#include "headerA.h"

int main()
{
    int tmp = printtex();
    
    switch (tmp) 
    {
        case 1: process_array<int>(); break;
        case 2: process_array<double>(); break;
        case 3: process_array<Complex>(); break;
        case 4: process_array<modular>(); break;
        default: 
            std::cout << "Неверное число!" << std::endl;
            return -1;
    }
    return 0;
}