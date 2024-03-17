#include <iostream>
#include <vector>
#include <functional>

using namespace std;

// Define the size of the hash table
const int TABLE_SIZE = 10;

// Structure for key-value pairs
struct KeyValuePair {
    string key;
    int value;
};

// Hash Table class
class HashTable {
private:
    vector<vector<KeyValuePair>> table;

    // Hash function to compute the index
    size_t hashFunction(const string& key) {
        return hash<string>{}(key) % TABLE_SIZE;
    }

public:
    HashTable() : table(TABLE_SIZE) {}

    // Function to insert a key-value pair into the hash table
    void insert(const string& key, int value) {
        size_t index = hashFunction(key);
        table[index].push_back({key, value});
    }

    // Function to check if a key is present in the hash table
    bool contains(const string& key) {
        size_t index = hashFunction(key);
        for (const auto& kvp : table[index]) {
            if (kvp.key == key) {
                return true;
            }
        }
        return false;
    }
};

// Test function for Hash Table
void testHashTable() {
    HashTable ht;

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
    testHashTable();
    return 0;
}
