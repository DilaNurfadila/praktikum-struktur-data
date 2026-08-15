#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // assign vector
    vector<int> vec1;

    // menambahkan element ke vector dengan looping
    for (int i = 1; i <= 10; i++)
    {
        vec1.push_back(i);
    }

    // menampilkan element setelah ditambahkan dengan looping
    cout << "Understanding begin() and end() function : " << endl;
    for (auto i = vec1.begin(); i != vec1.end(); ++i)
    {
        // output => 1 2 3 4 5 6 7 8 9 10
        cout << *i << " ";
    }
}