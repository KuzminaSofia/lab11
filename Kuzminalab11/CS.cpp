#include "pch.h"
#include "CS.h"
#include <ostream>
#include <string>

using namespace std;
int CS::MaxID = 0;

CS::CS()
{
	id = ++MaxID;
	name = "";
	col_cex = 0;
	col_work = 0;
	effic = 0;
}
template <typename T>

T ProvNumber(T min, T max)   //proverka
{
    T num;
    while ((cin >> num).fail() || num < min || num > max)
    {
        cin.clear();
        cin.ignore(20000, '\n');
        cout << "������� ����� �� " << min << "�� " << max;
    }
    return num;

}

istream& operator >> (istream& in, CS& station)
{
    cout << "������� ��� ��: ";
    cin >> ws;
    getline(cin, station.name);
    cout << "������� ����� � �������? ";                                                 // ������� ����� � �������?
    station.col_cex = ProvNumber(0, INT_MAX);
    cout << "������� ����� � ������? ";                                                  // ������� ����� � ������?
    station.col_work = ProvNumber(0, station.col_cex);
    cout << "������������� ����: ";
    station.effic = ProvNumber(0.0, 100.0);
    return in;
}
std::ofstream& operator<<(std::ofstream& fout, const CS& station)
{
    if (fout.is_open())
    {
        fout << station.id << endl
            << station.name << endl
            << station.col_cex << endl
            << station.col_work << endl
            << station.effic << endl;
    }
    return fout;
}
std::ifstream& operator>>(std::ifstream& fin, CS& station)
{
    if (fin.is_open())
    {
        fin >> station.id;
        fin >> ws;
        getline(fin, station.name);
        fin >> station.col_cex;
        fin >> station.col_work;
}
    return fin;
}
ostream& operator << (ostream& out, const CS& station)
{
        cout << " ����� ��: " << station.id << " ���: " << station.name << " ���������� �����: " << station.col_cex << " ���������� ����� � ������: " << station.col_work << " �������������: " << station.effic << " %" << endl;
    return out;
}

void CS::redact()
{
    cout << "������� ����� � ������ �� ������� ������?" << endl;
    col_work = ProvNumber(0, col_cex);
}