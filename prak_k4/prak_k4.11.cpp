#include <iostream>
#define Max 10
using namespace std;

int DataQue[Max];
int pertama = 0, terakhir = 0;

void EnQue(int Data)
{
    if (terakhir < Max)
    {
        DataQue[terakhir++] = Data;
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
        Out = DataQue[pertama];
        for (int i = 0; i < terakhir - 1; i++)
        {
            DataQue[i] = DataQue[i + 1];
        }
        terakhir--;
        return Out;
    }
    else
    {
        cout << "Antrian kosong" << endl;
    }
}
int main()
{
    EnQue(10);
    EnQue(20);
    EnQue(30);
    EnQue(40);

    for (int i = pertama; i < terakhir; i++)
    {
        cout << DataQue[i] << " ";
    }
    cout << endl;

    int Out = DeQue();
    cout << "Data yang diambil dari antrian : " << Out << endl;
    cout << endl
         << endl;

    for (int i = pertama; i < terakhir; i++)
    {
        cout << DataQue[i] << " ";
    }
    cout << endl;
}