#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

vector<int> edge[N];
int n;
int ans[N], fa[N];
int b[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            ans[i] = 0;
        }
        int root = 0;
        for (int i = 1; i <= n; ++i) {
            int j;
            cin >> j;
            if (i == j) {
                root = j;
                continue;
            }
            fa[i] = j;
        }
        for (int i = 1; i <= n; ++i) {
            cin >> b[i];
        }
        if (root != b[1]) {
            cout << -1 << endl;
            continue;
        }
        int last = 0;
        bool ok = true;
        for (int i = 2; i <= n; ++i) {
            
        }
    }
    return 0;
}