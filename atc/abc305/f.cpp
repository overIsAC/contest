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

int n, m;
int vis[N];

vector<int> read() {
    int k;
    cin >> k;
    vector<int> edge;
    while (k--) {
        int y;
        cin >> y;
        edge.push_back(y);
    }
    return edge;
}

void dfs(int x) {
    if (x == n) {
        exit(0);
    }
    vis[x] = 1;

    auto edge = read();

    for (auto &y : edge) {
        if (vis[y]) {
            continue;
        }
        cout << y << endl;
        dfs(y);
        cout << x << endl;
        read();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    dfs(1);
    return 0;
}