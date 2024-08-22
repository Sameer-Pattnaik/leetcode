class Solution {
public:
    int findComplement(int num) {
        vector<int>arr;
        while(num)
        {
            int rem=num%2;
            arr.push_back(rem);
            num=num/2;
        }

        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==0)
            {
                arr[i]=1;
            }
            else
            {
                arr[i]=0;
            }
        }

        int i=0;
        int ans=0;
        while(i<arr.size())
        {
            if(arr[i]==1)
            {
            ans=ans+pow(2,i);
            }
            i++;
        }
        return ans;
        

    }
};