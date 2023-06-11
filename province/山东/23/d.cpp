#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

const int N = 3 + 1e5;

int n, v[N], w[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> v[i] >> w[i];
        }
        int l = 1, r = 1e9;
        auto ok = [&](int o) -> bool {
            vector<int> x, y;
            for (int i = 1; i <= n; ++i) {
                if (v[i] < o) {
                    x.push_back(o + w[i]);
                } else if (v[i] + w[i] > o) {
                    y.push_back(v[i] + w[i]);
                }
            }
            if (x.size() > y.size()) {
                return 0;
            }
            sort(x.begin(), x.end());
            sort(y.begin(), y.end());
            int p1 = 0, p2 = 0;
            while (p1 < x.size() && p2 < y.size()) {
                if (x[p1] <= y[p2]) {
                    ++p1;
                }
                ++p2;
            }
            return p1 == x.size();
        };
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (ok(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        cout << r << endl;
    }
    return 0;
}