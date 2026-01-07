class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        int i=0;
        int j=0;
        while(i<target.size()){
           if(target[i]==j+1){
            ans.push_back("Push");
            i++;
           }
           else{
            ans.push_back("Push");
            ans.push_back("Pop");
           }
           j++;
        }
        return ans;
    }
};