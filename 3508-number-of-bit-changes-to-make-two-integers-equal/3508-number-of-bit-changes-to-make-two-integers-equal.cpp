class Solution {
public:
    int minChanges(int n, int k) {
        int len=0;
        if(n>=k)
        {
           len=n;
        }
        else 
        {
           len=k;
        }
        vector<int>ans1(len,0);
        vector<int>ans2(len,0);
        int index1=0;
        int index2=0;
        while(n)
        {
            int rem=n%2;
            ans1[index1]=rem;
            n=n/2;
            index1++;
        }
        while(k)
        {
            int rem=k%2;
            ans2[index2]=rem;
            k=k/2;
            index2++;
        }
        reverse(ans1.begin(),ans1.end());
        reverse(ans2.begin(),ans2.end());
        int i=0;
        int j=0;
        int cnt=0;
        while(i<ans1.size() && j<ans2.size())
        {
            if(ans1[i]==1 && ans2[j]==0)
            {
                ans1[i]=0;
                cnt++;
            }
            i++;
            j++;
        }
        i=0;
        j=0;
        while(i<ans1.size() && j<ans2.size())
        {
            if(ans1[i]!=ans2[j])
            {
                return -1;
            }
            i++;
            j++;
        }
        return cnt;
    }
};