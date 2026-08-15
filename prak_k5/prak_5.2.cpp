#include <iostream>
// ====================
// Header untuk membuat fungsi getch
#include <termios.h>
#include <unistd.h>
// ====================
#define phi 3.14
using namespace std;

// ======================================================
// Membuat fungsi getch karena header conio.h tidak support untuk linux
/* reads from keypress, doesn't echo */
int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr(STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
    return ch;
}
// ======================================================

// Langsung dianggap variabel 'lingkaran'
struct
{
    float jari2;
    float keliling;
    float luas;
} lingkaran; // variabel global

// fungsi void untuk menghitung luas lingkaran
void luasLingkaran()
{
    // langsung menggunakan luas lingkaran asli
    lingkaran.luas = lingkaran.jari2 * lingkaran.jari2 * phi;
    cout << "\nLuas lingkaran = " << lingkaran.luas << endl;
}

// fungsi yang mengembalikan nilai float untuuk menghitung keliling lingkaran
float kelLingkaran(float j)
{
    return 2 * phi * lingkaran.jari2;
}

int main()
{
    system("clear"); // Menghapus/membersihkan tulisan dari layar terminal

    cout << "Jari - jari = ";
    cin >> lingkaran.jari2;
    // panggil fungsi luasLingkaran
    luasLingkaran();
    // panggil fungsi keliling, nilai kembalinya dikirim ke keliling lingkaran asli
    lingkaran.keliling = kelLingkaran(lingkaran.jari2);
    // tampilkan keliling lingkaran asli
    cout << "\nKeliling lingkaran = " << lingkaran.keliling << endl;
    getch();
}