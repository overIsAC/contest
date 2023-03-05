#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, k;
char s[N];

int main() {
    cin >> n >> k;
    cin >> s;
    cout << n << endl;
    bool ok = true;
    for (int i = k; i < n; ++i) {
        if (s[i % k] > s[i]) {
            for (int i = 0; i < n; ++i) {
                cout << s[i % k];
            }
            return 0;
        }
        if (s[i % k] < s[i]) {
            ok = false;
            break;
        }
    }
    if (!ok) {
        ++s[k - 1];
        for (int i = k - 1; i >= 0 && s[i] == '9' + 1; --i) {
            s[i] = '0';
            ++s[i - 1];
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << s[i % k];
    }
    return 0;
}