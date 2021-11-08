// Kuzminalab11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

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
        cout << " ����� ��: " << station.id << " ���: " << station.name << " ���������� �����: " << station.col_cex << " ���������� ����� � ������: " << station.col_work << " �������������: " << station.effic << " %";
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

void AddPipeVector(Pipe& p, int& pipe_id, std::unordered_map<int, Pipe>& Pipeline)
{
    p = AddPipe();
    pipe_id++;
    p.id = pipe_id;
    Pipeline.insert({ pipe_id, p });
}

void PrintPipeline(std::unordered_map<int, Pipe>::iterator& pipe_iter, std::unordered_map<int, Pipe>& Pipeline)
{
    cout << "Pipeline:\n ";
    pipe_iter = Pipeline.begin();
    for (int i = 0; pipe_iter != Pipeline.end(); pipe_iter++)
    {
        cout << " id: " << pipe_iter->second.id << " �������: " << pipe_iter->second.d << " �����: " << pipe_iter->second.l << " ������: " << pipe_iter->second.r << endl;

    }



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
    while (station.col_cex < 1) {
        cout << "������� ����� ������ 0";
        station.col_cex = ProvInt();
    }
    cout << "������� ����� � ������? ";                                                  // ������� ����� � ������?
    station.col_work = ProvInt();

    while (station.col_work > station.col_cex || station.col_cex < 0)
    {
        cout << "���������� ������� ������ ��� ����� ����� ��� �� ����� ������������� ��������. ����������, ������� ����� ��������: ";
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

void AddCSVector(CS& station, int& cs_id, std::unordered_map<int, CS>& CSline)
{
    station = AddCS();
    cs_id++;
    station.id = cs_id;
    CSline.insert({ cs_id, station });
}

void PrintCSline(std::unordered_map<int, CS>::iterator& cs_iter, std::unordered_map<int, CS>& CSline)
{
    cout << "CSline:\n ";
    cs_iter = CSline.begin();
    for (int i = 0; cs_iter != CSline.end(); cs_iter++)
    {
        cout << " ����� ��: " << cs_iter->second.id << " ���: " << cs_iter->second.name << " ���������� �����: " << cs_iter->second.col_cex << " ���������� ����� � ������: " << cs_iter->second.col_work << endl;

    }
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
    ofstream file;
    file.open("savep.txt");
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
            file << station.effic << endl;
        }
        file.close();
        cout << "���������\n";
    }
    else {
        cout << "�����������";
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
            if (text == "Pipe")
            {
                file >> p.id;
                file >> p.d;
                file >> p.l;
                file >> p.r;
            }
            if (text == "CS")
            {
                file >> station.id;
                file.ignore(37873, '\n');
                string(station.name);
                getline(file, station.name);
                //file >> station.name;
                file >> station.col_cex;
                file >> station.col_work;
                file >> station.effic;


            }
         

        }

        cout << "���������";
    }

}

void DeletePipe(std::unordered_map<int, Pipe>::iterator& pipe_iter, std::unordered_map<int, Pipe>& Pipeline)
{
    cout << "����� ����� �� ������ �������? (id)" << endl;
    vector <int> idv;
    int id;
    id = ProvInt();
    while (id != 0)
    {
        idv.push_back(id);
        cout << "������� 0 ����� ������� ��� �������� id";
        id = ProvInt();
    }
    pipe_iter = Pipeline.begin();
    for (int i = 0; i < idv.size(); i++)
    {
        pipe_iter = Pipeline.find(idv[i]);
        Pipeline.erase(pipe_iter);
    }
    idv.clear();
    cout << "�������" << endl;
}

void DeleteCS(std::unordered_map<int, CS>::iterator& cs_iter, std::unordered_map<int, CS>& CSline)
{
    cout << "����� ������� �� ������ �������? (id)" << endl;
    vector <int> csv;
    int id;
    id = ProvInt();
    while (id != 0)
    {
        csv.push_back(id);
        cout << "������� 0 ����� ������� ��� �������� id";
        id = ProvInt();
    }
    cs_iter = CSline.begin();
    for (int i = 0; i < csv.size(); i++)
    {
        cs_iter = CSline.find(csv[i]);
        CSline.erase(cs_iter);
    }
    csv.clear();
    cout << "�������" << endl;
}




int main()
{

    int m;                                                                             // ������� ����

    Pipe p = {};
    CS station = {};

    unordered_map <int, Pipe> Pipeline = {};
    unordered_map <int, CS> CSline = {};

    unordered_map <int, Pipe> :: iterator pipe_iter = Pipeline.begin();
    unordered_map <int, CS> ::iterator cs_iter = CSline.begin();

    int pipe_id = 0;
    int cs_id = 0;

    {
        setlocale(0, "");                                                              //������� ����  
    }

    for (;;) {
        cout << "\n 1. �����\n 2. �������� �����\n 3. �������� ��\n 4. �������� ��� �������\n 5. ������������� �����\n 6. ������������� ��\n 7. ���������\n 8. ���������\n 9. ������� �����\n 10. ������� ��\n";
        m = ProvInt();
        switch (m)
        {
        case 1:
        {
            return 0;
        }

        case 2:
        {
            system("cls");
            AddPipeVector(p, pipe_id, Pipeline);

           // p = AddPipe();
            break;
        }

        case 3:
        {
            system("cls");
            AddCSVector(station, cs_id, CSline);

           // station = AddCS();
            break;
        }

        case 4:
        {
            system("cls");
            PrintPipeline(pipe_iter, Pipeline);
            PrintCSline(cs_iter, CSline);
            //PrintePipe(p);
            //PrinteCS(station);
            break;
        }

        case 5:
        {   system("cls");
            editpipe(p);
            break;
        }

        case 6:
        {
            system("cls");
            editcs(station);
            break;
        }
        case 7:
        {
            system("cls");
            Save(p, station);
            break;
        }
        case 8:
        {
            system("cls");
            Doload(p, station);
            break;
        }
        case 9:
        {
            DeletePipe(pipe_iter, Pipeline);
            break;
        }
        case 10:
        {
            DeleteCS(cs_iter, CSline);
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
