#include <iostream>
#define Max 5
using namespace std;

int DataQue[Max];
int head = 0, tail = 0;

void EnQue(int Data)
{
    if (tail < Max)
    {
        DataQue[tail++] = Data;
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
    if (head < tail)
    {
        int data = DataQue[head++];
        cout << "Data " << data << " berhasil diambil dari antrian" << endl;
        return data;
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

    int data1 = DeQue();
    int data2 = DeQue();
    cout << endl
         << endl;

    EnQue(40);
    EnQue(50);
    EnQue(60);
    cout << endl
         << endl;

    int data3 = DeQue();
    int data4 = DeQue();
    int data5 = DeQue();
    int data6 = DeQue();
    int data7 = DeQue();
}