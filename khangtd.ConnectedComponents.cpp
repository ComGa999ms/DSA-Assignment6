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

int n, m, s;
vector <int> res, adj[N];
bool vis[N];

void bfs(int x) {
    queue <int> q;
    q.push(x);
    vis[x] = 1;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        res.push_back(u);

        for (auto v : adj[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }
}

void solve(void) {
    cin >> n >> m;
    rep(i, 1, m) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin >> s;
    bfs(s);

    cout << sz(res) << endl;
    sort(all(res));
    for (auto u : res) cout << u << " ";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    if (multitest) {
        int t; cin >> t;
        while (t-- ) solve();
    } else solve();

    return 0;
}