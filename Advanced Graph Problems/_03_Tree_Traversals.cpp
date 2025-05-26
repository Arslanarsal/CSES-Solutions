#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define int long long int
#define ld long double
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oSet; // [find_by_order ==> given address at index] |==| [order_of_key ==> Number of element smaller then X]

const int mod = 1e9 + 7;
const int N = 2e5 + 10;
int t, n, q;
int pre[N], in[N], post[N];
unordered_map<int, int> freq;

void solve(int pl, int pr, int il, int ir)
{
    if (pl == pr)
    {
        post[pr] = in[pr];
        return;
    }
    post[pr] = pre[pl];
}

int32_t main()
{
    fastio;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> pre[i];

    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
        freq[in[i]] = i;
    }

    return 0;
}
