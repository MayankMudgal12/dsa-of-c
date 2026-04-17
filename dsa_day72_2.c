#include <stdio.h>
#include <limits.h>

int n;
int cost[15][15];
int dp[1 << 15][15];

int min(int a, int b) {
    return a < b ? a : b;
}

int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1)
        return cost[pos][0];

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX;

    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = cost[pos][city] + tsp(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    for (int i = 0; i < (1 << n); i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = -1;

    printf("%d", tsp(1, 0));
    return 0;
}