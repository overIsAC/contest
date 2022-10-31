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

int main() {
    string s, t;
    cin >> s >> t;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    int p = 0;
    while (p < s.size() and p < t.size() and s[p] == t[p]) {
        ++p;
    }
    cout << s.size() + t.size() - p * 2 << endl;
    return 0;
}