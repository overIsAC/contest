#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        vector<PII> a(n);
        for (auto &i : a) {
            cin >> i.first >> i.second;
        }
        vector<PII> u, v, w;
        for (auto [x, y] : a) {
            if (x == y) {
                w.push_back({x, y});
            } else if (x > y) {
                u.push_back({x, y});
            } else {
                v.push_back({x, y});
            }
        }
        LL ans = 0;
        sort(v.begin(), v.end(), [](PII &u, PII &v) {
            return u.second - u.first > v.second - v.first;
        });
        /*
3123
1 2
2 1

2 3
1 5
1 5
        */
        if (u.empty()) {
            for (auto &i : w) {
                ans += i.second;
            }
            if (n * 2 - 1 <= m) {
                for (auto &i : v) {
                    ans += i.second;
                }
            } else {
                int cnt = 0;
                for (auto &i : v) {
                    if (cnt < m - n) {
                        ++cnt;
                        ans += i.second;
                    } else {
                        ans += i.first;
                    }
                }
            }
            cout << ans << endl;
            continue;
        }
        if (m == n || v.empty()) {
            for (auto &i : a) {
                if (n > 1) {
                    ans += i.first;
                } else {
                    ans += i.second;
                }
            }
            cout << ans << endl;
            continue;
        }
        if (w.size() || m - n < v.size() || u.size() > 1) {
            for (auto &i : u) {
                ans += i.first;
            }
            int cnt = 0;
            for (auto &i : v) {
                if (cnt < m - n) {
                    ++cnt;
                    ans += i.second;
                } else {
                    ans += i.first;
                }
            }
            for (auto &i : w) {
                ans += i.first;
            }
            cout << ans << endl;
            continue;
        }
        if (u.size() && v.size()) {
            LL x = u[0].first + v.back().first;
            LL y = u[0].second + v.back().second;
            if (x < y) {
                v.push_back(u[0]);
                u.erase(u.begin());
            } else {
                u.push_back(v.back());
                v.pop_back();
            }
        }
        for (auto &i : u) {
            ans += i.first;
        }
        for (auto &i : v) {
            ans += i.second;
        }
        for (auto &i : w) {
            ans += i.first;
        }
        cout << ans << endl;
    }

    return 0;
}