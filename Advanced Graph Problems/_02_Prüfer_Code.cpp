#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define int long long int
#define ld long double

const int mod = 1e9 + 7;
int t, n, q;
const int N = 2e5 + 7;
int arr[N];

int32_t main()
{
    fastio;
    cin >> n;
    map<int, int> mp;
    for (int i = 1; i <= n - 2; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }
    set<int> st;
    for (int i = 1; i <= n; i++)
    {
        if (!mp.count(i))
        {
            st.insert(i);
        }
    }
    for (int i = 1; i <= n - 2; i++)
    {
        int j = *st.begin();
        st.erase(j);
        cout << arr[i] << " " << j << "\n";
        mp[arr[i]]--;
        if (mp[arr[i]] == 0)
            st.insert(arr[i]);
    }
    cout << *st.begin() << " " << *st.rbegin();

    return 0;
}
