#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e3;

int fa[N], n;
char s[N];
int pre[26];

int main() {
    cin >> n;
    int now = 0;
    for (int i = 1; i <= n; ++i) {
        cout << "? 2 1 " << i << endl;
        int x;
        cin >> x;
        if (x > now) {
            pre[now] = i;
            now = x;
        }
    }
    for (int i = 0; i < now; ++i) {
        cout << "? 1 " << pre[i] << endl;
        cin >> s[pre[i]];
    }
    for (int i = 1; i <= n; ++i) {
        if (s[i]) {
            continue;
        }
        vector<int> ve;
        for (int j = 0; j < 26; ++j) {
            if (pre[j] && pre[j] < i) ve.push_back(j);
        }
        sort(ve.begin(), ve.end(),
             [&](const int &a, const int &b) { return pre[a] < pre[b]; });
        int l = 0, r = ve.size() - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1, x;
            cout << "? 2 " << pre[ve[mid]] << ' ' << i << endl;
            cin >> x;
            if (x == ve.size() - mid)
                l = mid;
            else
                r = mid - 1;
        }
        s[i] = s[pre[ve[r]]];
        pre[ve[r]] = i;
    }
    cout << "! ";
    cout << s + 1 << endl;
    return 0;
}