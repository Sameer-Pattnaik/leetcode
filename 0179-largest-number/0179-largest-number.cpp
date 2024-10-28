class Solution {
public:
    static bool compare(int x,int y)
    {
        string a=to_string(x);
        string b=to_string(y);
        return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),compare);
        string ans="";
        for(int i=0;i<nums.size();i++)
        {
            ans+=to_string(nums[i]);
        }
        if(ans[0]=='0')
        {
            return "0";
        }
        return ans;
    }
};