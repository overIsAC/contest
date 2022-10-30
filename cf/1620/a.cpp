#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int fa[N];

int find(int p) { return p == fa[p] ? p : fa[p] = find(fa[p]); }

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            fa[i] = i;
        }
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'E') {
                fa[find(i)] = find((i + 1) % n);
            }
        }
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'N') {
                if (find(i) == find((i + 1) % n)) {
                    ok = false;
                }
            }
        }
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}