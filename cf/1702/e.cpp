#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n;
PII a[N];



int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        map<int, int> mp;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i].first >> a[i].second;
        }
        bool ok = true;
        for (int i = 1; i <= n; ++i) {
            if (++mp[a[i].first] > 2) ok = false;
            if (++mp[a[i].second] > 2) ok = false;
            if (a[i].first == a[i].second) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl; 
    }
    return 0;
}