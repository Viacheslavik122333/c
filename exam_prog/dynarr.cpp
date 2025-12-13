#include <iostream>
#include <fstream>

using std:: cout;
using std:: cin;
using std:: endl;

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

    void push_back(int x)
    {
        if(cur_sz < mx_sz)
        {
            arr[cur_sz++]=x;
            return;
        }
        int*narr = (int *)malloc(2 * mx_sz * sizeof(int));
        if(narr == NULL)
        {
            // printf("не выделилась память (");
            return;
        }
        for(int i=0; i<mx_sz; ++i)
        {
            narr[i]=arr[i];
        }
        mx_sz*=2;
        free(arr);
        arr = narr;
        arr[cur_sz++] = x;
        return;
    }

    void pop_back ()
    {
        if(cur_sz == 0)
        {
            // printf("cur_sz == 0, не делай так!");
            return;
        }
        --cur_sz;
        return;
    }

    int operator [] (int i) const
    {
        if(i<0 || i>=cur_sz)
        {
            // printf("x<0 || x>cur_sz, не делай так!");
            return;
        }
        return arr[i];
    }
};