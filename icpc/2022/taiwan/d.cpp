#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

const int mod = 7 + 1e9;
const int N = 30 + 1e4;

int n, a[N], th;
bitset<N> vis[N];
vector<int> edge[N];
int du[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> th;
    for (int i = 2; i <= n + 1; ++i) {
        int x, y, j;
        cin >> j;
        cin >> x >> y >> a[j];
        edge[j].push_back(x);
        edge[j].push_back(y);
        ++du[x];
        ++du[y];
    }
    queue<int> q;
    for (int i = 2; i <= n + 1; ++i) {
        vis[i][i] = 1;
        if (!du[i]) {
            q.push(i);
        }
    }
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (auto &y : edge[x]) {
            vis[y] |= vis[x];
            if (!--du[y]) {
                q.push(y);
            }
        }
    }
    int cnt = 0;
    for (int i = 2; i <= n + 1; ++i) {
        int d = 0;
        for (int j = 2; j <= n + 1; ++j) {
            if (vis[i][j]) {
                d += a[j];
            }
        }
        if (d >= th) {
            cout << i << ' ' << d << '\n';
            ++cnt;
        }
    }
    cout << cnt << endl;

    return 0;
}