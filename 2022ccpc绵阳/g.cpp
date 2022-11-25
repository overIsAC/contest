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
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    vector<int> ve;
    for (int i = 1; i <= n; ++i) {
        ve.push_back(a[i]);
    }
    while (ve.size() > 1) {
        vector<int> temp;
        for (int i = 0; i < ve.size(); ++i) {
            if (i && ve[i - 1] > ve[i]) {
                continue;
            }
            if (i + 1 < ve.size() && ve[i + 1] > ve[i]) {
                continue;
            }
            temp.push_back(ve[i]);
        }
        swap(ve,temp);
        ++ans;
    }
    cout << ans << endl;

    return 0;
}