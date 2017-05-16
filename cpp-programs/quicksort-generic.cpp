#include <iostream>

using namespace std;

template <class T>
void quicksortSubList(T *arr, int first, int last)
{
    if (first >= last)
        return;
    else
    {
        T pivot, temp;
        int pivotPos, i;
        pivot = arr[last];
        pivotPos = first;
        for(i = first; i < last; i++)
            if(arr[i] <= pivot)
            {
                temp = arr[i];
                arr[i] = arr[pivotPos];
                arr[pivotPos] = temp;
                pivotPos += 1;
            }
        temp = arr[pivotPos];
        arr[pivotPos] = arr[last];
        arr[last] = temp;

        quicksortSubList(arr, first, pivotPos - 1);
        quicksortSubList(arr, pivotPos + 1, last);
    }
}

template <class T>
void quicksort(T *arr, int length)
{
    quicksortSubList(arr, 0, length - 1);
}

// simple test
int main()
{
    int arr[] = {5, 1, 9, 3, 12, 2, 7, 4};
    quicksort(arr, 8);
    int i;
    for(i = 0; i < 8; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
