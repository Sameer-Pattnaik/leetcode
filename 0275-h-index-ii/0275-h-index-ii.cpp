class Solution {
public:
    int hIndex(vector<int>& citations) {
        int low=0;
        int high=citations.size()-1;
        int mid=(high+low)/2;
        while(low<=high)
        {
             if(citations[mid]==citations.size()-mid)
             {
                return citations[mid];
             }
             else if(citations[mid]>citations.size()-mid)
             {
                high=mid-1;
             }
             else
             {
                low=mid+1;
             }
             mid=(high+low)/2;
        }
        return citations.size()-low;
    }
};