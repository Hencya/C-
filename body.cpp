#include "header.h"

void createListInstructor(listInstructor &L){
    L.first = NULL;
    L.last = NULL;
    L.sumInstructor =0;
}

void createListCourse(listCourse &L){
    L.first = NULL;
    L.last = NULL;
    L.sumCourse = 0;
}

adr createCourse(string name,address teached){
    adr P = new elmListCourse;
    P->nameCourse = name;
    P->next = NULL;
    P->prev = NULL;
    P->teached = teached;
    return P;
}

address createInstructor(string name){
    address P = new elmListInstructor;
    P->nameInstructor = name;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void insertInstructor(listInstructor &L,address P){
    if (L.first != NULL && L.last != NULL){
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
        L.sumInstructor = L.sumInstructor + 1;
    }else {
        L.first = P;
        L.last = P;
        L.sumInstructor = L.sumInstructor +1;
    }
}

void insertCourse(listCourse &L,adr P){
     if (L.first != NULL && L.last != NULL){
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
        L.sumCourse = L.sumCourse +1;
    }else {
        L.first = P;
        L.last = P;
        L.sumCourse = L.sumCourse +1;
    }
}

void printCourse(listCourse L1,listInstructor L2){
    adr P;
    P = L1.first;
    while (P != NULL){
        cout << "Nama kursus : " << P->nameCourse << endl;
        cout << "diajarkan oleh instruktur " << P->teached->nameInstructor << endl;
        P = P->next;
    }
    cout << "Jumlah kursus : " << L1.sumCourse<< endl;
}

void printinstructor(listInstructor L){
    address P;
    P = L.first;
    while (P != NULL){
        cout << "Nama instruktur : " << P->nameInstructor << endl;
        P = P->next;
    }
    cout << endl;
    cout << "Jumlah instruktur :" << L.sumInstructor << endl;
}

address searchInstructor(listInstructor L,string name){
    address pInstructor;
    pInstructor = L.first;
    while (pInstructor != NULL && pInstructor->nameInstructor != name){
        pInstructor = pInstructor->next;
    }
    if ( pInstructor->nameInstructor == name){
        return pInstructor;
    }else if (pInstructor == NULL) {
        return NULL;
    }

}
adr searchCourse(listCourse L,string name){
    adr pCourse;
    pCourse = L.first;
    while(pCourse != NULL && pCourse->nameCourse != name){
        pCourse = pCourse->next;
    }
     if (pCourse == NULL){
        return NULL;
     }else {
        return pCourse;
     }
}

void deleteCourse(listCourse &L,adr P){
    if (P->prev == NULL){
        (P->next)->prev = NULL;
        P->next = NULL;
        P->teached = NULL;
    }else {
        adr Q = P->prev;
        Q->next = NULL;
        P->prev = NULL;
        P->teached = NULL;
    }
}

void menu(listCourse &L1,listInstructor &L2){
    int pilih,input;
    address pInstructor,teached;
    adr pCourse;
    string name;

    cout << "=================================================================" << endl;
    cout << "                   PILIH MENU YANG INGIN DILIH                 " << endl;
    cout << "=================================================================" << endl;
    cout << "1. Membuat list instruktur " << endl;
    cout << "2. Mencari nama instruktur dan membuatkan kurusu untuknya " << endl;
    cout << "3. Menghapus kursus tertentu " << endl;
    cout << "0. Exit " << endl;
    cout << "pilih : ";
    cin >> pilih ;
    cin.ignore();
        if (pilih == 1 ){
            cout << "Masukan nama instruktur : " ;
            getline(cin,name);
            pInstructor = createInstructor(name);
            insertInstructor(L2,pInstructor);
            cout << "Apakah ingin kembali ke menu ? " << endl;
            cout << " 1. Ya " << endl;
            cout << " 2. Tidak " << endl;
            cout << "Pilih : " ;
            cin >> input ;
            cin.ignore();
            if (input == 1){
                cout << "=================================================================" << endl;
                cout << endl << endl << endl;
                menu(L1,L2);
            }else {
                cout << "                            SELESAI                              " << endl;
                cout << "=================================================================" << endl;
                cout << endl << endl << endl;
            }
        }else if (pilih == 2 ){
            cout << "Masukan nama instruktur yang dicari dan ingin dibuatkan kursus : " ;
            getline(cin,name);
            teached = searchInstructor(L2,name);
            if (teached == NULL){
                cout << "INSTRUKTUR YANG DICARI TIDAK ADA !!!! "<< endl;
            }else {
                cout << "Instruktur yang dicari ada "<< endl;
                cout << "Masukan nama kursus yang akan di ajar oleh instruktur tersebut : ";
                getline(cin,name);
                pCourse = createCourse(name,teached);
                insertCourse(L1,pCourse);
            }
            cout << "Apakah ingin kembali ke menu ? " << endl;
            cout << " 1. Ya " << endl;
            cout << " 2. Tidak " << endl;
            cout << "Pilih = " ;
            cin >> input ;
            cin.ignore();
            if (input == 1){
                cout << "=================================================================" << endl;
                cout << endl << endl << endl;
               menu(L1,L2);
            }else {
                cout << "                            SELESAI                              " << endl;
                cout << "=================================================================" << endl;
                cout << endl << endl << endl;
            }
        }else if (pilih == 3){
            cout << "Masukan nama kursus yang ingin dihapus : ";
            getline(cin,name);
            pCourse = searchCourse(L1,name);
            if (pCourse != NULL){
                deleteCourse(L1,pCourse);
            }else {
                cout << "kursus yang dicari tak ada ";
            }
            cout << "Apakah ingin kembali ke menu ? " << endl;
            cout << " 1. Ya " << endl;
            cout << " 2. Tidak " << endl;
            cout << "Pilih = " ;
            cin >> input ;
            cin.ignore();
            if (input == 1){
                cout << "=================================================================" << endl;
                cout << endl << endl << endl;
               menu(L1,L2);
            }else {
                cout << "                            SELESAI                              " << endl;
                cout << "=================================================================" << endl;
                cout << endl << endl << endl;
            }
        }else if (pilih == 0){
             cout << "                            SELESAI                              " << endl;
             cout << "=================================================================" << endl;
        }else {
            cout << " Inputam tidak sesuai apakah anda ingin menguilang inputan ? " << endl;
            cout << " 1. Ya " << endl;
            cout << " 2. Tidak " << endl;
            cout << "Pilih = " ;
            cin >> input ;
            cin.ignore();
            if (input == 1){
                menu(L1,L2);
            }else {
                cout << "                            SELESAI                              " << endl;
            }
        }


}

