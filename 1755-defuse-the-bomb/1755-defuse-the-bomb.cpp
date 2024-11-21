class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
     int n=code.size();
     int div=abs(k);
     vector<int>res(n,0);
     for(int i=0;i<n;i++)
     {
        for(int j=1;j<=div;j++)
        {
           res[i]+=code[(n+i+k/div*j)%n];
        }
     }  
     return res; 
    }
};