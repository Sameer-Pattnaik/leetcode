class Solution {
public:
    int nextGreaterElement(int n) {
        string ans=to_string(n);
       next_permutation(ans.begin(),ans.end());
       if(stol(ans)<=n || stol(ans)>INT_MAX)
       {
        return -1;
       }
       return stol(ans); 
    }
};