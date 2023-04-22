#include <bits/stdc++.h>
using namespace std;

int dp[15];

int main() {
    memset(dp, 0x3f, sizeof(dp));
    dp[1] = 1;
    for (int i = 2; i <= 12; ++i) {
        for (int j = 1; j <= i; ++j) {
            int k = i - j;
            dp[i] = min(dp[i], dp[j] * 2 + (1 << k) - 1);
        }
    }
    for (int i = 1; i <= 12; ++i) {
        cout << dp[i] << endl;
    }
    return 0;
}