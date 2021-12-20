#include "pch.h"
#include "Pipe.h"
#include <ostream>
#include <string>

using namespace std;
int Pipe::MaxID = 0;

Pipe::Pipe()
{
	id = ++MaxID;
	d = 0;
	l = 0;
	r = 0;
    name = "";
    pin = 0;
    pout = 0;
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
    cout << "������� ��� �����: ";
    cin >> ws;
    getline(cin, p.name);
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
            << p.name << endl
            << p.d << endl
            << p.l << endl
            << p.r << endl
            << p.pin << endl
            << p.pout << endl;
   }
    return fout;
}

std::ifstream& operator>>(std::ifstream& fin, Pipe& p)
{
    if (fin.is_open())
    {
        fin >> p.id;
        fin >> ws;
        getline(fin, p.name);
        fin >> p.d;
        fin >> p.l;
        fin >> p.r;
        fin >> p.pin;
        fin >> p.pout;
 }
    return fin;
}

ostream& operator << (ostream& out, const Pipe& p)
{
        cout << " ����� ��� �������: " << p.id << " ��� ����� " << p.name << "  �������: " << p.d << " �� " << " �����: " << p.l << " ��\n";
        cout << " ����� � �������: " << p.r << endl;
    return out;
}

void Pipe::redact()
{
    r = !r;
}

void Pipe::link(int in, int out)
{
    if (pin == 0 && pout == 0 && in != out)
    {
        pin = in;
        pout = out;
    }
    else cout << "hyuna" << endl;
}

void Pipe::ClearLink()
{
    pin = 0;
    pout = 0;
}


