class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x=0;
        for(int i=0;i<operations.size();i++)
        {
            if(operations[i].contains('+'))
            {
                x+=1;
            }
            else if(operations[i].contains('-'))
            {
                x-=1;
            }
        }
        return x;
    }
};