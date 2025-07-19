#include <iostream>
using namespace std;

class Solution
{
public:
    long long binomial_coefficient(int n, int r);
    void solve(int k);
};

long long Solution::binomial_coefficient(int n, int r)
{
    long long res = 1;
    if (r > n - r)
        r = n - r;

    for (int i = 0; i < r; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

void Solution::solve(int k)
{
    // For a k x k grid, total paths = C(2k, k)
    long long result = binomial_coefficient(2 * k, k);
    cout << "Number of lattice paths in a " << k << " x " << k << " grid is: " << result << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int k;
    cin >> k;
    Solution sol;
    sol.solve(k);

    return 0;
}
