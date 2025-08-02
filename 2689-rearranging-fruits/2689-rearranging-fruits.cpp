class Solution 
{
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) 
    {
        unordered_map<int, int> count;
        int globalMin = INT_MAX;
        for (int x : basket1) 
        {
            count[x]++;
            globalMin = min(globalMin, x);
        }
        for (int x : basket2) 
        {
            count[x]--;
            globalMin = min(globalMin, x);
        }
        long long total = 0;
        for (auto& [k, v] : count) 
        {
            if (v % 2 != 0)
            {
                return -1; 
            } 
            total += abs(v);
        }
        vector<int> im;
        for (auto& [num, v] : count) 
        {
            for (int i = 0; i < abs(v) / 2; ++i) 
            {
                im.push_back(num);
            }
        }
        sort(im.begin(), im.end());
        long long ans = 0;
        long long doubleMin = 2LL * globalMin;
        int half = im.size() / 2;
        for (int i = 0; i < half; ++i) 
        {
            ans += min((long long)im[i], doubleMin);
        }
        return ans;
    }
};