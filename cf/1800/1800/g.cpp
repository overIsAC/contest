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
const int N = 3 + 2e5;

map<vector<int>, int> mp;
vector<int> sym;
int n;
vector<int> edge[N];

int dfs(int x, int fa) {
    vector<int> ve;
    for (auto &y : edge[x]) {
        if (y == fa) {
            continue;
        }
        ve.push_back(dfs(y, x));
    }
    sort(ve.begin(), ve.end());
    if (!mp.count(ve)) {
        int flag = 1;
        int i = 0;
        for (; i < ve.size(); i += 2) {
            if (i + 1 == ve.size()) {
                if (!sym[ve[i]]) {
                    flag = false;
                }
                i += 1;
                break;
            }
            if (ve[i] != ve[i + 1]) {
                if (!sym[ve[i]]) {
                    flag = false;
                    break;
                }
                ++i;
                for (; i < ve.size(); i += 2) {
                    if (i + 1 == ve.size()) {
                        flag = false;
                        break;
                    }
                    if (ve[i] != ve[i + 1]) {
                        flag = false;
                        break;
                    }
                }
                break;
            }
        }
        if (i != ve.size()) {
            flag = false;
        }
        sym.push_back(flag);
        mp[ve] = mp.size();
    }
    return mp[ve];
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            edge[i].clear();
        }
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        cout << (sym[dfs(1, 0)] ? "YES" : "NO") << endl;
    }
    return 0;
}