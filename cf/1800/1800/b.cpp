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
        cin >> n >> k >> s;
        map<int, int> mp;
        for (auto &i : s) {
            ++mp[i];
        }
        int c = 0, d = 0;
        for (int i = 'a'; i <= 'z'; ++i) {
            c += min(mp[i], mp[toupper(i)]);
            d += abs(mp[i] - mp[toupper(i)]) / 2;
        }
        cout << c + min(d, k) << endl;
    }
    return 0;
}