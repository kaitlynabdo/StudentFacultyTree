#include <iostream>
#include "Person.h"
#include "Faculty.h"
#ifndef STUDENT_H
#define STUDENT_H


class Student : public Person{
    public:
        Student();
        Student(int i, string n, string l, string s, double g, int a);
        ~Student();
        double getGPA();
        void setGPA(double g);
        int getAdvisor();
        void setAdvisor(int a);
        void printInfo();
        void printAdvisor();

        friend bool operator== (const Student &s1, const Student &s2);
        friend bool operator< (const Student &s1, const Student &s2);
        friend bool operator> (const Student &s1, const Student &s2);
        friend bool operator!= (const Student &s1, const Student &s2);

    private:
        double gpa;
        int advisor;
};
#endif
