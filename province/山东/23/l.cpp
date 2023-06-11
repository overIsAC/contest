#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<vector<int>> ans;

    int x1 = 1, y1 = 1;
    int x2 = 1, y2 = n;
    int x3 = n, y3 = 1;
    int x4 = n, y4 = n;
    int len = n;
    while (len > 1) {
        int ax = a - x1 + 1, ay = b - y1 + 1;

        if (ax <= (len + 1) / 2 && ay <= (len + 1) / 2) {
            --len;
            ans.push_back({x4, y4, -len, -len});
            --y2;
            --x3;
            --x4;
            --y4;
            continue;
        }
        if (ax >= len - (len + 1) / 2 + 1 && ay >= len - (len + 1) / 2 + 1) {
            --len;
            ans.push_back({x1, y1, len, len});
            ++x1;
            ++y1;
            ++x2;
            ++y3;
            continue;
        }
        if (ax <= (len + 1) / 2 && ay >= len - (len + 1) / 2 + 1) {
            --len;
            ans.push_back({x3, y3, -len, len});
            ++y1;
            ++y3;
            --x3;
            --x4;
            continue;
        }
        if (ax >= len - (len + 1) / 2 + 1 && ay <= (len + 1) / 2) {
            --len;
            ans.push_back({x2, y2, len, -len});
            ++x1;
            ++x2;
            --y2;
            --y4;
            continue;
        }
        assert(false);
    }
    cout << "Yes" << endl;
    cout << ans.size() << endl;
    for (auto &i : ans) {
        for (auto &j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }
    return 0;
}
