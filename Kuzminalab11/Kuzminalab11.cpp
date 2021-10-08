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
    int col_cex;                                                                               // количество цехов
    int col_work;                                                                              // количество в работе 
    double effic;                                                                              // эффективность
};


void PrintePipe(Pipe& p)
{
    cout << " Труба под номером: " << p.id << "  Диаметр: " << p.d << " мм " << " Длина: " << p.l << " км\n" ;
    cout << " Труба в ремонте: " << p.r <<endl;
}

void PrinteCS(CS& station)
{
    cout << " Номер кс: " << station.id << " Имя: " << station.name << " Количество цехов: " << station.col_cex << " Количество цехов в работе: " << station.col_work;
}

Pipe AddPipe()
{
    Pipe p;
    p.id = 0;
    cout << "Введите диаметр: ";
    cin >> p.d; 
    while (p.d < 400 || p.d > 2000)
    {
        cout << "ВВедите число из промежутка [400;2000] mm \n";
        cin >> p.d;
    }
    cout << "Введите длину: ";
    cin >> p.l;
    while (p.l < 10 || p.l > 100)
    {
        cout << "Введите число из промежутка [10;100] km \n";
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
    cout << "Введите имя кс ";
    cin >> station.name;
    cout << "Сколько цехов в станции? ";                                                  // сколько цехов в станции?
    cin >> station.col_cex;
    cout << "Сколько цехов в работе? ";                                                   // сколько цехов в работе?
    cin >> station.col_work;

    while (station.col_work > station.col_cex)
    {
        cout << "Количество рабочих больше чем всего цехов. Пожалуйста, введите новое значение: ";
        cin >> station.col_work;
    }
    return station;

}  
void editpipe(Pipe& p)                                                                  //редактор трубы
{
    if (p.l > 1)                                                                        //существует
    {
        cout << "Если труба в работе нажмите - 0, если в ремонте - 1 \n";               //не работает ничего кроме 1 и 0, вылетает прога
        cin >> p.r;
    //  while (p.r != 0 || p.r != 1)
    //  {
    //      cout << "Введите 1 или 0 ";
    //      cin >> p.r;
    // }
    }
    else cout << "Добавьте трубу";
}

void editcs(CS& station)                                                                 //редактор компрессорной станции
{
    if (station.col_cex > 0)
    {
        cout << "Сколько цехов в работе сейчас?";
        cin >> station.col_work;
        while (station.col_work > station.col_cex)                                      //проверка на количество рабочих цехов в редакторе
        {
            cout << "Количество рабочих больше чем всего цехов. Пожалуйста, введите новое значение: \n";
            cin >> station.col_work;
        }

    }
    else cout << "Добавьте цех";

}

void Save(Pipe p, CS station)                                                          //сохранение в файл
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
        cout << "Сохранено\n";
    }

}





int main()
{

    int m;                                                                             // создали меню

    Pipe p = {};
    CS station = {};

    {
        setlocale(0, "");                                                              //русский язык  
    }

    for (;;) {
        cout << "\n 1. Выход\n 2. Добавить трубу\n 3. Добавить кс\n 4. Показать все объекты\n 5. Редактировать трубу\n 6. Редактировать кс\n 7. Сохранить\n 8. Загрузить\n";
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
