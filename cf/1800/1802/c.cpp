#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 200;

int n, m;
LL a[N][N];

int main() {
    a[1][1] = 1;
    for (int i = 2; i < N; ++i) {
        a[i][1] = i * 1024;
    }
    for (int i = 2; i < N; ++i) {
        a[1][i] = i * (1LL << 50);
    }
    for (int i = 2; i < N; ++i) {
        for (int j = 2; j < N; ++j) {
            a[i][j] = a[1][1] ^ a[1][j] ^ a[i][1];
        }
    }
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        cout << n * m << endl;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cout << a[i][j] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}