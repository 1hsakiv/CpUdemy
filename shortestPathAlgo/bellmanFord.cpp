// weighted graphs
// single source shortest paths SSSP
// bellman ford WORKS FOR NEGATIVE WEIGHT EDGES
// bellman ford is based on dynamic programming
// https://basecamp.eolymp.com/en/problems/1453
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
#define N 2000
const int mod = 1e9 + 7;
vector<int> adj[N];
// bool visited[N];

// void IOS()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
// }

int32_t main()
{
    // IOS();
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    rep(i, m)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges.pb({a, b, w});
    }

    vi dist(n + 1, INT_MAX);
    dist[1] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (vi edge : edges)
        {
            int v = edge[1];
            int u = edge[0];
            int wt = edge[2];
            if (dist[u] != INT_MAX && dist[v] > dist[u] + wt)
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // checking for negative edge cycle
    // same code for iteration and even if wt changes then negative weight 
    // cycle exist

    
    // for (vi edge : edges)
    // {
    //     for (vi edge : edges)
    //     {
    //         int v = edge[1];
    //         int u = edge[0];
    //         int wt = edge[2];
    //         if (dist[u] != INT_MAX && dist[v] > dist[u] + wt)
    //         {
    //             // dist[v] = dist[u] + wt;
    //             cout<<"Negative Edge Cycle exit";
    //             return 0;
    //         }
    //     }
    // }

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INT_MAX)
        {
            cout << "30000 ";
        }
        else
        {
            cout << dist[i] << " ";
        }
    }

    return 0;
}