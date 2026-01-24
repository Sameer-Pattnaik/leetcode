class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        if (n <= 200) {
            sort(nums.begin(), nums.end());
            int res = 0;
            for (int i = 0; i < (n >> 1); i++)
                res = max(res, nums[n - 1 - i] + nums[i]);
            return res;
        }

        int maxi = 0;
        for (auto& num : nums)
            maxi = max(maxi, num);

        vector<int> freq(maxi + 1, 0);

        for (auto& num : nums)
            freq[num]++;

        int i = 0, j = maxi;
        while (i <= maxi && freq[i] == 0) i++;
        while (j >= 0 && freq[j] == 0) j--;

        int res = 0;
        for (int k = nums.size() / 2; k > 0; k--) {
            res = max(res, i + j);
            freq[i]--;
            freq[j]--;

            if (freq[i] == 0)
                while (i <= maxi && freq[i] == 0) i++;

            if (freq[j] == 0)
                while (j >= 0 && freq[j] == 0) j--;
        }
        return res;
    }
};
