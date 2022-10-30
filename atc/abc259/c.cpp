#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
const double pi = acos(-1);
// const int mod = 998244353;
const int N = 3 + 1e5;

int main() {
    string a, b;
    vector<PII> q, w;
    cin >> a >> b;
    for (auto &i : a) {
        if (q.empty() || q.back().first != i) {
            q.push_back({i, 1});
        } else {
            ++q.back().second;
        }
    }
    for (auto &i : b) {
        if (w.empty() || w.back().first != i) {
            w.push_back({i, 1});
        } else {
            ++w.back().second;
        }
    }
    if (q.size() != w.size()) {
        cout << "No" << endl;
    } else {
        for (int i = 0; i < q.size(); ++i) {
            if (q[i].first != w[i].first || q[i].second > w[i].second) {
                cout << "No" << endl;
                return 0;
            } else if (q[i].second < w[i].second && q[i].second == 1) {
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
    }
    return 0;
}