// Kuzminalab11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
using namespace std;
struct Pipe
{
    int id;
    int d; 
    int l;
    bool r;  // ?
 
};

struct CS
{
    int id;
    string name;
    int col_cex;                                                                               // ���������� �����
    int col_work;                                                                              // ���������� � ������ 
    double effic;                                                                              // �������������
};


void PrintePipe(Pipe& p)
{
    cout << " ����� ��� �������: " << p.id << "  �������: " << p.d << " �� " << " �����: " << p.l << " ��\n" ;
    cout << " ����� � �������: " << p.r <<endl;
}

void PrinteCS(CS& station)
{
    cout << " ����� ��: " << station.id << " ���: " << station.name << " ���������� �����: " << station.col_cex << " ���������� ����� � ������: " << station.col_work;
}

Pipe AddPipe()
{
    Pipe p;
    p.id = 0;
    cout << "������� �������: ";
    cin >> p.d; 
    while (p.d < 400 || p.d > 2000)
    {
        cout << "������� ����� �� ���������� [400;2000] mm \n";
        cin >> p.d;
    }
    cout << "������� �����: ";
    cin >> p.l;
    while (p.l < 10 || p.l > 100)
    {
        cout << "������� ����� �� ���������� [10;100] km \n";
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
    cout << "������� ��� �� ";
    cin >> station.name;
    cout << "������� ����� � �������? ";                                                  // ������� ����� � �������?
    cin >> station.col_cex;
    cout << "������� ����� � ������? ";                                                   // ������� ����� � ������?
    cin >> station.col_work;

    while (station.col_work > station.col_cex)
    {
        cout << "���������� ������� ������ ��� ����� �����. ����������, ������� ����� ��������: ";
        cin >> station.col_work;
    }
    return station;

}  
void editpipe(Pipe& p)                                                                  //�������� �����
{
    if (p.l > 1)                                                                        //����������
    {
        cout << "���� ����� � ������ ������� - 0, ���� � ������� - 1 \n";               //�� �������� ������ ����� 1 � 0, �������� �����
        cin >> p.r;
    //  while (p.r != 0 || p.r != 1)
    //  {
    //      cout << "������� 1 ��� 0 ";
    //      cin >> p.r;
    // }
    }
    else cout << "�������� �����";
}

void editcs(CS& station)                                                                 //�������� ������������� �������
{
    if (station.col_cex > 0)
    {
        cout << "������� ����� � ������ ������?";
        cin >> station.col_work;
        while (station.col_work > station.col_cex)                                      //�������� �� ���������� ������� ����� � ���������
        {
            cout << "���������� ������� ������ ��� ����� �����. ����������, ������� ����� ��������: \n";
            cin >> station.col_work;
        }

    }
    else cout << "�������� ���";

}

void Save(Pipe p, CS station)                                                          //���������� � ����
{
    ofstream file;
    file.open("vyvod.txt");
    if (file.good())
    {
        if (p.l > 0)
        {
            file << "Pipe: \n";
            file << p.id << "\n";
            file << p.d << "\n";
            file << p.l << "\n";
            file << p.r << "\n";
        }
        if (station.name != "")
        {
            file << "CS: \n";
            file << station.id << "\n";
            file << station.name << "\n";
            file << station.col_cex << "\n";
            file << station.col_work << "\n";
        }
        file.close();
        cout << "���������\n";
    }

}





int main()
{

    int m;                                                                             // ������� ����

    Pipe p = {};
    CS station = {};

    {
        setlocale(0, "");                                                              //������� ����  
    }

    for (;;) {
        cout << "\n 1. �����\n 2. �������� �����\n 3. �������� ��\n 4. �������� ��� �������\n 5. ������������� �����\n 6. ������������� ��\n 7. ���������\n 8. ���������\n";
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
        case 7:
            system("cls");
            Save(p, station);
            break;


        }

    }
    return 0;
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
