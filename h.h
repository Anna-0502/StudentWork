#ifndef FURNITURE_H
#define FURNITURE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Furniture{
    private:
        string name;
        string color;
        int number;
        int id;
    public:
        Furniture(): name(""), color(""), number(0), id(0){}
        Furniture(string n, string c, int num, int i): name(n), color(c), number(num), id(i){}

    string getName() const {return name;}
    string getColor() const {return color;}
    int getNumber() const {return number;}
    int getId() const {return id;}

    void setName(string n) {name = n;}
    void setColor(string c) {color = c;}
    void setNumber(int num) {number = num;}

    friend ostream&operator<<(ostream&out, const Furniture&furniture);
    friend istream&operator>>(istream&in, Furniture&arr);
};

class Func{
    private:
        Furniture*arr;
        int capacity;
        int count;
        string filename;
        static int nextID;

        void size();
    public:
        Func(string file);
        ~Func();
        void load();
        void save();
        void add(Furniture ar);
        void display() const;
        void erase(int id);
        void edit(int id);
        void search(int number, string name) const;
};

void menu();

#endif