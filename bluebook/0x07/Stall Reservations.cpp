#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

const int N = 3 + 5e4;

vector<int> a[N];
int n;
int b[N], ans[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int u, v;
        cin >> u >> v;
        a[i].push_back(u);
        a[i].push_back(v);
        a[i].push_back(i);
    }
    sort(a + 1, a + n + 1);
    priority_queue<PII, vector<PII>, greater<PII>> q;
    int id = 0;
    for (int i = 1; i <= n; ++i) {
        if (q.empty() || a[i][0] <= q.top().first) {
            ++id;
            q.push({a[i][1], id});
            ans[a[i][2]] = id;
        } else {
            auto [u, v] = q.top();
            q.pop();
            q.push({a[i][1], v});
            ans[a[i][2]] = v;
        }
    }
    cout << id << endl;
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}