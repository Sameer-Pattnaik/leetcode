class Solution {
public:
    int dayOfYear(string date) {
       string d=date.substr(8,2);
       int dd=stoi(d);
       string m=date.substr(5,2);
       int mm=stoi(m);
       string y=date.substr(0,4);
       int yy=stoi(y);
       int c[12]={31,28,31,30,31,30,31,31,30,31,30,31};
       if(yy%400==0 || (yy%4==0 && yy%100!=0))
       {
        c[1]={29};
       }
       for(int i=0;i<mm-1;i++)
       {
        dd=dd+c[i];
       }
       return dd;
    }
};