#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

int n;

map<vector<int>, int> mp;
int idx = 1;

vector<int> centree(vector<int> adj[])
{
    vector<int> v;
    int deg[N] = {0};
    for (int i = 1; i <= n; i++)
    {
        deg[i] = adj[i].size();
        if (deg[i] == 1)
            v.push_back(i), deg[i]--;
    }
    int m = v.size();
    while (m < n)
    {
        vector<int> vv;
        for (auto &&i : v)
        {
            for (auto &&nei : adj[i])
            {
                deg[nei]--;
                if (deg[nei] == 1)
                {
                    vv.push_back(nei);
                }
            }
        }
        m += vv.size();
        v = vv;
    }
    return v;
}

int dfs(int u, int p, vector<int> adj[])
{
    vector<int> v;
    for (auto &&nei : adj[u])
    {
        if (nei != p)
        {
            v.push_back(dfs(nei, u, adj));
        }
    }
    sort(v.begin(), v.end());
    if (!mp.count(v))
    {
        mp[v] = idx++;
    }
    return mp[v];
}

int32_t main()
{

    int t;
    int a, b;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> adj1[n + 1], adj2[n + 1];
        mp.clear();
        idx = 1;

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

        vector<int> v1 = centree(adj1);
        vector<int> v2 = centree(adj2);

        int s1 = dfs(v1[0], 0, adj1);
        bool flag = false;
        for (auto &&i : v2)
        {
            int s2 = dfs(i, 0, adj2);
            if (s1 == s2)
            {
                flag = true;
                break;
            }
        }

        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
