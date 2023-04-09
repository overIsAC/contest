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

bool isPrime(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return n > 1;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 1) {
            ans.push_back(a[i]);
        }
    }
    if (ans.size() > 1) {
        for (int i = 1; i <= n; ++i) {
            if (a[i] != 1 && isPrime(1 + a[i])) {
                ans.push_back(a[i]);
                break;
            }
        }
        cout << ans.size() << endl;
        for (auto &i : ans) {
            cout << i << ' ';
        }
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (isPrime(a[i] + a[j])) {
                cout << 2 << endl;
                cout << a[i] << ' ' << a[j] << endl;
                return 0;
            }
        }
    }
    cout << 1 << endl;
    cout << a[1] << endl;
    return 0;
}