#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;

vector<int> adj[N];
int visited[N];
bool cycle = false;

void dfs(int u, int par) {
	visited[u] = 1;
	for (auto v : adj[u]) {
		if (!visited[v]) {
			dfs(v, u);
		}
		else if (v != par) {
			// here v --> u is back edge
			cycle = true;
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);

	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i, 0);
		}
	}

	if (cycle) {
		cout << "Yes cycle found";
	}
	else {
		cout << "Not found";
	}


	return 0;
}