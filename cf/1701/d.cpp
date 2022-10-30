#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 5e5;

struct Node {
    int x, y, id;
    bool operator<(const Node &b) const {
        return x < b.x || x == b.x && y < b.y;
    }
} a[N];

struct cmp {
    bool operator()(const Node &a, const Node &b) { return a.y > b.y; }
};

int n, b[N];
int ans[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (b[i] == 0) {
            a[i] = {i + 1, n, i};
        } else {
            a[i] = {i / (i[b] + 1) + 1, i / i[b], i};
        }
    }
    sort(a + 1, a + n + 1);
    priority_queue<Node, vector<Node>, cmp> q;
    for (int i = 1, j = 1; i <= n; ++i) {
        while (j <= n && a[j].x <= i) q.push(a[j++]);
        int id = q.top().id;
        q.pop();
        ans[id] = i;
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}