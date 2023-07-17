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

int f(string s) {
    string t = s;
    reverse(t.begin(), t.end());
    return t == s;
}

void solve(int &n, vector<string> &a) {
    for (auto &i : a) {
        if (i.size() == 1) {
            cout << "YES" << endl;
            return;
        }
        if (i.size() == 2 && i[0] == i[1]) {
            cout << "YES" << endl;
            return;
        }
        if (i.size() == 3 && i[0] == i[2]) {
            cout << "YES" << endl;
            return;
        }
    }
    set<string> st[26];
    for (auto &i : a) {
        for (auto &j : st[i.back() - 'a']) {
            if (f(j + i)) {
                cout << "YES" << endl;
                return;
            }
        }
        st[i[0] - 'a'].insert(i);
    }
    cout << "NO" << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<string> a(n);
        for (auto &i : a) {
            cin >> i;
        }
        solve(n, a);
    }
    return 0;
}