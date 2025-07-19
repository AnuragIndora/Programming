#include <iostream>
#include <unordered_map>

using namespace std;

int N = 1000000;

class Solution
{
private:
    unordered_map<long long, long long> dp;

public:
    long long generate_chain(long long n);       // Optimized
    long long generate_chain_brute(long long n); // Brute force
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
    long long max_chain = 0;
    int best_start = 0;

    for (long long i = 1; i <= N; i++)
    {
        // Uncomment one of the lines below depending on which version you want to test:

        // long long curr = generate_chain_brute(i); // Brute force version
        long long curr = generate_chain(i); // Optimized version
        cout << "chain lenght " << i << " = " << curr << endl;

        if (curr > max_chain)
        {
            max_chain = curr;
            best_start = i;
        }
    }

    cout << "best start = " << best_start << endl;
    cout << "max chain length = " << max_chain << endl;
}

// Brute force approach (O(chain length))
long long Solution::generate_chain_brute(long long n)
{
    long long chain_len = 0;
    long long curr = n;

    while (curr > 1)
    {
        // if (curr % 2 == 0)
        // {
        //     curr = curr / 2;
        // }
        // else
        // {
        //     curr = 3 * curr + 1;
        // }
        curr = (curr % 2 == 0) ? (curr / 2) : (3LL * curr + 1);
        chain_len++;
    }

    return chain_len + 1; // +1 for the final "1"
}

long long Solution::generate_chain(long long n)
{
    if (n == 1)
        return 1;

    if (dp.find(n) != dp.end())
        return dp[n];

    long long next = (n % 2 == 0) ? (n / 2) : (3LL * n + 1);
    dp[n] = 1 + generate_chain(next);

    return dp[n];
}
