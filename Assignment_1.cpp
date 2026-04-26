#include <iostream>
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
        for (int i = 0; i < size; i++)
            table[i] = NULL;
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
            if (temp->data == key) {
                cout << "Key " << key << " found at index " << index << endl;
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

    	while(temp != NULL) {
    		if (temp->data == key) {
    			if(prev == NULL) {
    				table[index] = temp->next;
    			} else {
    				prev->next = temp->next;
    			}

    			delete temp;
    			cout << "Deleted " << key << " from index " << index << endl;
    			return;
    		}

    		prev = temp;
    		temp = temp->next;
    	}

    	cout << "Key Not Found";
    }



    void display() {
        for (int i=0; i<size; i++) {
            cout << "Index " << i << " : ";
            Node* temp = table[i];
            while (temp != NULL) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    int n;
    cout << "Enter size of the table: ";
    cin >> n;

    HashTable h(n);

    int choice, key;
    while (true) {
        cout << "\n1.Insert\n2.Display\n3.Search\n4.Delete\n5.Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key: ";
            cin >> key;
            h.insert(key);
            break;

        case 2:
            h.display();
            break;

        case 3:
        	cout << "Enter Key: ";
        	cin >> key;
            h.search(key);
            break;

        case 4:
        	cout << "Enter Key: ";
        	cin >> key;
        	h.remove(key);
        	break;

        default:
            cout << "Invalid choice\n";
        }
    }
}