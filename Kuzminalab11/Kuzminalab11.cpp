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
#include <unordered_set>
#include "Graph.h"
#include <set>

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


template <typename T>
int PoiskID(const T& line, int id)
{
    if (line.find(id) != line.end())
        return id;
    return 0;
}

vector <int> PoiskRemont(unordered_map<int, Pipe>& Pipeline, bool& r)
{
    vector <int> line;
    for (auto& p : Pipeline)
    {
        if (p.second.getR() == r)
            line.push_back(p.first);
    }
    return line;
}


template <typename T>
vector<int> PoiskName(T& line, string& name)
{
    vector<int> res;
    for (auto& id : line) {
        if (id.second.getName() == name)
            res.push_back(id.first);
    }
    return res;
}

vector<int> PoiskProc(unordered_map<int, CS>& CSs, double& proc)
{
    vector<int> res;
    for (auto& station : CSs) {
        if (round((((double(station.second.getCex()) - double(station.second.getWork())) / double(station.second.getCex()) * 100) >= proc)))
            res.push_back(station.first);
    }
    return res;
}

int redactPipe(unordered_map<int, Pipe>& Pipeline)
{
    cout << "������� ID ����: " << endl;
    for (;;)
    {
        int id = ProvNumber(0, Pipe::getMaxID());
        if (PoiskID(Pipeline, id) != 0)
        {
            Pipeline[id].redact();
            cout << "��������" << endl;
            return id;
        }
        else cout << "��� ����� � ����� ID" << endl;
    }
}

int redactCS(unordered_map<int, CS>& CSline)
{
    cout << "������� ID �������: " << endl;
    for (;;)
    {
        int id = ProvNumber(0, CS::getMaxID());
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
void DELETE(T& line, int id)
{
    if (line.find(id) != line.end())
        line.erase(id);
    
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

void redactPipeline(unordered_map<int, Pipe>& PipeLine)
{
    if (PipeLine.size() != 0)
    {
        cout << "��������������: " << endl << " 1 - ���� ����� " << endl << " 2 - ��������� ���� " << endl;
        switch (ProvNumber(1, 2))
        {
        case 1:
        {
            cout << " 1 - �������� ������ �������, 2 - ������� ";
            if (ProvNumber(1,2) == 1)
            redactPipe(PipeLine);
            else
            {
                cout << "������� ID �����: ";
                int id = ProvNumber(0, Pipe::getMaxID());
                if (PoiskID(PipeLine, id) != 0)
                DELETE(PipeLine, id);
                else cout << "��� ����� � ����� ID" << endl;
            }

            break;
        }
        case 2:
        {
            cout << "1. ����� ���� �� ����� " << endl
                 << "2. ����� ���� �� ������� �������" << endl
                 << "3.����� ���� �� ID " << endl
                 << "4. �����" << endl;
        switch (ProvNumber(1, 4))
        {
        case 1: //����� �� �����
        {
            cout << "������� ��� ���� " << endl;
            string name;
            cin.ignore(12345, '\n');
            getline(cin, name);
            vector <int> namepipe = PoiskName(PipeLine, name);
            for (int i : namepipe)
                cout << PipeLine[i];

            cout << "1. �������� ������ ������� ����" << endl
                << "2. ������� ����� " << endl
                << "3. ����� " << endl;

            switch (ProvNumber(1, 3))
            {
            case 1:
            {
                cout << " 1 - �������� ��� ��������� �����, 2 - �������� �� ������, 0 - ����� ";
                if (ProvNumber(1, 2) == 1)
                {
                    if (namepipe.size() != 0)

                    {
                        for (auto& id : namepipe)
                            PipeLine[id].redact();
                        cout << "��������" << endl;
                    }
                    else cout << "��� ����" << endl;
                    
                }
                else {
                    unordered_set<int> res;
                    cout << "������� ID ���� ��� ��������������, ������� 0 ����� ���������� ";
                    int id = ProvNumber(0, Pipe::getMaxID());
                    while (id) 
                    {
                        res.insert(id);
                        id = ProvNumber(0, Pipe::getMaxID());
                    }
                    for (auto& pid : namepipe)
                        if (res.count(pid) > 0)
                            PipeLine[pid].redact();
                }
                PrintePipe(PipeLine);
                break;
            }
            case 2:
            {
                cout << " 1 - ������� ��� ��������� �����, 2 - ������� �� ������";
                if (ProvNumber(1, 2) == 1)
                {
                    if (namepipe.size() != 0)

                    {
                        for (auto& id : namepipe)
                            DELETE(PipeLine, id);
                        cout << "�������" << endl;
                    }
                    else cout << "��� ����" << endl;
                    
                }
                else {
                    unordered_set<int> res;
                    cout << "������� ID ���� ��� ��������, ������� 0 ����� ���������� ";
                    int id = ProvNumber(0, Pipe::getMaxID());
                    while (id)
                    {
                        res.insert(id);
                        id = ProvNumber(0, Pipe::getMaxID());
                    }
                    for (auto& pid : namepipe)
                        if (res.count(pid) > 0)
                            DELETE(PipeLine, pid);
                }
                PrintePipe(PipeLine);
                break;
            }
            case 0:
                return;
            }
            break;
        }
        case 2: // ����� �� ������� ������� 
        {
            cout << "0 - ������� ��� ������� �����, 1 - ������� ��� ����� � �������, 2 - ����� " << endl;
            bool remont = ProvNumber(0, 2);
            vector <int> rempipe = PoiskRemont(PipeLine, remont);
            if (rempipe.size() != 0) {
                for (int i : rempipe)
                    cout << PipeLine[i];
            }
            else
            {
                cout << "��� ���� � ������� " << endl;
                return;
            }

            cout << "1. �������� ������ ������� ���� " << endl
                << "2. ������� ����� " << endl
                << "3. ����� " << endl;

            switch (ProvNumber(1, 3))
            {
            case 1: //�������� ������
            {
                cout << " 1 - �������� ��� ��������� �����, 2 - �������� �� ������, 0 - ����� ";
                if (ProvNumber(1, 2) == 1)
                {
                    if (rempipe.size() != 0)

                    {
                        for (auto& id : rempipe)
                            PipeLine[id].redact();
                        cout << "��������" << endl;
                    }
                    else cout << "��� ����" << endl;

                }
                else {
                    unordered_set<int> res;
                    cout << "������� ID ���� ��� ��������������, ������� 0 ����� ���������� ";
                    int id = ProvNumber(0, Pipe::getMaxID());
                    while (id)
                    {
                        res.insert(id);
                        id = ProvNumber(0, Pipe::getMaxID());
                    }
                    for (auto& pid : rempipe)
                        if (res.count(pid) > 0)
                            PipeLine[pid].redact();
                }
                PrintePipe(PipeLine);
                break;
            }
            case 2:
            {
                cout << " 1 - ������� ��� ��������� �����, 2 - ������� �� ������";
                if (ProvNumber(1, 2) == 1)
                {
                    if (rempipe.size() != 0)

                    {
                        for (auto& id : rempipe)
                            DELETE(PipeLine, id);
                        cout << "�������" << endl;
                    }
                    else cout << "��� ����" << endl;

                }
                else {
                    unordered_set<int> res;
                    cout << "������� ID ���� ��� ��������, ������� 0 ����� ���������� ";
                    int id = ProvNumber(0, Pipe::getMaxID());
                    while (id)
                    {
                        res.insert(id);
                        id = ProvNumber(0, Pipe::getMaxID());
                    }
                    for (auto& pid : rempipe)
                        if (res.count(pid) > 0)
                            DELETE(PipeLine, pid);
                }
                PrintePipe(PipeLine);
                break;
            }
            case 3:
                return;
            }
            break;
        }
        case 3:
        {
            cout << "������� ID ���� ��� ��������������, ������� 0 ����� ���������� " << endl;
            int id;
            vector<int> idpipe;
            do {
                id = ProvNumber(0, Pipe::getMaxID());
                if (PoiskID(PipeLine, id) != 0)
                    idpipe.push_back(id);
            } while (id != 0);
            for (auto i : idpipe)
                cout << PipeLine[i];

            cout << "1. �������� ������ ������� ����" << endl
                << "2. ������� ����� " << endl
                << "3. ����� " << endl;

            switch (ProvNumber(1, 3))
            {
            case 1: //�������� ������
            {
                cout << " 1 - �������� ��� ��������� �����, 2 - �������� �� ������, 0 - ����� ";
                if (ProvNumber(1, 2) == 1)
                {
                    if (idpipe.size() != 0)

                    {
                        for (auto& id : idpipe)
                            PipeLine[id].redact();
                        cout << "��������" << endl;
                    }
                    else cout << "��� ����" << endl;

                }
                else {
                    unordered_set<int> res;
                    cout << "������� ID ���� ��� ��������������, ������� 0 ����� ���������� ";
                    int id = ProvNumber(0, Pipe::getMaxID());
                    while (id)
                    {
                        res.insert(id);
                        id = ProvNumber(0, Pipe::getMaxID());
                    }
                    for (auto& pid : idpipe)
                        if (res.count(pid) > 0)
                            PipeLine[pid].redact();
                }
                PrintePipe(PipeLine);
                break;
            }
            case 2:
            {
                cout << " 1 - ������� ��� ��������� �����, 2 - ������� �� ������";
                if (ProvNumber(1, 2) == 1)
                {
                    if (idpipe.size() != 0)

                    {
                        for (auto& id : idpipe)
                            DELETE(PipeLine, id);
                        cout << "�������" << endl;
                    }
                    else cout << "��� ����" << endl;

                }
                else {
                    unordered_set<int> res;
                    cout << "������� ID ���� ��� ��������, ������� 0 ����� ���������� ";
                    int id = ProvNumber(0, Pipe::getMaxID());
                    while (id)
                    {
                        res.insert(id);
                        id = ProvNumber(0, Pipe::getMaxID());
                    }
                    for (auto& pid : idpipe)
                        if (res.count(pid) > 0)
                            DELETE(PipeLine, pid);
                }
                PrintePipe(PipeLine);
                break;
            }
            case 3:
                return;
            }
            break;
        }
        case 4:
            return;
        }
        }
        }
        
    }
    else cout << "��� ����" << endl;
}

void redactCSline(unordered_map<int, CS>& CSline)
{
    if (CSline.size() != 0)
    {
        cout << "��������������: " << endl << " 1 - ���� �� " << endl << " 2 - ��������� �� ";
        switch (ProvNumber(1, 2))
        {
        case 1:
        {
            cout << " 1 - �������� ���������� ���������� �����, 2 - ������� �� ";
            if (ProvNumber(1, 2) == 1)
                redactCS(CSline);
            else
            {
                cout << "������� ID ��: ";
                int id = ProvNumber(0, CS::getMaxID());
                if (PoiskID(CSline, id) != 0)
                    DELETE(CSline, id); \
                else cout << " ��� �� � ����� ID" << endl;
            }

            break;
        }
        case 2:
        {
            cout << "1. ����� �� �� ����� " << endl
                << "2. ����� �� �� % ����������������� ����� " << endl
                << "3. �����" << endl;
            switch (ProvNumber(1, 3))
            {
            case 1: //����� �� �����
            {
                cout << "������� ��� ��" << endl;
                string name;
                cin.ignore(12345, '\n');
                getline(cin, name);
                vector <int> namecs = PoiskName(CSline, name);
                for (int i : namecs)
                    cout << CSline[i];
                if (namecs.size() == 0)
                {
                    cout << "��� ����� ��" << endl;
                }
                else {

                    cout << "1. �������� ���������� ���������� ����� " << endl
                        << "2. ������� �� " << endl
                        << "3. ����� " << endl;

                    switch (ProvNumber(1, 3))
                    {
                    case 1:
                    {
                        cout << " 1 - �������� ��� ��������� ��, 2 - �������� �� ������, 0 - ����� ";
                        if (ProvNumber(1, 2) == 1)
                        {
                            if (namecs.size() != 0)

                            {
                                for (auto& id : namecs)
                                    CSline[id].redact();
                                cout << "��������" << endl;
                            }
                            else cout << "��� ��" << endl;

                        }
                        else {
                            unordered_set<int> res;
                            cout << "������� ID �� ��� ��������������, ������� 0 ����� ���������� ";
                            int id = ProvNumber(0, CS::getMaxID());
                            while (id)
                            {
                                res.insert(id);
                                id = ProvNumber(0, CS::getMaxID());
                            }
                            for (auto& cid : namecs)
                                if (res.count(cid) > 0)
                                    CSline[cid].redact();
                        }
                        PrinteCS(CSline);
                        break;
                    }
                    case 2:
                    {
                        cout << " 1 - ������� ��� ��������� ��, 2 - ������� �� ������";
                        if (ProvNumber(1, 2) == 1)
                        {
                            if (namecs.size() != 0)

                            {
                                for (auto& id : namecs)
                                    DELETE(CSline, id);
                                cout << "�������" << endl;
                            }
                            else cout << "��� ��" << endl;

                        }
                        else {
                            unordered_set<int> res;
                            cout << "������� ID �� ��� ��������, ������� 0 ����� ���������� ";
                            int id = ProvNumber(0, CS::getMaxID());
                            while (id)
                            {
                                res.insert(id);
                                id = ProvNumber(0, CS::getMaxID());
                            }
                            for (auto& cid : namecs)
                                if (res.count(cid) > 0)
                                    DELETE(CSline, cid);
                        }
                        PrinteCS(CSline);
                        break;
                    }
                    case 0:
                        return;
                    }
                    break;
                }
                break;
            }
            case 2: // ����� %
            {
                cout << "������� % ���������������� ����� " << endl;
                double proc = ProvNumber(0.0, 100.0);
                vector <int> proccs = PoiskProc(CSline, proc);
                for (int i : proccs)
                    cout << CSline[i];
                if (proccs.size() == 0)
                {
                    cout << "��� ����� ��" << endl;
                }
                else {
                    cout << "1. �������� ���������� ���������� ������� " << endl
                        << "2. ������� �� " << endl
                        << "3. ����� " << endl;

                    switch (ProvNumber(1, 3))
                    {
                    case 1:
                    {
                        cout << " 1 - �������� ��� ��������� ��, 2 - �������� �� ������, ";
                        if (ProvNumber(1, 2) == 1)
                        {
                            if (proccs.size() != 0)

                            {
                                for (auto& id : proccs)
                                    CSline[id].redact();
                                cout << "��������" << endl;
                            }
                            else cout << "��� ��" << endl;

                        }
                        else {
                            unordered_set<int> res;
                            cout << "������� ID �� ��� ��������������, ������� 0 ����� ���������� ";
                            int id = ProvNumber(0, CS::getMaxID());
                            while (id)
                            {
                                res.insert(id);
                                id = ProvNumber(0, CS::getMaxID());
                            }
                            for (auto& cid : proccs)
                                if (res.count(cid) > 0)
                                    CSline[cid].redact();
                        }
                        PrinteCS(CSline);
                        break;
                    }
                    case 2:
                    {
                        cout << " 1 - ������� ��� ��������� ��, 2 - ������� �� ������";
                        if (ProvNumber(1, 2) == 1)
                        {
                            if (proccs.size() != 0)

                            {
                                for (auto& id : proccs)
                                    DELETE(CSline, id);
                                cout << "�������" << endl;
                            }
                            else cout << "��� ��" << endl;

                        }
                        else {
                            unordered_set<int> res;
                            cout << "������� ID �� ��� ��������, ������� 0 ����� ���������� ";
                            int id = ProvNumber(0, CS::getMaxID());
                            while (id)
                            {
                                res.insert(id);
                                id = ProvNumber(0, CS::getMaxID());
                            }
                            for (auto& cid : proccs)
                                if (res.count(cid) > 0)
                                    DELETE(CSline, cid);
                        }
                        PrinteCS(CSline);
                        break;
                    }
                    case 3:
                        return;
                    }
                    break;
                }
            }
            case 3:
                return;
            }
        }
        }

    }
    else cout << "��� �� :( " << endl;
}

void CreatLink(unordered_map<int, Pipe>& PipeLine, unordered_map<int, CS>& CSline)
{
    cout << "������� ID �����, ������� ����� ������������ " << endl;
    int pipeid = PoiskID(PipeLine, ProvNumber(0, Pipe::getMaxID()));
    while (PipeLine[pipeid].getR() != 0)
    {
        cout << " ����� � �������, ������� ������ ID" << endl;
        pipeid = PoiskID(PipeLine, ProvNumber(0, Pipe::getMaxID()));
    }
    cout << "������� ID ��, �� ������� ������� �����" << endl;
    int out = PoiskID(CSline, ProvNumber(0, CS::getMaxID()));
    cout << "������� ID ��, � ������� ������ �����" << endl;
    int in = PoiskID(CSline, ProvNumber(0, CS::getMaxID()));

    if (CSline[in].col_pipe >= CSline[in].getWork() && CSline[out].col_pipe >= CSline[out].getWork())
        cout << " ������������ ������� ����� � �������" << endl;
    if (pipeid != 0 && PipeLine[pipeid].pin == 0 && PipeLine[pipeid].pout == 0 && in != out && out != 0 && in != 0 && CSline[in].col_pipe < CSline[in].getWork() && CSline[out].col_pipe < CSline[out].getWork())
    {
        PipeLine[pipeid].link(in, out);
        CSline[in].link();
        CSline[out].link();
    }
    else cout << "���-�� ����� �� ���..." << endl;
}

vector<vector<int>> CreateGraph(const unordered_map<int, Pipe>& Pipeline, const unordered_map<int, CS>& CSline) {
    set<int> vertices;
    for (const auto& p : Pipeline)
        if (p.second.pin >0 && p.second.pout> 0 && p.second.getR() == false && CSline.count(p.second.pin) && CSline.count(p.second.pout))
        {
            vertices.insert(p.second.pout);
            vertices.insert(p.second.pin);
        }

    unordered_map<int, int> VerticesIndex;
    int i = 0;
    for (const int& v : vertices)
        VerticesIndex.insert({ v, i++ });
    vector<vector<int>> r;
    r.resize(vertices.size());
    for (const auto& p : Pipeline)
        if (p.second.pin > 0 && p.second.pout > 0 && p.second.getR() == false)
            r[VerticesIndex[p.second.pout]].push_back(VerticesIndex[p.second.pin]);
    return r;
}

void DeleteLink(unordered_map<int, Pipe>& PipeLine, unordered_map<int, CS>& CSline)
{
    cout << "������� ID �����, ������� ������ �������: " << endl;
    int pipeid = PoiskID(PipeLine, ProvNumber(0, Pipe::getMaxID()));
    if (pipeid != 0 && PipeLine[pipeid].pin >0  && PipeLine[pipeid].pout > 0)
    {
            for (auto& p : PipeLine)
            {
                CSline[PipeLine[pipeid].pin].ClearLink();
                CSline[PipeLine[pipeid].pout].ClearLink();
                PipeLine[pipeid].ClearLink();
            }
            cout << "������� :) " << endl;
    }
    else   cout << "����� ����� �� ��������� � ����" << endl;
}

void PrintLink(unordered_map<int, Pipe>& PipeLine)
{
    for (auto& p : PipeLine)
        if (p.second.pin > 0 && p.second.pout > 0)
            cout << "kc " << p.second.pout << " --> pipe " << p.first << " -->kc " << p.second.pin << ((p.second.getR() == true) ? " � ������� " : " � ������ ") << endl; 
}

vector<vector <int>> CreatGraph(unordered_map<int, Pipe>& PipeLine, unordered_map<int, CS>& CSline)
{
    unordered_set<int> gr;
    for (auto& p : PipeLine)
        if (p.second.pin > 0 && p.second.pout > 0 && p.second.getR() == 0)
        {
            gr.insert(p.second.pout);
            gr.insert(p.second.pin);
        }
    unordered_map <int, int> index;
    int i = 0;
    for (auto& g : gr)
        index.insert({ g, i++ });
  vector<vector <int>> r;
    r.resize(gr.size());
    for (auto& p : PipeLine)
        if (p.second.pin > 0 && p.second.pout > 0 && p.second.getR() == 0)
            r[index[p.second.pout]].push_back(index[p.second.pin]);
    return r;
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
    for (int i = 0; i < sizepipe; i++)
    {
        Pipe p;
        fin >> p;
        Pipeline.insert({ p.getId(), p });
    }
    for (int i = 0; i < sizecs; i++)
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
        cout << "\n 1.�����"
            << "\n 2. �������� �����"
            << "\n 3. �������� ��"
            << "\n 4. �������� ��� �������"
            << "\n 5. �������� �����"
            << "\n 6. �������� ��"
            << "\n 7. ���������"
            << "\n 8. ���������"
            << "\n 9. ������������ �����"
            << "\n 10. ������� �����"
            << "\n 11. �������� �����"
            << "\n 12. �������������� ���������� \n";
        m = ProvNumber(1,12);
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
            else cout << " ��� ���� :( " << endl;
            if (CSline.size() != 0)
            {
                cout << " �������: " << endl;
                PrinteCS(CSline);
            }
            else cout << " ��� �� :( " << endl;
            break;
        }

        case 5:
        {   system("cls");
            redactPipeline(Pipeline);
            break;
        }

        case 6:
        {
            system("cls");
           redactCSline(CSline);
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
            system("cls");
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
        case 9: // ������������ ����� � ����
        {   
            if (Pipeline.size() > 0 && CSline.size() > 1)
                CreatLink(Pipeline, CSline);
            else cout << " ������������ ������ " << endl;
            break;
        }
        case 10: // �������� ����� �� ����
        {
            if (Pipeline.size() > 0 && CSline.size() > 1)
                DeleteLink(Pipeline, CSline);
            else cout << "���-�� ����� �� ���..." << endl;
            break;
        }
        case 11: //�������� �����
        {
            if (Pipeline.size() > 0 && CSline.size() > 1)
                PrintLink(Pipeline);
            else cout << " �������� ����� " << endl;
            break;
        }
        case 12:
        {
            
            vector<vector<int>> r = CreateGraph(Pipeline, CSline);
            Graph ESG(r);
            set<int> vertices;
            for (const auto& p : Pipeline)
                if (p.second.pin > 0 && p.second.pout > 0 && p.second.getR() == false && CSline.count(p.second.pin) && CSline.count(p.second.pout))
                {
                    vertices.insert(p.second.pout);
                    vertices.insert(p.second.pin);
                }
            unordered_map<int, int> VerticesIndex;
            int i = 0;
            for (const int& v : vertices)
                VerticesIndex.insert({ i++, v });
            ESG.TopSort(VerticesIndex);
            break;
        }
        }

    }
    return 0;
    }
