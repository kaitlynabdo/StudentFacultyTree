#include <iostream>
#include <list>
#include <stack>
#include <deque>
#include <fstream>
#include "Menu.h"
#include "BST.h"
#include "Student.h"
#include "Faculty.h"
#include "TreeNode.h"
using namespace std;

Menu::Menu(){
    masterStudent = nullptr;
    masterFaculty = nullptr;
}

Menu::~Menu(){}

bool Menu::findStudent(int id){ // making sure the student exists
    Student s;
    s.setID(id);
    return masterStudent->search(s);
}

bool Menu::findStudentGivenAdvisor(int id){ // finding student with that advisor
    Student s;
    s.setAdvisor(id);
    return masterStudent->search(s);
}


bool Menu::findFaculty(int id){// making sure the faculty exists
    Faculty f;
    f.setID(id);

    return masterFaculty->search(f);
}

void Menu::rollbackFunc(){
    if(rollback.empty())
        cout << "Rollback is empty. No changes were made." << endl;

    else if(rollback.front() == 's'){ // most recent change was a student change
        Student s = stuDeque.front();
        if(findStudent(s.getID()) == false){ // if its not in the tree, it must have been deleted
            masterStudent -> insert(s); // reinsert
            stuDeque.pop_front();
        }
        else{
            masterStudent -> deleteNode(s); // if it was present, delete it
            stuDeque.pop_front();
        }
        rollback.pop_front();
    }

    else if(rollback.front() == 'f'){ // most recent change was a faculty change
        Faculty f = facDeque.front();
        if(findFaculty(f.getID()) == false){ // not in tree, it was deleted
            masterFaculty -> insert(f); // reinsert
            facDeque.pop_front();
        }
        else{
            masterFaculty -> deleteNode(f); // delete the node that was just added
            facDeque.pop_front();
        }
        rollback.pop_front();
    }
}

void Menu::menuExecute(){
    //menu
    while(true){
        char selection = ' ';
        cout << "Please select from the following options. Enter the number of the operation you wish to complete:" << endl;
        cout << "1. Print all students and their information (sorted by ascending id #)" << endl;
        cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
        cout << "3. Find and display student information given the students id" << endl;
        cout << "4. Find and display faculty information given the faculty id" << endl;
        cout << "5. Given a student’s id, print the name and info of their faculty advisor" << endl;
        cout << "6. Given a faculty id, print ALL the names and info of his/her advisees." << endl;
        cout << "7. Add a new student" << endl;
        cout << "8. Delete a student given the id" << endl;
        cout << "9. Add a new faculty member" << endl;
        cout << "10. Delete a faculty member given the id." << endl;
        cout << "11. Change a student’s advisor given the student id and the new faculty id." << endl;
        cout << "12. Remove an advisee from a faculty member given the ids" << endl;
        cout << "13. Rollback" << endl;
        cout << "14. Exit" << endl;

        cin >> selection;

        if (selection == 1){
            masterStudent -> printTree();
        }
        else if (selection == 2){
            masterFaculty -> printTree();
        }
        else if (selection == 3){
            int idS = 0;
            cout << "Please enter in a student id: " << endl;
            cin >> idS;
            if(findStudent(idS) == true){ // ensure it exists
                Student s;
                s.setID(idS);
                Student st = masterStudent -> searchObject(s); // get student from tree
                st.printInfo(); // print the info
            }
            else{
                cout << "No student found." << endl;
            }

        }
        else if (selection == 4){
            int idF = 0;
            cout << "Please enter in a faculty id: " << endl;
            cin >> idF;
            if(findFaculty(idF) == true){ // ensure faculty exists
                Faculty f;
                f.setID(idF);
                Faculty fac = masterFaculty -> searchObject(f); // get faculty
                fac.printInfo(); // print info
            }
            else{
                cout << "No faculty found." << endl;
            }
        }
        else if (selection == 5){
            int idS = 0;
            cout << "Please enter in a student id: " << endl;
            cin >> idS;
            int advisor = 0;
            if(findStudent(idS) == true){
                Student s;
                s.setID(idS);
                Student st = masterStudent -> searchObject(s);
                advisor = st.getAdvisor(); // get the id from the student
            }
            if(findFaculty(advisor) == true){ // ensure faculty exists
                Faculty f;
                f.setID(advisor);
                Faculty fac = masterFaculty -> searchObject(f); // get faculty
                fac.printInfo(); // print info
            }
            else{
                cout << "No student found." << endl;
            }
        }
        else if (selection == 6){

        }
        else if (selection == 7){
            int idS = 0, idF = 0;
            string nameS = "", levelS = "", major = "";
            double gpa = 0.0;
            cout << "Please enter in a student id: " << endl;
            cin >> idS;
            cout << endl;
            cout << "Please enter in a student name: " << endl;
            cin >> nameS;
            cout << endl;
            cout << "Please enter in a student's year: " << endl;
            cin >> levelS;
            cout << endl;
            cout << "Please enter in a student's major: " << endl;
            cin >> major;
            cout << endl;
            cout << "Please enter in a student's GPA: " << endl;
            cin >> gpa;
            cout << endl;

            cout << "Please enter in the student's advisor's id: " << endl;
            cin >> idF;

            Student* s = new Student(idS, nameS, levelS, major, gpa, idF); // creating new student
            masterStudent->insert(*s);
            if(rollback.size() == 5){
                rollback.pop_back();
            }
            stuDeque.push_front(*s);
            rollback.push_front('s');
        }
        else if (selection == 8){
             int id = 0;
             cout << "Enter the ID of the student you would like to delete: " << endl;
             cin >> id;
             cout << endl;
             while(findStudent(id) == false) {    //id doesnt exist
                  cout << "Student not found. Please enter in a new student ID:" << endl;
                  cin >> id;
                  cout << endl;
             }
             Student s;
             s.setID(id);
             Student st = masterStudent -> searchObject(s);

             if(rollback.size() == 5){
                 rollback.pop_back();
             }
             stuDeque.push_front(st);
             rollback.push_front('s');


             if(masterStudent -> deleteNode(st))
                  cout << "Student was deleted." << endl;

        }
        else if (selection == 9){
            int idF = 0;
            string nameF = "", levelF = "", dept = "";

            cout << "Please enter in a faculty id: " << endl;
            cin >> idF;
            cout << endl;
            cout << "Please enter in a faculty name: " << endl;
            cin >> nameF;
            cout << endl;
            cout << "Please enter in a faculty's level: " << endl;
            cin >> levelF;
            cout << endl;
            cout << "Please enter in a faculty's department: " << endl;
            cin >> dept;
            cout << endl;
            Faculty f;
            f.setName(nameF);
            f.setID(idF);
            f.setLevel(levelF);

            int ans;
            list<int>* advisees; //creating the list of ids
            while(ans != 0){
                cout << "Enter the faculty's advisee ID numbers." << endl;
                cout << "When completed, type 0." << endl;
                cin >> ans;
                cout << endl;
                if (ans != 0)
                    advisees -> push_front(ans);
            }
            f.setList(advisees);
            masterFaculty -> insert(f);
            cout << "Faculty inserted." << endl;

            if(rollback.size() == 5){
                rollback.pop_back();
                facDeque.pop_back();
            }
            facDeque.push_front(f);
            rollback.push_front('f');

        }
        else if (selection == 10){ //delete faculty member
            int id = 0, newID = 0;
            cout << "Enter the ID of the faculty you would like to delete: " << endl;
            cin >> id;
            cout << endl;
            while(findFaculty(id) == false) {    //id doesnt exist
                 cout << "Faculty not found. Please enter in a new faculty ID:" << endl;
                 cin >> id;
                 cout << endl;
            }
            Faculty f;
            f.setID(id);
            Faculty fac = masterFaculty -> searchObject(f);

            if(rollback.size() == 5){ // updating rollback
                rollback.pop_back();
                facDeque.pop_back();
            }
            facDeque.push_front(fac);
            rollback.push_front('f');

            if(masterFaculty -> deleteNode(fac))
                 cout << "Faculty was deleted." << endl;


            cout << "The faculty deleted was assigned to a student. Please enter the ID for a new advisor: " << endl;
            cin >> newID;
            cout << endl;
            while (findStudentGivenAdvisor(id) == true){
                Student s;
                s.setAdvisor(newID);
                Student st = masterStudent -> searchObject(s);
                st.setAdvisor(newID);
            }
            cout << "All students have been updated with the new advisor." << endl;
        }
        else if (selection == 11){ // change student's faculty given both ids
            int idS = 0;
            cout << "Please enter in a student id: " << endl;
            cin >> idS;
            int idF = 0;
            cout << "Please enter in the new faculty id: " << endl;
            cin >> idF;

            if(findStudent(idS) == true){ // ensure it exists
                Student s;
                s.setID(idS);
                Student st = masterStudent -> searchObject(s); // get student from tree
                st.setAdvisor(idF);
            }
            else{
                cout << "No student found." << endl;
            }
            cout << "Student's advisor was updated." << endl;
        }
        else if (selection == 12){ // remove advisee from faculty
            int idF = 0;
            cout << "Please enter in the faculty id: " << endl;
            cin >> idF;
            int idA = 0;
            cout << "Please enter in the advisee id you would like to remove: " << endl;
            cin >> idA;

            if(findFaculty(idF) == true){ // ensure it exists
                Faculty f;
                f.setID(idF);
                Faculty fac = masterFaculty -> searchObject(fac); // get student from tree
                fac.deleteFromList(idA);
            }
            else{
                cout << "No faculty found." << endl;
            }
            cout << "Faculty's advisor was deleted." << endl;
        }
        else if (selection == 13){//rollback
            rollbackFunc();
        }
        else if (selection == 14){
            break;
        }
    }
}
