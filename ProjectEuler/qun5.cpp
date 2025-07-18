#include <iostream>
using namespace std;

class Solution
{
public:
    bool isprime(int n);
    void solve(int n);
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
    int n;
    cin >> n;
    sol.solve(n);

    return 0;
}

void Solution::solve(int n)
{
    // Write your solution logic here
    long long lcm = 1;
    for (int i = 2; i <= n; i++)
    {
        if (isprime(i))
        {
            int maxpower = i;
            while (maxpower * i <= n)
            {
                maxpower *= i;
            }
            lcm *= maxpower;
        }
    }
    cout << "smallest postive number: " << lcm << "\n";
    return;
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