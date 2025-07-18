#include <iostream>
using namespace std;

class Solution
{
public:
    bool isprime(int n);
    void solve();
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Solution sol;
    sol.solve();

    return 0;
}

void Solution::solve()
{
    // Write your solution logic here
    long long sum = 0;
    int n = 2000000;
    // int n = 10;

    for (int i = 2; i < n; i++)
    {
        if (isprime(i))
        {
            sum += i;
        }
    }

    cout << "sum of the prime less than 2 million: " << sum << endl;
}

bool Solution::isprime(int n)
{
    if (n < 2)
        return false;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}