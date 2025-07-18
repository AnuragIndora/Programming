#include <iostream>
#include <unordered_set>
using namespace std;

typedef long long ll;
#define endl "\n"

class Solution
{
public:
    ll solve(int limit)
    {
        ll ans = 0;
        for (int i = 1; i < limit; i++)
        {
            if (i % 3 == 0 || i % 5 == 0)
            {
                ans += i;
            }
        }
        return ans;
    }
};

int main()
{
    int limit;
    cin >> limit;

    Solution sol;
    ll ans = sol.solve(limit);
    cout << ans << endl;
    return 0;
}
