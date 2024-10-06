class Solution {
public:
    string reformatDate(string date) {
       string d=date.substr(0,2);
       int dd=stoi(d);
       string y="";
       if(dd<10)
       {
       y=date.substr(8,4);
       }
       else
       {
       y=date.substr(9,4);
       }
       string m="";
       if(dd<10)
       {
       m=date.substr(4,3);
       }
       else{
        m=date.substr(5,3);
       }
       
       
       string months[13]={" ","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
       string ans="";
       ans+=y;
       ans+="-";
       for(int i=0;i<13;i++)
       {
        if(months[i]==m)
        {
            if(i<10)
            {
                ans+="0";
            }
            ans+=to_string(i);
        }
       }
       ans+="-";
       if(dd<10)
       {
        ans+="0";
       }
      ans+=to_string(dd);
      return ans;
    }
};