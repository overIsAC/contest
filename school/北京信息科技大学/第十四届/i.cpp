#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 3 + 2e5;

int n, m, a[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int l = 1, r = 1e9;

    auto ok = [&](int v) {
        int cnt = 0;
        vector<int> b;
        for (int i = 1; i <= n; ++i) {
            if (a[i] <= v) {
                b.push_back(i);
            }
        }
        if (b.empty()) {
            return false;
        }
        if (b[0] == 1) { 
            for (int i = 1; i < b.size(); ++i) {
                if (abs(b[i] - b[i - 1]) == 1) {
                    b[i - 1] = 0;
                    ++i;
                }
            }
        } else {
            for (int i = (int)b.size() - 1; i - 1 >= 0; --i) {
                if (abs(b[i] - b[i - 1]) == 1) {
                    b[i] = 0;
                    --i;
                }
            }
        }

        sort(b.rbegin(), b.rend());
        while (b.size() && b.back() == 0) {
            b.pop_back();
        }
        cnt = b.size() * 2 - 1;
        if (b[0] > 1) {
            ++cnt;
        }
        if (b.back() < n) {
            ++cnt;
        }
        return cnt >= m;
    };

    // cout << ok(2) << endl;
    // return 0;

    while (l < r) {
        int mid = l + r >> 1;
        if (ok(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << r << endl;

    return 0;
}