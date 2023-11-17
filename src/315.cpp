/*
 * @Author: qingfuliu 1805003304@qq.com
 * @Date: 2023-11-16 22:39:41
 * @LastEditors: qingfuliu 1805003304@qq.com
 * @LastEditTime: 2023-11-16 23:45:40
 * @FilePath: /leetCode/315.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <vector>
#include <assert.h>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {
        vector<int> ans(nums.size(), 0);
        vector<int> index(nums.size());
        {
            int i = 0;
            std::transform(index.begin(), index.end(), index.begin(), [&](int &)
                           { return i++; });
        }
        merge_sort(nums, ans, index, 0, nums.size());
        return ans;
    }

    void merge_sort(const vector<int> &nums, vector<int> &ans, vector<int> &index, int begin, int end)
    {
        if (begin + 1 >= end)
        {
            return;
        }
        int mid = (end - begin) / 2 + begin;
        merge_sort(nums, ans, index, begin, mid);
        merge_sort(nums, ans, index, mid, end);

        int left = begin;
        int right = mid;
        vector<int> temp(end - begin);
        int temp_index = 0;
        while (left < mid && right < end)
        {
            if (nums[index[left]] <= nums[index[right]])
            {
                ans[index[left]] += (right - mid);
                temp[temp_index++] = index[left++];
            }
            else
            {
                temp[temp_index++] = index[right++];
            }
        }

        while (left < mid)
        {
            ans[index[left]] += (right - mid);
            temp[temp_index++] = index[left++];
        }
        while (right < end)
        {
            temp[temp_index++] = index[right++];
        }
        assert(temp_index == temp.size());
        std::copy(temp.begin(), temp.end(), index.begin() + begin);
    }
};

int main()
{
    vector<int> nums{1, 34, 456, 23, 567, 67, 34, 6457, 67, 34, 457, 678, 4, 678, 687, 215667};
    Solution s;
    s.countSmaller(nums);
    return 0;
}