//Реализация протокола Диффи–Хеллмана

#include "primitive_root.h"
#include <random>

const int p = 1e9+7;
std::mt19937 rd(time(NULL));

struct Speaker
{
private:
    ll key; // ключ
    ll root; // первообразный корень

public:
    Speaker (ll prim_root) 
    {
        root = prim_root;
        key = rd() % (p - 1) + 1;
    }
    ll get_open() // возвращает открытый ключ
    {
        return pow_mod(root, key, p);
    }

    ll cipher(ll message, ll open_key) // кодирует сообщение
    {
        ll tmp = pow_mod(open_key, key, p);
        return (message * tmp) % p;
    }

    ll decipher(ll message, ll open_key) // декодирует сообщение
    {
        ll tmp = pow_mod(open_key, key, p);
        tmp = pow_mod(tmp, p-2, p);
        return (message * tmp) % p;
    }
};


int main()
{
    ll p_ = primitive_root(p);

    Speaker A(p_);
    Speaker B(p_);

    ll A_ = A.get_open();
    ll B_ = B.get_open();


    std::cout << "Открытый ключ A: " << A_ << std::endl;
    std::cout << "Открытый ключ B: " << B_ << std::endl;

    ll message;
    std::cout << "Введите сообщение: A -> B: ";
    std::cin >> message;

    ll tmp = A.cipher(message, B_);
    
    std::cout << "Зашифрованное:  " << tmp << std::endl;
    
    std::cout << "Расшифрованное: " << B.decipher(tmp, A_) << std::endl;
    
    return 0;
}