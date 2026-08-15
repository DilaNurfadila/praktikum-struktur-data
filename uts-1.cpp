#include <iostream> // header yang mendefinisikan input dan output
// ====================
#include <termios.h>
#include <unistd.h>
// ====================

// Membuat variable global
#define JMHS 30
#define JMTK 4
#define JNIL 2

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
// Array of object
MHS student1 = {"Rohman", 1};
MHS student2 = {"Renata", 1};
MHS student3 = {"Aditya", 1};
MHS Mhs[JMHS] = {student1, student2, student3};
MHS NilMtkMhs[JMHS];

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
    Mhs[JmlMhs].NAMA = nama;
    Mhs[JmlMhs].TAG = 1;
    JmlMhs++;
}

int SrcMhs(int JumMhs, bool flag)
{
    string Nma;
    cout << endl
         << "Nama : ";
    fflush(stdin); // fflush
    getline(cin, Nma);

    while (JumMhs >= 0 && Mhs[--JumMhs].NAMA != Nma)
        ; // Selama belum ditemukan
    if (Mhs[JumMhs].TAG == flag)
        return JumMhs; // Decriment index
    else
        return -1;
}

// Menentukan nilai akhir
string NilAkhir(int akhir)
{
    if (akhir >= 85 && akhir <= 100)
    {
        return "A";
    }
    else if (akhir >= 70 && akhir < 85)
    {
        return "B";
    }
    else if (akhir >= 55 && akhir < 70)
    {
        return "C";
    }
    else if (akhir >= 40 && akhir < 55)
    {
        return "D";
    }
    else if (akhir < 40)
    {
        return "E";
    }
}

// List nilai mahasiswa
void ListNilaiMhs(int i)
{
    int NilAkhirSTD = (NilMtkMhs[i].NilMTK.STD.UTS + NilMtkMhs[i].NilMTK.STD.UAS) / 2;
    int NilAkhirALG = (NilMtkMhs[i].NilMTK.ALG.UTS + NilMtkMhs[i].NilMTK.ALG.UAS) / 2;
    int NilAkhirPBO = (NilMtkMhs[i].NilMTK.PBO.UTS + NilMtkMhs[i].NilMTK.PBO.UAS) / 2;
    int NilAkhirWEB = (NilMtkMhs[i].NilMTK.WEB.UTS + NilMtkMhs[i].NilMTK.WEB.UAS) / 2;

    cout << endl
         << "STD, UTS : " << NilMtkMhs[i].NilMTK.STD.UTS;
    cout << endl
         << "STD, UAS : " << NilMtkMhs[i].NilMTK.STD.UAS << endl;
    cout << "STD, AKHIR : " << NilAkhir(NilAkhirSTD); // menghitung nilai akhir dari rata-rata UTS dan UAS
    cout << endl
         << endl
         << "ALG, UTS : " << NilMtkMhs[i].NilMTK.ALG.UTS;
    cout << endl
         << "ALG, UAS : " << NilMtkMhs[i].NilMTK.ALG.UAS << endl;
    cout << "ALG, AKHIR : " << NilAkhir(NilAkhirALG);
    cout << endl
         << endl
         << "PBO, UTS : " << NilMtkMhs[i].NilMTK.PBO.UTS;
    cout << endl
         << "PBO, UAS : " << NilMtkMhs[i].NilMTK.PBO.UAS << endl;
    cout << "PBO, AKHIR : " << NilAkhir(NilAkhirPBO);
    cout << endl
         << endl
         << "WEB, UTS : " << NilMtkMhs[i].NilMTK.WEB.UTS;
    cout << endl
         << "WEB, UAS : " << NilMtkMhs[i].NilMTK.WEB.UAS << endl;
    cout << "WEB, AKHIR : " << NilAkhir(NilAkhirWEB);
    cout << endl;
}

// Ubah nilai
void UpdNilaiMhs(int MhsKe)
{
    string stdUts, stdUas, algUts, algUas, pboUts, pboUas, webUts, webUas;

    cout << endl
         << "Just leave blank if no change.." << endl;

    for (int M = 0; M < JMTK; M++)
    {
        for (int N = 0; N < JNIL; N++)
        {
            if (M == 0 && N == 0)
            {
                cout << "Ubah STD, UTS : " << NilMtkMhs[MhsKe].NilMTK.STD.UTS << " ..menjadi : ";
                fflush(stdin);
                getline(cin, stdUts);
            }
            else if (M == 0 && N == 1)
            {
                cout << "Ubah STD, UAS : " << NilMtkMhs[MhsKe].NilMTK.STD.UAS << " ..menjadi : ";
                fflush(stdin);
                getline(cin, stdUas);
            }
            else if (M == 1 && N == 0)
            {
                cout << "Ubah ALG, UTS : " << NilMtkMhs[MhsKe].NilMTK.ALG.UTS << " ..menjadi : ";
                fflush(stdin);
                getline(cin, algUts);
            }
            else if (M == 1 && N == 1)
            {
                cout << "Ubah ALG, UAS : " << NilMtkMhs[MhsKe].NilMTK.ALG.UAS << " ..menjadi : ";
                fflush(stdin);
                getline(cin, algUas);
            }
            else if (M == 2 && N == 0)
            {
                cout << "Ubah PBO, UTS : " << NilMtkMhs[MhsKe].NilMTK.PBO.UTS << " ..menjadi : ";
                fflush(stdin);
                getline(cin, pboUts);
            }
            else if (M == 2 && N == 1)
            {
                cout << "Ubah PBO, UAS : " << NilMtkMhs[MhsKe].NilMTK.PBO.UAS << " ..menjadi : ";
                fflush(stdin);
                getline(cin, pboUas);
            }
            else if (M == 3 && N == 0)
            {
                cout << "Ubah WEB, UTS : " << NilMtkMhs[MhsKe].NilMTK.WEB.UTS << " ..menjadi : ";
                fflush(stdin);
                getline(cin, webUts);
            }
            else if (M == 3 && N == 1)
            {
                cout << "Ubah WEB, UAS : " << NilMtkMhs[MhsKe].NilMTK.WEB.UAS << " ..menjadi : ";
                fflush(stdin);
                getline(cin, webUas);
            }
        }

        // Jika nilai tidak kosong dan nilai lebih dari 0 dan nilai kurang dari sama dengan 100 maka nilai tetap yang sebelumnya
        if (!stdUts.empty() && stoi(stdUts) > 0 && stoi(stdUts) <= 100)
        {
            NilMtkMhs[MhsKe].NilMTK.STD.UTS = stoi(stdUts);
        }

        if (!stdUas.empty() && stoi(stdUas) > 0 && stoi(stdUas) <= 100)
        {
            NilMtkMhs[MhsKe].NilMTK.STD.UAS = stoi(stdUas);
        }

        if (!algUts.empty() && stoi(algUts) > 0 && stoi(algUts) <= 100)
        {
            NilMtkMhs[MhsKe].NilMTK.ALG.UTS = stoi(algUts);
        }

        if (!algUas.empty() && stoi(algUas) > 0 && stoi(algUas) <= 100)
        {
            NilMtkMhs[MhsKe].NilMTK.ALG.UAS = stoi(algUas);
        }

        if (!pboUts.empty() && stoi(pboUts) > 0 && stoi(pboUts) <= 100)
        {
            NilMtkMhs[MhsKe].NilMTK.PBO.UTS = stoi(pboUts);
        }

        if (!pboUas.empty() && stoi(pboUas) > 0 && stoi(pboUas) <= 100)
        {
            NilMtkMhs[MhsKe].NilMTK.PBO.UAS = stoi(pboUas);
        }

        if (!webUts.empty() && stoi(webUts) > 0 && stoi(webUts) <= 100)
        {
            NilMtkMhs[MhsKe].NilMTK.WEB.UTS = stoi(webUts);
        }

        if (!webUas.empty() && stoi(webUas) > 0 && stoi(webUas) <= 100)
        {
            NilMtkMhs[MhsKe].NilMTK.WEB.UAS = stoi(webUas);
        }
    }
}

int main()
{
    char Pilih;

    // Nilai dari setiap matkul mahasiswa
    NilMtkMhs[0].NilMTK.STD.UTS = 50;
    NilMtkMhs[0].NilMTK.STD.UAS = 69;
    NilMtkMhs[0].NilMTK.ALG.UTS = 30;
    NilMtkMhs[0].NilMTK.ALG.UAS = 67;
    NilMtkMhs[0].NilMTK.PBO.UTS = 76;
    NilMtkMhs[0].NilMTK.PBO.UAS = 67;
    NilMtkMhs[0].NilMTK.WEB.UTS = 90;
    NilMtkMhs[0].NilMTK.WEB.UAS = 45;

    NilMtkMhs[1].NilMTK.STD.UTS = 67;
    NilMtkMhs[1].NilMTK.STD.UAS = 59;
    NilMtkMhs[1].NilMTK.ALG.UTS = 30;
    NilMtkMhs[1].NilMTK.ALG.UAS = 70;
    NilMtkMhs[1].NilMTK.PBO.UTS = 55;
    NilMtkMhs[1].NilMTK.PBO.UAS = 75;
    NilMtkMhs[1].NilMTK.WEB.UTS = 66;
    NilMtkMhs[1].NilMTK.WEB.UAS = 80;

    NilMtkMhs[2].NilMTK.STD.UTS = 65;
    NilMtkMhs[2].NilMTK.STD.UAS = 70;
    NilMtkMhs[2].NilMTK.ALG.UTS = 40;
    NilMtkMhs[2].NilMTK.ALG.UAS = 50;
    NilMtkMhs[2].NilMTK.PBO.UTS = 80;
    NilMtkMhs[2].NilMTK.PBO.UAS = 80;
    NilMtkMhs[2].NilMTK.WEB.UTS = 70;
    NilMtkMhs[2].NilMTK.WEB.UAS = 70;

    bool loop = true;

    do
    {                    // display menu
        system("clear"); // Membersihkan atau menghapus tampilan dari terminal
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
        Pilih = getch(); // input tanpa buffer, artinya kita tidak perlu menekan enter setelah memilih menu
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
            cout << Mhs[JmlMhs - 1].NAMA << ".. Added" << endl;
            pause();
            break;
        }

        case '3':
        {
            int X = SrcMhs(JmlMhs, 1);
            if (X >= 0)
            {
                cout << "Ubah Nama : " << Mhs[X].NAMA << " ..menjadi : ";
                fflush(stdin);
                getline(cin, Mhs[X].NAMA);
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
            int X = SrcMhs(JmlMhs, 1);
            if (X == -1)
                cout << " Tdk Ada.. " << endl;
            else
            {
                cout << "Delete Nama : " << Mhs[X].NAMA << " y/n : ";
                if (getch() == 'y')
                {
                    Mhs[X].TAG = 0;
                    cout << endl
                         << Mhs[X].NAMA << " ..Deleted.." << endl;
                }
            }
            pause();
            break;
        }

        case '5':
        {
            cout << "Deleted" << endl;
            cout << "==========" << endl;
            LstMhs(0);
            pause();
            break;
        }

        case '6':
        {
            cout << "UnDelete MHS" << endl;
            int X = SrcMhs(JmlMhs, 0);
            if (X == -1)
                cout << " Tdk Ada.. " << endl;
            else
            {
                cout << "UnDelete Nama : " << Mhs[X].NAMA << " y/n : ";
                if (getch() == 'y')
                {
                    Mhs[X].TAG = 1;
                    cout << endl
                         << Mhs[X].NAMA << " ..UnDeleted.." << endl;
                }
            }
            pause();
            break;
        }

        case '7':
        {
            cout << "Lihat Nilai MHS" << endl;
            int X = SrcMhs(JmlMhs, 1);
            if (X >= 0)
            {
                cout << "Nilai MTK : " << Mhs[X].NAMA;
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
            int X = SrcMhs(JmlMhs, 1);
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