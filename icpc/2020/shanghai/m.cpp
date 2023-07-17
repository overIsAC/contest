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

struct Node {
    map<int, Node *> ne;
    int bad;
    Node(int bad = 0) {
        this->bad = bad;
    }
};

void solve() {
    map<string, int> id;
    int n, m;
    cin >> n >> m;
    vector<string> a(n), b(m);
    for (auto &i : a) {
        cin >> i;
    }
    for (auto &i : b) {
        cin >> i;
    }
    Node root(1);

    for (auto &i : a) {
        Node *now = &root;
        string s;
        for (auto &j : i) {
            if (j == '/') {
                if (!id[s]) {
                    id[s] = id.size();
                }
                int t = id[s];
                if (!now->ne.count(t)) {
                    now->ne[t] = new Node();
                }
                now = now->ne[t];
                s = "";
            } else {
                s += j;
            }
        }
        if (!id[s]) {
            id[s] = id.size();
        }
        int t = id[s];
        if (!now->ne.count(t)) {
            now->ne[t] = new Node();
        }
    }

    for (auto &i : b) {
        Node *now = &root;
        string s;
        for (auto &j : i) {
            if (j == '/') {
                if (!id[s]) {
                    id[s] = id.size();
                }
                int t = id[s];
                if (!now->ne.count(t)) {
                    now->ne[t] = new Node(1);
                }
                now = now->ne[t];
                now->bad = 1;
                s = "";
            } else {
                s += j;
            }
        }
        if (!id[s]) {
            id[s] = id.size();
        }
        int t = id[s];
        if (!now->ne.count(t)) {
            now->ne[t] = new Node(1);
        }
        now = now->ne[t];
        now->bad = 1;
    }

    int ans = 0;
    function<void(Node *)> dfs = [&](Node *node) {
        if (!node->bad) {
            ++ans;
            return;
        }
        for (auto &[x, y] : node->ne) {
            dfs(y);
        }
    };
    dfs(&root);
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}