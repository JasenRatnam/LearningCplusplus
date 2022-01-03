

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    cout << "Enter words ";
    string words;
    vector <string> stringHolder;
    
    int size = 0;
    
    while (size != 5)
    {
        size++;
        cin >> words;
        stringHolder.push_back(words);
    }
    
    sort(stringHolder.begin(), stringHolder.end());
    
    int vSize = stringHolder.size();
    
    if(vSize == 0)
    {
        cout << "No words ";
        return 1;
    }
    
    int wordCount = 1;
    words = stringHolder[0];
    for(int i = 1; i < vSize; i++)
    {
        if(words != stringHolder[i])
        {
            cout << words << " appeared " << wordCount << " amount of time\n";
            wordCount = 0;
            words = stringHolder[i];
        }
        wordCount++;
        
    }
    cout << words << " appeared " << wordCount << " amount of times \n";
    return 0;
}

