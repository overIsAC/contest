#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 3;
int n, m;
int a[N];
bitset<N * 100> dp;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp |= dp << a[i];
    }
    for (int i = m; i < N * 100; ++i) {
        if (dp[i]) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}