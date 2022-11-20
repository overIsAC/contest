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
const int N = 3 + 1000;

int n;
char a[N][N];
set<int> ans[N];
queue<int> q;
int du[N];
vector<int> edge[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> a[i][j];
            }
        }
        for (int i = 1; i <= n; ++i) {
            du[i] = 0;
            ans[i].clear();
            edge[i].clear();
            ans[i].insert(i);
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (a[i][j] == '1') {
                    edge[i].push_back(j);
                    du[j] += 1;
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (!du[i]) {
                q.push(i);

                db(i);
            }
        }
        while (q.size()) {
            int x = q.front();
            q.pop();
            for (auto &y : edge[x]) {
                if (!--du[y]) {
                    q.push(y);
                }
                ans[y].insert(ans[x].begin(), ans[x].end());
            }
        }
        for (int i = 1; i <= n; ++i) {
            cout << ans[i].size() << ' ';
            for (auto &j : ans[i]) {
                cout << j << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}