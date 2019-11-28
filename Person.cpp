
#include <iostream>
#include "Person.h"
using namespace std;

Person::Person(){
    id = 0;
    name = "";
    level = "";
    specialty = "";
}
Person::Person(int i, string n, string l, string s){
    id = i;
    name = n;
    level = l;
    specialty = s;
}

Person::~Person(){}

int Person::getID(){
    return id;
}
void Person::setID(int i){
    id = i;
}
string Person::getName(){
    return name;
}
void Person::setName(string n){
    name = n;
}
string Person::getLevel(){
    return level;
}
void Person::setLevel(string l){
    level = l;
}

string Person::getSpecialty(){
    return specialty;
}
void Person::setSpecialty(string s){
    specialty = s;
}
