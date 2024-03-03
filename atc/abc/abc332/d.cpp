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
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, m;

vector<vector<int>> get1(vector<vector<int>> a, int i, int j) {
    swap(a[i], a[j]);
    return a;
}

vector<vector<int>> get2(vector<vector<int>> a, int i, int j) {
    for (int k = 0; k < n; ++k) {
        swap(a[k][i], a[k][j]);
    }
    return a;
}

int main() {
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m));
    for (auto& i : a) {
        for (auto& j : i) {
            cin >> j;
        }
    }
    for (auto& i : b) {
        for (auto& j : i) {
            cin >> j;
        }
    }
    queue<vector<vector<int>>> q;
    map<vector<vector<int>>, int> d;
    d[a] = 0;
    q.push(a);
    while (q.size()) {
        auto x = q.front();
        q.pop();
        if (x == b) {
            cout << d[x] << endl;
            return 0;
        }
        for (int i = 0; i + 1 < n; ++i) {
            auto y = get1(x, i, i + 1);
            if (d.count(y)) {
                continue;
            }
            d[y] = d[x] + 1;
            q.push(y);
        }
        for (int i = 0; i + 1 < m; ++i) {
            auto y = get2(x, i, i + 1);
            if (d.count(y)) {
                continue;
            }
            d[y] = d[x] + 1;
            q.push(y);
        }
    }
    cout << -1 << endl;

    return 0;
}