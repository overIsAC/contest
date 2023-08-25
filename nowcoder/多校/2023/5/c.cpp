#include <bits/stdc++.h>
using namespace std;

const int N = 3 + 3e3;

int n, a[N][N];

int du1[N], du2[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            if (a[i][j]) {
                ++du1[i];
                ++du2[j];
            }
        }
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; ++i) {
        if (du1[i]) {
            ++cnt1;
        }
        if (du2[i]) {
            ++cnt2;
        }
    }
    cout << min(cnt1, cnt2) << endl;

    return 0;
}