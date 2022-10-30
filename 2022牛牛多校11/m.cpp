#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int main() {
    vector<vector<double>> tb;

    tb.push_back({1, 1, 0.8, 0.5, 0});
    tb.push_back({2, 2, 1.6, 1.0, 0});
    tb.push_back({3, 3, 2.4, 1.5, 0});
    tb.push_back({5, 5, 2.5, 2, 0});
    tb.push_back({1, 0.5, 0.4, 0.3, 0});

    double a = 0, b = 0;
    double A = 0, B = 0;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 5; ++j) {
            double c;
            cin >> c;
            a += tb[i][j] * c;
            A += tb[i][0] * c;
        }
    }

    for (int j = 0; j < 5; ++j) {
        double c;
        cin >> c;
        a += tb[3][j] * c;
        A += tb[3][0] * c;
        b += tb[4][j] * c;
        B += tb[4][0] * c;
    }
    cout << fixed << setprecision(10) << a / A * 100 + b / B << endl;

    return 0;
}