#include <iostream>
#include <fstream>

using std:: cout;
using std:: cin;
using std:: endl;
// static int global_zero = 0;

struct dynarr
{
    int *arr;
    int mx_sz;
    int cur_sz;

    dynarr()
    {
        arr = (int *)malloc(4 * sizeof(int));
        mx_sz = 4;
        cur_sz = 0;
    }

    ~dynarr()
    {
        free(arr);
    }

    int push_back(int x)
    {
        if(cur_sz < mx_sz)
        {
            arr[cur_sz++]=x;
            return 0;
        }
        int*narr = (int *)malloc(2 * mx_sz * sizeof(int));
        if(narr == NULL)
        {
            // printf("не выделилась память (");
            return -1;
        }
        for(int i=0; i<mx_sz; ++i)
        {
            narr[i]=arr[i];
        }
        mx_sz*=2;
        free(arr);
        arr = narr;
        arr[cur_sz++] = x;
        return 0;
    }

    int pop_back ()
    {
        if(cur_sz == 0)
        {
            // printf("cur_sz == 0, не делай так!");
            return -1;
        }
        --cur_sz;
        return 0;
    }

    int operator [] (int i) const
    {
        if(i<0 || i>=cur_sz)
        {
            // printf("x<0 || x>cur_sz, не делай так!");
            return 0;
        }
        return arr[i];
    }
};


int main()
{
    int n, t, x;
    dynarr arr;
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    if (!fin.is_open()) 
    {
        std::cerr << "Не удалось открыть файл fin" << std::endl;
        return -1;
    }
    if (!fout.is_open()) 
    {
        std::cerr << "Не удалось открыть файл fout" << std::endl;
        return -1;
    }

    fin >> n;

    for (int i=0; i<n; ++i)
    {
        fin >> t;
        switch (t)
        {
        case 0:
            fin >> x;
            fout << arr.push_back(x) << endl;
            break;
        case 1:
            fout << arr.pop_back() << endl;
            break;

        case 2:
            fin >> x;
            fout << arr[x] << endl;
            break;
        }
    }

    fin.close();
    fout.close();
    return 0;
}