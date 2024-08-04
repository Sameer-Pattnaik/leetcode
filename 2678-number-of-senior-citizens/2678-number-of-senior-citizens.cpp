class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans=0;
        for(auto& detail:details)
        {
            int age=stoi(detail.substr(11,2));
            ans+=age>60;
        }
        return ans;
    }
};