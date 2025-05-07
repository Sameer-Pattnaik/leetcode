class Solution {
public:
    string multiply(string &s1, string &s2) {
        if(s1[0] == '0' || s2[0] == '0') return "0";
        int n = s1.size();
        int m = s2.size();
        vector<int> multipy(n+m,0);

        for(int i = n-1;i >= 0;--i){
            for(int j = m-1;j >= 0;--j){
                int mult = (s1[i] - '0') * (s2[j] - '0');
                int sum = mult + multipy[i+j+1];

                multipy[i+j] += sum / 10;
                multipy[i+j+1] = sum % 10;

            }
        }

        bool zero = true;
        string res = "";
        for(int& dig : multipy){
            if(zero && dig == 0) continue;
            zero = false;
            res.push_back(dig + '0');
        }
        return res;
    }
};