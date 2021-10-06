// Kuzminalab11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
struct Pipe
{
    int id;
    int d; 
    int l;
    bool r;
 
};

struct CS
{
    int id;
    string name;
    int col_cex; // ���������� �����
    int col_work; // ���������� � ������ 
    double effic; // �������������
};


void PrintePipe(Pipe& p)
{
    cout << " Pipe ID number: " << p.id << "  Diameter: " << p.d << " mm " << " Lenght: " << p.l << " km \n" ;
    cout << " Pipe under repair: " << p.r <<endl;
}
void PrinteCS(CS& station)
{
    cout << " CS ID number: " << station.id << " Name: " << station.name << " Number of shops: " << station.col_cex << " Work: " << station.col_work;
}
Pipe AddPipe()
{
    Pipe p;
    p.id = 0;
    cout << "Enter the diameter ";
    cin >> p.d;
    while (p.d < 400 || p.d > 2000)
    {
        cout << "������� ����� �� ���������� [400;2000] mm ";
        cin >> p.d;
    }
    cout << "Enter the lenght ";
    cin >> p.l;
    while (p.l < 10 || p.l > 100)
    {
        cout << "������� ����� �� ���������� [10;100] km ";
        cin >> p.l; 
    }
    p.r = 0;
   // cout << "Is the pipe repaired?";
   // cin >> p.r;
    return p;
}
CS AddCS()
{
    CS station;
    station.id = 0;
    cout << "Enter the name ";
    cin >> station.name;
    cout << "How many shops are there? ";                  // ������� ����� � �������?
    cin >> station.col_cex;
    cout << "How many shops do we have in the job? ";      // ������� ����� � ������?
    cin >> station.col_work;

    while (station.col_work > station.col_cex)
    {
        cout << "���������� ������� ������ ��� ����� �����";
        cin >> station.col_work;
    }
    return station;

}
Pipe editpipe(Pipe& p)                                    //�������� �����
{
    if (p.l > 1) //����������
    {
        cout << "Work 0";                            //�� �������� ������ ����� 1 � 0, �������� �����
        cin >> p.r;
    }
    else cout << "�������� �����";
        return p;
}

CS editcs(CS& station)                                   //�������� ������������� �������
{
    if (station.col_cex > 0)
    {
        cout << "������� ����� � ������ ������?";
        cin >> station.col_cex;
    }
    else cout << "�������� ���";
    return station;

}

int main()
{

    int m; // ������� ����

    Pipe p = {};
    CS station = {};

    for (;;) {
        cout << "\n 1. Exit\n 2. Add pipe\n 3. Add CS\n 4. All objects\n 5. EditPipe\n 6. EditCS\n 7. Save\n 8. Dowland\n";
        cin >> m;
        switch (m)
        {
        case 1:

            return 0;

        case 2:

            system("cls");
            p = AddPipe();
            break;

        case 3:
            system("cls");
            station = AddCS();
            break;

        case 4:

            system("cls");
            PrintePipe(p);
            PrinteCS(station);
            break;

        case 5:
            system("cls");
            editpipe(p);
            break;

        case 6:
            system("cls");
            editcs(station);
            break;

        }

    }

    }




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
