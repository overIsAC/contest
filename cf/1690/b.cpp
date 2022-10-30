#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, a[N], b[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> b[i];
        }
        bool ok = true;
        vector<int> q, w;
        for (int i = 1; i <= n; ++i) {
            if (a[i] < b[i]) {
                ok = false;
                break;
            }
            if (b[i] == 0)
                q.push_back(a[i] - b[i]);
            else
                w.push_back(a[i] - b[i]);
        }
        set<int> s(w.begin(), w.end());
        if (s.size() > 1) ok = false;
        if (s.size()) {
            int o = *s.begin();
            for (auto &i : q) {
                if (o < i) {
                    ok = false;
                    break;
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