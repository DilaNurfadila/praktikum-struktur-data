#include <iostream>
using namespace std;
int main() {
    int marks[5];
    // Getting marks of 10 students
    for(int i=0; i<5; i++){
        cout << "Enter Marks of Student " << i << " : ";
        cin >> marks[i];
    }
    // Displaying marks
    for(int j=0; j<5; j++){
        cout << "Marks of " << j << " student is : " << marks[j];
        cout << endl;
    }
}