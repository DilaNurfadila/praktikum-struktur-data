#include <iostream>
using namespace std;
int linSortSearch(int Fnd, int Arr[], int Size)
{
    while (Size >= 0 && Fnd < Arr[--Size])
        ;
    if (Arr[Size] == Fnd)
        return Size;
    return (-1);
}

int linSearch(int Fnd, int Arr[], int Size)
{
    while (Size >= 0 && Fnd != Arr[--Size])
        ;
    return Size;
}
int main()
{
    int arr[] = {10, 50, 30, 70, 80};
    for (auto z : arr)
        cout << z << " ";
    cout << endl
         << endl;
    cout << linSearch(10, arr, 5);
    cout << endl
         << endl;
    cout << linSortSearch(30, arr, 5);
    cout << endl;
}