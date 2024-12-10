class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
       int cnt=0;
       vector<string>obj;
       while(left<=right)
       {
          obj.push_back(words[left]);
          left++;
       }
       for(int i=0;i<obj.size();i++)
       {
        string word=obj[i];
        if((word[0]=='a'|| word[0]=='e' || word[0]=='i' || word[0]=='o' || word[0]=='u')&&(word[word.length()-1]=='a'|| word[word.length()-1]=='e' || word[word.length()-1]=='i' || word[word.length()-1]=='o' || word[word.length()-1]=='u'))
        {
            cnt++;
        }
       }
       return cnt; 
    }
};