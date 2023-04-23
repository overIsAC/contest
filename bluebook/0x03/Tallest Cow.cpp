#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

const int N = 3 + 1e3;

int pre[N];
set<PII> st;
int n, m, k, t;

int main() {
    cin >> n >> m >> k >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (a > b) {
            swap(a, b);
        }
        if (st.count({a, b})) {
            continue;
        }
        st.insert({a, b});
        --pre[a + 1];
        ++pre[b];
    }
    for (int i = 1; i <= n; ++i) {
        pre[i] += pre[i - 1];
    }
    for (int i = 1; i <= n; ++i) {
        cout << k - pre[m] + pre[i] << endl;
    }

    return 0;
}