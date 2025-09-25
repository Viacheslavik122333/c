#include "iostream"
#include "vector"


struct Employee // Сотрудник
{
    int id;
    int level;
    std::vector<Employee*> sons; // список подчиненных
    Employee()
    {
        id=0; level=0;
    }
};

void quantity_fun(std::vector<Employee*> tmp, std::vector<int> &levelcount, int n);
int findMaxLevel(Employee* emp, int Level, int max);

std::vector<Employee*> fun (int n, std::vector<int>& arr) 
{
    std::vector<Employee*> tmp (n + 1); // массив сотрудников

    for (int i = 1; i <= n; i++) // создали n сотрудников компании
    {
        tmp[i] = new Employee();
        tmp[i]->id = i;
    }
    for (int i = 2; i <= n; ++i) 
    {
        int Id = arr[i - 2]; // bosses[0] - начальник сотрудника 2
        tmp[Id]->sons.push_back(tmp[i]);
        
    }

    int max = findMaxLevel(tmp[1], 0, 0);
    std::vector<int> levelcount(max+1, 0);

    quantity_fun(tmp, levelcount, n);
    std::cout << max << "\n";
    for(int i=0; i<max+1; ++i)
    {
        std::cout << levelcount[i] << " ";
    }
    
    return tmp;
}

void quantity_fun(std::vector<Employee*> tmp, std::vector<int> &levelcount, int n) 
{
    for(int i = 1; i <= n; ++i )
    {
        levelcount [ tmp[i]->level ] ++;
    }
    return;
}

int findMaxLevel(Employee* emp, int Level, int max) 
{
    if (emp == nullptr) return max;
    
    emp->level = Level;
    
    if (Level > max) 
    {
        max = Level;
    }
    
    for (Employee* son : emp->sons) 
    {
        max = findMaxLevel(son, Level + 1, max);
    }
    
    return max;
}


int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr (n - 1);

    for (int i = 0; i < n - 1; i++) 
    {
        std::cin >> arr[i];
    }

    std::vector<Employee*> B = fun(n, arr);
    for(int i=0; i<n+1; ++i) 
    {
        delete B[i];
    }

    return 0;
}