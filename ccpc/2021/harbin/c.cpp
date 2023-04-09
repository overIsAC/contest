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

vector<int> edge[N];
int n, c[N];
map<int, int> mp[N];
set<PII> cnt[N];
int zero[N], sum[N];

void dfs(int x) {
    for (auto &y : edge[x]) {
        dfs(y);
        if (mp[y].size() > mp[x].size()) {
            swap(mp[x], mp[y]);
            swap(cnt[x], cnt[y]);
        }
        for (auto &i : mp[y]) {
            cnt[x].erase({mp[x][i.first], i.first});
            mp[x][i.first] += i.second;
            cnt[x].insert({mp[x][i.first], i.first});
        }
        sum[x] = sum[x] + sum[y] + zero[y];
    }
    cout << x << ' ' << sum[x] << ' ' << zero[x] << ' ' << cnt[x].begin()->first + 1 << endl;
    zero[x] = min(sum[x] + zero[x], sum[x] + cnt[x].begin()->first + 1);
    cout << x << ' ' << zero[x] << ' ' << sum[x] << endl;
    zero[x] -= sum[x];
    while (mp[x].size()) {
        auto p = --cnt[x].end();
        if (p->first < zero[x]) {
            break;
        }
        mp[x].erase(p->second);
        cnt[x].erase(p);
    }
    // zero[x] + sum[x] - 1;
    int o = zero[x] + sum[x];
    cout << x << ' ' << o << endl;
    zero[x] += o;
    sum[x] -= o;
    cout << "??? " << x << ' ' << zero[x] << ' ' << sum[x] << endl;
    for (auto &i : mp[x]) {
        cout << i.first << ' ' << i.second << endl;
    }
    cout << "||||" << endl;
    for (auto &i : cnt[x]) {
        cout << i.first << ' ' << i.second << endl;
    }
    cout << "------------" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u;
        v = i + 1;
        edge[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
        if (c[i]) {
            mp[i][c[i]] = 0;
            cnt[i].insert({0, c[i]});
        }
        zero[i] = 1e9;
    }
    dfs(1);
    cout << zero[1] + sum[1] << endl;
    return 0;
}