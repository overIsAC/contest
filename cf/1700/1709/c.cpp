#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

char s[N];
int n;
bool vis[N];

void solve() {
    int p1 = 0, p2 = 0;
    int L = count(s + 1, s + n + 1, '(');
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '?') {
            if (n / 2 > L) {
                s[i] = '(';
                ++L;
                p1 = i;
            } else {
                s[i] = ')';
                if (!p2) p2 = i;
            }
        }
    }
    if (!p1 || !p2) {
        cout << "YES" << endl;
        return;
    }
    swap(s[p1], s[p2]);
    int top = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '(') ++top;
        if (s[i] == ')') {
            if (top)
                --top;
            else {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> s + 1;
        n = strlen(s + 1);
        solve();
    }
    return 0;
}