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
const int N = 3 + 2e5;

int n, q;
char s[N];
set<int> st1, st2;

int main() {
    cin >> n >> q;
    cin >> s + 1;
    for (int i = 1; i < n; ++i) {
        if (s[i] == '(' && s[i + 1] == '(') {
            st1.insert(i);
        }
        if (s[i] == ')' && s[i + 1] == ')') {
            st2.insert(i);
        }
    }
    while (q--) {
        int p;
        cin >> p;
        if (p - 1 >= 1 && s[p] == '(' && s[p - 1] == '(') {
            st1.erase(p - 1);
        }
        if (p - 1 >= 1 && s[p] == ')' && s[p - 1] == ')') {
            st2.erase(p - 1);
        }
        if (p + 1 <= n && s[p] == '(' && s[p + 1] == '(') {
            st1.erase(p);
        }
        if (p + 1 <= n && s[p] == ')' && s[p + 1] == ')') {
            st2.erase(p);
        }
        s[p] = s[p] == ')' ? '(' : ')';
        if (p - 1 >= 1 && s[p] == '(' && s[p - 1] == '(') {
            st1.insert(p - 1);
        }
        if (p - 1 >= 1 && s[p] == ')' && s[p - 1] == ')') {
            st2.insert(p - 1);
        }
        if (p + 1 <= n && s[p] == '(' && s[p + 1] == '(') {
            st1.insert(p);
        }
        if (p + 1 <= n && s[p] == ')' && s[p + 1] == ')') {
            st2.insert(p);
        }
        if (s[1] != '(' || s[n] != ')' || n % 2) {
            cout << "No" << endl;
            continue;
        }
        db(s + 1);
        db(st1.size());
        db(st2.size());
        if (st1.empty() && st2.empty()) {
            db(__LINE__);
            cout << "Yes" << endl;
            continue;
        }
        if (st1.empty() || st2.empty()) {
            db(__LINE__);
            cout << "No" << endl;
            continue;
        }
        if (st2.lower_bound(*st1.rbegin()) == st2.end()) {
            db(__LINE__);
            cout << "No" << endl;
            continue;
        }
        if (st1.upper_bound(*st2.begin()) == st1.begin()) {
            db(__LINE__);
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
    }
    return 0;
}