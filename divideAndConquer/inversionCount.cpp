// https://www.interviewbit.com/problems/inversions/
// similar to mergeSort
// add one line in merge function
// time -> O(nlogn)

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

int merge(vi &nums, int l, int mid, int r)
{
    int l1 = mid - l + 1;
    int l2 = r - mid;
    int inv = 0;

    vi temp1(l1, 0), temp2(l2, 0);

    for (int i = 0; i < l1; i++)
    {
        temp1[i] = nums[l + i];
    }

    for (int i = 0; i < l2; i++)
    {
        temp2[i] = nums[mid + 1 + i];
    }

    int i = 0, j = 0, k = l;

    while (i < l1 && j < l2)
    {
        if (temp1[i] < temp2[j])
        {
            nums[k++] = temp1[i++];
        }
        else
        {
            inv += l1-i;
            nums[k++] = temp2[j++];
        }
    }

    while (i < l1)
    {
        nums[k++] = temp1[i++];
    }

    while (j < l2)
    {
        nums[k++] = temp2[j++];
    }

    return inv;
}

int mergeSort(vi &nums, int l, int r)
{
    int inv = 0;
    if (l < r)
    {
        int mid = (l + r) / 2;
        inv += mergeSort(nums, l, mid);
        inv += mergeSort(nums, mid + 1, r);
        inv += merge(nums, l, mid, r);
    }
    return inv;
}

int countInversions(vector<int> &nums)
{
    int l = 0;
    int r = nums.size() - 1;
    return mergeSort(nums, l, r);
}

int32_t main()
{
    IOS();
    w(t)
    {
        vi nums = {2, 4, 1, 3, 5};
        cout << countInversions(nums) << endl;
        for (int x : nums)
            cout << x << " ";
    }
    return 0;
}