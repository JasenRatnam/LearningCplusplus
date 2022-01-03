
#include <iostream>

using namespace std;

int main() 
{
    int numlist[6] = {25, 37, 62, 78, 92, 13};
    int *listPtr = numlist;
    int *temp = listPtr + 2;
    int num;
    
    *listPtr = *(listPtr + 1) - *listPtr;
    listPtr++;
    num = *temp;
    temp++;
    listPtr ++;
    *listPtr = *temp;
    *temp = num;
    listPtr = listPtr + 2;
    *listPtr = *(listPtr-1);
    
    cout << numlist;
    return 0;
}

