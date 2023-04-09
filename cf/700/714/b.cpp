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

int n, a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    map<int, int> mp;
    for (int i = 1; i <= n; ++i) {
        ++mp[a[i]];
    }
    if (mp.size() <= 2) {
        cout << "YES" << endl;
        return 0;
    }
    if (mp.size() > 3) {
        cout << "NO" << endl;
        return 0;
    }
    int a = mp.begin()->first;
    int b = (++mp.begin())->first;
    int c = prev(mp.end())->first;
    if (a + c == 2 * b) {
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}