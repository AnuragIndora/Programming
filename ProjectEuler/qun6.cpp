#include <iostream>
using namespace std;

class Solution
{
public:
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
    long long sum_of_n = n * (n + 1) / 2;
    long long sum_of_n2 = (n * (n + 1) * (2 * n + 1)) / 6;
    std::cout << "sum of the n natural number = " << sum_of_n << std::endl;
    std::cout << "square of the sum of the n natural number = " << sum_of_n * sum_of_n << std::endl;
    std::cout << "sum of the square of the n natural number = " << sum_of_n2 << std::endl;
    std::cout << "difference between the sum of the squares of the first n natural numbers and the square of the sum = " << (sum_of_n * sum_of_n) - sum_of_n2 << "\n";
    return;
}