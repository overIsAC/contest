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
        cin >> n >> k;
        string a, b;
        cin >> a >> b;
        vector<int> fa(n);
        for (int i = 0; i < n; ++i) {
            fa[i] = i;
        }
        function<int(int)> find = [&](int x) {
            return x == fa[x] ? x : fa[x] = find(fa[x]);
        };
        for (int i = 0; i < n; ++i) {
            if (i + k < n) {
                fa[find(i)] = find(i + k);
            }
            if (i + k + 1 < n) {
                fa[find(i)] = find(i + k + 1);
            }
        }
        map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i) {
            mp[find(i)].push_back(i);
        }
        bool ok = true;
        for (auto &i : mp) {
            auto &ve = i.second;
            string s, t;
            for (int j : ve) {
                s += a[j];
                t += b[j];
            }
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            if (s != t) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}