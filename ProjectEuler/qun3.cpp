#include <iostream>
#include <vector>
#include <chrono>
#include <unordered_set>
using namespace std::chrono;

/*
class Solution
{
public:
    int64_t solve(int64_t n)
    {
        int factor = 2;
        int last_factor = 1;
        std::vector<int64_t> prime_factors;

        while (n > 1)
        {
            if (n % factor == 0)
            {
                last_factor = factor;
                prime_factors.push_back(last_factor);
                n /= factor;
                while (n % factor == 0)
                {
                    n /= factor;
                }
            }
            factor++;
        }

        for (auto prime : prime_factors)
            std::cout << prime << ", ";
        std::cout << "\n";

        return prime_factors.back();
    }
};
*/

class Solution
{
public:
    int64_t solve(int64_t n)
    {
        int64_t factor = 2;
        int64_t last_factor = 1;

        std::unordered_set<int64_t> prime;

        while (n % 2 == 0)
        {
            last_factor = 2;
            prime.insert(last_factor);
            n /= 2;
        }

        for (int64_t i = 3; i * i <= n; i += 2)
        {
            if (n % i == 0)
            {
                last_factor = i;
                prime.insert(last_factor);
                n /= i;
            }
        }

        if (n > 2)
        {
            last_factor = n;
            prime.insert(last_factor);
        }

        int64_t largest_prime_factore = *(prime.begin());

        for (auto it = prime.begin(); it != prime.end(); it++)
        {
            std::cout << (*it) << ", ";
            largest_prime_factore = (*it);
        }
        std::cout << "\n";

        return largest_prime_factore;
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int64_t n = 600851475143;
    Solution sol;

    auto start = high_resolution_clock::now();
    int64_t ans = sol.solve(n);
    std::cout << "ans = " << ans << "\n";
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop - start);
    std::cout << "time taken: " << duration.count() << "ms\n";
    return 0;
}