#include <iostream>
#include <list>
#include <stack>
#include <deque>
#include "BST.h"
#include "Student.h"
#include "Faculty.h"
#ifndef MENU_H
#define MENU_H
using namespace std;

class Menu{
public:
    Menu();
    ~Menu();
    void menuExecute();
    bool findStudent(int id);
    bool findStudentGivenAdvisor(int id);
    bool findFaculty(int id);
    void rollbackFunc();

private:
    BST<Student> *masterStudent;
    BST<Faculty> *masterFaculty;
    deque<Student> stuDeque;
    deque<Faculty> facDeque;
    deque<char> rollback;
};

#endif
