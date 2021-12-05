// Kuzminalab11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Pipe.h"
#include "CS.h"



using namespace std;


template <typename T> 

T ProvNumber(T min, T max)   //proverka
{
        T num;
        while ((cin >> num).fail() || num < min || num > max)
        {
            cin.clear();
            cin.ignore(20000, '\n');
            cout << "������� ����� �� " << min << " �� " << max << " ";
        }
        return num;
          
}

//string ProvStr()
//{
//    while (1)
//    {
//        cin >> ws;
//        string str;
//        getline(cin, str);
//        return str;
//    }
//}

template <typename T>
int PoiskID(const T& line, int id)
{
    if (line.find(id) != line.end())
        return id;
    return 0;
}

int redactPipe(unordered_map<int, Pipe>& Pipeline)
{
    cout << "������� ID ����: " << endl;
    for (;;)
    {
        int id = ProvNumber(0, INT_MAX);
        if (PoiskID(Pipeline, id) != 0)
        {
            Pipeline[id].redact();
            cout << "��������" << endl;
            return id;
        }
        else cout << "��� ����� � ����� ID" << endl;
    }
}

int redactSatation(unordered_map<int, CS>& CSline)
{
    cout << "������� ID �������: " << endl;
    for (;;)
    {
        int id = ProvNumber(0, INT_MAX);
        if (PoiskID(CSline, id) != 0)
        {
            CSline[id].redact();
            cout << "��������" << endl;
            return id;
        }
        else cout << "��� ������� � ����� ID" << endl;
    }
}

template <typename T>
void DELETE1(T& line, int id)
{
    if (line.find(id) != line.end())
        line.erase(id);
}

void DELETEPipe(unordered_map<int, Pipe>& Pipeline)
{
    cout << "������� ID �����" << endl;
    for (;;)
    {
        int id = ProvNumber(0, INT_MAX);
        if (PoiskID(Pipeline, id) != 0)
        {
            DELETE1(Pipeline, id);
            cout << "����� �������";
            return;
        }
        else cout << "����� � ����� ID ���" << endl;
    }
}

void DELETECS(unordered_map<int, CS>& CSline)
{
    cout << "������� ID �������" << endl;
    for (;;)
    {
        int id = ProvNumber(0, INT_MAX);
        if (PoiskID(CSline, id) != 0)
        {
            DELETE1(CSline, id);
            cout << "������� �������";
            return;
        }
        else cout << "������� � ����� ID ���" << endl;
    }
}

void PrintePipe( const unordered_map<int, Pipe>& PipeLine)
{
    for (auto& p : PipeLine)
        cout << p.second;
}

void PrinteCS( const unordered_map<int, CS>& CSline)
{
    for (auto& station : CSline)
        cout << station.second;
}


void Savepipe(const unordered_map <int, Pipe>& Pipeline, ofstream& fout)
{
    for (auto& p : Pipeline)
        fout << p.second;
}

void Savecs(const unordered_map <int, CS>& CSline, ofstream& fout)
{
    for (auto& station : CSline)
        fout << station.second;
}

void Load(unordered_map<int, Pipe>& Pipeline, unordered_map<int, CS>& CSline, ifstream& fin)
{
    int sizepipe, sizecs, maxidpipe, maxidcs;
    fin >> sizepipe;
    fin >> maxidpipe;
    fin >> sizecs;
    fin >> maxidcs;
    for (int i = 1; i < sizepipe; i++)
    {
        Pipe p;
        fin >> p;
        Pipeline.insert({ p.getId(), p });
    }
    for (int i = 1; i < sizecs; i++)
    {
        CS station;
        fin >> station;
        CSline.insert({ station.getId(), station });

    }
    Pipe::setMaxID(maxidpipe);
    CS::setMaxID(maxidcs);
}

int main()
{
    int m;                                                                             // ������� ����

    unordered_map <int, Pipe> Pipeline = {};
    unordered_map <int, CS> CSline = {};

    {
        setlocale(0, "");                                                              //������� ����  
    }

    for (;;) {
        cout << "\n 1. �����"
            << "\n 2. �������� �����"
            << "\n 3. �������� ��"
            << "\n 4. �������� ��� �������"
            << "\n 5. ������������� �����"
            << "\n 6. ������������� ��"
            << "\n 7. ���������"
            << "\n 8. ���������"
            << "\n 9. ����� �� �� ����� "
            << "\n 10. ������� �����"
            << "\n 11. ������� ��\n";
        
        m = ProvNumber(1,11);
        switch (m)
        {
        case 1:
        {
            return 0;
        }

        case 2:
        {
            system("cls");
            Pipe p;
            cin >> p;
            Pipeline.insert({ p.getId(), p });
            break;
        }

        case 3:
        {
            system("cls");
            CS station;
            cin >> station;
            CSline.insert({ station.getId(), station });
            break;
        }

        case 4:
        {
            system("cls");

            if (Pipeline.size() != 0)
            {
                cout << "�����: " << endl;
                    PrintePipe(Pipeline);
            }
            if (CSline.size() != 0)
            {
                cout << "�������: " << endl;
                PrinteCS(CSline);
            }
            break;
        }

        case 5:
        {   system("cls");
            redactPipe(Pipeline);
            break;
        }

        case 6:
        {
            system("cls");
           redactSatation(CSline);
            break;
        }
        case 7:
        {
            system("cls");
            string name;
            cout << "������� ��� �����: " << endl;
            cin.ignore(23456, '\n');
            getline(cin, name);
            ofstream fout;
            fout.open(name, ios::out);
                if (fout.is_open())
                {
                    if (Pipeline.size() != 0)
                        fout << Pipeline.size() << endl << Pipe::getMaxID() << endl;
                    else fout << 0 << endl << 0 << endl;
                    if (CSline.size() != 0)
                        fout << CSline.size() << endl << CS::getMaxID() << endl;
                    else fout << 0 << endl << 0 << endl;

                    if (Pipeline.size() != 0)
                        Savepipe(Pipeline, fout);
                    if (CSline.size() != 0)
                        Savecs(CSline, fout);
                    cout << "���������";
                }
                fout.close();

            break;
        }
        case 8:
        {
            string name;
            cout << "������� ��� �����: " << endl;
            cin.ignore(23456, '\n');
            getline(cin, name);
            ifstream fin;
            fin.open(name, ios::in);
            if (fin.is_open())
                Load(Pipeline, CSline, fin);
            cout << "���������";
            fin.close();
            break;
        }
        case 9:
        {
         
            break;
        }
        case 10:
        {
            DELETEPipe(Pipeline);
            break;
        }
        case 11:
        {
            DELETECS(CSline);
            break;
        }
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
