#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        string s;
        cin >> n;
        cin >> s;
        string u = "meow", v = "MEOW";
        int idx = 0;
        bool ok = 1;
        for (auto &i : s) {
            if (u[idx] != i and v[idx] != i) {
                ++idx;
            }
            if (idx == 4 or u[idx] != i and v[idx] != i) {
                ok = false;
                break;
            }
        }
        set<char> st(s.begin(), s.end());
        if (!st.count('m') && !st.count('M')) {
            ok = false;
        }
        if (!st.count('e') && !st.count('E')) {
            ok = false;
        }
        if (!st.count('o') && !st.count('O')) {
            ok = false;
        }
        if (!st.count('w') && !st.count('W')) {
            ok = false;
        }
        if (s.back() != 'w' and s.back() != 'W') {
            ok = false;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}