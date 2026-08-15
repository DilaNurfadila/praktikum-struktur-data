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
    Login user1;

    // Mengisi dan menampilkan value dari struct
    cout << "USER 1\n";
    cout << "ID : ";
    cin >> user1.ID;
    cout << "Tanggal Login\n";
    cout << "Hari : ";
    cin >> user1.tglLogin.dd;
    cout << "Bulan : ";
    cin >> user1.tglLogin.mm;
    cout << "Tahun : ";
    cin >> user1.tglLogin.yyyy;
    cout << "Waktu Login\n";
    cout << "Jam : ";
    cin >> user1.waktuLogin.h;
    cout << "Menit : ";
    cin >> user1.waktuLogin.m;
    cout << "Detik : ";
    cin >> user1.waktuLogin.s;
    cout << "\nTerima kasih\n";
    cout << "Data Anda : \n";
    cout << "ID : " << user1.ID << endl;
    cout << "Date : " << user1.tglLogin.dd << " - " << user1.tglLogin.mm << " - " << user1.tglLogin.yyyy << endl;
    cout << "Time : " << user1.waktuLogin.h << ":" << user1.waktuLogin.m << ":" << user1.waktuLogin.s << endl;

    getch();
}