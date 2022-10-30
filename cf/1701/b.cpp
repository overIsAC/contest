#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int f[N][20];
int pre[N][20];
int n;
bool vis[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) vis[i] = false;
        cout << 2 << endl;
        for (int i = 1; i <= n; ++i) {
            if (vis[i]) continue;
            for (int j = i; j <= n; j *= 2) {
                cout << j << ' ';
                vis[j] = true;
            }
        }
        cout << endl;
    }

    return 0;
}