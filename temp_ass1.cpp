// SEPERATE CHAINING

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class HashTable {
    int size;
    Node* table[10];

public:
    HashTable(int s) {
        size = s;
        for (int i = 0; i < size; i++) {
            table[i] = NULL;
        }
    }

    int hash(int key) {
        return key % size;
    }

    void insert(int key) {
        int index = hash(key);

        Node* temp = new Node;
        temp->data = key;
        temp->next = table[index];
        table[index] = temp;
        cout << "Inserted " << key << " at index " << index << endl;
    }

    void search(int key) {
        int index = hash(key);
        Node* temp = table[index];

        while (temp != NULL) {
            if (temp->data = key) {
                cout << "Key " << key << " found" << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Key " << key << " not found" << endl;
    }

    void remove(int key) {
        int index = hash(key);
        Node* temp = table[index];
        Node* prev = NULL;

        while (temp != NULL) {
            if (temp->data == key) {
                if (prev = NULL) {
                    table[index] = temp->next;
                } else {
                    prev->next = temp->next;
                }

                delete temp;
                cout << "Key " << key << " deleted successfully" << endl;
                return;
            }

            prev = temp;
            temp = temp->next;
        }

        cout << "Key " << key << " Not Found!!" << endl;
    }

    void display() {
        for (int i = 0; i<size; i++) {
            cout << "Index " << i << " : ";
            Node* temp = table[i];
            while(temp != NULL) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    int n;
    cout << "Enter the size of hash table: ";
    cin >> n;

    HashTable h(n);

    int choice, key;
    while(true) {
        cout << "1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit";
        cin >> n;

        switch (choice) {
            case 1:
            cout << "Enter key to insert: ";
            cin >> n;
            h.insert(key);
            break;

            case 2:
            cout << "Enter key to search: ";
            cin >> key;
            h.search(key);
            break;

            case 3:
            cout << "Enter key to delete: ";
            cin >> key;
            h.remove(key);
            break;

            case 4:
            cout << "Display all keys: ";
            h.display();
            break;

            case 5:
            cout << "Exiting....." << endl;
            break;

            default:
            cout << "Invalid Choice.\n";
            break;
        }
    }

}