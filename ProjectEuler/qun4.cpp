#include <iostream>
#include <chrono>

using namespace std::chrono;

class Solution
{
private:
    bool is_palindrome(int x) // Renamed function
    {
        if (x < 0)
            return false;
        int original = x, rev = 0;
        while (x > 0)
        {
            int rem = x % 10;
            rev = rev * 10 + rem;
            x /= 10;
        }
        return original == rev;
    }

public:
    void brute_force()
    {
        int max_palindrome = 0;

        for (int i = 100; i <= 999; i++)
        {
            for (int j = 100; j <= 999; j++)
            {
                int product = i * j;
                if (is_palindrome(product) && product > max_palindrome) // Changed & to &&
                    max_palindrome = product;
            }
        }

        std::cout << "Largest palindrome made from the product of two 3-digit numbers: " << max_palindrome << "\n";
    }

    void brute_force_earlystop()
    {
        int max_palindrome = 0;
        for (int i = 999; i >= 100; i--)
        {
            for (int j = 999; j >= 100; j--)
            {
                int product = i * j;
                if (is_palindrome(product) && product > max_palindrome)
                {
                    max_palindrome = product;
                    break;
                }
            }
        }
        std::cout << "Largest palindrome made from the product of two 3-digit numbers: " << max_palindrome << "\n";
    }

    void solve()
    {
        auto start1 = high_resolution_clock::now(); // Changed variable name
        brute_force();
        auto stop1 = high_resolution_clock::now(); // Changed variable name

        std::cout << "Brute Force Approach: " << duration_cast<nanoseconds>(stop1 - start1).count() << "ns\n"; // Corrected typo

        std::cout << "------------------\n";

        auto start2 = high_resolution_clock::now(); // Changed variable name
        brute_force_earlystop();
        auto stop2 = high_resolution_clock::now(); // Changed variable name

        std::cout << "Brute Force Earlystop Approach: " << duration_cast<nanoseconds>(stop2 - start2).count() << "ns\n"; // Corrected typo
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

    Solution sol;
    sol.solve();
    return 0;
}
