#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

const int mod = 7 + 1e9;
const int N = 3 + 2e5;

char s[N];
int pre[N][2];
int n;

bool ok(int v) {
    for (int i = 1, j = 1; i <= n; ++i) {
        while (pre[i][0] - pre[j - 1][0] > v) ++j;
        if (pre[j - 1][1] + pre[n][1] - pre[i][1] <= v) {
            return true;
        }
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> s + 1;
        n = strlen(s + 1);
        for (int i = 1; i <= n; ++i) {
            pre[i][0] = pre[i - 1][0];
            pre[i][1] = pre[i - 1][1];
            ++pre[i][s[i] - '0'];
        }
        int l = 0, r = n;
        while (l < r) {
            int mid = l + r >> 1;
            if (ok(mid))
                r = mid;
            else
                l = mid + 1;
        }
        cout << r << endl;
    }

    return 0;
}