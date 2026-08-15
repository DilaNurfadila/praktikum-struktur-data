#include <iostream>
using namespace std;

const int MAX = 5;
int DataQue[MAX];
int pertama = 0, terakhir = 0;

void EnQue(int Data)
{
    if (terakhir < MAX)
    {
        DataQue[terakhir++] = Data;
        cout << "Data " << Data << " telah ditambahkan ke antrian" << endl;
    }
    else
    {
        cout << "Antrian penuh" << endl;
    }
}

int DeQue()
{
    int Out;
    if (pertama < terakhir)
    {
        Out = DataQue[pertama++];
        if (pertama == terakhir)
        {
            pertama = terakhir = 0;
        }
        cout << "Data " << Out << " telah dihapus dari antrian" << endl;
    }
    else
    {
        cout << "Antrian kosong" << endl;
        return -1;
    }
}
int main()
{
    EnQue(10);
    EnQue(20);
    EnQue(30);
    cout << endl
         << endl;

    DeQue();
    DeQue();
    DeQue();
    DeQue();
    cout << endl
         << endl;

    EnQue(40);
    EnQue(50);
    EnQue(60);
    cout << endl
         << endl;

    DeQue();
    DeQue();
    DeQue();
    DeQue();
}