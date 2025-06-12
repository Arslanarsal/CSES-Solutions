#include <bits/stdc++.h>
using namespace std;

int32_t main()
{

    int n, m, a, b;
    cin >> n >> m;
    vector<int> adj[n + 1];
    vector<int> in(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[b].push_back(a);
        in[a]++;
    }
    set<int> st;
    for (int i = 1; i <= n; i++)
    {
        if (!in[i])
        {
            st.insert(i);
        }
    }
    vector<int> ans;
    while (!st.empty())
    {
        int node = *st.rbegin();
        st.erase(node);
        ans.push_back(node);
        for (auto &&nei : adj[node])
        {
            in[nei]--;
            if (!in[nei])
            {
                st.insert(nei);
            }
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
