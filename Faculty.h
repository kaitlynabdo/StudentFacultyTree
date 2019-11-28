#include <iostream>
#include <list>
#include "Person.h"
#ifndef FACULTY_H
#define FACULTY_H


class Faculty : public Person{
    public:
        Faculty();
        Faculty(int i, string n, string l, string s, list<int>* list);
        ~Faculty();
        void setList(list<int>* list);
        list<int>* getList();
        void addToList(int i);
        void deleteFromList(int i);
        void printInfo();
        friend bool operator== (const Faculty &f1, const Faculty &f2);
        friend bool operator< (const Faculty &f1, const Faculty &f2);
        friend bool operator> (const Faculty &f1, const Faculty &f2);
        friend bool operator!= (const Faculty &f1, const Faculty &f2);


    private:
        list<int>* advisees;

};
#endif
