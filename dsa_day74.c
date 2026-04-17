#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char names[n][50];

    for (int i = 0; i < n; i++)
        scanf("%s", names[i]);

    char unique[n][50];
    int count[n];
    int u = 0;

    for (int i = 0; i < n; i++) {
        int found = -1;
        for (int j = 0; j < u; j++) {
            if (strcmp(unique[j], names[i]) == 0) {
                found = j;
                break;
            }
        }
        if (found == -1) {
            strcpy(unique[u], names[i]);
            count[u] = 1;
            u++;
        } else {
            count[found]++;
        }
    }

    int maxVotes = -1;
    char winner[50];

    for (int i = 0; i < u; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, unique[i]);
        } else if (count[i] == maxVotes) {
            if (strcmp(unique[i], winner) < 0)
                strcpy(winner, unique[i]);
        }
    }

    printf("%s %d", winner, maxVotes);
    return 0;
}