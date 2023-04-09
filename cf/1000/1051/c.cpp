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
const int N = 3 + 1e5;

int n, a[N];
int cnt[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    int x = 0, y = 0;
    for (int i = 1; i <= 100; ++i) {
        if (cnt[i] == 1) {
            ++x;
        } else if (cnt[i] >= 3) {
            ++y;
        }
    }
    if (x % 2 == 0) {
        cout << "YES" << endl;
        int c = 'A';
        for (int i = 1; i <= n; ++i) {
            if (cnt[a[i]] > 1) {
                cout << "A";
            } else {
                cout << (char)c;
                c = (int)'A' + 'B' - c;
            }
        }
        return 0;
    }
    if (y >= 1) {
        cout << "YES" << endl;
        int c = 'A';
        char v = 'A';
        for (int i = 1; i <= n; ++i) {
            if (cnt[a[i]] > 1) {
                if (cnt[a[i]] >= 3) {
                    if (y) {
                        y = 0;
                        cout << (char)c;
                        c = (int)'A' + 'B' - c;
                        v = c;
                    } else {
                        cout << v;
                    }
                } else {
                    cout << v;
                }
            } else {
                cout << (char)c;
                c = (int)'A' + 'B' - c;
            }
        }
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}