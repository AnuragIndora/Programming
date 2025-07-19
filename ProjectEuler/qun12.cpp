#include <iostream>
using namespace std;

class Solution
{
public:
    int factor(long long n);
    void solve(int k);
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

    int k;
    cin >> k;

    Solution sol;
    sol.solve(k);

    return 0;
}

void Solution::solve(int k)
{
    // Write your solution logic here
    int n = 1;
    long long tri;
    while (true)
    {
        // tri = n * (n + 1) / 2;
        // cout << "trinagle number: " << tri << endl;

        // if factors are coprime
        long long a = n % 2 == 0 ? n / 2 : n;
        long long b = n % 2 == 0 ? (n + 1) : (n + 1) / 2;
        int count = factor(a) * factor(b);
        if (count >= k)
        {
            cout << "ans = " << 1LL * (n * (n + 1) / 2) << endl;
            break;
        }
        n++;
    }
    // cout << "ans = " << tri << endl;
}

int Solution::factor(long long n)
{
    int cnt = 0;
    for (long long i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt += 2;
            if (i * i == n)
                cnt--;
        }
    }
    // cout << "factor count: " << cnt << endl;
    return cnt;
}