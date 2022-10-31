#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, m;
LL cnt[N];
map<int, vector<int>> mp;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int a, b;
        cin >> a >> b;
        mp[a].push_back(b);
    }
    for (auto& i : mp) {
        auto& ve = i.second;
        sort(ve.rbegin(), ve.rend());
        LL sum = 0;
        for (int j = 0; j < ve.size(); ++j) {
            sum += ve[j];
            if (sum >= 0) {
                cnt[j] += sum;
            } else {
                break;
            }
        }
    }
    cout << *max_element(cnt, cnt + n + 1) << endl;
    return 0;
}