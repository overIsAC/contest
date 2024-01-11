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

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

string s = "123804765", t;
map<string, int> d;
queue<string> q;

PII getXY(string s) {
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0') {
            return {i / 3, i % 3};
        }
    }
    return {0, 0};
}

int main() {
    cin >> t;

    d[s] = 0;
    q.push(s);

    while (q.size()) {
        auto u = q.front();
        q.pop();

        PII xy = getXY(u);
        int x = xy.first, y = xy.second;

        if (t == u) {
            cout << d[t] << endl;
            return 0;
        }

        for (int i = 0; i < 4; ++i) {
            int tx = x + dx[i], ty = y + dy[i];
            if (0 <= tx && tx < 3 && 0 <= ty && ty < 3) {
                string v = u;
                swap(v[x * 3 + y], v[tx * 3 + ty]);
                if (d.count(v)) {
                    continue;
                }
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }

    cout << d[t] << endl;

    return 0;
}