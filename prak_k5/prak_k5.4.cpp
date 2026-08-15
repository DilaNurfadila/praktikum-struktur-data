#include <iostream>
// ====================
// Header untuk membuat fungsi getch
#include <termios.h>
#include <unistd.h>
// ====================
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

// Membuat struct
struct Date
{
    int dd;
    int mm;
    int yyyy;
};

struct Time
{
    int h;
    int m;
    int s;
};

// Membuat nested struct (struct di dalam struct)
struct Login
{
    int ID;
    Date tglLogin;
    Time waktuLogin;
};

int main()
{
    Login user[3]; // Membuat beberapa user dengan array

    // Mengisi dan menampilkan value dari struct sebanyak 3 user
    for (int i = 0; i < 3; i++)
    {
        cout << "USER ke-" << i + 1 << endl;
        cout << "ID : ";
        cin >> user[i].ID;
        cout << "Tanggal Login\n";
        cout << "Hari : ";
        cin >> user[i].tglLogin.dd;
        cout << "Bulan : ";
        cin >> user[i].tglLogin.mm;
        cout << "Tahun : ";
        cin >> user[i].tglLogin.yyyy;
        cout << "Waktu Login\n";
        cout << "Jam : ";
        cin >> user[i].waktuLogin.h;
        cout << "Menit : ";
        cin >> user[i].waktuLogin.m;
        cout << "Detik : ";
        cin >> user[i].waktuLogin.s;
        cout << "\nTerima kasih Atas Pengisiannya\n";
        cout << "Data User ke-" << i + 1 << endl;
        cout << "Login ID : " << user[i].ID << endl;
        cout << "Login Date : " << user[i].tglLogin.dd << " - " << user[i].tglLogin.mm << " - " << user[i].tglLogin.yyyy << endl;
        cout << "Login Time : " << user[i].waktuLogin.h << ":" << user[i].waktuLogin.m << ":" << user[i].waktuLogin.s << endl
             << endl;
    }
    getch();
}