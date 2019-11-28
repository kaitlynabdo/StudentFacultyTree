#include <iostream>
#include <list>
#include "Faculty.h"
using namespace std;

Faculty::Faculty() : Person::Person(){}
Faculty::Faculty(int i, string n, string l, string s, list<int>* list) : Person::Person(i, n, l, s){
    advisees = list;
}
Faculty::~Faculty(){
    advisees -> clear();
}
void Faculty::addToList(int i){
    advisees -> push_front(i);
}
void Faculty::deleteFromList(int i){
    if(!advisees -> empty()){
        advisees -> remove(i);
    }
    else{
        cout << "Advisee list is empty!" << endl;
    }
}

void Faculty::setList(list<int>* list){
    advisees = list;
}
list<int>* Faculty::getList(){
    return advisees;
}

void Faculty::printInfo(){
    cout << "Faculty ID: " << id << endl;
    cout << "Faculty name: " << name << endl;
    cout << "Faculty level: " << level << endl;
    cout << "Faculty department: " << specialty << endl;
}

bool operator== (const Faculty &f1, const Faculty &f2) {
    return (f1.id == f2.id);
}

bool operator!= (const Faculty &f1, const Faculty &f2) {
    return (f1.id != f2.id);
}

bool operator> (const Faculty &f1, const Faculty &f2) {
    return (f1.id > f2.id);
}

bool operator< (const Faculty &f1, const Faculty &f2) {
    return (f1.id < f2.id);
}
