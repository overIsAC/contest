#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

const int N = 3 + 25000;
const int M = 3 + 1e6;

int n, m;
PII a[N];
int tr[M];

int main() {
    cin >> n >> m;
    for (int i= 1; i <= n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + n + 1, [](PII &a, PII &b) {
        return a.second < b.second;
    });
    memset(tr, 0x3f, sizeof(tr));
    
    tr[1] = 0;
    
    for (int i = 1; i <= n; ++i) {
        int ans = 1e9;
        for (int j = a[i].first; j <= m + 1; j += j & -j) {
            ans = min(ans, tr[j]);
        }
        for (int j = a[i].second + 1; j >= 1; j -= j & -j) {
            tr[j] = min(tr[j], ans + 1);
        }
    }
    
    int ans = tr[m + 1];
    if (ans > 1e8) {
        ans = -1;
    }
    cout << ans << endl;
    
    return 0;
}