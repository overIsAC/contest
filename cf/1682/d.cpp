#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

char s[N];
int n;

void solve() {
    int c = 0;
    for (int i = 0; i < n; ++i) {
        s[i] -= '0';
        c += s[i];
    }
    if ((c & 1) || c == 0) {
        cout << "NO" << endl;
        return;
    }
    vector<PII> ans;
    int b = 0;
    for (int i = n; ans.size() < n - 1; ++i) {
        if (s[i % n] == 0) continue;
        int j = i + 1;
        while (s[j % n] == 0) {
            ans.push_back({(j - 1) % n, j % n});
            ++j;
        }
        if (b) {
            ans.push_back({b % n, (j - 1) % n});
        } else {
            b = j - 1;
        }
        i = j - 1;
    }
    cout << "YES" << endl;
    for (auto &i : ans) {
        cout << i.first + 1 << ' ' << i.second + 1 << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> s;
        solve();
    }
    return 0;
}