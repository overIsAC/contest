#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;
using LL = long long;

int l, r, b, k;

int main() {
    cin >> l >> r >> b >> k;
    cout << (LL)(l + b - 1) / b * b * k << endl;
    return 0;
}