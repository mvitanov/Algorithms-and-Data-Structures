#include <iostream>

using namespace std;

template <class T>
void insertionsort(T *arr, int length)
{
    int i;
    for(i = 0; i < length; i++)
    {
        T current, pos;
        current = arr[i];
        pos = i;
        while((pos > 0) && (current <= arr[pos - 1]))
        {
            arr[pos] = arr[pos - 1];
            pos -= 1;
        }
        arr[pos] = current;
    }
}

int main()
{
    int arr[] = {5, 122, 1, 9, 33, 3, 12, 2, 7, 4};
    insertionsort(arr, 10);
    int i;
    for(i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
