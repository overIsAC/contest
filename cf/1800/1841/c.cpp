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
const int N = 3 + 2e5;

int n;
char s[N];
int a[N];
int cc[] = {1, 10, 100, 1000, 10000};
int mx[N];

int get(char c) {
    return cc[c - 'A'];
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> s + 1;
        n = strlen(s + 1);
        mx[n + 1] = 0;
        for (int i = n; i >= 1; --i) {
            a[i] = get(s[i]);
            if (mx[i + 1] > get(s[i])) {
                a[i] = -a[i];
            }
            mx[i] = max(mx[i + 1], get(s[i]));
        }
        LL sum = accumulate(a + 1, a + n + 1, 0LL);
        map<int, LL> mp;
        LL ans = sum;
        for (int i = 1; i <= n; ++i) {
            for (auto &j : cc) {
                LL temp = sum - a[i];
                  if (mx[i + 1] > j) {
                    temp -= j;
                } else {
                    temp += j;
                }
                for (auto &[x, y] : mp) {
                    temp -= y;
                    if (max(mx[i + 1], j) > abs(x)) {
                        temp -= abs(y);
                    } else {
                        temp += abs(y);
                    }
                }
                ans = max(ans, temp);
            }
            mp[a[i]] += a[i];
            for (auto it = mp.begin(); it != mp.end();) {
                if (abs(it->first) < abs(a[i])) {
                    it = mp.erase(it);
                } else {
                    ++it;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}