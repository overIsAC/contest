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
const int N = 3 + 4e5;

int n, m;
string s;
vector<vector<char>> u, v;

int main() {
    cin >> n >> m;
    u.resize(m);
    v.resize(m);
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < m; ++j) {
            u[j].push_back(s[j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < m; ++j) {
            v[j].push_back(s[j]);
        }
    }
    sort(u.begin(), u.end());
    sort(v.begin(), v.end());
    if (u == v) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}