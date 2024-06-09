class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>ans;
    vector<int>add={1};
    reverse(digits.begin(),digits.end());
    int carry=0,sum=0,i=0,j=0;
    
    while(i<digits.size() && j<add.size())
    {
        int sol=(carry+add[j]+digits[i]);
        carry=sol/10;
        sum=sol%10;
        ans.push_back(sum);
        i++;
        j++;
    }
    while(i<digits.size())
    {
        
        int sol=(carry+digits[i]);
        sum=sol%10;
        carry=sol/10;
        ans.push_back(sum);
        i++;
    }
    if(carry>0)
    {
        sum=(carry+sum);
        ans.push_back(sum);
    }
    reverse(ans.begin(),ans.end());
    return ans;
    }
};