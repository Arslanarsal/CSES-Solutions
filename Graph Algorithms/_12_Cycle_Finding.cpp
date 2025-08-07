#include <bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX
#define int long long int
#define t tuple<int, int, int>
int n, m;
vector<int> dist;
vector<t> adj;
vector<int> relection;
int x;

void bellman_ford()
{

    for (int i = 1; i <= n; i++)
    {
        x = -1;
        for (auto &&it : adj)
        {
            int u = get<0>(it);
            int v = get<1>(it);
            int w = get<2>(it);
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                relection[v] = u;
                x = v;
            }
        }
    }
}

int32_t main()
{
    cin >> n >> m;
    dist.resize(n + 1, 0);
    relection.resize(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj.push_back({u, v, w});
    }

    bellman_ford();

    if (x == -1)
    {
        cout << "NO\n";
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        x = relection[x];
    }

    vector<int> cycle;
    int start = x;
    do
    {
        cycle.push_back(x);
        x = relection[x];
    } while (x != start);
    cycle.push_back(start);

    reverse(cycle.begin(), cycle.end());

    cout << "YES\n";
    int j = cycle.size();
    for (int i = 0; i < j; i++)
    {
        cout << cycle[i] << " ";
    }
    

    return 0;
}
