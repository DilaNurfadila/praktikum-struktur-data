#include <iostream>
using namespace std;
void insertionSort(int A[], int Size)
{
    for (int i = 1; i < Size; i++)
    {
        int j, key = A[i];
        for (j = i - 1; j >= 0 && A[j] > key; j--)
        {
            A[j + 1] = A[j];
        }
        A[j + 1] = key;
    }
}
int main()
{
    int arr[] = {12, 6, 3, 8, 20, 5, 35};
    for (auto z : arr)
        cout << z << " ";
    cout << endl
         << endl;
    insertionSort(arr, 7);
    cout << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
}