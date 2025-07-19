#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    void solve(int power);
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

    int power;
    cin >> power;

    Solution sol;
    sol.solve(power);

    return 0;
}

void Solution::solve(int power)
{
    // Write your solution logic here
    vector<int> number = {1};

    for (int i = 0; i < power; i++)
    {
        int carry = 0;
        for (int j = 0; j < number.size(); j++)
        {
            int val = number[j] * 2 + carry;
            number[j] = val % 10;
            carry = val / 10;
        }
        while (carry)
        {
            number.push_back(carry % 10);
            carry = carry / 10;
        }
    }

    int digit_sum = 0;
    for (auto it : number)
        digit_sum += it;

    string cal_num = "";
    for (int it : vector<int>(number.rbegin(), number.rend()))
    {
        cal_num += std::to_string(it);
    }
    std::cout << "sum of digit: " << digit_sum << endl;
    std::cout << "power: " << cal_num << endl;
}