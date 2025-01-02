class Solution {
public:
    vector<vector<int>> res;
    void generate(vector<int> curr, int i, int k, int n) {
        if (k == 0) {
            res.push_back(curr);
        } else if (n - k == i) {
            curr.push_back(i + 1);
            generate(curr, i + 1, k - 1, n);
        } else {
            generate(curr, i + 1, k, n);
            curr.push_back(i + 1);
            generate(curr, i + 1, k - 1, n);
        }
    }

    vector<vector<int>> combine(int n, int k) {
        generate({}, 0, k, n);
        return res;
    }
};