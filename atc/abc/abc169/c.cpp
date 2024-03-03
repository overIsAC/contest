#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int main() {
    string a, b;
    cin >> a >> b;
    b.erase(b.begin() + b.find('.'));
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (auto &i : a) {
        i -= '0';
    }
    for (auto &i : b) {
        i -= '0';
    }
    vector<int> c(a.size() * b.size() + 10);
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
            c[i + j] += a[i] * b[j];
        }
    }
    for (int i = 0; i + 1 < c.size(); ++i) {
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
    while (c.size() && c.back() == 0) {
        c.pop_back();
    }
    reverse(c.begin(), c.end());
    for (int i = 1; i <= 2 && c.size(); ++i) {
        c.pop_back();
    }
    if (c.empty()) {
        c.push_back(0);
    }
    for (auto &i : c) {
        cout << i;
    }
    return 0;
}