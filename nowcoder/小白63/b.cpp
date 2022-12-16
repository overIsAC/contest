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

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, m;
int main() {
    cin >> n >> m;
    vector<int> a(n);
    for (int& i : a) {
        cin >> i;
    }
    LL ans = 0;
    int d = 2;
    while (m--) {
        int c = 0;
        for (auto it = a.begin(); it != a.end();) {
            if (d >= *it) {
                if (d == *it) {
                    d++;
                }
                it = a.erase(it);
            } else {
                *it -= d;
                ++it;
            }
        }
        ans += d;
    }
    cout << ans << endl;
    return 0;
}