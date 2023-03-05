#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

const int mod = 7 + 1e9;
const int N = 3 + 1e5;

int n, a[N];
bool vis[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        bool ok = false;
        for (int i = 2; i < n; ++i) {
            if (__gcd(i, n - i - 1) == 1) {
                cout << i << ' ' << n - i - 1 << ' ' << 1 << endl;
                break;
            }
        }
    }
    return 0;
}