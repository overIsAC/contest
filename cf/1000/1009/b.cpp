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
    string s;
    cin >> s;
    int f = 0;
    for (auto &i : s) {
        if (i == '2') {
            f = 1;
        }
    }
    if (!f) {
        sort(s.begin(), s.end());
        cout << s << endl;
        return 0;
    }
    string t;
    int z = 0;
    for (auto &i : s) {
        if (i == '1') {
            ++z;
        } else {
            t += i;
        }
    }
    if (t.empty()) {
        cout << string(z, '1') << endl;
        return 0;
    }
    for (auto &i : t) {
        if (i == '2') {
            while (z-- > 0) {
                cout << '1';
            }
        }
        cout << i;
    }
    while (z-- > 0) {
        cout << '1';
    }
    
    return 0;
}