#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

class Solution
{
public:
    void merge(vi &nums, int l, int m, int r)
    {
        // Your code here

        int l1 = m - l + 1;
        int l2 = r - m;

        vector<int> temp1(l1, 0), temp2(l2, 0);

        for (int i = 0; i < l1; i++)
        {
            temp1[i] = nums[i + l];
        }

        for (int i = 0; i < l2; i++)
        {
            temp2[i] = nums[i + m + 1];
        }

        int i = 0, j = 0, k = l;

        while (i < l1 && j < l2)
        {
            if (temp1[i] < temp2[j])
            {
                nums[k++] = temp1[i++];
            }
            else
            {
                nums[k++] = temp2[j++];
            }
        }

        while (i < l1)
        {
            nums[k++] = temp1[i++];
        }

        while (j < l2)
        {
            nums[k++] = temp2[j++];
        }

        return;
    }

public:
    void mergeSort(vi &nums, int l, int r)
    {
        // code here+
        if (l < r)
        {
            int mid = (l + r) / 2;
            mergeSort(nums, l, mid);
            mergeSort(nums, mid + 1, r);
            merge(nums, l, mid, r);
            return;
        }
        return;
    }
};

int main()
{
    vi nums = {4, 6, 8, 3, 8, 6, 4, 3, 2, 9, 0, 5};
    Solution obj;
    obj.mergeSort(nums, 0, nums.size() - 1);
    for (int x : nums)
        cout << x << " ";
    return 0;
}