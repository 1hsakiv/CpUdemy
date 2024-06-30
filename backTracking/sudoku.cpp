#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
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

void printBoard(int grid[][9], int n)
{
    rep(i, 9)
    {
        rep(j, 9)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

bool allAssigned(int grid[][9], int &row, int &col, int n)
{
    for (row = 0; row < 9; row++)
    {
        for (col = 0; col < 9; col++)
        {
            if (grid[row][col] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

bool safeinRow(int grid[][9], int option, int col)
{
    for (int row = 0; row < 9; row++)
    {
        if (grid[row][col] == option)
        {
            false;
        }
    }
    return true;
}

bool safeInCol(int grid[][9], int option, int row)
{
    for (int col = 0; col < 9; col++)
    {
        if (grid[row][col] == option)
        {
            false;
        }
    }
    return true;
}

bool safeInBox(int grid[][9], int row, int col, int option)
{
    for(int sx = row-row%3; sx < row-row%3+3; sx++){
        for(int sy = col-col%3; sy < col-col%3+3; sy++){
            if(grid[sx][sy] == option){
                return false;
            }
        }
    }
    return true;
}

bool safe(int grid[][9], int option, int row, int col)
{
    if (safeinRow(grid, option, col) && safeInCol(grid, option, row) && safeInBox(grid, row, col, option))
    {
        return true;
    }
    return false;
}

bool solveSudoku(int grid[][9], int n)
{
    // base case
    int row, col;
    if(allAssigned(grid, row, col, n))
    {
        printBoard(grid, n);
        return true;
    }

    for (int option = 1; option <= 9; option++)
    {
        if (safe(grid, option, row, col))
        {
            grid[row][col] = option;
            if (solveSudoku(grid, n))
            {
                return true;
            }
        }
    }
    return false;
}

int32_t main()
{
    int n = 9;
    int grid[9][9] =
        {{5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}};

    if (!solveSudoku(grid, n))
    {
        cout << "No solution exists!";
    }
    return 0;
}