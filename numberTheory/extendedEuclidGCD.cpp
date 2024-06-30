// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1045
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;


#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define mii map<int, int>
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define inf 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define mk(arr, n, type) type *arr = new type[n];
#define w(t)  \
    int t;    \
    cin >> t; \
    while (t--)
#define sp << " " <<
#define ms(a, value) memset(a, value, sizeof(a))
#define pb push_back
#define fi first
#define se second
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repA(i, a, n) for (int i = a; i <= (n); ++i)
#define repD(i, a, n) for (int i = a; i >= (n); --i)
#define trav(a, x) for (auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define N 20000000
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng used to shuffle syntax below
// shuffle(arr , arr+n , rng);
class Triplet
{
public:
    int x, y, z;
};
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
// indexed_set s;
// s.insert(value);
// auto p = s.find_by_order(idx);
// int q = s.order_of_key(value);

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
const int mod = 1e9 + 7;
// vector <int> adj[N];
// bool visited[N];
// vector<bool> is_prime(N+1, true);
string str;
map<int, int> freq;
const double PI = 3.1415926535897;

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

vi extendedGCD(int a, int b)
{
    if (b == 0)
    {
        return {1, 0, a};
    }
    vi ans = extendedGCD(b, a % b);

    int x1 = ans[0];
    int y1 = ans[1];

    int x = y1;
    int y = x1 - (a / b) * y1;
    return {x, y, ans[2]};
}

int main()
{
    // IOS();

    // int a, b;
    // cin >> a >> b;
    // if (cin.fail())
    // {
    //     return -1;
    // }
    // else
    // {
    //     int a, b;
    //     cin >> a >> b;
    //     vi ans = extendedGCD(a, b);
    //     cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
    // }

    int a, b;
    while (scanf("%d %d", &a, &b) != EOF)
    {
        // int a, b;
        // cin >> a >> b;
        vi ans = extendedGCD(a, b);
        cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
    }
    return 0;
}