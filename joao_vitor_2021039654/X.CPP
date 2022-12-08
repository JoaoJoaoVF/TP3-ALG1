#include <bits/stdc++.h>

using namespace std;

// Function to construct and print Longest Increasing
// Subsequence
vector<int> constructPrintLIS(vector<int> arr, int n)
{
    // L[i] - The longest increasing sub-sequence
    // ends with arr[i]
    vector<vector<int>> L(n);

    // L[0] is equal to arr[0]
    L[0].push_back(arr[0]);

    // start from index 1
    for (int i = 1; i < n; i++)
    {
        // do for every j less than i
        for (int j = 0; j < i; j++)
        {
            /* L[i] = {Max(L[j])} + arr[i]
            where j < i and arr[j] < arr[i] */
            if ((arr[i] < arr[j]) &&
                (L[i].size() < L[j].size() + 1))
                L[i] = L[j];
        }

        // L[i] ends with arr[i]
        L[i].push_back(arr[i]);
    }

    // L[i] now stores increasing sub-sequence of
    // arr[0..i] that ends with arr[i]
    vector<int> max = L[0];

    // LIS will be max of all increasing sub-
    // sequences of arr
    for (vector<int> x : L)
        if (x.size() > max.size())
            max = x;

    // max will contain LIS
    return max;
}
void test()
{

    int n;
    cin >> n;
    while (n--)
    {
        int r;
        cin >> r;
        vector<int> v;
        vector<int> max;
        for (int i = 0; i < r; i++)
        {
            int p;
            cin >> p;
            if (i == 0)
            {
                v.push_back(p);
            }
            else
            {
                max = constructPrintLIS(v, v.size());
                int front = max[0], back = max[max.size() - 1];
                if (p > front)
                    v.insert(v.begin(), 1, p);
                else
                    v.push_back(p);
            }
        }
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        cout << endl;
        // int max = lis(v, v.size());
        max = constructPrintLIS(v, v.size());
        cout << max.size() << endl;
    }
}

void printLIS(vector<int> &arr)
{
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

int main()
{

    test();

    return (0);
}