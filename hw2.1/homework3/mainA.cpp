#include "iostream"
#include "vector"


struct Employee // Сотрудник
{
    int id;
    int quantity;
    std::vector<Employee*> sons; // список подчиненных
    Employee()
    {
        id=0; quantity=0;
    }
};

int quantity_fun(Employee* emp);

std::vector<Employee*> fun (int n, std::vector<int>& arr) 
{
    std::vector<Employee*> tmp (n + 1); // массив сотрудников

    for (int i = 1; i <= n; i++) // создали n сотрудников компании
    {
        tmp[i] = new Employee();
        tmp[i]->id = i;
    }

    int count;

    for (int i = 2; i <= n; ++i) 
    {
        int Id = arr[i - 2]; // bosses[0] - начальник сотрудника 2
        // tmp[j]->quantity++;
        tmp[Id]->sons.push_back(tmp[i]);
    }

    (void)(quantity_fun(tmp[1]));
    
    return tmp;
}

int quantity_fun(Employee* emp) 
{
    if (emp == nullptr) return 0;
    
    int total = emp->sons.size();
    
    for (Employee* son : emp->sons) 
    {
        total += quantity_fun(son);
    }
    
    emp->quantity = total;

    return total;
}

void res(std::vector<Employee*> emp, int n) 
{
    
    for (int i=1; i<=n; i++)
    {
        std::cout << emp[i]->quantity << " ";
    }
    return;
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
    res(B, n);
    for(int i=0; i<n+1; ++i) 
    {
        delete B[i];
    }
    
    return 0;
}