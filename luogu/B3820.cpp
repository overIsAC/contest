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
const int N = 3 + 1e5;

void solve() {
    int n;
    string kk;
    cin >> n >> kk;
    vector<int> a(n), b(n);
    LL sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];

        sum += a[i];

        b[i] = a[i] % 154;
        a[i] %= 147;
    }
    LL k;
    if (kk.size() > 16) {
        k = 1e16;
    } else {
        k = stoll(kk);
    }

    vector<int> cnt1(200), cnt2(200);
    int flag = 0;

    if (sum >= k) {
        flag = 1;
    }

    for (auto& i : a) {
        ++cnt1[i];
    }
    for (auto& i : b) {
        ++cnt2[i];
    }

    for (int i = 0; i <= 147; ++i) {
        if (flag) {
            break;
        }
        for (int j = i + 1; j <= 147; ++j) {
            if (flag) {
                break;
            }
            if (cnt1[i] && cnt1[j] && i * j % 147 == 0) {
                flag = 1;
            }
        }
        if (i * i % 147 == 0 && cnt1[i] >= 2) {
            flag = 1;
        }
    }
    for (int i = 0; i <= 154; ++i) {
        if (flag) {
            break;
        }
        for (int j = i + 1; j <= 154; ++j) {
            if (flag) {
                break;
            }
            if (cnt2[i] && cnt2[j] && i * j % 154 == 0) {
                flag = 1;
            }
        }
        if (i * i % 154 == 0 && cnt2[i] >= 2) {
            flag = 1;
        }
    }
    if (flag) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}