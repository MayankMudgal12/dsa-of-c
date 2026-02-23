#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    int value;
    struct Node* next;
};

#define SIZE 1000

struct Node* hashTable[SIZE];

int hash(int key) {
    if (key < 0) key = -key;
    return key % SIZE;
}

void insert(int key, int value) {
    int index = hash(key);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

int search(int key) {
    int index = hash(key);
    struct Node* temp = hashTable[index];
    while (temp) {
        if (temp->key == key)
            return temp->value;
        temp = temp->next;
    }
    return -1;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int n = sizeof(nums) / sizeof(nums[0]);

    for (int i = 0; i < SIZE; i++)
        hashTable[i] = NULL;

    for (int i = 0; i < n; i++) {
        int complement = target - nums[i];
        int index = search(complement);

        if (index != -1) {
            printf("%d %d", index, i);
            return 0;
        }

        insert(nums[i], i);
    }

    return 0;
}