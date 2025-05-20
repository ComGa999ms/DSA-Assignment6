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

int n, m;
map <char, int> e;
vector <int> adj[N];
char b[N];
bool vis[N];
int trace[N];

void bfs(int sta, int en) {
    if (sta == en) {
        cout << b[sta] << endl;
        return;
    }

    queue <int> q;
    q.push(sta);

    rep(i, 1, n) vis[i] = 0;
    vis[sta] = 1;
    trace[sta] = -1;

    while (q.size()) {
        int u = q.front(); q.pop();
        
        for (int v : adj[u]) {
            if (!vis[v]) {
                q.push(v);
                trace[v] = u;
                vis[v] = 1;
            }
        }
    }

    if (!vis[en]) {
        cout << "no_path";
        return;
    }

    vector <char> res;
    int i = en;
    while (i != -1) {
        // cout << b[i] << ' ';
        res.push_back(b[i]);
        i = trace[i];
    }

    repd(i, sz(res) - 1, 0) cout << res[i] << ' ';
    cout << endl;
}

void solve(void) {
    cin >> n >> m;
    rep(i, 1, n) {
        cin >> b[i];
        e[b[i]] = i;
    }
    rep(i, 1, m) {
        char u, v;
        cin >> u >> v;
        adj[e[u]].push_back(e[v]);
        // adj[e[v]].push_back(e[u]);
    }

    int ntest; cin >> ntest;
    while (ntest-- ) {
        char x, y;
        cin >> x >> y;

        // cout << e[x] << ' ' << e[y] << endl; 
        bfs(e[x], e[y]);
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    if (multitest) {
        int t; cin >> t;
        while (t-- ) solve();
    } else solve();

    return 0;
}