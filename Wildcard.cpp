#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define repd(i, r, l) for (int i = r; i >= l; --i)
#define _unique(x) (x).resize(unique((x).begin(), (x).end()) - (x).begin());
#define sz(v) (int)(v).size()
#define fi first
#define se second
#define pii pair<int,int>
#define p2i pair<int,pii>
#define endl "\n"

using namespace std;

const int N = 1e6 + 5;
const int inf = 1e18 + 7;
const bool multitest = 0;

int n, q;
string s[N];

void solve(void) {
    cin >> n >> q;
    rep(i, 1, n) cin >> s[i];

    while (q--) {
        string t;
        cin >> t;

        int res = 0;

        int pos = t.find('*');
        if (pos == -1) {
            rep(i, 1, n) if (s[i] == t) ++res;
        } else {
            string pre = t.substr(0, pos);
            string suf = t.substr(pos + 1);
            
            rep(i, 1, n) {
                // *
                if (sz(pre) == 0 && sz(suf) == 0) {
                    ++res;
                    continue;
                }
                
                // *suf
                if (sz(pre) == 0) {
                    if (sz(s[i]) >= sz(suf) && s[i].substr(sz(s[i]) - sz(suf)) == suf) ++res;
                    continue;
                }

                // pre*
                if (sz(suf) == 0) {
                    if (sz(s[i]) >= sz(pre) && s[i].substr(0, sz(pre)) == pre) ++res;
                    continue; 
                }
                
                // pre*suf
                if (sz(s[i]) >= sz(pre) + sz(suf)) {
                    int id = s[i].find(pre);
                    if (id != -1) {
                        string temp = s[i].substr(id + sz(pre));
                        if (temp.find(suf) != -1) ++res;
                    }
                } 
            }
        }
        cout << res << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    if (multitest) {
        int t; cin >> t;
        while (t--) solve();
    } else solve();

    return 0;
}