#include <iostream>
#include <string>

using namespace std;

void insertionsort(string *arr, int length)
{
    int i;
    for(i = 0; i < length; i++)
    {
        string current;
        int pos;
        current = arr[i];
        pos = i;
        while((pos > 0) && (current.compare(arr[pos - 1]) <= 0))
        {
            arr[pos] = arr[pos - 1];
            pos -= 1;
        }
        arr[pos] = current;
    }
}

// simple test program
int main()
{
    string arr[] = {"Mario", "Angela", "Zack", "Nicole", "John", "Catherine"};
    insertionsort(arr, 6);
    int i;
    for(i = 0; i < 6; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
