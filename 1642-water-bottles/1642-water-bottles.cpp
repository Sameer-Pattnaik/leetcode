class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
       int sum=numBottles;
       while(numBottles>1)
       {
           int ans1=numBottles/numExchange;
           int ans2=numBottles%numExchange;
           sum+=ans1;
           if(ans1>0)
           {
           numBottles=ans1+ans2;
           }
           else
           {
            numBottles=ans1;
           }
       }
       return sum; 
    }
};