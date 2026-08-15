#include <iostream>
#define Max 10
using namespace std;

int DataQue[Max];
int head = 0, tail = 0;
int isiCirQ = 0;

void EnQue(int Data)
{
    if (isiCirQ == Max)
        cout << "Antrian penuh" << endl;
    else
    {
        DataQue[tail++] = Data;
        isiCirQ++;
        tail++;
        if (tail == Max)
            tail = 0;
    }
}

int DeQue()
{
    int Out;
    if (isiCirQ)
    {
        Out = DataQue[head];
        isiCirQ--;
        head++;
        if (head == Max)
            head = 0;
        return Out;
    }
    else
    {
        cout << "Antrian kosong" << endl;
    }
    return 0;
}
int main()
{
    int pil, data;
    while (true)
    {
        cout << "1. Enqueue\n2. Dequeue\n3. Exit\nEnter your choice : ";
        cin >> pil;

        switch (pil)
        {
        case 1:
            cout << "Enter data to enqueue : ";
            cin >> data;
            EnQue(data);
            break;
        case 2:
            data = DeQue();
            if (data != 0)
            {
                cout << "Data dequeued : " << data << endl;
            }
            break;
        case 3:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
        }
    }

    for (int i = head; i < tail; i++)
    {
        cout << DataQue[i] << " ";
    }
    cout << endl;

    int Out = DeQue();
    cout << "Data yang diambil dari antrian : " << Out << endl;
    cout << endl
         << endl;

    for (int i = head; i < tail; i++)
    {
        cout << DataQue[i] << " ";
    }
    cout << endl;
}