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

int n, s;
int a[N];
map <int, vector <pii>> m;

void solve(void) {
    cin >> n >> s;
    rep(i, 1, n) cin >> a[i];

    rep(i, 1, n) rep(j, 1, i - 1) {
        int cur = a[i] + a[j];
        if (cur > s) continue;

        if (m.find(s - cur) != m.end()) {
            for (auto &T : m[s - cur]) {
                if (T.fi != i && T.fi != j && T.se != i && T.se != j) {
                    cout << i << ' ' << j << ' ' << T.fi << ' ' << T.se;
                    return ;
                }
            }
        } else m[cur].push_back(pii(i, j));
    }
    cout << "IMPOSSIBLE";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    if (multitest) {
        int t; cin >> t;
        while (t-- ) solve();
    } else solve();

    return 0;
}