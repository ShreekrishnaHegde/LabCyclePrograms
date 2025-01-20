#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // Maximum number of keys that can be stored in the hash table

// Define the structure of an entry in the hash table
typedef struct {
    int key;
    int isOccupied;  // 0 = empty, 1 = occupied, -1 = deleted
} HashTableEntry;

// Define the hash table
HashTableEntry hashTable[MAX_SIZE];

// Initialize the hash table
void initHashTable(int m) {
    for (int i = 0; i < m; i++) {
        hashTable[i].isOccupied = 0;  // Mark all entries as empty initially
    }
}

// Hash function: H(K) = K mod m
int hashFunction(int key, int m) {
    return key % m;
}

// Linear probing to handle collisions
int linearProbing(int key, int m) {
    int index = hashFunction(key, m);

    // Check for collision and resolve using linear probing
    int i = index;
    while (hashTable[i].isOccupied == 1) {
        // Move to the next location (linear probing)
        i = (i + 1) % m;
        if (i == index) {
            // If we've cycled back to the original index, the table is full
            printf("Hash table is full, cannot insert the key: %d\n", key);
            return -1;
        }
    }

    // Insert the key at the found empty location
    hashTable[i].key = key;
    hashTable[i].isOccupied = 1;
    return i;
}

// Search for a key in the hash table
int search(int key, int m) {
    int index = hashFunction(key, m);
    int i = index;

    // Search using linear probing
    while (hashTable[i].isOccupied != 0) {
        if (hashTable[i].isOccupied == 1 && hashTable[i].key == key) {
            return i;  // Found the key
        }
        // Move to the next location (linear probing)
        i = (i + 1) % m;
        if (i == index) {
            // If we've cycled back to the original index, the key is not in the table
            break;
        }
    }

    return -1;  // Key not found
}

// Function to print the hash table
void printHashTable(int m) {
    for (int i = 0; i < m; i++) {
        if (hashTable[i].isOccupied == 1) {
            printf("Index %d: Key = %d\n", i, hashTable[i].key);
        }
    }
}

// Main function to demonstrate hash table with linear probing
int main() {
    int m, n, key;

    // Read the size of the hash table
    printf("Enter the number of memory locations (m): ");
    scanf("%d", &m);

    // Initialize the hash table
    initHashTable(m);

    // Read the number of records
    printf("Enter the number of records (N): ");
    scanf("%d", &n);

    // Insert the records into the hash table
    for (int i = 0; i < n; i++) {
        printf("Enter key for record %d: ", i + 1);
        scanf("%d", &key);
        linearProbing(key, m);
    }

    // Print the hash table after insertions
    printf("\nHash table after insertions:\n");
    printHashTable(m);

    // Search for a key
    printf("\nEnter a key to search: ");
    scanf("%d", &key);

    int index = search(key, m);
    if (index != -1) {
        printf("Key %d found at index %d\n", key, index);
    } else {
        printf("Key %d not found in the hash table\n", key);
    }

    return 0;
}
