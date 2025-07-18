#include <iostream>
#include <vector>
#define endl "\n"
typedef long long ll;

// class Solution
// {
// public:
//     ll solve(int limit)
//     {
//         std::vector<int> fact;
//         fact.push_back(1);
//         fact.push_back(2);

//         while (true)
//         {
//             int f1 = fact[fact.size() - 2], f2 = fact[fact.size() - 1];
//             int next = f1 + f2;
//             if (next > limit)
//                 break;
//             fact.push_back(next);
//         }

//         ll sum = 0;
//         for (auto it : fact)
//         {
//             if (it % 2 == 0)
//                 sum += it;
//         }
//         return sum;
//     }
// };

// memory optimization
class Solution
{
public:
    ll solve(int limit)
    {
        int a = 1, b = 2;
        ll sum = 0;
        while (b <= limit)
        {
            if (b % 2 == 0)
                sum += b;

            int next = a + b;
            a = b;
            b = next;
        }
        return sum;
    }
};

int main()
{
    int limit;
    std::cin >> limit;
    Solution sol;
    ll ans = sol.solve(limit);

    std::cout << "ans = " << ans << endl;
    return 0;
}
