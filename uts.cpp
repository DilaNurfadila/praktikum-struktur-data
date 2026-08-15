#include <iostream> // header yang mendefinisikan input dan output
// ====================
#include <termios.h>
#include <unistd.h>
// ====================

// Membuat variable global
#define JMHS 30
#define JMTK 4
#define JNIL 3

// #define NAMA 0
// #define STTS 1

// #define UTS 0
// #define UAS 1
// #define AKHIR 2

// #define STD 0
// #define ALG 1
// #define PBO 2
// #define WEB 3

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
/* reads from keypress, echoes */
// int getche(void)
// {
//     struct termios oldattr, newattr;
//     int ch;
//     tcgetattr(STDIN_FILENO, &oldattr);
//     newattr = oldattr;
//     newattr.c_lflag &= ~(ICANON);
//     tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
//     ch = getchar();
//     tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
//     return ch;
// }

int pause(void)
{
    system("read -p 'Press any key to continue...' \e");
    return 0;
}
// ======================================================

struct Nilai
{
    int UTS;
    int UAS;
};

struct MTK
{
    Nilai STD;
    Nilai ALG;
    Nilai PBO;
    Nilai WEB;
};

struct MHS
{
    string NAMA;
    bool TAG;
    MTK NilMTK;
};
int JmlMhs = 3;
MHS student1 = {"Rohman", 1};
MHS student2 = {"Renata", 1};
MHS student3 = {"Aditya", 1};
MHS Mhs[JMHS] = {student1, student2, student3};
MHS NilMtkMhs;

// List all Mahasiswa
void LstMhs(bool flag)
{
    for (int i = 0; i < JmlMhs; i++)
    {
        if (Mhs[i].TAG == flag)
        {
            cout << Mhs[i].NAMA << endl; // ListNilaiMhs(i)
        }
    }
}

// Append Mahasiswa
void AppMhs()
{
    string nama;
    cout << endl
         << "Tambah MHS.. Nama : ";
    fflush(stdin);
    getline(cin, nama);
    Mhs[JmlMhs][0] = nama;
    Mhs[JmlMhs][1] = "1";

    for (int M = 0; M < JMTK; M++)
    {
        for (int N = 0; N < JNIL; N++)
        {
            NilMtkMhs[JmlMhs][M][N] = "0";
        }
    }
    JmlMhs++;
}

int SrcMhs(int JumMhs, string flag)
{
    string Nma;
    cout << endl
         << "Nama : ";
    fflush(stdin); // fflush
    getline(cin, Nma);

    while (JumMhs >= 0 && Mhs[--JumMhs][0] != Nma)
        ; // Selama belum ditemukan
    if (Mhs[JumMhs][STTS] == flag)
        return JumMhs; // Decriment index
    else
        return -1;
}

string NilAkhir(string akhir)
{
    if (stoi(akhir) >= 85 && stoi(akhir) <= 100)
    {
        return "A";
    }
    else if (stoi(akhir) >= 70 && stoi(akhir) < 85)
    {
        return "B";
    }
    else if (stoi(akhir) >= 55 && stoi(akhir) < 70)
    {
        return "C";
    }
    else if (stoi(akhir) >= 40 && stoi(akhir) < 55)
    {
        return "D";
    }
    else if (stoi(akhir) < 40)
    {
        return "E";
    }
}

void ListNilaiMhs(int i)
{
    NilMtkMhs[i][STD][AKHIR] = to_string((stoi(NilMtkMhs[i][STD][UTS]) + stoi(NilMtkMhs[i][STD][UAS])) / 2);
    NilMtkMhs[i][ALG][AKHIR] = to_string((stoi(NilMtkMhs[i][ALG][UTS]) + stoi(NilMtkMhs[i][ALG][UAS])) / 2);
    NilMtkMhs[i][PBO][AKHIR] = to_string((stoi(NilMtkMhs[i][PBO][UTS]) + stoi(NilMtkMhs[i][PBO][UAS])) / 2);
    NilMtkMhs[i][WEB][AKHIR] = to_string((stoi(NilMtkMhs[i][WEB][UTS]) + stoi(NilMtkMhs[i][WEB][UAS])) / 2);

    cout << endl
         << "STD, UTS : " << NilMtkMhs[i][STD][UTS];
    cout << endl
         << "STD, UAS : " << NilMtkMhs[i][STD][UAS] << endl;
    cout << "STD, AKHIR : " << NilAkhir(NilMtkMhs[i][STD][AKHIR]);
    cout << endl
         << endl
         << "ALG, UTS : " << NilMtkMhs[i][ALG][UTS];
    cout << endl
         << "ALG, UAS : " << NilMtkMhs[i][ALG][UAS] << endl;
    cout << "ALG, AKHIR : " << NilAkhir(NilMtkMhs[i][ALG][AKHIR]);
    cout << endl
         << endl
         << "PBO, UTS : " << NilMtkMhs[i][PBO][UTS];
    cout << endl
         << "PBO, UAS : " << NilMtkMhs[i][PBO][UAS] << endl;
    cout << "PBO, AKHIR : " << NilAkhir(NilMtkMhs[i][PBO][AKHIR]);
    cout << endl
         << endl
         << "WEB, UTS : " << NilMtkMhs[i][WEB][UTS];
    cout << endl
         << "WEB, UAS : " << NilMtkMhs[i][WEB][UAS] << endl;
    cout << "WEB, AKHIR : " << NilAkhir(NilMtkMhs[i][WEB][AKHIR]);
    cout << endl;
}

void UpdNilaiMhs(int MhsKe)
{
    string mtk, uji, nil;

    cout << endl
         << "Just leave blank if no change.." << endl;

    for (int M = 0; M < JMTK; M++)
    {
        for (int N = 0; N < JNIL; N++)
        {
            if (M == 0)
                mtk = "STD";
            if (M == 1)
                mtk = "ALG";
            if (M == 2)
                mtk = "PBO";
            if (M == 3)
                mtk = "WEB";

            if (N == 0)
                uji = "UTS";
            if (N == 1)
                uji = "UAS";

            cout << "Ubah " << mtk << ", " << uji << " : " << NilMtkMhs[MhsKe][M][N] << " ..menjadi : ";
            fflush(stdin);
            getline(cin, nil);

            if (!nil.empty() && stoi(nil) > 0 && stoi(nil) < 100)
                NilMtkMhs[MhsKe][M][N] = nil;
        }
    }
}

int main()
{
    char Pilih;

    NilMtkMhs[0][STD][UTS] = "50";
    NilMtkMhs[0][STD][UAS] = "69";
    NilMtkMhs[0][ALG][UTS] = "30";
    NilMtkMhs[0][ALG][UAS] = "67";
    NilMtkMhs[0][PBO][UTS] = "76";
    NilMtkMhs[0][PBO][UAS] = "67";
    NilMtkMhs[0][WEB][UTS] = "90";
    NilMtkMhs[0][WEB][UAS] = "45";

    NilMtkMhs[1][STD][UTS] = "67";
    NilMtkMhs[1][STD][UAS] = "59";
    NilMtkMhs[1][ALG][UTS] = "30";
    NilMtkMhs[1][ALG][UAS] = "70";
    NilMtkMhs[1][PBO][UTS] = "55";
    NilMtkMhs[1][PBO][UAS] = "75";
    NilMtkMhs[1][WEB][UTS] = "66";
    NilMtkMhs[1][WEB][UAS] = "80";

    NilMtkMhs[2][STD][UTS] = "65";
    NilMtkMhs[2][STD][UAS] = "70";
    NilMtkMhs[2][ALG][UTS] = "40";
    NilMtkMhs[2][ALG][UAS] = "50";
    NilMtkMhs[2][PBO][UTS] = "80";
    NilMtkMhs[2][PBO][UAS] = "80";
    NilMtkMhs[2][WEB][UTS] = "70";
    NilMtkMhs[2][WEB][UAS] = "70";

    bool loop = true;

    do
    { // display menu
        system("clear");
        cout << endl;
        cout << "   Menu" << endl;
        cout << "   ====" << endl;
        cout << "0. Exit" << endl;
        cout << "   Data MHS" << endl;
        cout << "   ====" << endl;
        cout << "1. Lst MHS" << endl;
        cout << "2. Add MHS" << endl;
        cout << "3. Upd MHS" << endl;
        cout << "4. Del MHS" << endl;
        cout << "5. Show Deleted" << endl;
        cout << "6. Undelete" << endl;
        cout << "   Data Nilai MTK MHS" << endl;
        cout << "   ==================" << endl;
        cout << "7. Lihat Nilai MHS" << endl;
        cout << "8. Ubah Nilai MHS" << endl;
        cout << "Pilih : ";
        Pilih = getch();
        system("clear");

        switch (Pilih)
        {
        case '0':
        {
            loop = false;
            break;
        }

        case '1':
        {
            cout << "Daftar MHS" << endl;
            cout << "==========" << endl;
            LstMhs("1");
            pause();
            break;
        }

        case '2':
        {
            AppMhs();
            cout << Mhs[JmlMhs - 1][NAMA] << ".. Added" << endl;
            pause();
            break;
        }

        case '3':
        {
            int X = SrcMhs(JmlMhs, "1");
            if (X >= 0)
            {
                cout << "Ubah Nama : " << Mhs[X][NAMA] << " ..menjadi : ";
                fflush(stdin);
                getline(cin, Mhs[X][NAMA]);
                cout << endl
                     << "Nama Updated.." << endl;
            }
            else
                cout << " Tdk Ada.. " << endl;
            pause();
            break;
        }

        case '4':
        {
            cout << "Delete MHS" << endl;
            int X = SrcMhs(JmlMhs, "1");
            if (X == -1)
                cout << " Tdk Ada.. " << endl;
            else
            {
                cout << "Delete Nama : " << Mhs[X][NAMA] << " y/n : ";
                if (getch() == 'y')
                {
                    Mhs[X][STTS] = "0";
                    cout << endl
                         << Mhs[X][NAMA] << " ..Deleted.." << endl;
                }
            }
            pause();
            break;
        }

        case '5':
        {
            cout << "Deleted" << endl;
            cout << "==========" << endl;
            LstMhs("0");
            pause();
            break;
        }

        case '6':
        {
            cout << "UnDelete MHS" << endl;
            int X = SrcMhs(JmlMhs, "0");
            if (X == -1)
                cout << " Tdk Ada.. " << endl;
            else
            {
                cout << "UnDelete Nama : " << Mhs[X][NAMA] << " y/n : ";
                if (getch() == 'y')
                {
                    Mhs[X][STTS] = "1";
                    cout << endl
                         << Mhs[X][NAMA] << " ..UnDeleted.." << endl;
                }
            }
            pause();
            break;
        }

        case '7':
        {
            cout << "Lihat Nilai MHS" << endl;
            int X = SrcMhs(JmlMhs, "1");
            if (X >= 0)
            {
                cout << "Nilai MTK : " << Mhs[X][NAMA];
                ListNilaiMhs(X);
            }
            else
                cout << " Tdk Ada.. " << endl;
            pause();
            break;
        }

        case '8':
        {
            cout << "Ubah Nilai MHS" << endl;
            int X = SrcMhs(JmlMhs, "1");
            if (X == -1)
                cout << " Tdk Ada.. " << endl;
            else
                UpdNilaiMhs(X);
            pause();
            break;
        }

        default:
            break;
        }
        cout << endl;
    } while (loop);
}