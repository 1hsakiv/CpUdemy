#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
class Solution
{
public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(vi &nums, int low, int high)
    {
        if (low < high)
        {
            int mid = partition(nums, low, high);
            quickSort(nums, low, mid - 1);
            quickSort(nums, mid + 1, high);
            return;
        }
        return;
    }

public:
    int partition(vi &nums, int low, int high)
    {

        // THIS AREA OF IS CODE IS WRITTEN BY YOU WHICH USES o(N) MEMORY
        // WRITTEN BY YOU TO UNDERSTAND HOW THINGS ARE WORKING
        // THIS CODE GOT ACCEPTED OF GFG

        // int pivot = nums[high];
        // vector<int> temp1, temp2;
        // int cnt = 0;
        // for (int j = low; j < high; j++)
        // {
        //     if (nums[j] <= pivot)
        //     {
        //         temp1.push_back(nums[j]);
        //         cnt++;
        //     }
        //     else
        //     {
        //         temp2.push_back(nums[j]);
        //     }
        // }

        // int k = low;

        // for (int x : temp1)
        // {
        //     nums[k++] = x;
        // }

        // nums[k++] = pivot;

        // for (int x : temp2)
        // {
        //     nums[k++] = x;
        // }

        // return low + cnt;

        // code from gfg

        int pivot = nums[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++)
        {
            if (nums[j] < pivot)
            {
                i++;
                swap(nums[i], nums[j]);
            }
        }

        swap(nums[i + 1], nums[high]);
        return i + 1;
    }
};

int main()
{
    vi nums = {4, 6, 8, 6, 4, 3, 2, 9, 0, 5};
    Solution obj;
    obj.quickSort(nums, 0, nums.size() - 1);
    for (int x : nums)
        cout << x << " ";
    return 0;
}