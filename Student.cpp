#include <iostream>
#include "Student.h"
using namespace std;

Student::Student() : Person::Person(){
    gpa = 0.0;
}
Student::~Student(){
}

Student::Student(int i, string n, string l, string s, double g, int a) : Person::Person(i, n, l, s){
    gpa = g;
    advisor = a;
}


double Student::getGPA(){
    return gpa;
}
void Student::setGPA(double g){
    gpa = g;
}
int Student::getAdvisor(){
    return advisor;
}
void Student::setAdvisor(int a){
    advisor = a;
}

void Student::printInfo(){
    cout << "Student ID: " << id << endl;
    cout << "Student name: " << name << endl;
    cout << "Student year: " << level << endl;
    cout << "Student major: " << specialty << endl;
    cout << "Student GPA: " << gpa << endl;
}
void Student::printAdvisor(){
    cout << "Student's advisor id: " << advisor << endl;
}

bool operator== (const Student &s1, const Student &s2) {
    return (s1.id == s2.id);
}

bool operator!= (const Student &s1, const Student &s2) {
    return (s1.id != s2.id);
}

bool operator> (const Student &s1, const Student &s2) {
    return (s1.id > s2.id);
}

bool operator< (const Student &s1, const Student &s2) {
    return (s1.id < s2.id);
}
