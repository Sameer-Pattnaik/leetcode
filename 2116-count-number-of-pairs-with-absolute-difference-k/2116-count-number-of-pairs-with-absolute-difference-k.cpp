class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int freq[101] = {0}, count = 0;
        for (int num : nums) {
            if (num - k >= 0) count += freq[num - k];
            if (num + k <= 100) count += freq[num + k];
            ++freq[num];
        }
        return count;
    }
};