/*Problem Statement
Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input Format
Same as previous.

Output Format
Result of SEARCH operations.

Sample Input
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output
FOUND
NOT FOUND

Explanation
Collisions resolved using i² jumps.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CMD_LEN 20

typedef struct {
    int key;
    bool isOccupied;
} HashTableEntry;

int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) != 2) return 0;

    HashTableEntry* table = (HashTableEntry*)malloc(sizeof(HashTableEntry) * m);
    for (int i = 0; i < m; i++) {
        table[i].isOccupied = false;
    }

    char command[MAX_CMD_LEN];
    int key;

    for (int j = 0; j < n; j++) {
        scanf("%s %d", command, &key);

        if (strcmp(command, "INSERT") == 0) {
            for (int i = 0; i < m; i++) {
                int index = (key % m + i * i) % m;
                if (!table[index].isOccupied) {
                    table[index].key = key;
                    table[index].isOccupied = true;
                    break;
                }
            }
        } else if (strcmp(command, "SEARCH") == 0) {
            bool found = false;
            for (int i = 0; i < m; i++) {
                int index = (key % m + i * i) % m;
                if (!table[index].isOccupied) {
                    break;
                }
                if (table[index].key == key) {
                    found = true;
                    break;
                }
            }
            if (found) {
                printf("FOUND\n");
            } else {
                printf("NOT FOUND\n");
            }
        }
    }

    free(table);
    return 0;
}