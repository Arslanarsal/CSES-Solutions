#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 2e5 + 7;
int tin[N]{}, low[N]{};
vector<vector<pair<int, int>>> adj(N);
bool visit[N];
int timer = 0;

void dfs(int u = 1, int p = 0)
{
    low[u] = timer;
    tin[u] = timer++;
    visit[u] = true;
    for (auto &&it : adj[u])
    {
        int v = it.first;
        if (v == p)
            continue;
        if (!visit[v])
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u])
            {
                cout << "IMPOSSIBLE\n";
                exit(0);
            }
        }
        else
        {
            low[u] = min(low[u], tin[v]);
        }
    }
}

vector<pair<int, int>> ans;
bool edgevisit[N];
void edfs(int u = 1)
{
    visit[u] = true;
    for (auto &&it : adj[u])
    {
        if (!edgevisit[it.second])
        {
            ans.push_back({u, it.first});
            edgevisit[it.second] = true;
        }
        if (!visit[it.first])
        {
            edfs(it.first);
        }
    }
}

int32_t main()
{
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    dfs();
    int num = accumulate(visit, visit + N, 0);
    
    if (num < n)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    memset(visit, 0, sizeof(visit));
    edfs();
    for (auto &&i : ans)
    {
        cout << i.first << " " << i.second << "\n";
    }

    return 0;
}
