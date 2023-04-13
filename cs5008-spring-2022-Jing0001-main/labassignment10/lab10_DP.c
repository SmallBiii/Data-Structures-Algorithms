#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int minCoins(int coins[], int n, int amount, int memo[]) {
    if (amount == 0) {
        return 0;
    }
    if (memo[amount] != -1) {
        return memo[amount];
    }
    int result = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (coins[i] <= amount) {
            int subResult = minCoins(coins, n, amount - coins[i], memo);
            if (subResult != -1 && subResult + 1 < result) {
                result = subResult + 1;
            }
        }
    }
    memo[amount] = (result == INT_MAX) ? -1 : result;
    return memo[amount];
}

int main() {
    int n, amount;
    printf("Number of values of coins: ");
    scanf("%d", &n);
    int coins[n];
    printf("Coins:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }
    printf("Amount: ");
    scanf("%d", &amount);
    int memo[amount + 1];
    for (int i = 0; i <= amount; i++) {
        memo[i] = -1;
    }
    int result = minCoins(coins, n, amount, memo);
    printf("Answer: %d\n", result);
    return 0;
}
