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

    int n;
    cin >> n;
    Solution sol;
    sol.solve(n);

    return 0;
}

void Solution::solve(int n)
{
    // Write your solution logic here
    int cnt = 1;
    int prime = 2;
    while (cnt < n)
    {
        int start = prime;
        for (int i = start + 1; i <= start * start; i++)
        {
            if (isprime(i))
            {
                prime = i;
                break;
            }
        }
        cnt++;
    }

    std::cout << prime << std::endl;
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