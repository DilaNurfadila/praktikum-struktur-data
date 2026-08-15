// #include <iostream>
// using namespace std;
// void insert(int A[], int &N, int item, int pos)
// {
//     for (int i = N - 1; i >= pos; i--)
//     {
//         A[i + 1] = A[i];
//     }
//     A[pos] = item;
//     N++;
// }
// int main()
// {
//     int arr[] = {10, 20, 50, 30, 15};
//     int N = 5;
//     for (auto z : arr)
//         cout << z << " ";
//     cout << endl
//          << endl;
//     insert(arr, N, 40, 3);
//     cout << endl;
//     for (int i = 0; i < N; i++)
//     {
//         cout << arr[i] << " ";
//     }
// }

#include <iostream>
using namespace std;
void insert(int A[], int &N, int item, int pos)
{
    for (int i = N - 1; i >= pos; i--)
    {
        A[i + 1] = A[i];
    }
    A[pos] = item;
    N++;
}
int main()
{
    int arr[] = {10, 20, 50, 30, 15};
    int N = 5;
    for (auto z : arr)
        cout << z << " ";
    cout << endl
         << endl;
    insert(arr, N, 40, 3);
    cout << endl;
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
}