#include<bits/stdc++.h>
using namespace std;

//Node Implementation
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int value) : data(value), next(nullptr) {}
};

//LL implementaton
class LL {
private:
    Node* head;
public:
    LL() {
        head = NULL;
    }
    // 🔹 Insert
    void insert(int value) {
        Node* newNode=new Node(value);
        if(head==NULL){
            head=newNode;
            return;
        }else{
            // traverse the LL
            Node* temp=head;
            while(temp->next !=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }

// 🔹 Insert at Position (0-based index)
    void insertAtPosition(int value, int pos) {
        Node* newNode = new Node(value);
        if (pos == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        for (int i = 0; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Position out of range\n";
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // 🔹 Delete by Value
    void deleteValue(int value) {
        if (head == NULL) return;
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL && temp->next->data != value) {
            temp = temp->next;
        }
        if (temp->next == NULL) {
            cout << "Value not found\n";
            return;
        }
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // 🔹 Display List
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};


int main() {
    LL list;
    cout << "Initial List: ";
    list.insert(10);
    list.display();
    list.insertAtPosition(15,1);
    list.display();
    list.deleteValue(10);
      list.display();
}
