#include <iostream>
#include <fstream>
#include <sstream>

using std:: cout;
using std:: cin;
using std:: endl;


struct symbol
{
    std::string value;

    void get_value(symbol)
    {
        cout << value << endl;
    }
};

struct dynarr
{
    symbol *arr;
    int mx_sz;
    int cur_sz;

    dynarr()
    {
        arr = (symbol *)malloc(4 * sizeof(symbol));
        mx_sz = 4;
        cur_sz = 0;
    }

    ~dynarr()
    {
        free(arr);
    }

    void push_back(std::string x)
    {
        if(cur_sz < mx_sz)
        {
            arr[cur_sz++].value = x;
            return;
        }


        symbol *narr = (symbol *)malloc(2 * mx_sz * sizeof(symbol));
        if(narr == NULL)
        {
            printf("не выделилась память (");
            return;
        }

        for(int i=0; i<mx_sz; ++i)
        {
            narr[i].value = arr[i].value;
        }
        mx_sz*=2;
        free(arr);
        arr = narr;
        arr[++cur_sz].value = x;
    }

    void pop_back ()
    {
        if(cur_sz == 0)
        {
            printf("cur_sz == 0, не делай так!");
            return;
        }
        --cur_sz;
        return;
    }

    symbol operator [] (int i) const
    {
        // if(i<0 || i>=cur_sz)
        // {
        //     printf("x<0 || x>cur_sz, не делай так!");
        //     exit ;
        // }
        return arr[i];
    }

    void get_v (int i)
    {
        if(i<0 || i>=cur_sz)
        {
            printf("x<0 || x>cur_sz, не делай так!");
            return;
        }
        arr[i].get_value(arr[i]);
    }
};

struct Node
{
    int data;
    Node* next;

    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

struct stack
{
    Node* real;

    stack()
    {
        real = nullptr;
    }
    ~stack()
    {
        while (real != nullptr)
        pop_back();
    }
    void push_back(int x)
    {
        Node* tmp = new Node(x);
        tmp->next = real;
        real = tmp;
    }

    void pop_back ()
    {
        if (real == nullptr) return;
        Node* tmp = real;
        real = real->next;
        delete tmp;
    }

    int get_back()
    {
        if (real == nullptr) return 0;
        return real->data;
    }
    bool empty() 
    {
        return real == nullptr;
    }
};


int main() 
{
    std::string input;
    std::getline(std::cin, input);
    
    std::istringstream line(input);
    std::string x;
    
    dynarr arr;
    int n = 0;
    
    while (line >> x) 
    { 
        arr.push_back(x);
        n++;
    }


    
    
    for(int i = 0; i < n; ++i) 
    {
        arr.get_v(i);
    }
    
    return 0;
}

