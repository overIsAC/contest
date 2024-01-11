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

string s, t;
vector<string> e, r;
string u, v;
map<string, int> d;
queue<string> q;

int main() {
    cin >> s >> t;
    while (cin >> u >> v) {
        e.push_back(u);
        r.push_back(v);
    }
    d[s] = 0;
    q.push(s);
    while (q.size()) {
        auto x = q.front();
        q.pop();
        if (x == t) {
            cout << d[x] << endl;
            return 0;
        }
        if (d[x] == 10) {
            continue;
        }
        for (int i = 0; i < e.size(); ++i) {
            for (int j = 0; j < x.size(); ++j) {
                if (x.substr(j, e[i].size()) == e[i]) {
                    string y = x.substr(0, j);
                    y += r[i];
                    y += x.substr(j + e[i].size());
                    if (!d.count(y)) {
                        d[y] = d[x] + 1;
                        q.push(y);
                    }
                }
            }
        }
    }
    cout << "NO ANSWER!" << endl;

    return 0;
}