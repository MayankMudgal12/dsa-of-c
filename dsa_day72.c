#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    int freq[26] = {0};
    scanf("%s", s);

    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';
        freq[index]++;
        if (freq[index] == 2) {
            printf("%c", s[i]);
            return 0;
        }
    }

    printf("-1");
    return 0;
}