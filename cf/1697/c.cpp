#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

string a, b;
int n;

void solve() {
    int c = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 'a') ++c;
        if (b[i] == 'a') --c;
        if (c < 0) {
            cout << "NO" << endl;
            return;
        }
        if (a[i] == 'c' || b[i] == 'c') {
            if (c) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == 'c') ++c;
        if (b[i] == 'c') --c;
        if (c < 0) {
            cout << "NO" << endl;
            return;
        }
        if (a[i] == 'a' || b[i] == 'a') {
            if (c) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> a >> b;
        if (count(a.begin(), a.end(), 'a') != count(b.begin(), b.end(), 'a')) {
            cout << "NO" << endl;
            continue;
        }
        if (count(a.begin(), a.end(), 'b') != count(b.begin(), b.end(), 'b')) {
            cout << "NO" << endl;
            continue;
        }
        if (count(a.begin(), a.end(), 'c') != count(b.begin(), b.end(), 'c')) {
            cout << "NO" << endl;
            continue;
        }
        solve();
    }
    return 0;
}