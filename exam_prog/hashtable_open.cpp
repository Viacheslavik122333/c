#include <iostream>
#include <vector>
#include <string>

class OpenHashTable 
{
private:
    size_t table_size; 
    std::vector<std::pair<std::string, int>> table;

    std::vector<bool> occupied; // занято место или нет 
    std::vector<bool> del; // удалено ли место

    // сама хеш-функция
    size_t _hash(std::string key)
    {
        size_t hash_value = 0;
        for (char c : key) hash_value = hash_value * 31 + static_cast<size_t>(c); // полиномиальный хеш
        return hash_value % table_size;
    }

    // поиск свободного места
    size_t _find_slot(const std::string& key, bool tmp) 
    {
        size_t index = _hash(key);
        size_t start = index;
        size_t count = 0;
        while (true) 
        {
            if (!occupied[index]) // не свободно
            { 
                if (tmp) return index;
                return table_size;
            }

            if (table[index].first == key && !del[index]) //
            {
                return index; 
            }
            count++;
            index = (start + count) % table_size;

            if (count >= table_size) return table_size; 
        }
    }

public:
    OpenHashTable(size_t size = 101)
    {
        table_size = size;
        table.resize(size, {"", 0});
        occupied.resize(size, false);
        del.resize(size, false);
    }

    // вставка или обновление
    void insert(const std::string& key, int value) 
    {
        if (key.empty()) return;

        size_t slot = _find_slot(key, true);

        if (slot == table_size) return;

        table[slot] = {key, value};
        occupied[slot] = true;
        del[slot] = false;
    }

    // поиск значения
    int search(const std::string& key)
    {
        size_t slot = _find_slot(key, false);

        if (slot == table_size) return -1;

        return table[slot].second;
    }

    // удаление
    bool remove(const std::string& key) 
    {
        size_t slot = _find_slot(key, false);

        if (slot == table_size) return false;

        del[slot] = true;
        return true;
    }


    void print()
    {
        for (size_t i = 0; i < table_size; ++i) 
        {
            if (occupied[i] && !del[i]) 
            {
                std::cout << "Слот " << i << ": {" << table[i].first << ", " << table[i].second << "}" << std::endl;
            } 
            else if (del[i]) 
            {
                std::cout << "Слот " << i << ": удален" << std::endl;
            }
        }
    }
};

int main() 
{
    OpenHashTable ht(11); // Маленький размер для теста коллизий

    ht.insert("apple", 10);
    ht.insert("banana", 20); //
    ht.insert("cherry", 30); 
    ht.insert("apple", 15); 
    ht.insert("CHerry", 30); //

    ht.print();

    ht.remove("banana");

    ht.print();

    return 0;
}