#include <iostream>
using namespace std;
int BinSearch(int arr[], int left, int right, int x)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x)
            return mid;
        else
        {
            if (arr[mid] < x)
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {1, 3, 12, 14, 23, 34, 55, 65, 75, 78};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (auto z : arr)
        cout << z << " ";
    cout << endl
         << endl;
    cout << BinSearch(arr, 0, n - 1, 75);
    cout << endl;
}