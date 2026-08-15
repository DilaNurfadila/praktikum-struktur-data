// Prak K2.1
// #include <iostream>
// using namespace std;
// int main() {
//     int a = 5;

//     cout << a << endl;
//     printf("%u\n", &a);
// }

// Prak K2.2
// #include <iostream>
// using namespace std;
// int main() {
//     int *p;
//     int a = 5;
//     p = &a;
//     cout << a << endl;
//     printf("%u\n", p);
// }

// Prak K2.3
// #include <iostream>
// using namespace std;
// int main() {
//     int *p;
//     int a = 5;
//     p = &a;
//     printf("%d\n", *p);
//     *p = *p + 1;
//     printf("%d\n", *p);
//     cout << a << endl;
//     // Mirip seperti a += 1, bedanya menggunakan pointer mengubah langsung di alamatnya bukan ditimpa seperti a += 1
// }

// Prak K2.4
// #include <iostream>
// using namespace std;
// int main() {
//     int *p;
//     int a = 5;
//     p = &a;

//     printf("%d\n", *p);
//     *p = *p + 1;
//     *p += 3;
//     printf("%d\n", *p);
//     printf("%d\n", a);
//     // value a ditambah terlebih dahulu dengan 1 yang mana hasilnya menjadi 6, kemudian di baris selanjutnya ditambah 3 dan hasilnya menjadi 9
// }

// Prak K2.5
// #include <iostream>
// using namespace std;
// void swap(int x, int y) {
//     int z;
//     z = x;
//     x = y;
//     y = z;
//     cout << "Swapped value a is: = " << x << endl;
//     cout << "Swapped value b is: = " << y << endl;
//     cout << "_____________________________" << endl;
// }
// int main() {
//     int a = 7, b = 4;

//     cout << "Original value a is: " << a << endl;
//     cout << "Original value b is: " << b << endl;
//     cout << "_____________________________" << endl;
//     swap(a,b);
//     cout << "The value of a after swapped is: " << a << endl;
//     cout << "The value of b after swapped is: " << b << endl;
// }

// Prak K2.6
// #include <iostream>
// using namespace std;
// void swap(int *x, int *y) {
//     int z;
//     z = *x;
//     *x = *y;
//     *y = z;
//     cout << "Swapped value a is: = " << *x << endl;
//     cout << "Swapped value b is: = " << *y << endl;
//     cout << "_____________________________" << endl;
// }
// int main() {
//     int a = 7, b = 4;

//     cout << "Original value a is: " << a << endl;
//     cout << "Original value b is: " << b << endl;
//     cout << "_____________________________" << endl;
//     swap(&a, &b);
//     cout << "The value of a after swapped is: " << a << endl;
//     cout << "The value of b after swapped is: " << b << endl;
// }