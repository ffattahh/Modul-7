//2311102169
//Ben Waiz Pintus W
#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    Mahasiswa* next;
};

Mahasiswa* front = nullptr; // Pointer depan
Mahasiswa* back = nullptr; // Pointer belakang

void enqueueAntrian(string nama, string nim) {
    Mahasiswa* newNode = new Mahasiswa;
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = nullptr;
    if (front == nullptr) { // Jika antrian kosong
        front = newNode;
        back = newNode;
    } else { // Jika antrian tidak kosong
        back->next = newNode;
        back = newNode;
    }
}

void dequeueAntrian() {
    if (front == nullptr) {
        cout << "Antrian kosong" << endl;
    } else {
        Mahasiswa* temp = front;
        front = front->next;
        delete temp;
    }
}

int countQueue() {
    int count = 0;
    Mahasiswa* current = front;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

void clearQueue() {
    while (front != nullptr) {
        Mahasiswa* temp = front;
        front = front->next;
        delete temp;
    }
    back = nullptr;
}

void viewQueue() {
    cout << "Data antrian mahasiswa:" << endl;
    Mahasiswa* current = front;
    int i = 1;
    while (current != nullptr) {
        cout << i << ". Nama: " << current->nama << ", NIM: " << current->nim << endl;
        current = current->next;
        i++;
    }
}

int main() {
    enqueueAntrian("Fattah", "2311102019");
    enqueueAntrian("Tristan", "2311102999");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}