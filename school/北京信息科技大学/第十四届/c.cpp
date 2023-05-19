#include <bits/stdc++.h>
using namespace std;

const int N = 100 + 3;

int n, m, a[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
    }
    vector<int> b;
    for (int i = 1; i <= n; ++i) {
        b.push_back(i);
    }
    int p = 0;
    for (int i = 1; i <= m; ++i) {
        p += a[i];
        p %= b.size();
        cout << b[p] << ' ';
        b.erase(b.begin() + p);
    }
    return 0;
}