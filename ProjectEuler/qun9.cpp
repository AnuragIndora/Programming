#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void solve();
    std::vector<int> perfect_square(int n);
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
    // condition: a + b + c = 1000, a2 + b2 = c2

    int a, b, c;

    for (a = 1; a <= 1000 / 3; a++)
    {
        for (b = a + 1; b <= 1000 / 2; b++)
        {
            c = 1000 - a - b;
            if (a * a + b * b == c * c)
            {
                printf("triplet: {(%d), (%d), (%d)}\n", a, b, c);
                int product = a * b * c;
                printf("Product: a*b*c = %d", product);
            }
        }
    }
    return;
}
