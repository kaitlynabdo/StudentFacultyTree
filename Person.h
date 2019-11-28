#include <iostream>
using namespace std;
#ifndef PERSON_H
#define PERSON_H

class Person {
    public:
        Person();
        Person(int i, string n, string l, string s);
        ~Person();
        int getID();
        void setID(int i);
        string getName();
        void setName(string n);
        string getLevel();
        void setLevel(string l);
        string getSpecialty();
        void setSpecialty(string s);

        int id;
        string name;
        string level;
        string specialty; //major vs department
};
#endif
