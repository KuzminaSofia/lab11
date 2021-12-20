#pragma once
#include <iostream>
#include <iostream>
#include <fstream>
class Pipe
{
    int id;
    int d;
    int l;
    bool r;
    std::string name;
    static int MaxID;
public:
    int pin, pout;
    Pipe();
    static void setMaxID(const int id) { MaxID = id; }
    static int getMaxID() { return MaxID; }
    int getId() const { return id; }

    int getD() const { return d; }
    int getL() const { return l; }
    bool getR() const { return r; }
    std::string getName() const { return name; }
    void redact();

    void link(int in, int out);
    void ClearLink();

    friend std::ostream& operator <<(std::ostream& out, const Pipe& p);
    friend std::istream& operator >>(std::istream& in, Pipe& p);

    friend std::ofstream& operator <<(std::ofstream& fout, const Pipe& p);
    friend std::ifstream& operator >>(std::ifstream& fin, Pipe& p);
};

