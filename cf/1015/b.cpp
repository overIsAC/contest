#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x)                                                             \
    cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " \
         << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n;
string s, t;

int main() {
    cin >> n >> s >> t;
    map<int, int> a, b;
    for (auto& i : s) {
        a[i]++;
    }
    for (auto& i : t) {
        b[i]++;
    }
    if (a != b) {
        cout << "-1" << endl;
        return 0;
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
            int p = i;
            while (s[p] != t[i]) {
                ++p;
            }
            while (p > i) {
                --p;
                ans.push_back(p);
                swap(s[p], s[p + 1]);
            }
        }
    }
    cout << ans.size() << endl;
    for (auto& i : ans) {
        cout << i + 1 << ' ';
    }
    return 0;
}