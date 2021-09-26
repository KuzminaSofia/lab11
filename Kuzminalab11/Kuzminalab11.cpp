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
    string r;
};


void PrintePipe(Pipe& p)
{
    cout << "Pipe ID number: " << p.id << "  Diameter: " << p.d << " mm " << " Lenght: " << p.l << " km \n" ;
    cout << "Pipe under repair: " << p.r;
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

int main()
{
    Pipe p = AddPipe();
    PrintePipe(p);
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
