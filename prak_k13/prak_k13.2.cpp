#include <iostream>
#include <iterator>
#include <map>

using namespace std;

int main()
{
    // assign map
    map<int, int> m = {{1, 2}, {2, 3}, {3, 4}};

    // add element
    // key | value => 4 | 5
    m.insert(pair<int, int>(4, 5));
    // key | value => 5 | 6
    m.insert(make_pair(5, 6));

    // assign iterator
    // access element in a container
    map<int, int>::iterator i, j;
    i = m.find(2); // assign key 2 to i
    j = m.find(5); // assign key 5 to j
    map<int, int> new_m;
    new_m.insert(i, j); // add to new_m
    // show key and value
    cout << "Key : " << i->first << ", value : " << i->second << endl; // output => Key : 2, value : 3
    cout << "Key : " << j->first << ", value : " << j->second << endl; // output => Key : 5, value : 6

    // show the element
    // output :
    // 2	3
    // 3	4
    // 4	5
    for (i = new_m.begin(); i != new_m.end(); ++i)
    {
        cout << '\t' << i->first << '\t' << i->second
             << '\n';
    }

    cout << endl
         << endl;

    // for (j = new_m.begin(); j != new_m.end(); ++j) {
    //     cout << '\t' << j->first << '\t' << j->second
    //          << '\n';
    // }

    // cout << endl << endl;

    // add value 6 to key 3, if exists not change the value with new value
    m.insert(make_pair(3, 6));
    for (i = m.begin(); i != m.end(); ++i)
    {
        // output :
        // 1	2
        // 2	3
        // 3	4
        // 4	5
        // 5	6
        cout << '\t' << i->first << '\t' << i->second
             << '\n';
    }

    // add value 6 to key 3, if exists replace previous value with new value
    m.insert_or_assign(3, 6);
    cout << endl
         << endl;
    for (i = m.begin(); i != m.end(); ++i)
    {
        // output :
        // 1	2
        // 2	3
        // 3	6
        // 4	5
        // 5	6
        cout << '\t' << i->first << '\t' << i->second
             << '\n';
    }
}