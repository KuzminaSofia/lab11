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



using namespace std;


template <typename T> 

T ProvNumber(T min, T max)   //proverka
{
        T num;
        while ((cin >> num).fail() || num < min || num > max)
        {
            cin.clear();
            cin.ignore(20000, '\n');
            cout << "Введите число от " << min << " до " << max << " ";
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
    cout << "Введите ID труб: " << endl;
    for (;;)
    {
        int id = ProvNumber(0, Pipe::getMaxID());
        if (PoiskID(Pipeline, id) != 0)
        {
            Pipeline[id].redact();
            cout << "Изменено" << endl;
            return id;
        }
        else cout << "Нет трубы с таким ID" << endl;
    }
}

int redactCS(unordered_map<int, CS>& CSline)
{
    cout << "Введите ID станции: " << endl;
    for (;;)
    {
        int id = ProvNumber(0, CS::getMaxID());
        if (PoiskID(CSline, id) != 0)
        {
            CSline[id].redact();
            cout << "Изменено" << endl;
            return id;
        }
        else cout << "Нет станции с таким ID" << endl;
    }
}

template <typename T>
void DELETE(T& line, int id)
{
    if (line.find(id) != line.end())
        line.erase(id);
    
}

//void DELETEPipe(unordered_map<int, Pipe>& Pipeline)
//{
//    cout << "Введите ID трубы" << endl;
//    for (;;)
//    {
//        int id = ProvNumber(0, Pipe::getMaxID());
//        if (PoiskID(Pipeline, id) != 0)
//        {
//            DELETE(Pipeline, id);
//            cout << "Труба удалена";
//            return;
//        }
//        else cout << "Трубы с таким ID нет" << endl;
//    }
//}

//void DELETECS(unordered_map<int, CS>& CSline)
//{
//    cout << "Введите ID станции" << endl;
//    for (;;)
//    {
//        int id = ProvNumber(0, CS::getMaxID());
//        if (PoiskID(CSline, id) != 0)
//        {
//            DELETE(CSline, id);
//            cout << "Станция удалена";
//            return;
//        }
//        else cout << "Станции с таким ID нет" << endl;
//    }
//}

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
        cout << "Редактирование: " << endl << " 1 - одну трубу " << endl << " 2 - несколько труб " << endl;
        switch (ProvNumber(1, 2))
        {
        case 1:
        {
            cout << " 1 - изменить статус ремонта, 2 - удалить ";
            if (ProvNumber(1,2) == 1)
            redactPipe(PipeLine);
            else
            {
                cout << "Введите ID трубы: ";
                int id = ProvNumber(0, Pipe::getMaxID());
                if (PoiskID(PipeLine, id) != 0)
                DELETE(PipeLine, id);
                else cout << "Нет трубы с таким ID" << endl;
            }

            break;
        }
        case 2:
        {
            cout << "1. Поиск труб по имени " << endl
                 << "2. Поиск труб по статусу ремонта" << endl
                 << "3.Поиск труб по ID " << endl
                 << "4. Выход" << endl;
        switch (ProvNumber(1, 4))
        {
        case 1: //поиск по имени
        {
            cout << "Введите имя труб " << endl;
            string name;
            cin.ignore(12345, '\n');
            getline(cin, name);
            vector <int> namepipe = PoiskName(PipeLine, name);
            for (int i : namepipe)
                cout << PipeLine[i];

            cout << "1. Изменить статус ремонта труб" << endl
                << "2. Удалить трубы " << endl
                << "3. ВЫход " << endl;

            switch (ProvNumber(1, 3))
            {
            case 1:
            {
                cout << " 1 - изменить все найденные трубы, 2 - изменить по выбору, 0 - назад ";
                if (ProvNumber(1, 2) == 1)
                {
                    if (namepipe.size() != 0)

                    {
                        for (auto& id : namepipe)
                            PipeLine[id].redact();
                        cout << "Изменено" << endl;
                    }
                    else cout << "Нет труб" << endl;
                    
                }
                else {
                    unordered_set<int> res;
                    cout << "Введите ID труб для редактирования, введите 0 чтобы продолжить ";
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
                cout << " 1 - удалить все найденные трубы, 2 - удалить по выбору";
                if (ProvNumber(1, 2) == 1)
                {
                    if (namepipe.size() != 0)

                    {
                        for (auto& id : namepipe)
                            DELETE(PipeLine, id);
                        cout << "Удалено" << endl;
                    }
                    else cout << "Нет труб" << endl;
                    
                }
                else {
                    unordered_set<int> res;
                    cout << "Введите ID труб для удаления, введите 0 чтобы продолжить ";
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
        case 2: // поиск по статусу ремонта 
        {
            cout << "0 - выбрать все рабочие трубы, 1 - выбрать все трубы в ремонте, 2 - назад " << endl;
            bool remont = ProvNumber(0, 2);
            vector <int> rempipe = PoiskRemont(PipeLine, remont);
            if (rempipe.size() != 0) {
                for (int i : rempipe)
                    cout << PipeLine[i];
            }
            else
            {
                cout << "Нет труб в ремонте " << endl;
                return;
            }

            cout << "1. Изменить статус ремонта труб " << endl
                << "2. Удалить трубы " << endl
                << "3. Выход " << endl;

            switch (ProvNumber(1, 3))
            {
            case 1: //изменить статус
            {
                cout << " 1 - изменить все найденные трубы, 2 - изменить по выбору, 0 - назад ";
                if (ProvNumber(1, 2) == 1)
                {
                    if (rempipe.size() != 0)

                    {
                        for (auto& id : rempipe)
                            PipeLine[id].redact();
                        cout << "Изменено" << endl;
                    }
                    else cout << "Нет труб" << endl;

                }
                else {
                    unordered_set<int> res;
                    cout << "Введите ID труб для редактирования, введите 0 чтобы продолжить ";
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
                cout << " 1 - удалить все найденные трубы, 2 - удалить по выбору";
                if (ProvNumber(1, 2) == 1)
                {
                    if (rempipe.size() != 0)

                    {
                        for (auto& id : rempipe)
                            DELETE(PipeLine, id);
                        cout << "Удалено" << endl;
                    }
                    else cout << "Нет труб" << endl;

                }
                else {
                    unordered_set<int> res;
                    cout << "Введите ID труб для удаления, введите 0 чтобы продолжить ";
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
            cout << "Введите ID труб для редактирования, нажмите 0 чтобы продолжить " << endl;
            int id;
            vector<int> idpipe;
            do {
                id = ProvNumber(0, Pipe::getMaxID());
                if (PoiskID(PipeLine, id) != 0)
                    idpipe.push_back(id);
            } while (id != 0);
            for (auto i : idpipe)
                cout << PipeLine[i];

            cout << "1. Изменить статус ремонта труб" << endl
                << "2. Удалить трубы " << endl
                << "3. Выход " << endl;

            switch (ProvNumber(1, 3))
            {
            case 1: //изменить статус
            {
                cout << " 1 - изменить все найденные трубы, 2 - изменить по выбору, 0 - назад ";
                if (ProvNumber(1, 2) == 1)
                {
                    if (idpipe.size() != 0)

                    {
                        for (auto& id : idpipe)
                            PipeLine[id].redact();
                        cout << "Изменено" << endl;
                    }
                    else cout << "Нет труб" << endl;

                }
                else {
                    unordered_set<int> res;
                    cout << "Введите ID труб для редактирования, введите 0 чтобы продолжить ";
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
                cout << " 1 - удалить все найденные трубы, 2 - удалить по выбору";
                if (ProvNumber(1, 2) == 1)
                {
                    if (idpipe.size() != 0)

                    {
                        for (auto& id : idpipe)
                            DELETE(PipeLine, id);
                        cout << "Удалено" << endl;
                    }
                    else cout << "Нет труб" << endl;

                }
                else {
                    unordered_set<int> res;
                    cout << "Введите ID труб для удаления, введите 0 чтобы продолжить ";
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
    else cout << "Нет труб" << endl;
}

void redactCSline(unordered_map<int, CS>& CSline)
{
    if (CSline.size() != 0)
    {
        cout << "Редактирование: " << endl << " 1 - одну кс " << endl << " 2 - несколько кс ";
        switch (ProvNumber(1, 2))
        {
        case 1:
        {
            cout << " 1 - изменить количество работающих цехов, 2 - удалить кс ";
            if (ProvNumber(1, 2) == 1)
                redactCS(CSline);
            else
            {
                cout << "Введите ID кс: ";
                int id = ProvNumber(0, CS::getMaxID());
                if (PoiskID(CSline, id) != 0)
                    DELETE(CSline, id); \
                else cout << " Нет кс с таким ID" << endl;
            }

            break;
        }
        case 2:
        {
            cout << "1. Поиск кс по имени " << endl
                << "2. Поиск кс по % незадействованных цехов " << endl
                << "3. Выход" << endl;
            switch (ProvNumber(1, 3))
            {
            case 1: //поиск по имени
            {
                cout << "Введите имя кс" << endl;
                string name;
                cin.ignore(12345, '\n');
                getline(cin, name);
                vector <int> namecs = PoiskName(CSline, name);
                for (int i : namecs)
                    cout << CSline[i];
                if (namecs.size() == 0)
                {
                    cout << "Нет таких кс" << endl;
                }
                else {

                    cout << "1. Изменить количество работающих цехов " << endl
                        << "2. Удалить кс " << endl
                        << "3. Выход " << endl;

                    switch (ProvNumber(1, 3))
                    {
                    case 1:
                    {
                        cout << " 1 - изменить все найденные кс, 2 - изменить по выбору, 0 - назад ";
                        if (ProvNumber(1, 2) == 1)
                        {
                            if (namecs.size() != 0)

                            {
                                for (auto& id : namecs)
                                    CSline[id].redact();
                                cout << "Изменено" << endl;
                            }
                            else cout << "Нет кс" << endl;

                        }
                        else {
                            unordered_set<int> res;
                            cout << "Введите ID кс для редактирования, введите 0 чтобы продолжить ";
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
                        cout << " 1 - удалить все найденные кс, 2 - удалить по выбору";
                        if (ProvNumber(1, 2) == 1)
                        {
                            if (namecs.size() != 0)

                            {
                                for (auto& id : namecs)
                                    DELETE(CSline, id);
                                cout << "Удалено" << endl;
                            }
                            else cout << "Нет кс" << endl;

                        }
                        else {
                            unordered_set<int> res;
                            cout << "Введите ID кс для удаления, введите 0 чтобы продолжить ";
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
            case 2: // поиск %
            {
                cout << "Введите % незадействованых цехов " << endl;
                double proc = ProvNumber(0.0, 100.0);
                vector <int> proccs = PoiskProc(CSline, proc);
                for (int i : proccs)
                    cout << CSline[i];
                if (proccs.size() == 0)
                {
                    cout << "Нет таких кс" << endl;
                }
                else {
                    cout << "1. Изменить количество работающих станций " << endl
                        << "2. Удалить кс " << endl
                        << "3. Выход " << endl;

                    switch (ProvNumber(1, 3))
                    {
                    case 1:
                    {
                        cout << " 1 - изменить все найденные кс, 2 - изменить по выбору, ";
                        if (ProvNumber(1, 2) == 1)
                        {
                            if (proccs.size() != 0)

                            {
                                for (auto& id : proccs)
                                    CSline[id].redact();
                                cout << "Изменено" << endl;
                            }
                            else cout << "Нет кс" << endl;

                        }
                        else {
                            unordered_set<int> res;
                            cout << "Введите ID кс для редактирования, введите 0 чтобы продолжить ";
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
                        cout << " 1 - удалить все найденные кс, 2 - удалить по выбору";
                        if (ProvNumber(1, 2) == 1)
                        {
                            if (proccs.size() != 0)

                            {
                                for (auto& id : proccs)
                                    DELETE(CSline, id);
                                cout << "Удалено" << endl;
                            }
                            else cout << "Нет кс" << endl;

                        }
                        else {
                            unordered_set<int> res;
                            cout << "Введите ID кс для удаления, введите 0 чтобы продолжить ";
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
    else cout << "Нет кс :( " << endl;
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
    int m;                                                                             // создали меню

    unordered_map <int, Pipe> Pipeline = {};
    unordered_map <int, CS> CSline = {};

    {
        setlocale(0, "");                                                              //русский язык  
    }

    for (;;) {
        cout << "\n 1.Выход"
             << "\n 2. Добавить трубу"
             << "\n 3. Добавить кс"
             << "\n 4. Показать все объекты"
             << "\n 5. Изменить трубы"
             << "\n 6. Изменить кс"
             << "\n 7. Сохранить"
             << "\n 8. Загрузить\n";
        
        m = ProvNumber(1,8);
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
                cout << "Трубы: " << endl;
                PrintePipe(Pipeline);
            }
            else cout << " Нет труб :( " << endl;
            if (CSline.size() != 0)
            {
                cout << " Станции: " << endl;
                PrinteCS(CSline);
            }
            else cout << " Нет кс :( " << endl;
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
            cout << "Введите имя файла: " << endl;
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
                    cout << "Сохранено";
                }
                fout.close();

            break;
        }
        case 8:
        {
            system("cls");
            string name;
            cout << "Введите имя файла: " << endl;
            cin.ignore(23456, '\n');
            getline(cin, name);
            ifstream fin;
            fin.open(name, ios::in);
            if (fin.is_open())
                Load(Pipeline, CSline, fin);
            cout << "Загружено";
            fin.close();
            break;
        }
      
        }

    }
    return 0;
    }
