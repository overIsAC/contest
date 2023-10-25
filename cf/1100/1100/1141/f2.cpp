#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, a[N];
map<int, vector<PII>> mp;

vector<PII> calc(vector<PII> a) {
    sort(a.begin(), a.end(), [&](PII &a, PII &b) {
        return a.second < b.second;
    });
    map<int, int> v, b;
    for (auto &i : a) {
        v[i.first];
        v[i.second];
    }
    int p = 0;
    for (auto &i : v) {
        i.second = ++p;
        b[p] = i.first;
    }
    vector<int> dp(p + 1);
    vector<int> cnt(p + 1);
    int j = 1;
    for (auto &i : a) {
        int L = v[i.first];
        int R = v[i.second];

        while (j <= R) {
            dp[j] = max(dp[j], dp[j - 1]);
            ++j;
        }
        dp[R] = max(dp[R], dp[L - 1] + 1);
        if (dp[R] == dp[L - 1] + 1) {
            cnt[R] = L;
        }
    }
    vector<PII> ans;
    for (int i = p; i >= 1;) {
        if (cnt[i]) {
            ans.push_back({b[cnt[i]], b[i]});
            i = cnt[i] - 1;
        } else {
            --i;
        }
    }
    return ans;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        int sum = 0;
        for (int j = i; j <= n; ++j) {
            sum += a[j];
            mp[sum].push_back({i, j});
        }
    }
    vector<PII> ans;
    for (auto &i : mp) {
        auto temp = calc(i.second);
        if (temp.size() > ans.size()) {
            swap(temp, ans);
        }
    }
    cout << ans.size() << endl;
    for (auto &i : ans) {
        cout << i.first << ' ' << i.second << endl;
    }
    return 0;
}