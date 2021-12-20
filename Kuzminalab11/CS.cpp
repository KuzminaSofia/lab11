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
    col_pipe = 0;
    connection = false;
}
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



istream& operator >> (istream& in, CS& station)
{
    cout << "Введите имя кс: ";
    cin >> ws;
    getline(cin, station.name);
    cout << "Сколько цехов в станции? ";                                                 // сколько цехов в станции?
    station.col_cex = ProvNumber(0, INT_MAX);
    cout << "Сколько цехов в работе? ";                                                  // сколько цехов в работе?
    station.col_work = ProvNumber(0, station.col_cex);
    station.effic = (double(station.col_work) / double(station.col_cex))*100;
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
            << station.effic << endl
            << station.connection << endl;
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
        fin >> station.effic;
        fin >> station.connection;
}
    return fin;
}
ostream& operator << (ostream& out, const CS& station)
{
        cout << " Номер кс: " << station.id << " Имя: " << station.name << " Количество цехов: " << station.col_cex << " Количество цехов в работе: " << station.col_work << " Эффективность: " << station.effic << " %" << endl;
    return out;
}

void CS::redact()
{
    cout << " Сколько цехов в работе на станции сейчас? " << endl;
    col_work = ProvNumber(0, col_cex);
    effic = (double(col_work) / double(col_cex)) * 100;
}
void CS::link()
{
    if (connection == false)
        connection == true;
    if (col_pipe < col_work)
        col_pipe++;
    else cout << " Недостаточно рабочих цехов в станции" << endl;
}

void CS::ClearLink()
{
    connection = false;
}
