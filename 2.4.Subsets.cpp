class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        helper(nums, tmp, 0, ans);

        return ans;
    }

    void helper(vector<int> &nums, vector<int> &tmp, int i, vector<vector<int>> &ans)
    {
        if (i == nums.size())
        {
            ans.push_back(tmp);
            return;
        }
        //choice-1(take it)
        tmp.push_back(nums[i]);
        helper(nums, tmp, i + 1, ans);

        //choice-2(drop it)
        tmp.pop_back();
        helper(nums, tmp, i + 1, ans);
    }
};