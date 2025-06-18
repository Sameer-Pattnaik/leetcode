class Solution 
{
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i += 3) 
        {
            int a = nums[i];
            int b = nums[i + 1];
            int c = nums[i + 2];
            if (c - a > k)
            {
                return {};
            } 
            result.push_back({a, b, c});
        }

        return result;
    }
};