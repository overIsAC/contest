#include <bits/stdc++.h>
using namespace std;

const int N = 5;

char s[N][N];
int vis[N][N];

int calc(int st) {
    for (int i = 0; i < 5; ++i) {
        vis[0][i] = st >> i & 1;
    }
    for (int i = 0; i + 1 < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            int v = s[i][j] - '0';
            v = !v;
            if (vis[i][j]) {
                v = !v;
            }
            if (i && vis[i - 1][j]) {
                v = !v;
            }
            if (j && vis[i][j - 1]) {
                v = !v;
            }
            if (j + 1 < 5 && vis[i][j + 1]) {
                v = !v;
            }
            vis[i + 1][j] = v;
        }
    }

    int ans = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            int v = s[i][j] - '0';
            v = !v;
            if (vis[i][j]) {
                v = !v;
            }
            if (i && vis[i - 1][j]) {
                v = !v;
            }
            if (j && vis[i][j - 1]) {
                v = !v;
            }
            if (i + 1 < 5 && vis[i + 1][j]) {
                v = !v;
            }
            if (j + 1 < 5 && vis[i][j + 1]) {
                v = !v;
            }
            if (v) {
                return INT_MAX;
            }
            ans += vis[i][j];
        }
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        for (int i = 0; i < 5; ++i) {
            cin >> s[i];
        }
        int ans = INT_MAX;
        for (int i = 0; i < 1 << 5; ++i) {
            ans = min(ans, calc(i));
        }
        if (ans > 6) {
            ans = -1;
        }
        cout << ans << endl;
    }
    return 0;
}