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
const int N = 3 + 5e3;

int n, m;
char s[N];
int d[N][N];

struct Trie {
    int tr[N][26], id, end[N];
    void insert(char *s) {
        int rt = 0;
        int n = strlen(s + 1);
        for (int i = 1; i <= n; ++i) {
            int c = s[i] - 'a';
            int &p = tr[rt][c];
            if (!p) {
                p = ++id;
            }
            rt = p;
        }
        end[rt] = 1;
    }
} a, b;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> s + 1;
        a.insert(s);
    }
    for (int i = 1; i <= m; ++i) {
        cin >> s + 1;
        b.insert(s);
    }

    memset(d, 0x3f, sizeof(d));
    d[0][0] = 0;
    queue<PII> q;
    q.push({0, 0});

    auto transfer = [&](int u, int v, int x, int y) {
        if (x && y) {
            if (d[x][y] > d[u][v] + 1) {
                d[x][y] = d[u][v] + 1;
                q.push({x, y});
            }
        }
    };

    while (q.size()) {
        auto [u, v] = q.front();
        q.pop();
        if (a.end[u] && b.end[v]) {
            cout << d[u][v] << endl;
            return 0;
        }
        for (int i = 0; i < 26; ++i) {
            {
                int x = a.tr[u][i], y = b.tr[v][i];
                transfer(u, v, x, y);
            }
            {
                if (b.end[v]) {
                    int x = a.tr[u][i], y = b.tr[0][i];
                    transfer(u, v, x, y);
                }
            }
            {
                if (a.end[u]) {
                    int x = a.tr[0][i], y = b.tr[v][i];
                    transfer(u, v, x, y);
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}