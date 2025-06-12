#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 1e5 + 5;
vector<int> adj[N];
int visit[N]{0};
bool isEdge[N];
vector<pair<int, int>> ans;
int timer = 1;

void dfs(int node, int p = 0)
{
    visit[node] = timer++;
    for (auto &&i : adj[node])
    {
        if (i == p)
            continue;

        if (!visit[i])
        {
            dfs(i, node);
            if (isEdge[i])
            {
                ans.push_back({i, node});
                isEdge[i] = 0;
            }
            else
            {
                ans.push_back({node, i});
                isEdge[node] ^= 1;
            }
        }
        else if (visit[i] < visit[node])
        {
            ans.push_back({node, i});
            isEdge[node] ^= 1;
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
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        if (!visit[i])
            dfs(i);

    if (accumulate(isEdge, isEdge + N, 0))
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (auto &&i : ans)
        cout << i.first << " " << i.second << "\n";

    return 0;
}
