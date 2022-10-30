#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int solve(vector<int> &a, vector<int> &b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int p1 = 0, p2 = 0;
    int ans = 0;
    while (p1 < a.size() && p2 < b.size()) {
        if (a[p1] == b[p2]) {
            ++ans;
            ++p1;
            ++p2;
        }
        if (a[p1] > b[p2]) {
            ++p2;
        }
        if (a[p1] < b[p2]) {
            ++p1;
        }
    }
    p1 = 0;
    int c = 0, d = ans;
    for (int i = 0, j = 0; i < b.size(); ++i) {
        while (p1 < a.size() && a[p1] <= b[i]) {
            if (a[p1] == b[i]) --d;
            ++c;
            ++p1;
        }
        while (j < b.size() && c < b[i] - b[j] + 1) ++j;
        ans = max(ans, i - j + 1 + d);
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        vector<int> a, b, c, d;
        int n, m, q;
        cin >> n >> m;
        while (n--) {
            cin >> q;
            if (q > 0)
                a.push_back(q);
            else
                b.push_back(-q);
        }
        while (m--) {
            cin >> q;
            if (q > 0)
                c.push_back(q);
            else
                d.push_back(-q);
        }
        cout << solve(a, c) + solve(b, d) << endl;
    }
    return 0;
}