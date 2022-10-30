#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#define db(x) cout << #x << ' ' << x << endl;

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 3e5;

char s[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cout << flush;
        cin >> s + 1;
        int n = strlen(s + 1);
        set<int> r, e, d, w;
        for (int i = 1; i <= n; ++i) {
            if (s[i] == '?')
                w.insert(i);
            else if (s[i] == 'r')
                r.insert(i);
            else if (s[i] == 'e')
                e.insert(i);
            else if (s[i] == 'd')
                d.insert(i);
        }
        bool ok = true;
        for (auto pe = e.begin(); pe != e.end(); ++pe) {
            int ve = *pe;
            auto pr = r.lower_bound(ve);
            auto pd = d.lower_bound(ve);
            if (pr == r.begin()) {
                auto pw = w.lower_bound(ve);
                if (pw == w.begin()) {
                    ok = false;
                    break;
                } else {
                    --pw;
                    w.erase(pw);
                }
            } else {
                --pr;
                r.erase(pr);
            }

            if (pd == d.end()) {
                auto pw = w.lower_bound(ve);
                if (pw == w.end()) {
                    ok = false;
                    break;
                } else {
                    w.erase(pw);
                }
            } else {
                d.erase(pd);
            }
        }

        if (!ok) {
            cout << "No\n";
            continue;
        }

        for (auto pr = r.begin(); pr != r.end();) {
            int vr = *pr;
            pr = r.erase(pr);

            auto pw = w.lower_bound(vr);
            if (pw == w.end()) {
                ok = false;
                break;
            }

            int vw = *pw;
            w.erase(pw);

            auto pd = d.lower_bound(vw);
            if (pd == d.end()) {
                auto pw = w.lower_bound(vr);
                if (pw == w.end()) {
                    ok = false;
                    break;
                }
                w.erase(pw);
                continue;
            }
            d.erase(pd);
        }

        if (!ok) {
            cout << "No\n";
            continue;
        }

        db(__LINE__);

        for (auto pd = d.rbegin(); pd != d.rend();) {
            int vd = *pd;
            ++pd;

            auto pw = w.lower_bound(vd);
            if (pw == w.begin()) {
                ok = false;
                break;
            }

            --pw;
            int vw = *pw;
            w.erase(pw);

            auto pr = r.lower_bound(vw);
            if (pr == r.begin()) {
                auto pw = w.lower_bound(vw);
                if (pw == w.begin()) {
                    ok = false;
                    break;
                }
                --pw;
                w.erase(pw);

                continue;
            }
            --pr;
            d.erase(pr);
        }

        if (!ok) {
            cout << "No\n";
            continue;
        }

        cout << "Yes\n";
    }
    return 0;
}