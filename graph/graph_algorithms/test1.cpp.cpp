#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double dd;
typedef pair<ll, ll> pii;
const int MAX = 2e9 + 23;
ll inf = 1e18 + 23;
const int mod = 1e9 + 7;
const int N = 1e5 + 7;
#define rep(i, n) for(int i = 1; i <= n; i++)
#define For(i, n) for(int i = 0; i < n; i++)

vector<int> graph[N];
bool visited[N];
int level[N];
string s;

void init_code()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

void dfs(int u)
{
	visited[u] = true;
	cout << "Node " << u << '\n';
	for(auto v : graph[u])
	{
		if(s[v] == 'L') level[v] = level[u];
		else level[v] = level[u] + 1;
		if(visited[v]) continue;
		dfs(v);
	}
}

void solve()
{
	int n; cin >> n;
	cin >> s;
	vector<int> leaf;
	for(int i = 1; i <= n; i++)
	{
		int u,v ;
		cin >> u >> v;
		if(u != 0) graph[i].push_back(u);
		if(v != 0) graph[i].push_back(v);
		if(u == 0 && v == 0) leaf.push_back(i);
	}
	level[1] = 1;
	dfs(1);
	int ans = INT_MAX;
	for(auto val : leaf)
	{
		ans = min(ans, level[val]);
	}
	cout << ans << '\n';
}

int main()
{
	init_code();
	ll t = 1;
	// cin >> t;
	while(t--) solve();
	return 0;
}
