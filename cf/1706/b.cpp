#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, a[N];
vector<int> ve[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            ve[i].clear();
        }
        for (int i = 1; i <= n; ++i) {
            ve[a[i]].push_back(i);
        }
        for (int i = 1; i <= n; ++i) {
            int b[2] = {0};
            for (int j = 0; j < ve[i].size(); ++j) {
                int &p = ve[i][j];
                b[p & 1] = max(b[p & 1], b[p & 1 ^ 1] + 1);
            }
            cout << max(b[0], b[1]) << ' ';
        }
        cout << endl;
    }
    return 0;
}