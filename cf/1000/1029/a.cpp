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

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, m;
string s;

int main() {
    cin >> n >> m;
    cin >> s;
    int len = 1;
    int mx = 0;
    auto ok = [&]() -> bool {
        for (int i = 0, j = n - len; i < len; ++i, ++j) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    };
    while (len < n) {
        if (ok()) {
            mx = len;
        }
        ++len;
    }
    cout << s;  
    for (int i = 1; i < m; ++i) {
        cout << s.substr(mx);
    }
    return 0;
}