// works for weighted graph
// single source shortest path SSSP
// greedy algo
// uses priority queue
// IMPORTANT dijkstra does not work for NEGAVTIVE
// weight edges
// if weight is negative then use bellman ford algo

// Problem link
// https://www.spoj.com/problems/EZDIJKST/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define mii map<int, int>
#define w(t)  \
    int t;    \
    cin >> t; \
    while (t--)
#define ms(a, value) memset(a, value, sizeof(a))
#define pb push_back
#define fi first
#define se second
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repA(i, a, n) for (int i = a; i <= (n); ++i)
#define repD(i, a, n) for (int i = a; i >= (n); --i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define N 20000000
const int mod = 1e9 + 7;
// vector <int> adj[N];
// bool visited[N];

const int INF = LONG_MAX;
vector<pair<int, int>> adj[N];

void dijkstra(int s, vector<int> &d, vector<int> &p)
{
    // int n = adj.size();
    // d.assign(n, INF);
    // p.assign(n, -1);

    d[s] = 0;
    set<pair<int, int>> q;
    q.insert({0, s});
    while (!q.empty())
    {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : adj[v])
        {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to])
            {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
}

vector<int> restore_path(int s, int t, vector<int> const &parent)
{
    vector<int> path;
    for (int v = t; v != s; v = parent[v])
    {
        path.push_back(v);
    }
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}

void IOS()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int32_t main()
{
    IOS();
    w(t)
    {

        int n, m;
        cin >> n >> m;
        int p, q;
        rep(i, n + 1)
        {
            adj[i].clear();
        }
        vi dist(n + 1, INF), parent(n + 1, -1);
        rep(i, m)
        {
            int a, b, w;
            cin >> a >> b >> w;
            adj[a].pb({b, w});
            // adj[b].pb({a, w});
        }
        cin >> p >> q;
        dijkstra(p, dist, parent);
        if (dist[q] != INF)
        {
            cout << dist[q] << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}