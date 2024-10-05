class Solution {
public:
    bool containsZero(int num) 
    {
        while (num > 0) 
        {
            if (num % 10 == 0) return true;
            num /= 10;
        }
        return false;
    }

    vector<int> getNoZeroIntegers(int n) 
    {
        for (int a = 1; a < n; a++) 
        {
            int b = n - a;
            if (!containsZero(a) && !containsZero(b)) return {a, b};
        }
        return {};
    }
};