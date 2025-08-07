#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;



#define int long long int
#define ld long double
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oSet; // [find_by_order ==> given address at index] |==| [order_of_key ==> Number of element smaller then X]

const int mod = 1e9 + 7;
int t, n, q, sum;

vector<int> solve(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans;
    for (int mask = 0; mask < (1 << n); mask++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                sum += arr[i];
            }
        }
        ans.push_back(sum);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int32_t main()
{
    t = 1;
    while (t--)
    {

        cin >> n >> sum;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<int> part[2];
        for (int i = 0; i < n; i++)
        {
            part[i & 1].push_back(arr[i]);
        }
        vector<int> a = solve(part[0]);
        vector<int> b = solve(part[1]);

        int m = a.size();
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            ans += upper_bound(b.begin(), b.end(), sum - a[i]) - lower_bound(b.begin(), b.end(), sum - a[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}
