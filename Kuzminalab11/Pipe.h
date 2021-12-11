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
 
    Pipe();
    static void setMaxID(const int id) { MaxID = id; }
    static int getMaxID() { return MaxID; }
    int getId() { return id; }

    int getD() { return d; }
    int getL() { return l; }
    bool getR() { return r; }
    std::string getName() { return name; }
    void redact();

    friend std::ostream& operator <<(std::ostream& out, const Pipe& p);
    friend std::istream& operator >>(std::istream& in, Pipe& p);

    friend std::ofstream& operator <<(std::ofstream& fout, const Pipe& p);
    friend std::ifstream& operator >>(std::ifstream& fin, Pipe& p);
};

