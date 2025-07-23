class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> res;
        string prefix;
        int n = products.size();
        for (char c : searchWord) {
            prefix += c;
            auto it = lower_bound(products.begin(), products.end(), prefix);
            vector<string> group;
            for (int i = 0; i < 3 && it + i != products.end(); ++i) {
                if ((it + i)->compare(0, prefix.size(), prefix) == 0) group.push_back(*(it + i));
                else break;
            }
            res.push_back(group);
        }
        return res;
    }
};