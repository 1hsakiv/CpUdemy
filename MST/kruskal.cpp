// https://www.spoj.com/problems/MST/
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

// call make_function to initilize the dsu
unordered_map<int, int> father;
unordered_map<int, int> len;
// we can use len map to store rank of graph in given data

void make_set(int v)
{
    father[v] = v;
    len[v] = 1;
}

void make_father(int x, int y)
{
    repA(i, x, y)
    {
        make_set(i);
    }
}

int _find(int v)
{
    if (v == father[v])
        return v;
    return father[v] = _find(father[v]);
}

void _union(int a, int b)
{
    a = _find(a);
    b = _find(b);
    if (a != b)
        father[b] = a;
}

int32_t main()
{
    IOS();
    int n, m;
    cin >> n >> m;
    vector<vi> edge;
    rep(i, m)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edge.pb({w, a, b});
    }
    sort(all(edge));
    make_father(1, n);
    int mstWeight = 0;
    rep(i, sz(edge))
    {
        int x = edge[i][1];
        int y = edge[i][2];

        if (_find(x) != _find(y))
        {
            mstWeight += edge[i][0];
            _union(x, y);
        }
    }
    cout << mstWeight << endl;
    return 0;
}