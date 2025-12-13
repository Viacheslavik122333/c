#include "headerC.h"

int main()
{
    int tmp = printtex();
    
    switch (tmp) 
    {
        case 1: process_array<int>(); break;
        case 2: process_array<double>(); break;
        default: 
            std::cout << "Неверное число!" << std::endl;
            return -1;
    }
    return 0;
}