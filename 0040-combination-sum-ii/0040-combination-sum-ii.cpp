class Solution {
public:
    void recursiveFunction(vector<vector<int>>& ans, vector<int>& candidates, int n, int target, int index, int currentSum, vector<int>& subset) {
        if (currentSum == target) {
            ans.push_back(subset);
            return;
        }

        for (int i = index; i < n; ++i) {
            // Skip duplicates at the same level
            if (i > index && candidates[i] == candidates[i - 1]) continue;

            // Prune if currentSum exceeds target
            if (currentSum + candidates[i] > target) break;

            subset.push_back(candidates[i]);
            recursiveFunction(ans, candidates, n, target, i + 1, currentSum + candidates[i], subset);
            subset.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> subset;
        recursiveFunction(ans, candidates, candidates.size(), target, 0, 0, subset);
        return ans;
    }
};
