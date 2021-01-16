/*
 * Main.cpp
 * Implementation of Main class
 * Author: Billy Wolf
 * Created: May 5, 2019
 * Current: May 8, 2019
 *
 * Compile with:
 * g++ -c -std=c++11 main.cpp
 * g++ -o prog.exe main.o
 * ./prog.exe
 * 
 * Creates a student information database where users can add/delete students
 * view and find the information for each student and sort the students by
 * certain categories
 */

#include "dll.h"
#include "student.h"
#include <string>
#include <iostream>

using namespace std;


int main(){
    student newStudent;
    list<student> myList;
    string input, end = "a";
    bool valid = true;
    int id, years, num;
    double gpa;
    
    while (end != "Quit"){ //menu
    cout << "====================================" << endl;
    cout << "Student Information Database Menu" << endl;
    cout << "====================================" << endl;
    cout << "V - View Student Information Database" << endl;
    cout << "F - Find Student Information by Student" << endl;
    cout << "S - Sort Student" << endl;
    cout << "A - Add Student" << endl;
    cout << "D - Delete a Student" << endl;
    cout << "Q - Quit the program" << endl;
    
    cin >> input;
    
    //options for the menu
    
    if (input == "V" || input == "v"){
        myList.DisplayList();
    }else if (input == "F" || input == "f"){ //calls the FindStudent function
        cout << "Enter a student name to find " << endl;
        cin >> input;
        myList.FindStudent(input);
    }else if (input == "S" || input == "s"){ //calls the sort function
        myList.Sort();
    }else if (input == "A" || input == "a"){ //calls the insert function
        cout << "Enter Student information: " << endl;
        cout << "Name: " << endl;
        if(!(cin >> input)){
            cout << "Invalid input, must enter a string" << endl;
            break;
        }
        cout << "ID: " << endl;
        if(!(cin >> id)){
            cout << "Invalid input, must enter a integer" << endl;
            break;
        }
        cout << "Years in School: " << endl;
        if(!(cin >> years)){
            cout << "Invalid input, must enter a integer" << endl;
            break;
        }
        cout << "GPA: " << endl;
        if(!(cin >> gpa)){
            cout << "Invalid input, must enter a double" << endl;
            break;
        }
        newStudent.setName(input);
        newStudent.setID(id);
        newStudent.setSchool(years);
        newStudent.setGPA(gpa);
        
        myList.Insert(newStudent);
    }else if (input == "D" || input == "d"){ //calls the remove function
        cout << "What is the number of the student to remove: " << endl;
        cin >> num;
        myList.Remove(num);
    }else if (input == "Q" || input == "q"){ //quits the loop
        break;
    }else{
            cout << "Invalid input, try again. " << endl;
        }
    
    }
    
    return 0;
}