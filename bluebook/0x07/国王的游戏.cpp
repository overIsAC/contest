#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

const int N = 3 + 1e3;

int n, a, b;
PII c[N];

struct BigInt {
    vector<int> a;
    BigInt(int v = 0) {
        do {
            a.push_back(v % 10);
            v /= 10;
        } while (v);
    }
    BigInt operator*(int v) {
        BigInt t;
        vector<int>& ans = t.a;
        ans = this->a;
        int g = 0;
        for (int i = 0; i < ans.size(); ++i) {
            ans[i] *= v;
            ans[i] += g;
            g = ans[i] / 10;
            ans[i] %= 10;
        }
        while (g) {
            ans.push_back(g % 10);
            g /= 10;
        }
        return t;
    }
    BigInt operator/(int v) {
        BigInt t;
        vector<int>& ans = t.a;
        ans.clear();
        int g = 0;
        for (auto it = a.rbegin(); it != a.rend(); ++it) {
            g = g * 10 + *it;
            ans.push_back(g / v);
            g %= v;
        }
        reverse(ans.begin(), ans.end());
        while (ans.size() > 1 && ans.back() == 0) {
            ans.pop_back();
        }
        return t;
    }
    bool operator<(const BigInt& other) const {
        if (a.size() != other.a.size()) {
            return a.size() < other.a.size();
        }
        for (int i = a.size() - 1; i >= 0; ++i) {
            int u = a[i], v = other.a[i];
            if (u != v) {
                return u < v;
            }
        }
        return false;
    }
    friend ostream& operator<<(ostream& cout, BigInt& obj) {
        for (auto it = obj.a.rbegin(); it != obj.a.rend(); ++it) {
            cout << *it;
        }
        return cout;
    }
};

int main() {
    cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i].first >> c[i].second;
    }
    sort(c + 1, c + n + 1, [](PII& a, PII& b) {
        return a.first * a.second < b.first * b.second;
    });

    BigInt t(a), mx;
    for (int i = 1; i <= n; ++i) {
        auto o = t / c[i].second;
        if (mx < o) {
            mx = o;
        }
        t = t * c[i].first;
    }
    cout << mx << endl;

    return 0;
}