#include <iostream>
#define MAX 10
using namespace std;

int Top = 0, StcArray[MAX];

void Push(int Data)
{
    if (Top < MAX)
    {
        StcArray[Top++] = Data;
        cout << "Data " << Data << " berhasil ditambahkan ke stack" << endl;
    }
    else
    {
        cout << "Stack penuh" << endl;
    }
}

void Pop()
{
    if (Top > 0)
    {
        int data = StcArray[--Top];
        cout << "Data " << data << " berhasil dihapus dari stack" << endl;
    }
    else
    {
        cout << "Stack kosong" << endl;
    }
}
int main()
{
    Push(10);
    Push(20);
    Push(30);
    Pop();
    Pop();
    Pop();
    Pop();
}