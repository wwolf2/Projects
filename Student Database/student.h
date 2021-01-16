/*
 * student.h
 * Implementation of student class
 * Author: Billy Wolf
 * Created: May 5, 2019
 * Current: May 8, 2019
 */

#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;


class student{
    
public:
    student(); 
    student(string, int , int , double);
    void setName(string);
    void setID(int);
    void setSchool(int);
    void setGPA(double);
    string name;
    int id;
    int school;
    double GPA;
    
};

student::student(){ //constructor
 name = "";
 id = 0;
 school = 0;
 GPA = 0.0;
    
}

student::student(string n, int i, int s, double g){ //nondefault constructor
    name = n;
    id = i;
    school = s;
    GPA = g;
    
}

 //set functions
void student::setName(string n){
    name = n;
}
void student::setID(int num){
    id = num;
}
void student::setSchool(int years){
    school = years;
}
void student::setGPA(double num){
    GPA = num;
}

ostream &operator<<(ostream & ostream, const student& m){ //operator overload for output
    ostream << m.name << " ";
    ostream << m.id << " ";
    ostream << m.school << " ";
    //fprintf(ostream,"%d",m.GPA);
    ostream << m.GPA << " ";

    return ostream;
    
}



#endif