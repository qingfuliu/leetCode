#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution
{
public:
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<int> ans(k, 0);
        {
            vector<int> a(k, 0);
            vector<int> b(k, 0);
            for (int i = 0; i <= k; ++i)
            {
                if (selectNums(nums1, nums2, a, b, i, k - i))
                {
                    merge(ans, a, b);
                }
            }
        }
        return ans;
    }

    bool compare(vector<int> &a, vector<int> &b) noexcept
    {
        return this->compare(a, b, 0, 0);
    }

    bool compare(vector<int> &a, vector<int> &b, int k1, int k2) noexcept
    {
        size_t i = k1;
        size_t j = k2;
        while (i < a.size() && j < b.size())
        {
            if (a[i] != b[j])
            {
                return a[i] > b[j];
            }
            ++i;
            ++j;
        }
        return i < a.size();
    }

    bool selectNums(const vector<int> &nums1, const vector<int> &nums2, vector<int> &a, vector<int> &b, int k1, int k2)
    {
        if (k1 > nums1.size() || k2 > nums2.size())
        {
            return false;
        }
        a.resize(0);
        b.resize(0);
        selectOneVec(nums1, a, k1);
        selectOneVec(nums2, b, k2);
        assert(a.size() == k1);
        assert(b.size() == k2);
    }

    void selectOneVec(const vector<int> &nums, vector<int> &a, int k) noexcept
    {
        int nums_index = 0;
        while (nums_index < nums.size())
        {
            int remind = nums.size() - nums_index;
            while (!a.empty() && a.size() + remind > k && a.back() < nums[nums_index])
            {
                a.pop_back();
            }
            if (a.size() < k)
            {
                a.push_back(nums[nums_index]);
            }
            ++nums_index;
        }
    }

    void merge(vector<int> &ans, vector<int> &a, vector<int> &b) noexcept
    {
        vector<int> temp_ans(ans.size(), 0);
        assert(temp_ans.size() == a.size() + b.size());
        size_t i = 0;
        size_t j = 0;
        size_t ans_index = 0;
        while (i < a.size() && j < b.size())
        {
            if (compare(a, b, i, j))
            {
                temp_ans[ans_index++] = a[i++];
            }
            else
            {
                temp_ans[ans_index++] = b[j++];
            }
        }
        while (i < a.size())
        {
            temp_ans[ans_index++] = a[i++];
        }
        while (j < b.size())
        {
            temp_ans[ans_index++] = b[j++];
        }
        
        if (compare(temp_ans, ans, 0, 0))
        {
            ans.swap(temp_ans);
        }
    }
};

int main()
{
    Solution s;

    vector<int> nums1{3, 4, 6, 5};
    vector<int> nums2{9, 1, 2, 5, 8, 3};
    int k = 5;
    auto ans = s.maxNumber(nums1, nums2, k);
    for (auto i : ans)
    {
        std::cout << i << " ";
    }
}