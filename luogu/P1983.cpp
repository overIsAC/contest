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
const int N = 3 + 1e3;

int n, m;
// vector<int> edge[N];
int edge[N][N];
int du[N];
queue<int> q;
int maxLenth[N];

int main() {
    cin >> n >> m;
    while (m--) {
        int t;
        cin >> t;
        vector<int> seq(t);
        for (auto& i : seq) {
            cin >> i;
        }

        for (int i = 0; i + 1 < seq.size(); ++i) {
            for (int j = seq[i] + 1; j <= seq[i + 1] - 1; ++j) {
                for (int k : seq) {
                    // edge[j].push_back(k);
                    edge[j][k] = 1;
                    // ++du[k];
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (edge[i][j]) {
                ++du[j];
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!du[i]) {
            q.push(i);
            maxLenth[i] = 1;
        }
    }
    while (q.size()) {
        int x = q.front();
        q.pop();
        // for (auto& y : edge[x]) {
        for (int y = 1; y <= n; ++y) {
            if (!edge[x][y]) {
                continue;
            }
            if (!--du[y]) {
                q.push(y);
            }
            maxLenth[y] = max(maxLenth[y], maxLenth[x] + 1);
        }
    }
    cout << *max_element(maxLenth + 1, maxLenth + n + 1) << endl;

    return 0;
}