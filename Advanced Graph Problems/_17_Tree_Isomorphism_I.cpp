#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
vector<int> adj1[N], adj2[N];
int n;

map<vector<int>, int> mp;
int idx = 1;
int dfs(int u, int p, vector<int> adj[])
{
    vector<int> v;
    for (auto &&nei : adj[u])
        if (nei != p)
            v.push_back(dfs(nei, u, adj));

    sort(v.begin(), v.end());
    if (!mp.count(v))
        mp[v] = idx++;
    return mp[v];
}

int32_t main()
{

    int t;
    int a, b;
    cin >> t;
    while (t--)
    {
       
        for (int i = 1; i <= n; i++)
        {
            adj1[i].clear();
            adj2[i].clear();
        }
        mp.clear();
        idx = 1;

        cin >> n;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a >> b;
            adj1[a].push_back(b);
            adj1[b].push_back(a);
        }

        for (int i = 0; i < n - 1; i++)
        {
            cin >> a >> b;
            adj2[a].push_back(b);
            adj2[b].push_back(a);
        }
        int s1 = dfs(1, 0, adj1);
        int s2 = dfs(1, 0, adj2);
        if (s1 == s2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
