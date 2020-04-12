#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#define NIL NULL
#include <iostream>

using namespace std;

typedef struct elmListCourse *adr;
typedef struct elmListInstructor *address;

struct elmListInstructor {
    address next ;
    address prev;
    string nameInstructor;

};

struct elmListCourse {
    adr next;
    adr prev;
    string nameCourse;
    address teached;
};

struct listInstructor {
    address first;
    address last;
    int sumInstructor;
};
struct listCourse {
    adr first;
    adr last;
    int sumCourse;
};




void createListInstructor(listInstructor &L);
void createListCourse(listCourse &L);
adr createCourse(string name,address teached);
address createInstructor(string name);
void insertInstructor(listInstructor &L,address P);
void insertCourse(listCourse &L,adr P);
void printCourse(listCourse L);
void printinstructor(listInstructor L);
void menu(listCourse &L1,listInstructor &L2);
address searchInstructor(listInstructor L,string name);
adr searchCourse(listCourse L,string name);
void deleteCourse(listCourse &L,adr P);

#endif // HEADER_H_INCLUDED
