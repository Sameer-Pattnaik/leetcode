class Solution {
public:
    string mergeAlternately(string word1, string word2) {
       string ans="";
       int n1=word1.length(); 
       int n2=word2.length();
       int i=0,j=0,k=0;
       while(i<n1 && j<n2)
       {
           if(k%2==0)
           {
            ans.push_back(word1[i]);
            i++;
            k++;
           }
           else
           {
            ans.push_back(word2[j]);
            j++;
            k++;
           }
       }
       while(i<n1)
       {
        ans.push_back(word1[i]);
        i++;
        k++;
       }
       while(j<n2)
       {
        ans.push_back(word2[j]);
        j++;
        k++;
       }
       return ans;
    }
};