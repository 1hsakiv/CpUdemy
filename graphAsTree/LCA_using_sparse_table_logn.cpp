#include <bits/stdc++.h>

using namespace std;

const int N = 1e5, M = 20;

vector<int> adj[N];
int depth[N], Parent[N][M];

// O(N*M)
void dfs(int u, int par)
{
	depth[u] = depth[par] + 1;

	Parent[u][0] = par;
	for (int j = 1; j < M; j++)
	{
		Parent[u][j] = Parent[Parent[u][j - 1]][j - 1];
	}

	for (auto v : adj[u])
	{
		if (v != par)
		{
			dfs(v, u);
		}
	}
}

// O(M) = logN
int LCA(int u, int v)
{
	if (u == v)
		return u;
	if (depth[u] < depth[v])
		swap(u, v);
	int diff = depth[u] - depth[v];

	for (int j = M - 1; j >= 0; j--)
	{
		if ((diff >> j) & 1)
		{
			// if 2^j parent is present then update the parent
			// jth bit of diff is set
			u = Parent[u][j];
		}
	}
	// u and v are on the same leve
	// best possible way to move with higest power to 2 such that
	// it is just below the LCA
	for (int j = M - 1; j >= 0; j--)
	{
		if (Parent[u][j] != Parent[v][j])
		{
			u = Parent[u][j];
			v = Parent[v][j];
		}
	}

	// Parent[v][0]
	return Parent[u][0];
}

// O(1)
int LengthFromUtoV(int u, int v)
{
	int lca = LCA(u, v);
	return depth[u] + depth[v] - 2 * depth[lca];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	dfs(1, 0);

	// for (int i = 1; i <= 12; i++) {
	// 	cout << i << "-> ";
	// 	for (int j = 0; j < 4; j++) {
	// 		cout << Parent[i][j] << " ";
	// 	} cout << '\n';
	// }

	// for (int i = 1; i <= n; i++) {
	// 	cout << i << " " << depth[i] << '\n';
	// }
	cout << "LCA" << endl;
	cout << LCA(9, 12) << '\n';
	cout << LCA(10, 8) << '\n';
	cout << LCA(9, 11) << '\n';

	cout << "pathLength" << endl;
	cout << LengthFromUtoV(9, 12) << '\n';
	cout << LengthFromUtoV(10, 8) << '\n';

	return 0;
}

// Test Case
// 12
// 1 2
// 1 3
// 2 4
// 2 5
// 2 6
// 3 7
// 4 10
// 5 8
// 7 12
// 8 9
// 8 11