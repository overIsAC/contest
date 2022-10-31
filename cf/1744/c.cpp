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
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, a[N], q;
char c;
char s[N];
int temp[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> c;
        cin >> s;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'g') {
                temp[i] = 0;
                int j = (i - 1 + n) % n;
                int cnt = 0;
                while (s[j] != 'g') {
                    temp[j] = ++cnt;
                    j = (j - 1 + n) % n;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == c) {
                ans = max(ans, temp[i]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}