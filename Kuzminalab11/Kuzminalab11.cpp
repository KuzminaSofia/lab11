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
    int col_cex; // количество цехов
    int col_work; // количество в работе 
    double effic; // эффективность
};


void PrintePipe(Pipe& p)
{
    cout << "Pipe ID number: " << p.id << "  Diameter: " << p.d << " mm " << " Lenght: " << p.l << " km \n" ;
    cout << "Pipe under repair: " << p.r<<endl;
}
void PrinteCS(CS& station)
{
    cout << "CS ID number: " << station.id << "Name: " << station.name << "Number of shops: " << station.col_cex << "Work: " << station.col_work;
}
Pipe AddPipe()
{
    Pipe p;
    p.id = 0;
    cout << "Enter the diameter ";
    cin >> p.d;
    cout << "Enter the lenght ";
    cin >> p.l;
    cout << "Is the pipe repaired?";
    cin >> p.r;
    return p;
}
CS AddCS()
{
    CS station;
    station.id = 0;
    cout << "Enter the name ";
    cin >> station.name;
    cout << "How many shops are there? "; // сколько цехов в станции?
    cin >> station.col_cex;
    cout << "How many shops do we have in the job? "; // сколько цехов в работе?
    cin >> station.col_work;
    return station;

}
int main()
{
    int m; // создали меню
    Pipe p;
    CS station;
    cout << "\n 1. Exit\n 2. Add pipe\n 3. Add CS\n 4. All objects\n ";
    cin >> m;
    switch (m)
    {
    case 1:
        return 0;
    case 2:
        p = AddPipe();
        break;
    case 3:
        station = AddCS();
        break;
    case 4:
        PrintePipe(p);
        PrinteCS(station);
        break;

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
