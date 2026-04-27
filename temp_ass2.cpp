#include<bits/stdc++.h>
using namespace std;

#define TABLE_SIZE 10

class LinearProbing {
    int table[TABLE_SIZE];
    bool occupied[TABLE_SIZE];

    public:
    LinearProbing() {
        for (int i = 0; i<TABLE_SIZE; i++) {
            table[i] = -1;
            occupied[i] = false;
        }
    }

    void insert(int key) {
        int index = key % TABLE_SIZE;
        int start = index;

        while(occupied[index]) {
            index = (index + 1) % TABLE_SIZE;
            if (start == index) {
                cout << "Hash table is full.\n";
                return;
            }
        }
        table[index] = key;
        occupied[index] = true;
        cout << "Key " << key << " inserted at index " << index << endl;
    }

    void search(int key) {
        int index = key % TABLE_SIZE;
        int start = index;

        while(occupied[index]) {
            if (table[index] == key) {
                cout << "Key " << key << " Found at index " << index << endl;
                return;
            }

            index = (index + 1) % TABLE_SIZE;
            if (index == start) {
                break;
            }
        }
        cout << "Key " << key << " not found!" << endl;
    }

    void display() {
        for (int i=0; i<TABLE_SIZE; i++) {
            if (occupied[i]) {
                cout << "Index: " << i << " --> " << table[i] << endl;
            } else {
                cout << "Index: " << i << " NULL\n";
            }
        }
    }
};

int main() {
    int n;

    LinearProbing l;

    int choices, key;
    while(true) {
        cout << "1. Insert\n2. Search\n3. Display\n4. Exit\n";
        cin >> choices;

        switch(choices) {
            case 1:
                cout << "Enter the key: ";
                cin >> key;
                l.insert(key);
                break;

            case 2:
                cout << "Enter a key to search: ";
                cin >> key;
                l.search(key);
                break;

            case 3:
                cout << "Hash Table: \n";
                l.display();
                break;

            case 4:
                cout << "Exiting...." << endl;
                return 0; 

            default:
                cout << "Invaid Choice Code!\n";
                break;
        }
    }
}