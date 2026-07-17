class Solution {
public:
    bool isIPv4(string command){
        int start=0;
        int segment=0;
        if(count(command.begin(),command.end(),'.')!=3){
            return false;
        }
        for(int i=0;i<=command.length();i++){
            if(command[i]=='.' || i==command.length()){
               int len=i-start;
               if(len<1 || len>3){
                return false;
               }
               if(len>1 && command[start]=='0'){
                return false;
               }
               int num=0;
               for(int j=start;j<i;j++){
                if(!isdigit(command[j])){
                    return false;
                }
                num=num*10+(command[j]-'0');
               }
               if(num>255){
                return false;
               }
               start=i+1;
               segment++;
            }
        }
        return segment==4;
    }
    bool isIPv6(string command){
        int start=0;
        int segment=0;
        if(count(command.begin(),command.end(),':')!=7){
            return false;
        }
        for(int i=0;i<=command.length();i++){
            if(command[i]==':' || i==command.length()){
                int len=i-start;
               if(len<1 || len>4){
                return false;
               }
               for(int j=start;j<i;j++){
                if(!isxdigit(command[j])){
                    return false;
                }
               }
               start=i+1;
               segment++;
            }
        }
        return segment==8;
    }
    string validIPAddress(string queryIP) {
        if(isIPv4(queryIP)){
            return "IPv4";
        }
        else if(isIPv6(queryIP)){
            return "IPv6";
        }
        return "Neither";
    }
};