#include <iostream>
#include <map>

using namespace std;

int main()
{
    // assign map and value
    map<int, string> m = {{1, "nikhilesh"}, {2, "shrikant"}, {3, "ashish"}};

    cout << m.at(1); // output => nikhilesh
    cout << m.at(2); // output => shrikant

    // kesimpulan :
    // at() adalah key

    cout << m[3]; // output => ashish

    m.at(1) = "vikas"; // change nikhilesh with vikas
    m[2] = "navneet";  // change shrikant with navneet
    m[4] = "doodrah";  // add doodrah at 4

    m.at(5) = "umeshwa"; // add umeshwa at 5
}