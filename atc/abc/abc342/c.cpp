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

int main() {
    map<char, char> mp;
    for (int i = 'a'; i <= 'z'; ++i) {
        mp[i] = i;
    }
    int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;
    while (q--) {
        char u, v;
        cin >> u >> v;
        for (auto& [x, y] : mp) {
            if (y == u) {
                y = v;
            }
        }
    }
    for (auto i : s) {
        cout << mp[i];
    }
    return 0;
}