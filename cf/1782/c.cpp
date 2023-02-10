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
    int T;
    cin >> T;
    while (T--) {
        string s;
        int n;
        cin >> n >> s;
        map<char, vector<int>> mp;
        for (int i = 0; i < n; ++i) {
            mp[s[i]].push_back(i);
        }
        vector<pair<char, vector<int>>> ve(mp.begin(), mp.end());
        sort(ve.begin(), ve.end(), [&](pair<char, vector<int>>& u, pair<char, vector<int>>& v) {
            return u.second.size() > v.second.size();
        });
        int dif = n * 2, p = 1;
        for (int i = 1; i <= 26; ++i) {
            if (n % i) {
                continue;
            }
            int cnt = 0;
            for (int j = 0; j < i && j < ve.size(); ++j) {
                cnt += min((int)ve[j].second.size(), n / i);
            }
            if (n - cnt < dif) {
                dif = n - cnt;
                p = i;
            }
        }
        vector<int> temp;
        dif = 0;
        while (ve.size() > p) {
            temp.insert(temp.end(), ve.back().second.begin(), ve.back().second.end());
            dif += ve.back().second.size();
            mp.erase(ve.back().first);
            ve.pop_back();
        }
        for (auto& i : ve) {
            if (i.second.size() == n / p) {
                continue;
            }
            while (i.second.size() > n / p) {
                ++dif;
                temp.push_back(i.second.back());
                i.second.pop_back();
            }
        }
        for (auto& i : ve) {
            if (i.second.size() < n / p) {
                int v = n / p - i.second.size();
                for (int j = 1; j <= v; ++j) {
                    int idx = temp.back();
                    temp.pop_back();
                    s[idx] = i.first;
                }
            }
        }
        for (int i = 'a'; i <= 'z' && temp.size(); ++i) {
            if (mp.count(i)) {
                continue;
            }
            for (int j = 1; j <= n / p; ++j) {
                int idx = temp.back();
                temp.pop_back();
                s[idx] = i;
            }
        }
        cout << dif << endl;
        cout << s << endl;
    }
    return 0;
}