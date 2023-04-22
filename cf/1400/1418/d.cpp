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

multiset<int> s1, s2;

void insert(int v) {
    auto p = s1.lower_bound(v);
    if (p != s1.begin() && p != s1.end()) {
        auto pp = p;
        --pp;
        s2.erase(s2.find(abs(*p - *pp)));
    }
    if (p != s1.end()) {
        s2.insert(abs(v - *p));
    }
    if (p != s1.begin()) {
        --p;
        s2.insert(abs(v - *p));
    }
    s1.insert(v);
}

void remove(int v) {
    s1.erase(s1.find(v));
    auto p = s1.lower_bound(v);
    if (p != s1.end()) {
        s2.erase(s2.find(abs(v - *p)));
    }
    if (p != s1.begin()) {
        auto pp = p;
        --pp;
        s2.erase(s2.find(abs(v - *pp)));
    }
    if (p != s1.begin() && p != s1.end()) {
        auto pp = p;
        --pp;
        s2.insert(abs(*p - *pp));
    }
}

void output() {
    if (s1.size() <= 1) {
        cout << 0 << endl;
    } else {
        cout << *prev(s1.end()) - *s1.begin() - *prev(s2.end()) << endl;
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    while (n--) {
        int v;
        cin >> v;
        insert(v);
    }
    output();
    while (q--) {
        int op, v;
        cin >> op >> v;
        if (op == 0) {
            remove(v);
        } else {
            insert(v);
        }
        output();
    }
    return 0;
}