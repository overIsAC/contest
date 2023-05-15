#include <bits/stdc++.h>
using namespace std;

int pow3[11];
char ans[1000][1000];

void dfs(int x, int y, int n) {
    if (n == 1) {
        ans[x][y] = 'X';
        return;
    }
    dfs(x, y, n - 1);
    dfs(x, y + pow3[n - 2] * 2, n - 1);
    dfs(x + pow3[n - 2], y + pow3[n - 2], n - 1);
    dfs(x + pow3[n - 2] * 2, y, n - 1);
    dfs(x + pow3[n - 2] * 2, y + pow3[n - 2] * 2, n - 1);
}

int main() {
    pow3[0] = 1;
    for (int i = 1; i <= 10; ++i) {
        pow3[i] = pow3[i - 1] * 3;
    }
    int n;
    while (cin >> n, n != -1) {
        memset(ans, 0, sizeof(ans));
        dfs(1, 1, n);
        for (int i = 1; i <= pow3[n - 1]; ++i) {
            for (int j = 1; j <= pow3[n - 1]; ++j) {
                if (ans[i][j]) {
                    cout << ans[i][j];
                } else {
                    cout << ' ';
                }
            }
            cout << endl;
        }
        cout << '-' << endl;
    }
    return 0;
}