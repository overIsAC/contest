#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

int a[4][4];
char c;
int len;
vector<PII> ans;

vector<PII> get(int st) {
    vector<int> x(4), y(4);
    vector<vector<int>> b(4, vector<int>(4));
    vector<PII> ans;
    for (int i = 0; i < 16; ++i) {
        if (st >> i & 1) {
            x[i / 4] += 1;
            y[i % 4] += 1;
            ++b[i / 4][i % 4];
            ans.push_back({i / 4 + 1, i % 4 + 1});
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (x[i] + y[j] + a[i][j] + b[i][j] & 1) {
                len = 11111;
                return {};
            }
        }
    }
    len = ans.size();
    return ans;
}

int main() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> c;
            if (c == '+') {
                a[i][j] = 1;
            }
        }
    }
    int temp = 11111;
    for (int i = 0; i < 1 << 16; ++i) {
        auto t = get(i);
        if (len < temp) {
            temp = len;
            ans = t;
        }
    }
    cout << temp << endl;
    for (auto [x, y] : ans) {
        cout << x << ' ' << y << endl;
    }
    return 0;
}