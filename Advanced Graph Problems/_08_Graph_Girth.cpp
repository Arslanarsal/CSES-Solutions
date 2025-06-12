#include <bits/stdc++.h>
using namespace std;
const int N = 2507;
int n, m;
vector<int> adj[N];
vector<int> dist(N);

int solve(int s)
{
    fill(dist.begin(), dist.end(), -1);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    int ans = INT_MAX;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto &&i : adj[node])
        {
            if (dist[i] == -1)
            {
                dist[i] = dist[node] + 1;
                q.push(i);
            }
            else if (dist[i] >= dist[node])
            {
                ans = min(ans, dist[i] + dist[node] + 1);
            }
        }
    }
    return ans;
}

int32_t main()
{
    cin >> n >> m;
    int a, b;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, solve(i));
    }
    cout << ((ans == INT_MAX) ? -1 : ans);

    return 0;
}
