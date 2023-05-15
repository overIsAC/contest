#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

const int N = 3000;

PII a[N], b[N];
int n, m;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i].first >> b[i].second;
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    priority_queue<int, vector<int>, greater<int>> q;
    int ans = 0;
    for (int i = 1, j = 1; i <= m; ++i) {
        while (j <= n && b[i].first >= a[j].first) {
            q.push(a[j].second);
            ++j;
        }
        while (q.size() && q.top() < b[i].first) {
            q.pop();
        }
        while (q.size() && b[i].second) {
            --b[i].second;
            q.pop();
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}