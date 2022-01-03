
#include <iostream>
#include<cmath>

using namespace std;

int main() 
{
    void f(int *a, int b =0, int c =2)
    {
        *a += b * b +2*b*c+1;
        return;
    }
    int main()
    {
        int a =5;
        f(&a,3);
        cout << a;
    }
}

