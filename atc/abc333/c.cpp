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

int main() {
    set<LL> st;
    vector<LL> a;
    for (LL i = 1; i <= 1e17; i = i * 10 + 1) {
        a.push_back(i);
    }
    for (auto& i : a) {
        for (auto& j : a) {
            for (auto& k : a) {
                st.insert(i + j + k);
            }
        }
    }
    int k;
    cin >> k;
    cout << vector(st.begin(), st.end())[k - 1] << endl;
    return 0;
}