#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <utility> // pair

class HashTable
{
private:
    size_t table_size;
    std::vector<std::list<std::pair<std::string, int>>> table; // {ключ, значение}

    // сама хеш-функция
    size_t _hash( std::string key)
    {
        size_t hash_value = 0;
        for (char c : key) hash_value = hash_value * 31 + static_cast<size_t>(c); // полиномиальный хеш
        return hash_value % table_size;
    }

public:

    HashTable(size_t size = 100)
    {
        table_size = size;
        table.resize(size);
    }

    void insert(std::string key, int value) // вставка или обновление элемента
    {
        size_t index = _hash(key);
        auto& chain = table[index]; // ссылка на лист 

        // ищем ключ
        for (auto& pair : chain) 
        {
            if (pair.first == key) 
            {
                pair.second = value; // обновляем
                return;
            }
        }
        chain.push_back({key, value});
    }

    int search(std::string key) // поиск
    {
        size_t index = _hash(key); 
        auto& chain = table[index]; 

        for (auto& pair : chain)
        {
            if (pair.first == key) return pair.second; // победили
        }

        return -1; // не победили
    }

    bool del(std::string key) // удаление
    {
        size_t index = _hash(key);
        auto& chain = table[index];

        for (auto it = chain.begin(); it != chain.end(); ++it) // проходим весь лист
        {
            if (it->first == key) 
            {
                chain.erase(it);
                return true;
            }
        }
        return false; 
    }

    
    void print() // вывод таблицы
    {
        for (size_t i = 0; i < table_size; ++i) 
        {
            if (!table[i].empty()) 
            {
                std::cout << "Slot " << i << ": ";
                for (auto& pair : table[i]) std::cout << "{" << pair.first << ": " << pair.second << "} ";
                std::cout << std::endl;
            }
        }
    }
};

int main() 
{
    HashTable ht(10);

    ht.insert("apple", 5);
    ht.insert("banana", 10); //
    ht.insert("apple", 15);
    ht.insert("cherry", 20);
    ht.insert("CHerry", 30); //

    std::cout << "Hash Table contents:" << std::endl;
    ht.print();

    std::cout << "Search 'apple': " << ht.search("apple") << std::endl; // 15
    std::cout << "Search 'lala': " << ht.search("grape") << std::endl; // -1

    ht.del("banana");
    ht.print();

    return 0;
}