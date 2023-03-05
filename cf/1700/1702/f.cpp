#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, a[N], m;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        multiset<int> s1, s2;
        cin >> n;
        for (int i = 1, a; i <= n; ++i) {
            cin >> a;
            while (a % 2 == 0) {
                a /= 2;
            }
            s1.insert(a);
        }
        for (int i = 1, a; i <= n; ++i) {
            cin >> a;
            while (a % 2 == 0) {
                a /= 2;
            }
            s2.insert(a);
        }
        bool ok = true;
        while (s2.size()) {
            auto p = --s2.end();
            if (s1.count(*p)) {
                s1.erase(s1.find(*p));
                s2.erase(p);
            } else {
                if (*p == 1) {
                    ok = false;
                    break;
                }
                s2.insert(*p / 2);
                s2.erase(p);
            }
        }
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}