#include <iostream>
#include <iomanip>
// ====================
#include <termios.h> // header untuk mendefinisikan terminal I/O
#include <unistd.h>  // header untuk mendefinisikan konstanta dan tipe simbolik standar
// ====================

// Baris ini digunakan supaya kita tidak perlu menuliskan berulang kata std di setiap perintah I/O
using namespace std;

// ======================================================
/* reads from keypress, doesn't echo */
// Karena di linux tidak ada header <conio.h>, maka diganti dengan baris perintah berikut untuk menggunakan fungsi _getch() pada header <conio.h>
// Fungsi getch digunakan untuk membaca input satu karakter tanpa menekan tombol enter
int getch(void)
{
    struct termios oldattr, newattr;   // deklarasi 2 variable dengan tipe termios
    int ch;                            // deklarasi untuk membaca karakter
    tcgetattr(STDIN_FILENO, &oldattr); // mengambil atribut dari terminal yang kemudian disimpan ke address oldattr
    newattr = oldattr;                 // pengaturan terminal yang lama disalin ke variable newattr

    newattr.c_lflag &= ~(ICANON | ECHO); // mematikan mode canonical dan mode echo
    /* ICANON merupakan parameter yang menentukan apakah inputan dari user harus disimpan dalam buffer atau tidak.

    ECHO merupakan parameter yang menentukan apakah inputan dari user akan ditampilkan di layar atau tidak */

    tcsetattr(STDIN_FILENO, TCSANOW, &newattr); // menerapkan perubahan pengaturan terminal
    ch = getchar();                             // membaca inputan satu karakter yang kemudian disimpan dalam variable ch
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr); // mengembalikan terminal ke pengaturan awal
    return ch;                                  // return nilai ch ke fungsi getch
}

// Karena di linux tidak ada perintah pause, maka digantikan dengan perintah read pada bash scripting
int pause(void)
{
    /* Perintah read digunakan untuk membaca sebuah FD (File Descriptor)
    Parameter -p digunakan untuk menampilkan pesan yang diikuti isi pesan yang ingin ditampilkan
    Perintah \e digunakan untuk escape */
    system("read -p 'Press any key to continue...' \e");
    return 0;
}
// ======================================================

struct Simpul
{
    int Info;
    Simpul *Next;
    Simpul *Prev;
};

Simpul *AwalList;
Simpul *AkhirList;

void InsertEmpty(Simpul *Newcell)
{
    AwalList = Newcell;
    AkhirList = Newcell;
}

void InsertFirst() /* Insert diawal*/
{
    int data;
    cout << endl
         << "Input data yang akan disimpan : ";
    cin >> data;

    Simpul *newcell;
    newcell = (Simpul *)malloc(sizeof(Simpul));
    newcell->Info = data;
    newcell->Next = NULL;
    newcell->Prev = NULL;

    if (AwalList == NULL)
        InsertEmpty(newcell);
    else
    {
        AwalList->Prev = newcell;
        newcell->Next = AwalList;
        AwalList = newcell;
    }
}

void InsertLast() /* Insert di akhir */
{
    int data;
    cout << endl
         << "Input data yang akan disimpan : ";
    cin >> data;

    Simpul *Newcell;
    Newcell = (Simpul *)malloc(sizeof(Simpul));

    Newcell->Info = data;
    Newcell->Next = NULL;

    if (AwalList == NULL)
        InsertEmpty(Newcell);
    else
    {
        Simpul *p;
        for (p = AwalList; p->Next != NULL; p = p->Next)
            ;
        p->Next = Newcell;
        Newcell->Prev = p;
        AkhirList = Newcell;
    }
}

void InsertAfter()
{
    if (AwalList == NULL)
        cout << "List masih kosong";
    else
    {
        int FindData;
        cout << endl
             << endl
             << "Input data yang dicari : ";
        cin >> FindData;

        Simpul *p;
        for (p = AwalList; p != NULL && p->Info != FindData; p = p->Next)
            ;

        if (p == NULL)
            cout << "Tidak bisa insert, yang dicari tidak ada";
        else if (p->Next == NULL)
            InsertLast();
        else
        {
            int InsertData;
            cout << "Input data yang akan di Insert : ";
            cin >> InsertData;

            Simpul *Newcell;
            Newcell = (Simpul *)malloc(sizeof(Simpul));

            Newcell->Info = InsertData;
            Newcell->Next = NULL;
            Newcell->Prev = NULL;

            Newcell->Prev = p;
            Newcell->Next = p->Next;
            p->Next->Prev = Newcell;
            p->Next = Newcell;
        }
    }
}

void InsertBefore()
{
    if (AwalList == NULL)
        cout << "List masih kosong";
    else
    {
        int FindData;
        cout << endl
             << endl
             << "Input data yang dicari : ";
        cin >> FindData;

        Simpul *p;
        for (p = AwalList; p != NULL && p->Info != FindData; p = p->Next)
            ;

        if (p == NULL)
            cout << "Tidak bisa insert, yang dicari tidak ada";
        else if (p->Prev == NULL)
            InsertFirst();
        else
        {
            int InsertData;
            cout << "Input data yang akan di Insert : ";
            cin >> InsertData;

            Simpul *Newcell;
            Newcell = (Simpul *)malloc(sizeof(Simpul));

            Newcell->Info = InsertData;
            Newcell->Next = NULL;
            Newcell->Prev = NULL;

            Newcell->Next = p;
            Newcell->Prev = p->Prev;
            p->Prev->Next = Newcell;
            p->Prev = Newcell;
        }
    }
}

// void InsertBefore()
// {
//     int data;
//     cout << endl
//          << "Input data yang akan dimasukan :";
//     cin >> data;

//     if (AkhirList == NULL)
//     {
//         printf("Block Akhir tidak boleh kosong");
//         return;
//     }
//     Simpul *newcell;
//     newcell = (Simpul *)malloc(sizeof(Simpul));
//     newcell->Info = data;
//     newcell->Prev = AkhirList->Prev;

//     newcell->Prev = newcell;

//     newcell->Next = AkhirList;

//     if (newcell->Prev != NULL)
//         newcell->Prev->Next = newcell;
//     else
//         AwalList = newcell;
// }

// void DispForward()
// {
//     if (AwalList == NULL)
//         cout << "List masih kosong..";
//     else
//     {
//         Simpul *p;
//         for (p = AwalList; p != NULL; p = p->Next)
//             cout << p->Info << " ";
//     }
// }

// void DispBackward()
// {
//     if (AhirList == NULL)
//         cout << "List masih kosong..";
//     else
//     {
//         Simpul *p;
//         for (p = AhirList; p != NULL; p = p->Prev)
//             cout << p->Info << " ";
//     }
// }

void DispForward()
{
    Simpul *temp = AwalList;
    while (temp != NULL)
    {
        cout << temp->Info << " --> ";
        temp = temp->Next;
    }
    cout << "NULL" << endl;
}

void DispBackward()
{
    Simpul *temp = AkhirList;
    while (temp != NULL)
    {
        cout << temp->Info << " --> ";
        temp = temp->Prev;
    }
    cout << "NULL" << endl;
}

Simpul *searchData()
{
    int FindData;
    cout << endl
         << "Input data yang dicari : ";
    cin >> FindData;

    Simpul *p;
    for (p = AwalList; p != NULL && p->Info != FindData; p = p->Next)
        ;

    return p;
}
void DeleteLast()
{
    Simpul *p = AkhirList;
    AkhirList->Prev->Next = NULL;
    AkhirList = AkhirList->Prev;
    delete p;
}

void DeleteFirst()
{
    Simpul *p = AwalList;
    AwalList->Next->Prev = NULL;
    AwalList = AwalList->Next;
    delete p;
}

void DeletePost()
{
    if (AwalList == NULL)
        cout << "list masih kosong";
    else
    {
        Simpul *p = searchData();
        if (p == NULL)
            cout << "Data tidak ada atau sudah ujung";
        else
        {
            if (p->Next == NULL)
                DeleteLast();
            else if (p->Prev == NULL)
                DeleteFirst();
            else
            {
                p->Prev->Next = p->Next;
                p->Next->Prev = p->Prev;
                delete p;
            }
        }
    }
}

void EditData()
{
    Simpul *p = searchData();
    if (p != NULL)
    {
        int NewData;
        cout << "Input data baru : ";
        cin >> NewData;
        p->Info = NewData;
        cout << "Data sudah diubah";
    }
}

int main()
{
    AwalList = NULL;
    AkhirList = NULL;
    bool loop = true;

    do
    {
        system("clear");
        cout << endl;
        cout << "====================================" << endl;
        cout << "|          PRAKTIKUM LIST          |" << endl;
        cout << "====================================" << endl;
        cout << "esc. Exit" << endl;
        cout << "1.Insert First" << endl;
        cout << "2.Insert Last" << endl;
        cout << "3.Insert After" << endl;
        cout << "4.Insert Before" << endl;
        cout << "5.Display Forward" << endl;
        cout << "6.Display Backward" << endl;
        cout << "7.Search Data" << endl;
        cout << "8.Delete Post" << endl;
        cout << "9.Edit Data" << endl
             << endl;
        cout << "Masukan Pilih : " << endl;

        switch (getch())
        {
        case 27:
        {
            loop = false;
            cout << "next..by";
            break;
        }
        case '1':
        {
            InsertFirst();
            break;
        }
        case '2':
        {
            InsertLast();
            break;
        }
        case '3':
        {
            InsertAfter();
            break;
        }
        case '4':
        {
            InsertBefore();
            break;
        }
        case '5':
        {
            cout << endl
                 << "Isi list maju : ";
            DispForward();
            break;
        }
        case '6':
        {
            cout << endl
                 << "Isi list mundur : ";
            DispBackward();
            break;
        }
        case '7':
        {
            if (searchData() == NULL)
                cout << "Data tidak ada";
            else
                cout << "Data ditemukan";
            break;
        }
        case '8':
        {
            DeletePost();
            break;
        }
        case '9':
        {
            EditData();
            break;
        }
        break;
        }
        cout << endl;
        pause();
    } while (loop);
    return 0;
}