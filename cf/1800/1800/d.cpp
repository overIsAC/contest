#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
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
const int mod[] = {7 + (int)1e9, 9 + (int)1e9, 998244353, 1073741789};
// const int mod = 998244353;
const int N = 3 + 2e5;

char s[N];
ULL p[4][N];
int n;
ULL v[4][N];

int main() {
    for (int j = 0; j < 4; ++j) {
        p[j][0] = 1;
        for (int i = 1; i < N; ++i) {
            p[j][i] = 131 * p[j][i - 1] % mod[j];
        }
    }
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> s + 1;
        set<pair<ULL, ULL>> st;
        for (int j = 0; j < 4; ++j) {
            for (int i = 1; i <= n; ++i) {
                v[j][i] = (v[j][i - 1] * 131 + s[i]) % mod[j];
            }
        }
        for (int i = 1; i < n; ++i) {
            ULL u[4];
            for (int j = 0; j < 4; ++j) {
                u[j] = v[j][i - 1] * p[j][n - (i + 1)] % mod[j];
                u[j] = (u[j] + v[j][n] - v[j][i + 1] + mod[j]) % mod[j];
            }
            st.insert({u[0] * 2000000000 + u[1], u[2] * 2000000000 + u[3]});
            cout << u[0] << ' ' << u[1] << ' ' << u[2] << ' ' << u[3] << endl;
        }
        cout << st.size() << endl;
    }
    return 0;
}