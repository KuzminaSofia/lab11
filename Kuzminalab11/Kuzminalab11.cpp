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
            cout << "Введите число от " << min << "до" << max ;
        }
        return num;
          
}

string ProvStr()
{
    while (1)
    {
        cin >> ws;
        string str;
        getline(cin, str);
        return str;
    }
}



//void PrintePipe( const Pipe& p)
//{
//    if (p.l > 1)
//    {
//    cout << " Труба под номером: " << p.id << "  Диаметр: " << p.d << " мм " << " Длина: " << p.l << " км\n" ;
//    cout << " Труба в ремонте: " << p.r << endl; }
//    else
//    {
//        cout << "  Нет трубы \n";
//    }
//}

//void PrinteCS( const CS& station)
//{
//    if (station.col_cex > 0)
//    {
//        cout << " Номер кс: " << station.id << " Имя: " << station.name << " Количество цехов: " << station.col_cex << " Количество цехов в работе: " << station.col_work << " Эффективность: " << station.effic << " %";
//    }
//    else
//    {
//        cout << "  Нет компрессорной станции \n";
//    }
//    
//}

//Pipe AddPipe()
//{
//    Pipe p;
//    p.id = 0;
//    cout << "Введите диаметр: ";
//    p.d = ProvNumber(400,2000);
//    cout << "Введите длину: ";
//    p.l = ProvNumber(10,1234);
//    p.r = 0;
//    return p;
//}

//void AddPipeVector(Pipe& p, int& pipe_id, std::unordered_map<int, Pipe>& Pipeline)
//{
//    p = AddPipe();
//    pipe_id++;
//    p.id = pipe_id;
//    Pipeline.insert({ pipe_id, p });
//}

//void PrintPipeline(std::unordered_map<int, Pipe>::iterator& pipe_iter, std::unordered_map<int, Pipe>& Pipeline)
//{
//    cout << "Pipeline:\n ";
//    pipe_iter = Pipeline.begin();
//    for (int i = 0; pipe_iter != Pipeline.end(); pipe_iter++)
//    {
//        cout << " id: " << pipe_iter->second.id << " Диаметр: " << pipe_iter->second.d << " Длина: " << pipe_iter->second.l << " Ремонт: " << pipe_iter->second.r << endl;
//
//    }
//
//
//
//}


//CS AddCS()
//{
//    CS station;
//    station.id = 0;
//    cout << "Введите имя кс ";
//    cin >> ws;
//    getline(cin, station.name);
//    cout << "Сколько цехов в станции? ";                                                 // сколько цехов в станции?
//    station.col_cex = ProvNumber(0,INT_MAX);
//    cout << "Сколько цехов в работе? ";                                                  // сколько цехов в работе?
//    station.col_work = ProvNumber(0, station.col_cex);
//    cout << "Эффективность цеха";
//    station.effic = ProvNumber(0.0,100.0);
//    return station;
//}  

//void AddCSVector(CS& station, int& cs_id, std::unordered_map<int, CS>& CSline)
//{
//    station = AddCS();
//    cs_id++;
//    station.id = cs_id;
//    CSline.insert({ cs_id, station });
//}

//void PrintCSline(std::unordered_map<int, CS>::iterator& cs_iter, std::unordered_map<int, CS>& CSline)
//{
//    cout << "CSline:\n ";
//    cs_iter = CSline.begin();
//    for (int i = 0; cs_iter != CSline.end(); cs_iter++)
//    {
//        cout << " Номер кс: " << cs_iter->second.id << " Имя: " << cs_iter->second.name << " Количество цехов: " << cs_iter->second.col_cex << " Количество цехов в работе: " << cs_iter->second.col_work << endl;
//
//    }
//}

template <typename T>
using Filter = bool(*)(const CS& station, T param);
bool CheckByName(const CS& station, string param)
{
    return station.name == param;
}

template <typename T>
vector <int> FindCSByFilter(const vector<CS>& CSline, Filter <T> filter, T param)
{
    vector <int> result;
    int i = 0;
    for (auto& station : CSline)
    {
        if (filter(station, param))
            result.push_back(i);
        i++;
    }
    return result;
}

void editpipe(Pipe& p)                                                                  //редактор трубы
{
    if (p.l > 1)                                                                        //существует
    {
        
        cout << "Если труба в работе нажмите - 0, если в ремонте - 1 \n";               //не работает ничего кроме 1 и 0, вылетает прога
        p.r = ProvNumber(0,1);
    }
    else cout << "Добавьте трубу";
}

void editcs(CS& station)                                                                 //редактор компрессорной станции
{
    if (station.col_cex > 0)
    {
        cout << "Сколько цехов в работе сейчас?";
        station.col_work = ProvNumber(0,station.col_cex);
        cout << "Изм эфф";
        station.effic = ProvNumber(0.0,100.0);

    }
    else cout << "Добавьте цех";

}

//void Save( const Pipe& p, const CS& station)                                                          //сохранение в файл
//{
//    ofstream file;
//    file.open("savep.txt");
//    if (file.good())
//    {
//        if (p.l > 1)
//        {
//            file << "Pipe" << endl;
//            file << p.id << endl;
//            file << p.d << endl;
//            file << p.l << endl;
//            file << p.r << endl;
//        }
//        if (station.col_cex > 0)
//        {
//            file << "CS" << endl;
//            file << station.id << endl;
//            file << station.name << endl;
//            file << station.col_cex << endl;
//            file << station.col_work << endl;
//            file << station.effic << endl;
//        }
//        file.close();
//        cout << "Сохранено\n";
//    }
//    else {
//        cout << "переделывай";
//    }
//
//}

void Savepipe(ofstream& file, const Pipe& p)
{
    if (p.l > 1)
    {
          file << p.id << endl
            << p.d << endl
            << p.l << endl
            << p.r << endl;
    }
}

void Savestation(ofstream& file, const CS& station)
{
    if (station.col_cex > 0) 
    {
        file << station.id << endl
            << station.name << endl
            << station.col_cex << endl
            << station.col_work << endl
            << station.effic << endl;

    }
}

Pipe Doloadp(ifstream& file)
{
    Pipe p;
    file >> p.id;
    file >> p.l;
    file >> p.d;
    file >> p.r;
    return p;

}

CS Doloadstation(ifstream& file)
{
    CS station;
    file >> station.id;
    file.ignore(1000, '\n');
    getline(file, station.name);
    file >> station.col_cex;
    file >> station.col_work;
    return station;

}

//void Doload(Pipe& p, CS& station)
//{
//    ifstream file;
//    file.open("savep.txt");
//    if (file.good())
//    {
//        while (!file.eof())
//        {
//            string text;
//            file >> text;
//            cout << text << endl;
//            if (text == "Pipe")
//            {
//                file >> p.id;
//                file >> p.d;
//                file >> p.l;
//                file >> p.r;
//            }
//            if (text == "CS")
//            {
//                file >> station.id;
//                file.ignore(37873, '\n');
//                //string(station.name);
//                getline(file, station.name);
//                //file >> station.name;
//                file >> station.col_cex;
//                file >> station.col_work;
//                file >> station.effic;
//
//
//            }
//         
//
//        }
//
//        cout << "Загружено";
//    }
//
//}

//void DeletePipe(std::unordered_map<int, Pipe>::iterator& pipe_iter, std::unordered_map<int, Pipe>& Pipeline)
//{
//    cout << "Какую трубу Вы хотите удалить? (id)" << endl;
//    vector <int> idv;
//    int id;
//    id = ProvInt();
//    while (id != 0)
//    {
//        idv.push_back(id);
//        cout << "Нажмите 0 чтобы удалить или добавьте id";
//        id = ProvInt();
//    }
//    pipe_iter = Pipeline.begin();
//    for (int i = 0; i < idv.size(); i++)
//    {
//        pipe_iter = Pipeline.find(idv[i]);
//        Pipeline.erase(pipe_iter);
//    }
//    idv.clear();
//    cout << "Удалено" << endl;
//}

//void DeleteCS(std::unordered_map<int, CS>::iterator& cs_iter, std::unordered_map<int, CS>& CSline)
//{
//    cout << "Какую станцию Вы хотите удалить? (id)" << endl;
//    vector <int> csv;
//    int id;
//    id = ProvNumber();
//    while (id != 0)
//    {
//        csv.push_back(id);
//        cout << "Нажмите 0 чтобы удалить или добавьте id";
//        id = ProvInt();
//    }
//    cs_iter = CSline.begin();
//    for (int i = 0; i < csv.size(); i++)
//    {
//        cs_iter = CSline.find(csv[i]);
//        CSline.erase(cs_iter);
//    }
//    csv.clear();
//    cout << "Удалено" << endl;
//}

istream& operator >> (istream& in, Pipe& p)
{
     cout << "Введите диаметр: ";
     p.d = ProvNumber(400,2000);
     cout << "Введите длину: ";
     p.l = ProvNumber(10,1234);
     p.r = 0;
     return in;
}

istream& operator >> (istream& in, CS& station)
{
    cout << "Введите имя кс ";
    cin >> ws;
    getline(cin, station.name);
    cout << "Сколько цехов в станции? ";                                                 // сколько цехов в станции?
    station.col_cex = ProvNumber(0, INT_MAX);
    cout << "Сколько цехов в работе? ";                                                  // сколько цехов в работе?
    station.col_work = ProvNumber(0, station.col_cex);
    cout << "Эффективность цеха";
    station.effic = ProvNumber(0.0, 100.0);
    return in;
}

ostream& operator << (ostream& out, const Pipe& p)
{
    if (p.l > 1)
    {
        cout << " Труба под номером: " << p.id << "  Диаметр: " << p.d << " мм " << " Длина: " << p.l << " км\n";
        cout << " Труба в ремонте: " << p.r << endl;
    }
    else
    {
        cout << "  Нет трубы \n";
    }
    return out;
}

ostream& operator << (ostream& out, CS& station)
{
         if (station.col_cex > 0)
          cout << " Номер кс: " << station.id << " Имя: " << station.name << " Количество цехов: " << station.col_cex << " Количество цехов в работе: " << station.col_work << " Эффективность: " << station.effic << " %";
          else  cout << "  Нет компрессорной станции \n";
          
    return out;
}


int main()
{

    int m;                                                                             // создали меню

   /* Pipe p = {};
    CS station = {};

    unordered_map <int, Pipe> Pipeline = {};
    unordered_map <int, CS> CSline = {};

    unordered_map <int, Pipe> :: iterator pipe_iter = Pipeline.begin();
    unordered_map <int, CS> ::iterator cs_iter = CSline.begin();

    int pipe_id = 0;
    int cs_id = 0;*/

    vector<Pipe> Pipeline;
    vector<CS> CSline;

    {
        setlocale(0, "");                                                              //русский язык  
    }

    for (;;) {
        cout << "\n 1. Выход\n 2. Добавить трубу\n 3. Добавить кс\n 4. Показать все объекты\n 5. Редактировать трубу\n 6. Редактировать кс\n 7. Сохранить\n 8. Загрузить\n 9. Поиск кс по имени \n 10. Удалить кс\n";
        m = ProvNumber(1,10);
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
            Pipeline.push_back(p);
            /*AddPipeVector(p, pipe_id, Pipeline);*/
           // p = AddPipe();
            break;
        }

        case 3:
        {
            system("cls");
            CS station;
            cin >> station;
            CSline.push_back(station);
           /* AddCSVector(station, cs_id, CSline);*/
           // station = AddCS();
            break;
        }

        case 4:
        {
            system("cls");
            cout << "Трубы \n";
            for (int i = 0; i < Pipeline.size(); i++)
                cout << Pipeline[i] << endl;

            cout << "КС \n";
            for (int i = 0; i < CSline.size(); i++)
                cout << CSline[i] << endl;
           /* PrintPipeline(pipe_iter, Pipeline);
            PrintCSline(cs_iter, CSline);*/
            //PrintePipe(p);
            //PrinteCS(station);
            break;
        }

        case 5:
        {   system("cls");
            //editpipe(p);
            break;
        }

        case 6:
        {
            system("cls");
           // editcs(station);
            break;
        }
        case 7:
        {
            system("cls");

            ofstream file;
            file.open("C:\\Пользователи\\User\\Рабочий стол\\lab11\\lab11\\Kuzminalab11\\savep.txt", ios::out);
            if (file.good())
            {
                file << Pipeline.size() << endl;
                for (Pipe p : Pipeline)
                    Savepipe(file, p);

                file << CSline.size() << endl;
                for (CS station : CSline)
                    Savestation(file, station);

            }
            cout << "Сохранено" << endl;

            //Save(p, station);
            break;
        }
        case 8:
        {
            system("cls");
            ifstream file;
            file.open("savep.txt", ios::in);
            if (file.is_open())
            {
                int count1;
                file >> count1;
                while (count1--)
                    Pipeline.push_back(Doloadp(file));

                int count2;
                file >> count2;
                while (count2--)
                    CSline.push_back(Doloadstation(file));
                file.close();
            }

            //Doload(p, station);
            break;
        }
        case 9:
        {
            string name;
            cout << "enter name" << endl;
            cin >> name;
            for (int i : FindCSByFilter<string>(CSline, CheckByName, name))
                cout << CSline[i]<< endl;

            //DeletePipe(pipe_iter, Pipeline);
            break;
        }
        case 10:
        {
            //DeleteCS(cs_iter, CSline);
            break;
        }
        default:
            cout << "Введите пункт из меню";
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
