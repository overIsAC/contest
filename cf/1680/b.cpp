#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

const int mod = 7 + 1e9;
const int N = 3 + 1e5;

char s[22][22];
int n, m;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        bool ok = false;
        for (int i = 1; i <= n; ++i) {
            cin >> s[i] + 1;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s[i][j] == 'E') continue;
                bool f = true;
                for (int q = 1; q < i; ++q) {
                    for (int w = 1; w <= m; ++w) {
                        if (s[q][w] == 'R') {
                            f = false;
                        }
                    }
                }
                for (int q = 1; q <= n; ++q) {
                    for (int w = 1; w < j; ++w) {
                        if (s[q][w] == 'R') {
                            f = false;
                        }
                    }
                }
                if (f) {
                    ok = true;
                    cout << "YES" << endl;
                    break;
                }
            }
            if (ok) {
                break;
            }
        }
        if (ok == false) {
            cout << "NO" << endl;
        }
    }

    return 0;
}