#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n;
char s[N];
int a, b, c, d;
bool vis[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> a >> b >> c >> d;
        cin >> s + 1;
        n = strlen(s + 1);
        for (int i = 1; i <= n; ++i) {
            vis[i] = false;
        }
        for (int i = 1; i < n && d; ++i) {
            if (s[i] == 'B' && s[i + 1] == 'A') {
                if (i + 2 <= n && s[i + 2] == 'B') {
                    continue;
                }
                if (i - 1 >= 1 && s[i - 1] == 'A') {
                    continue;
                }
                vis[i] = true;
                vis[i + 1] = true;
                --d;
            }
        }

        cout << "v111" << endl;
        for (int i = 1; i <= n; ++i) {
            if (vis[i])
                cout << 'C';
            else
                cout << s[i];
        }
        cout << endl;

        for (int i = 1; i < n && d; ++i) {
            if (vis[i] || vis[i + 1]) continue;
            if (s[i] == 'B' && s[i + 1] == 'A') {
                if (i - 1 == 0 || vis[i - 1] || s[i - 1] == 'B') {
                    vis[i] = true;
                    vis[i + 1] = true;
                    --d;
                    continue;
                }
            }
        }
            cout << "v222" << endl;
        for (int i = 1; i <= n; ++i) {
            if (vis[i])
                cout << 'C';
            else
                cout << s[i];
        }
        cout << endl;

        cout << d << endl;
        for (int i = n - 1; i && d; --i) {
            cout << i << ' ' << (int)vis[i] << ' ' << (int)vis[i + 1] << endl;
            if (vis[i] || vis[i + 1]) continue;
            if (s[i] == 'B' && s[i + 1] == 'A') {
                cout << i + 2 << ' ' << (int)vis[i + 2] << ' ' << s[i + 2]
                     << endl;
                if (i + 2 > n || vis[i + 2] || s[i + 2] == 'A') {
                    vis[i] = true;
                    vis[i + 1] = true;
                    --d;
                    continue;
                }
            }
        }

        cout << "vvv" << endl;
        for (int i = 1; i <= n; ++i) {
            if (vis[i])
                cout << 'C';
            else
                cout << s[i];
        }
        cout << endl;

        for (int i = 1; i < n && d; ++i) {
            if (vis[i] || vis[i + 1]) continue;
            if (s[i] == 'B' && s[i + 1] == 'A') {
                vis[i] = true;
                vis[i + 1] = true;
                --d;
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (vis[i])
                cout << 'C';
            else
                cout << s[i];
        }
        cout << endl;
        for (int i = 1; i < n && c; ++i) {
            if (vis[i] || vis[i + 1]) continue;
            if (s[i] == 'A' && s[i + 1] == 'B') {
                vis[i] = true;
                vis[i + 1] = true;
                --c;
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (vis[i])
                cout << 'C';
            else
                cout << s[i];
        }
        cout << endl;
        for (int i = 1; i <= n && a; ++i) {
            if (vis[i] || s[i] != 'A') continue;
            --a;
        }
        for (int i = 1; i <= n && b; ++i) {
            if (vis[i] || s[i] != 'B') continue;
            --b;
        }
        cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
        if (a || b || c || d) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}