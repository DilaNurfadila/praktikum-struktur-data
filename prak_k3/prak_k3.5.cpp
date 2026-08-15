#include <iostream>
using namespace std;
void print(int A[], int length)
{
    for (int n = 0; n < length; n++)
    {
        cout << A[n] << " \n";
    }
}
int main()
{
    int arr[3] = {5, 10, 15}; // array yang akan passing ke fungsi parameter
    print(arr, 3);            // passing value dan length ke fungsi parameter
}