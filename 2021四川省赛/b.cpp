#include <bits/stdc++.h>
using namespace std;

const int N = 3 + 1e5;

int n, k, m, a[N];
vector<int> ve[N];
int ans[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k >> m;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= k; ++i) {
            ve[i].clear();
        }
        for (int i = 1; i <= n; ++i) {
            ve[a[i]].push_back(i);
            ans[i] = 0;
        }
        for (int i = 1; i <= k; ++i) {
            auto &vec = ve[i];
            if (vec.empty()) {
                continue;
            }
            int u = m / (n * 2), v = m % (n * 2);
            for (int j = 1; j < vec.size() * 2; j += 2) {
                ans[vec[j % vec.size()]] += u;
            }
            for (int j = 1; j < vec.size() * 2; j += 2) {
                int p = vec[j % vec.size()];
                if (j >= vec.size()) {
                    p += n;
                }
                if (p <= v) {
                    ans[vec[j % vec.size()]] += 1;
                }
            }
        }
        cout << ans[1];
        for (int i = 2; i <= n; ++i) {
            cout << ' ' << ans[i];
        }
        // cout << endl;
        cout << '\n';
    }
    return 0;
}