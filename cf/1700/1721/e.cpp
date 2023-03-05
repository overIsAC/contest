#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x)                                                             \
    cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " \
         << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e6 + 233;

char s[N];
int nxt[N];
pair<string, int> a[N];
pair<int, vector<int>> ans[N];

int main() {
    cin >> s + 1;
    int n = strlen(s + 1);

    for (int i = 2, j = 0; i <= n; ++i) {
        while (j && s[j + 1] != s[i]) {
            j = nxt[j];
        }
        if (s[j + 1] == s[i]) {
            ++j;
        }
        nxt[i] = j;
    }

    int q;
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + q + 1);
    int last = n;
    for (int qq = 1; qq <= q; ++qq) {
        int i = n;
        auto& t = a[qq].first;
        last = min<int>(last, n + t.size());
        while (i + 1 <= last && s[i + 1] == t[i - n]) {
            ++i;
        }
        last = n + t.size();
        for (int j = 0; j < t.size(); ++j) {
            s[n + j + 1] = t[j];
        }
        int j = nxt[i];
        i += 1;
        for (; i <= last; ++i) {
            while (j && s[j + 1] != s[i]) {
                j = nxt[j];
            }
            if (s[j + 1] == s[i]) {
                ++j;
            }
            nxt[i] = j;
        }
        for (int i = 0; i < t.size(); ++i) {
            ans[qq].second.push_back(nxt[i + n + 1]);
            ans[qq].first = a[qq].second;
        }
    }
    sort(ans + 1, ans + q + 1);
    for (int i = 1; i <= q; ++i) {
        for (auto& j : ans[i].second) {
            cout << j << ' ';
        }
        cout << endl;
    }
    return 0;
}