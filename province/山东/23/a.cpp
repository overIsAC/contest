#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<PII> a(n);
        LL cost = 0;
        for (auto &i : a) {
            cin >> i.first >> i.second;
        }
        sort(a.begin(), a.end());
        int ok = 1;
        for (auto &i : a) {
            if (i.second <= (LL)i.first * m - cost) {
                cost += i.second;
            } else {
                ok = 0;
                break;
            }
        }
        if (ok) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}