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
            cout << "Введите число от " << min << " до " << max << " ";
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


//template <typename T>
//using Filter = bool(*)(const CS& station, T param);
//bool CheckByName(const CS& station, string param)
//{
//    return station.name == param;
//}

//template <typename T>
//vector <int> FindCSByFilter(const vector<CS>& CSline, Filter <T> filter, T param)
//{
//    vector <int> result;
//    int i = 0;
//    for (auto& station : CSline)
//    {
//        if (filter(station, param))
//            result.push_back(i);
//        i++;
//    }
//    return result;
//}
//
//void editpipe(Pipe& p)                                                                  //редактор трубы
//{
//    if (p.l > 1)                                                                        //существует
//    {
//        
//        cout << "Если труба в работе нажмите - 0, если в ремонте - 1 \n";               //не работает ничего кроме 1 и 0, вылетает прога
//        p.r = ProvNumber(0,1);
//    }
//    else cout << "Добавьте трубу";
//}
//
//void editcs(CS& station)                                                                 //редактор компрессорной станции
//{
//    if (station.col_cex > 0)
//    {
//        cout << "Сколько цехов в работе сейчас?";
//        station.col_work = ProvNumber(0,station.col_cex);
//        cout << "Изм эфф";
//        station.effic = ProvNumber(0.0,100.0);
//
//    }
//    else cout << "Добавьте цех";
//
//}

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



int main()
{
    int m;                                                                             // создали меню

    unordered_map <int, Pipe> Pipeline = {};
    unordered_map <int, CS> CSline = {};

    {
        setlocale(0, "");                                                              //русский язык  
    }

    for (;;) {
        cout << "\n 1. Выход"
            << "\n 2. Добавить трубу"
            << "\n 3. Добавить кс"
            << "\n 4. Показать все объекты"
            << "\n 5. Редактировать трубу"
            << "\n 6. Редактировать кс"
            << "\n 7. Сохранить"
            << "\n 8. Загрузить"
            << "\n 9. Поиск кс по имени "
            << "\n 10. Удалить кс\n";
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
            if (CSline.size() != 0)
            {
                cout << "Станции: " << endl;
                PrinteCS(CSline);
            }
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
            string name;
            cout << "Введите имя файла: " << endl;
            cin.ignore(23456, '\n');
            getline(cin, name);
            ofstream fout;
            fout.open(name, ios::out)
                if (fout.is_open())
                {
                    if (Pipeline.size() != 0)
                        fout << Pipeline.size() << endl << Pipe::getMaxID() << endl;
                    else fout << 0 << endl << 0 << endl;
                }




            break;
        }
        case 8:
        {
           /* system("cls");
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
            }*/

            //Doload(p, station);
            break;
        }
        case 9:
        {
            /*string name;
            cout << "enter name" << endl;
            cin >> name;
            for (int i : FindCSByFilter<string>(CSline, CheckByName, name))
                cout << CSline[i]<< endl;*/

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
