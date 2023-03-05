#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n;
vector<int> ve[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        map<int, int> mp;
        for (int i = 1; i <= n; ++i) {
            ve[i].clear();
            int m, a;
            cin >> m;
            while (m--) {
                cin >> a;
                ve[i].push_back(a);
                ++mp[a];
            }
        }
        bool ok = false;
        for (int i = 1; i <= n; ++i) {
            bool flag = true;
            for (auto &j : ve[i]) {
                if (!--mp[j]) {
                    flag = false;
                }
            }
            if (flag) {
                ok = true;
                break;
            }
            for (auto &j : ve[i]) {
                ++mp[j];
            }
        }
        if (ok) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}