#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
const int N = 3 + 2e5;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> du(n, vector<int>(m));
    for (auto &i : s) {
        cin >> i;
    }
    for (auto &i : a) {
        for (auto &j : i) {
            cin >> j;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int px = 0, py = 0;
            int dr;
            if (s[i][j] == 'r') {
                dr = 2;
            } else if (s[i][j] == 'l') {
                dr = 3;
            } else if (s[i][j] == 'u') {
                dr = 1;
            } else {
                dr = 0;
            }
            px = dx[dr] * a[i][j];
            py = dy[dr] * a[i][j];
            px += i;
            py += j;
            if (0 <= px && px < n && 0 <= py && py < m) {
                ++du[px][py];
            }
        }
    }
    int sx = -1, sy = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (du[i][j] == 0) {
                if (sx >= 0) {
                    cout << "No" << endl;
                    return;
                }
                sx = i;
                sy = j;
            }
        }
    }
    vector<vector<int>> vis(n, vector<int>(m));
    if (sx == -1 && sy == -1) {
        sx = 0;
        sy = 0;
    }
    int cnt = 0;
    while (0 <= sx && sx < n && 0 <= sy && sy < m && !vis[sx][sy]) {
        vis[sx][sy] = 1;
        ++cnt;
        int px = 0, py = 0;
        int dr;
        if (s[sx][sy] == 'r') {
            dr = 2;
        } else if (s[sx][sy] == 'l') {
            dr = 3;
        } else if (s[sx][sy] == 'u') {
            dr = 1;
        } else {
            dr = 0;
        }
        px = dx[dr] * a[sx][sy];
        py = dy[dr] * a[sx][sy];
        sx += px;
        sy += py;
    }
    if (cnt == n * m) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}