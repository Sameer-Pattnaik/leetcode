class Solution {
public:
    int search(int num, vector<int>& potions, long long success) {
        int low = 0, high = potions.size() - 1;
        int count = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long prod = (long long)potions[mid] * num;
            if (prod >= success) {
                count += (high - mid + 1);
                high = mid - 1; 
            } else {
                low = mid + 1;
            }
        }
        return count;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end()); 
        vector<int> ans;
        for (int i = 0; i < spells.size(); i++) {
            int num = spells[i];
            int count = search(num, potions, success);
            ans.push_back(count);
        }
        return ans;
    }
};