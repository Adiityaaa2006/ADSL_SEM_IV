// LINEAR PROBING 

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

    int search(int key) {
        int index = key % TABLE_SIZE;
        int start = index;

        while(occupied[index]) {
            index = (index + 1) % TABLE_SIZE;
            if (table[index] == key) {
                return index;
            }

            if (index == start) {
                break;
            }
        }
    }
};