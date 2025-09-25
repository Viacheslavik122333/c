#include "iostream"
#include "cmath"


void swap (int *N, int start, int end)
{
    int tmp = N[end];
    for(int i=end; i>start; --i)
    {
        N[i] = N[i-1]; 
    }
    N[start] = tmp;
    return;
}

void fun (int h, int* N, int start, int end, int tmph)
{
    int n = end - start+1;
    if(n<3) return;


    for(int i=1; i<=(n-1)/2; ++i)
    {
        swap(N, start, start + i);
        tmph--;
        
        if(tmph == h)
        {
            return;
        } 

    }

    fun(h, N, start+1, start + n/2, tmph);
    fun(h, N, start + (n+1)/2, end, tmph);

    return;
}

int main()
{

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, h;

    std::cin >> n;
    std::cin >> h;
    ++h;

    if (h > n || n > (1 << h) - 1)
    {
        std::cout << -1  << std::endl;
        return 0;
    }
    
    if (h == n)
    {
        for(int i=n; i>0; --i)
        {
            std::cout << i << " ";
        }
        return 0;
    }
    
////////////////////////////////

    int* N = new int[n];
    for(int i=0; i<n; ++i)
    {
        N[i] = i+1;
    }

    fun (h, N, 0, n-1, n);

    for(int i=0; i<n; ++i)
    {
        std::cout << N[i] << " ";
    }
    delete[] N;

    return 0;
}