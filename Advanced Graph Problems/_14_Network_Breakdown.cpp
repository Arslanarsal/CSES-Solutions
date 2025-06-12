#include <bits/stdc++.h>
using namespace std;
const int M = 2e5 + 10;
vector<pair<int, int>> edges(M);
set<pair<int, int>> st;
vector<pair<int, int>> quiers(M);

class MST
{
public:
    vector<int> parent, siz;
    MST(int n)
    {
        parent.resize(n);
        siz.resize(n, 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int par(int u)
    {
        if (parent[u] == u)
        {
            return u;
        }
        return parent[u] = par(parent[u]);
    }

    bool merge(int u, int v)
    {
        u = par(u);
        v = par(v);
        if (u == v)
            return false;

        if (siz[u] > siz[v])
        {
            parent[v] = u;
            siz[u] += siz[v];
        }
        else
        {
            parent[u] = v;
            siz[v] += siz[u];
        }
        return true;
    }
};

int32_t main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (b > a)
            swap(a, b);
        edges[i] = {a, b};
    }
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        if (b > a)
            swap(a, b);
        st.insert({a, b});
        quiers[i] = {a, b};
    }

    int cnt = n;
    MST ms = MST(n + 1);
    for (int i = 0; i < m; i++)
    {
        if (st.find(edges[i]) == st.end())
        {
            if (ms.merge(edges[i].first, edges[i].second))
            {
                cnt--;
            }
        }
    }
    int ans[k];
    for (int i = k - 1; i >= 0; i--)
    {
        ans[i] = cnt;
        if (ms.merge(quiers[i].first, quiers[i].second))
            cnt--;
    }

    for (int i = 0; i < k; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
