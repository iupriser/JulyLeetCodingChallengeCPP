class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &A)
    {
        int n = A.size();
        if (n < 3)
        {
            return {};
        }
        vector<vector<int>> ans;
        sort(A.begin(), A.end());

        for (int i = 0; i < n; ++i)
        {
            int start = i + 1, end = n - 1;
            if (i > 0 && A[i] == A[i - 1])
            {
                continue;
            }
            while (start < end)
            {
                //Ignore duplicates
                if (end < n - 1 && A[end] == A[end + 1])
                {
                    end--;
                    continue;
                }

                long long int sum = 0LL + A[i] + A[start] + A[end];
                if (sum < 0)
                {
                    start++;
                }
                else if (sum > 0)
                {
                    end--;
                }
                else
                {
                    ans.push_back({A[i], A[start], A[end]});
                    start++;
                    end--;
                }
            }
        }
        return ans;
    }
};

/*

class Solution {
public:
vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size()<=2)return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            int a = nums[i];
            if(a > 0) break;
            if (i > 0 && a == nums[i - 1]) continue;
            for (long j = i + 1, k = nums.size() - 1; j < k;) {
                int b = nums[j];
                int c = nums[k];
                int value = a + b + c;
                if (value == 0) {
                    result.push_back(vector<int>({a, b, c}));
                    //to avoid elements that are equal to start(i.e. b) and end(i.e. c) because you have already considered them.    
                    while (j<k && b == nums[++j]);
                    while (j < k &&c == nums[--k]);
                
                } else if (value > 0) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return result;
    }      
};

*/