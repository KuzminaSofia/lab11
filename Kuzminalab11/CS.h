#pragma once
#include <string>
#include <iostream>
#include <fstream>
class CS
{
int id;
std::string name;
int col_cex;
int col_work;
double effic;
static int MaxID;

public:
    CS();
    static void setMaxID(const int id) { MaxID = id; }
    static int getMaxID() { return MaxID; }
    int getId() { return id; }

    int getCex() { return col_cex; }
    int getWork() { return col_work; }
    double getEffic() { return effic; }
    std::string getName() { return name; }
    void redact();

    friend std::ostream& operator <<(std::ostream& out, const CS& station);
    friend std::istream& operator >>(std::istream& in, CS& station);

    friend std::ofstream& operator <<(std::ofstream& fout, const CS& station);
    friend std::ifstream& operator >>(std::ifstream& fin, CS& station);
};

