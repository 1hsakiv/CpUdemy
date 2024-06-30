#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int N = 1e5 + 1, mod = 1e9 + 7;
vector<int> adj[N];
int dp[N][2];

int calc(int cur, int paint, int par)
{
    int &ans = dp[cur][paint];

    if (ans != -1){
        return ans;
    }
        

    ans = 1;
    for (auto child : adj[cur])
    {
        if (child != par)
        {
            if (paint)
            {
                ans *= calc(child, 0, cur) + calc(child, 1, cur);
            }
            else
            {
                ans *= calc(child, 1, cur);
            }
            ans %= mod;
        }
    }
    return ans;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(dp, -1, sizeof(dp));
    cout << (calc(1, 1, 0) + calc(1, 0, 0))%mod;
    return 0;
}