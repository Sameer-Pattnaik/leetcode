class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string>arr={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    vector<string>ans;
    for(int i=0;i<words.size();i++){
        string s="";
        for(int j=0;j<words[i].length();j++){
            s+=arr[words[i][j]-'a'];
        }
        ans.push_back(s);
    }
    map<string,int>mp;
    for(int i=0;i<ans.size();i++){
        mp.insert({ans[i],i});
    }
    return mp.size();
    }
};