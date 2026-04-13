#include <stdio.h>
#include <string.h>

#define SIZE 100

int table[SIZE];

int hash(int key, int m) {
    return key % m;
}

void insert(int key, int m) {
    int i = 0;
    int idx;
    while (i < m) {
        idx = (hash(key, m) + i * i) % m;
        if (table[idx] == -1) {
            table[idx] = key;
            return;
        }
        i++;
    }
}

int search(int key, int m) {
    int i = 0;
    int idx;
    while (i < m) {
        idx = (hash(key, m) + i * i) % m;
        if (table[idx] == -1)
            return 0;
        if (table[idx] == key)
            return 1;
        i++;
    }
    return 0;
}

int main() {
    int m, q;
    scanf("%d", &m);
    scanf("%d", &q);

    for (int i = 0; i < m; i++)
        table[i] = -1;

    char op[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);
        if (strcmp(op, "INSERT") == 0)
            insert(key, m);
        else if (strcmp(op, "SEARCH") == 0) {
            if (search(key, m))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}