class Solution {
public:
    string sortVowels(string s) {
      unordered_map<char,int>mp;
      for(int i=0;i<s.length();i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
            mp[s[i]]++;
        }
      }  
      vector<pair<char,int>>ans;
      for(auto m:mp){
        ans.push_back(m);
      }
      sort(ans.begin(),ans.end(),[](auto &a, auto &b){
        return a.second<b.second;
      });
      stack<char>st;
      for(int i=0;i<ans.size();i++){
        while(ans[i].second){
           st.push(ans[i].first);
           ans[i].second--;
        }
      }
      for(int i=0;i<s.length();i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
            s[i]=st.top();
            st.pop();
        }
      }
      return s;
    }
};