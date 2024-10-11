class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> vec;
        for(int i=0;i<n;i++) vec.push_back(i+1);
        for(int i=0;i<k-1;i++) next_permutation(vec.begin(),vec.end());
        string s;
        for(int i=0;i<n;i++) s+='0'+vec[i];
        return s;
    }
};