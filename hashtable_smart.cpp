#include <iostream>
#include <vector>
#include <functional>

using namespace std;

// Structure for key-value pairs
struct KeyValuePair {
    string key;
    int value;
    KeyValuePair* next; // Pointer to the next key-value pair in the linked list
};

// Hash Table class
class SmarterHashTable {
private:
    vector<KeyValuePair*> table;
    size_t size;

    // Hash functions for double hashing
    size_t hashFunction1(const string& key) {
        return hash<string>{}(key) % table.size();
    }

    size_t hashFunction2(const string& key) {
        return 7 - (hash<string>{}(key) % 7); // Prime number close to table size
    }

public:
    SmarterHashTable(size_t capacity) : table(capacity, nullptr), size(0) {}

    // Function to insert a key-value pair into the smarter hash table
    void insert(const string& key, int value) {
        size_t index = hashFunction1(key);
        size_t step = hashFunction2(key);
        
        // Create a new key-value pair
        KeyValuePair* newPair = new KeyValuePair{key, value, nullptr};

        // If the bucket is empty, insert the new pair
        if (!table[index]) {
            table[index] = newPair;
        } else {
            // Collision occurred, append to the end of the linked list
            KeyValuePair* current = table[index];
            while (current->next) {
                current = current->next;
            }
            current->next = newPair;
        }
        size++;
    }

    // Function to check if a key is present in the smarter hash table
    bool contains(const string& key) {
        size_t index = hashFunction1(key);
        KeyValuePair* current = table[index];
        while (current) {
            if (current->key == key) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

// Test function for Hash Table
void testSmarterHashTable() {
    SmarterHashTable ht(10);

    // Test Insert Function
    ht.insert("dog", 5);
    ht.insert("cat", 10);
    ht.insert("birb", 7);

    // Test Contains Function
    if (!ht.contains("dog")) {
        cout << "Test Contains Function failed: 'dog' key not found." << endl;
        return;
    }
    if (!ht.contains("cat")) {
        cout << "Test Contains Function failed: 'cat' key not found." << endl;
        return;
    }
    if (!ht.contains("birb")) {
        cout << "Test Contains Function failed: 'birb' key not found." << endl;
        return;
    }

    cout << "All tests passed successfully!" << endl;
}

int main() {
    testSmarterHashTable();
    return 0;
}
