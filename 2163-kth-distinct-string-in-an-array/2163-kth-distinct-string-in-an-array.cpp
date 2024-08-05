class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
    
        vector<string>res;
        int n=arr.size(),count=0;
        map<string,int>mpp;
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
        }
        for(int i=0;i<n;i++){
            if(mpp[arr[i]]==1){
            res.push_back(arr[i]);
            count++;
            }
        }
        if(k>count) return "";
         return res[k-1];
    
    }
};