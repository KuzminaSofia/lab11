// Kuzminalab11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

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

int ProvInt()   //proverka
{
    for (;;)
    {
        int num;
        cin >> num;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "������� ���������� int";
        }
        else
        {
            return num;
        }
    }
}

bool ProvBool()    //��� ������� �����
{
    for (;;)
    {
        bool num;
        cin >> num;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << " ������� ��� bool \n";

        }
        else
        {
            return num;
        }
    }
}


void PrintePipe( const Pipe& p)
{
    if (p.l > 1)
    {
    cout << " ����� ��� �������: " << p.id << "  �������: " << p.d << " �� " << " �����: " << p.l << " ��\n" ;
    cout << " ����� � �������: " << p.r << endl; }
    else
    {
        cout << "  ��� ����� \n";
    }
}

void PrinteCS( const CS& station)
{
    if (station.col_cex > 0)
    {
        cout << " ����� ��: " << station.id << " ���: " << station.name << " ���������� �����: " << station.col_cex << " ���������� ����� � ������: " << station.col_work << "�������������: " << station.effic << " %";
    }
    else
    {
        cout << "  ��� ������������� ������� \n";
    }
    
}

Pipe AddPipe()
{
    Pipe p;
    p.id = 0;
    cout << "������� �������: ";
    p.d = ProvInt(); 
    while (p.d < 400 || p.d > 2000)
    {
        cout << "������� ����� �� ���������� [400;2000] mm \n";
        p.d = ProvInt();
    }
    cout << "������� �����: ";
    p.l = ProvInt();
    while (p.l < 10 || p.l > 1234)
    {
        cout << "������� ����� �� ���������� [10;1234] km \n";
        p.l = ProvInt();
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
    cin >> ws;
    getline(cin, station.name);
    cout << "������� ����� � �������? ";                                                 // ������� ����� � �������?
    station.col_cex = ProvInt();
    cout << "������� ����� � ������? ";                                                  // ������� ����� � ������?
    station.col_work = ProvInt();

    while (station.col_work > station.col_cex)
    {
        cout << "���������� ������� ������ ��� ����� �����. ����������, ������� ����� ��������: ";
        station.col_work = ProvInt();
    }

    cout << "������������� ����";
    station.effic = ProvInt();
    while (station.effic < 0 || station.effic > 100) {
        cout << "������������� � %";
        station.effic = ProvInt();
    }
    return station;
    
}  
void editpipe(Pipe& p)                                                                  //�������� �����
{
    if (p.l > 1)                                                                        //����������
    {
        
        cout << "���� ����� � ������ ������� - 0, ���� � ������� - 1 \n";               //�� �������� ������ ����� 1 � 0, �������� �����
        p.r = ProvBool();
    }
    else cout << "�������� �����";
}

void editcs(CS& station)                                                                 //�������� ������������� �������
{
    if (station.col_cex > 0)
    {
        cout << "������� ����� � ������ ������?";
        station.col_work = ProvInt();
        while (station.col_work > station.col_cex)                                      //�������� �� ���������� ������� ����� � ���������
        {
            cout << "���������� ������� ������ ��� ����� �����. ����������, ������� ����� ��������: \n";
            station.col_work = ProvInt();
        }
        cout << "��� ���";
        station.effic = ProvInt();
        while (station.effic < 0 || station.effic > 100) {
            cout << "������������� � %";
            station.effic = ProvInt();
        }

    }
    else cout << "�������� ���";

}

void Save( const Pipe& p, const CS& station)                                                          //���������� � ����
{
    ofstream file("savep.txt");
    file.open("savep.txt", ios_base::out);
    if (file.good())
    {
        if (p.l > 1)
        {
            file << "Pipe" << endl;
            file << p.id << endl;
            file << p.d << endl;
            file << p.l << endl;
            file << p.r << endl;
        }
        if (station.col_cex > 0)
        {
            file << "CS" << endl;
            file << station.id << endl;
            file << station.name << endl;
            file << station.col_cex << endl;
            file << station.col_work << endl;
        }
        file.close();
        cout << "���������\n";
    }
    else {
        cout << "����� �����������";
    }

}

void Doload(Pipe& p, CS& station)
{
    ifstream file;
    file.open("savep.txt");
    if (file.good())
    {
        while (!file.eof())
        {
            string text;
            file >> text;
            cout << text << endl;
            if (text == "Pipe: ")
            {
                file >> p.id;
                file >> p.d;
                file >> p.l;
                file >> p.r;
            }
            if (text == "CS: ")
            {
                file >> station.id;
                file >> station.name;
                file >> station.col_cex;
                file >> station.col_work;


            }
         

        }

        cout << "��";
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
        m = ProvInt();
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
        case 8:
            system("cls");
            Doload(p, station);
            break;
        default:
            cout << "������� ����� �� ����";
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
