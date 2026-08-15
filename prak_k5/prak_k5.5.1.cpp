#include <iostream>
// ====================
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
// ====================
using namespace std;

// ======================================================
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

// int linSearch(int Fnd, int Arr[], int Size)
// {
//     while (Size >= 0 && Fnd != Arr[--Size])
//         ;
//     return Size;
// }

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

struct Login
{
    int ID;
    Date tglLogin;
    Time waktuLogin;
};

int main()
{
    int X;
    bool data = false;
    Login user[3];

    user[0].ID = 1;
    user[0].tglLogin.dd = 1;
    user[0].tglLogin.mm = 1;
    user[0].tglLogin.yyyy = 1;
    user[0].waktuLogin.h = 1;
    user[0].waktuLogin.m = 1;
    user[0].waktuLogin.s = 1;

    user[1].ID = 2;
    user[1].tglLogin.dd = 2;
    user[1].tglLogin.mm = 2;
    user[1].tglLogin.yyyy = 2;
    user[1].waktuLogin.h = 2;
    user[1].waktuLogin.m = 2;
    user[1].waktuLogin.s = 2;

    int sz = sizeof(user) / sizeof(user[0]);

    bool Loop = true;
    while (Loop)
    {
        cout << "Masukan nilai X : ";
        cin >> X;

        // for (int N = 0; N < sz; N++)
        // {
        //     if (!cin)
        //     {
        //         Loop = false;
        //     }
        //     else
        //     {
        //         if (user[N].ID == X)
        //         {
        //             cout << "Login ID : " << user[N].ID << endl;
        //             cout << "Login Date : " << user[N].tglLogin.dd << " - " << user[N].tglLogin.mm << " - " << user[N].tglLogin.yyyy << endl;
        //             cout << "Login Time : " << user[N].waktuLogin.h << ":" << user[N].waktuLogin.m << ":" << user[N].waktuLogin.s << endl
        //                  << endl;
        //         }
        //     }
        // }

        // while (cin)
        // {
        //     if (user[N].ID == X)
        //         {
        //             cout << "Login ID : " << user[N].ID << endl;
        //             cout << "Login Date : " << user[N].tglLogin.dd << " - " << user[N].tglLogin.mm << " - " << user[N].tglLogin.yyyy << endl;
        //             cout << "Login Time : " << user[N].waktuLogin.h << ":" << user[N].waktuLogin.m << ":" << user[N].waktuLogin.s << endl
        //                  << endl;
        //         }
        //         else
        //         {
        //             cout << "Tidak ada" << endl;
        //         }
        // }

        if (!cin)
        {
            Loop = false;
        }
        else
        {
            for (int N = 0; N < sz; N++)
            {
                if (user[N].ID == X)
                {

                    cout << "Login ID : " << user[N].ID << endl;
                    cout << "Login Date : " << user[N].tglLogin.dd << " - " << user[N].tglLogin.mm << " - " << user[N].tglLogin.yyyy << endl;
                    cout << "Login Time : " << user[N].waktuLogin.h << ":" << user[N].waktuLogin.m << ":" << user[N].waktuLogin.s << endl
                         << endl;
                    data = true;
                    break;
                }
                else if (user[N].ID != X)
                {
                    data = false;
                }
            }
            if (data == false)
            {
                cout << "Tidak ada" << endl;
            }
        }
    }
    getch();
}