#include "pch.h"
#include "Pipe.h"
#include <ostream>

using namespace std;
int Pipe::MaxID = 0;

Pipe::Pipe()
{
	id = ++MaxID;
	d = 0;
	l = 0;
	r = 0;
}

template <typename T>

T ProvNumber(T min, T max)   //proverka
{
    T num;
    while ((cin >> num).fail() || num < min || num > max)
    {
        cin.clear();
        cin.ignore(20000, '\n');
        cout << "������� ����� " << min << "-" << max << " ";
    }
    return num;
}

istream& operator >> (istream& in, Pipe& p)
{
    cout << "������� �������: ";
    p.d = ProvNumber(400, 2000);
    cout << "������� �����: ";
    p.l = ProvNumber(10, 1234);
    p.r = 0;
    return in;
}

std::ofstream& operator<<(std::ofstream& fout, const Pipe& p)
{
    if (fout.is_open())
    {
        fout << p.id << endl
            << p.d << endl
            << p.l << endl
            << p.r << endl;
   }
    return fout;
}

std::ifstream& operator>>(std::ifstream& fin, Pipe& p)
{
    if (fin.is_open())
    {
        fin >> p.id;
        fin >> p.d;
        fin >> p.l;
        fin >> p.r;
 }
    return fin;
}

ostream& operator << (ostream& out, const Pipe& p)
{
        cout << " ����� ��� �������: " << p.id << "  �������: " << p.d << " �� " << " �����: " << p.l << " ��\n";
        cout << " ����� � �������: " << p.r << endl;
    return out;
}


