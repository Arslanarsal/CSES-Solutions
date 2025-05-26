#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main()
{

    int n, m, k;
    cin >> n >> m >> k;
    vector<bool> hasAnime(n + 1, false);
    for (int i = 0; i < k; i++)
    {
        int city;
        cin >> city;
        hasAnime[city] = true;
    }
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<vector<array<int, 2>>> dist(n + 1, vector<array<int, 2>>(2, {INT_MAX, INT_MAX}));
    queue<array<int, 3>> q;
    for (int i = 1; i <= n; i++)
    {
        if (hasAnime[i])
        {
            q.push({i, i, 0});
            dist[i][0] = {0, i};
        }
    }
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int node = it[0];
        int source_anime_shop = it[1];
        int d = it[2];
        for (int child : graph[node])
        {
            if (d + 1 < dist[child][0][0])
            {
                dist[child][0] = {d + 1, source_anime_shop};
                q.push({child, source_anime_shop, d + 1});
            }
            else if (d + 1 < dist[child][1][0] && source_anime_shop != dist[child][0][1])
            {
                dist[child][1] = {d + 1, source_anime_shop};
                q.push({child, source_anime_shop, d + 1});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (hasAnime[i])
        {
            cout << (dist[i][1][0] == INT_MAX ? -1 : dist[i][1][0]) << " ";
        }
        else
        {
            cout << (dist[i][0][0] == INT_MAX ? -1 : dist[i][0][0]) << " ";
        }
    }
}