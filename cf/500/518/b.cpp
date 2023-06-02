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
    string a, b;
    cin >> a >> b;
    map<char, int> mp1, mp2;
    for (auto &i : a) {
        ++mp1[i];
    }
    for (auto &i : b) {
        ++mp2[i];
    }
    int ans = 0;
    for (auto &i : mp1) {
        int t = min(i.second, mp2[i.first]);
        ans += t;
        i.second -= t;
        mp2[i.first] -= t;
    }
    cout << ans << ' ';
    ans = 0;
    for (auto &i : mp1) {
        int t = min(i.second, max(mp2[tolower(i.first)], mp2[toupper(i.first)]));
        ans += t;
        i.second -= t;
        if (mp2[tolower(i.first)]) {
            mp2[tolower(i.first)] -= t;
        } else {
            mp2[toupper(i.first)] -= t;
        }
    }
    cout << ans << endl;
    return 0;
}