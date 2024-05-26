#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
};

Node* front = nullptr; // Pointer depan
Node* back = nullptr; // Pointer belakang

void enqueueAntrian(string data) {
    Node* newNode = new Node;
    newNode->data = data;
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
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

int countQueue() {
    int count = 0;
    Node* current = front;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

void clearQueue() {
    while (front != nullptr) {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
    back = nullptr;
}

void viewQueue() {
    cout << "Data antrian teller:" << endl;
    Node* current = front;
    int i = 1;
    while (current != nullptr) {
        cout << i << ". " << current->data << endl;
        current = current->next;
        i++;
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
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