
#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

std::vector<int> PushFront(int x, std::vector<int> subsequence)
{
    subsequence.insert(subsequence.begin(), x);
    return subsequence;
}

std::vector<int> PushBack(std::vector<int> subsequence, int x)
{
    subsequence.push_back(x);
    return subsequence;
}

void Consider(std::map<std::pair<int, int>, std::vector<int>> &table,
              std::vector<int> subsequence)
{
    std::vector<int> &entry = table[{subsequence.front(), subsequence.back()}];
    if (subsequence.size() > entry.size())
    {
        entry = std::move(subsequence);
    }
}

std::vector<int> TwoSidedDecreasingSubsequence(const std::vector<int> &input)
{
    if (input.empty())
    {
        return {};
    }
    // Maps {front, back} to the longest known subsequence.
    std::map<std::pair<int, int>, std::vector<int>> table;
    for (int x : input)
    {
        auto table_copy = table;
        for (const auto &[front_back, subsequence] : table_copy)
        {
            auto [front, back] = front_back;
            if (x > front)
            {
                Consider(table, PushFront(x, subsequence));
            }
            if (back > x)
            {
                Consider(table, PushBack(subsequence, x));
            }
        }
        Consider(table, {x});
    }
    return std::max_element(
               table.begin(), table.end(),
               [&](const std::pair<std::pair<int, int>, std::vector<int>> &a,
                   const std::pair<std::pair<int, int>, std::vector<int>> &b)
               {
                   return a.second.size() < b.second.size();
               })
        ->second;
}

int main()
{
    int size = 0;
    for (int x : TwoSidedDecreasingSubsequence({20, 19, 7, 9, 15, 14, 8, 5, 17, 18, 13, 12, 11, 2, 20, 4, 6, 3, 16, 10, 1}))
    {
        std::cout << x << ' ';
        size++;
    }
    std::cout << '\n';

    std::cout << size << '\n';

    //  std::cout << '\n';

    size = 0;
    for (int x : TwoSidedDecreasingSubsequence({15, 12, 5, 8, 1, 17, 13, 6, 19, 18, 9, 3, 4, 16, 7, 20, 2, 11, 10, 14}))
    {
        std::cout << x << ' ';
        size++;
    }
    std::cout << '\n';

    std::cout << size << '\n';

    //  std::cout << '\n';

    size = 0;
    for (int x : TwoSidedDecreasingSubsequence({2, 14, 8, 3, 9, 20, 16, 11, 13, 10, 7, 12, 5, 15, 17, 18, 1, 4, 6, 19}))
    {
        std::cout << x << ' ';
        size++;
    }
    std::cout << '\n';

    std::cout << size << '\n';

    //  std::cout << '\n';

    size = 0;
    for (int x : TwoSidedDecreasingSubsequence({10, 17, 13, 9, 6, 3, 8, 12, 2, 7, 18, 19, 15, 16, 14, 11, 4, 5, 1, 20}))
    {
        std::cout << x << ' ';
        size++;
    }
    std::cout << '\n';

    std::cout << size << '\n';

    //  std::cout << '\n';

    size = 0;
    for (int x : TwoSidedDecreasingSubsequence({16, 2, 6, 8, 10, 11, 5, 3, 17, 14, 7, 12, 4, 18, 19, 20, 9, 1, 13, 15}))
    {
        std::cout << x << ' ';
        size++;
    }
    std::cout << '\n';

    std::cout << size << '\n';

    //  std::cout << '\n';

    size = 0;
    for (int x : TwoSidedDecreasingSubsequence({10, 1, 5, 3, 19, 16, 9, 6, 20, 8, 11, 14, 4, 13, 15, 18, 17, 2, 12, 7}))
    {
        std::cout << x << ' ';
        size++;
    }
    std::cout << '\n';

    std::cout << size << '\n';

    //  std::cout << '\n';

    size = 0;
    for (int x : TwoSidedDecreasingSubsequence({15, 10, 20, 12, 14, 7, 8, 6, 3, 1, 4, 16, 13, 17, 19, 18, 9, 5, 11, 2}))
    {
        std::cout << x << ' ';
        size++;
    }
    std::cout << '\n';

    std::cout << size << '\n';

    //  std::cout << '\n';

    size = 0;
    for (int x : TwoSidedDecreasingSubsequence({13, 15, 17, 4, 2, 3, 14, 11, 20, 9, 1, 16, 6, 5, 18, 7, 12, 19, 8, 10}))
    {
        std::cout << x << ' ';
        size++;
    }
    std::cout << '\n';

    std::cout << size << '\n';

    //  std::cout << '\n';

    size = 0;
    for (int x : TwoSidedDecreasingSubsequence({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}))
    {
        std::cout << x << ' ';
        size++;
    }
    std::cout << '\n';

    std::cout << size << '\n';

    //  std::cout << '\n';

    size = 0;
    for (int x : TwoSidedDecreasingSubsequence({20, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1}))
    {
        std::cout << x << ' ';
        size++;
    }
    std::cout << '\n';

    std::cout << size << '\n';
}
