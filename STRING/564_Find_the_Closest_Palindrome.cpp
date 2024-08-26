class Solution {
public:
/*
String Implementation
Five Base Conditions: 
i) n.length() == 1  
ii) n=="11"  
iii)  n =="99....9"  
iv)  n == "100....0"   
v)  n == "1000...0001"
TC: O(n)
SC: O(n)
*/
    string nearestPalindromic(string n) {

        if(n.length()==1) {
            int integer = stoll(n);
            integer-=1;
            return to_string(integer);
        }

        if(  n=="11"){
            return "9";
        }

        if( n=="99" || n=="999" || n=="9999" || n=="99999" || n=="999999" || n=="9999999" || n=="99999999" || n=="999999999" || n=="9999999999" ){
            long long integer = stoll(n);
            integer+=2;
            return to_string(integer);
        }

        if(n == "10" || n=="100" || n=="1000" || n=="10000" || n=="100000" || n=="1000000" || n=="10000000" || n=="100000000" || n=="1000000000") {
            long long integer = stoll(n);
            integer-=1;
            return to_string(integer);
        }

        if(n=="101" || n=="1001" || n=="10001" || n=="1000001" || n=="100000001" ){
            long long integer = stoll(n);
            integer-=2;
            return to_string(integer);
        }

        string str = n;
        reverse(str.begin(),str.end());

        bool flag = false;

        if(str==n){
            flag = true;
        }

        string ans = "";

        if(flag){
            if(n.length()%2!=0){

                // eg: "12021"
                int divide = n.length()/2;
                string temp = n.substr(0,divide+1);  // "120"

                long long tempint1 = stoll(temp); // 120
                tempint1+=1; // 121
                string tempintstring1 = to_string(tempint1);  // "121"
                string string1 = tempintstring1.substr(0,tempintstring1.length()-1); //"12"
                reverse(string1.begin(),string1.end()); // "21"

                long long tempint2 = stoll(temp); // 120
                tempint2-=1; // 119
                string tempintstring2 = to_string(tempint2);  // "119"
                string string2 = tempintstring2.substr(0,tempintstring2.length()-1); // "11"
                reverse(string2.begin(),string2.end()); // "11"

                string strless = tempintstring2 + string2;  // "11911"
                string strgreater = tempintstring1 + string1;  // "12121"

                if((stoll(n)-stoll(strless))>(stoll(strgreater)-stoll(n))){
                    ans=strgreater;
                }
                else{
                    ans = strless;
                }
            }
            else{
                // eg: "123321"
                int divide = n.length()/2;
                string temp = n.substr(0,divide);  // "123"

                long long tempint1 = stoll(temp); // 123
                tempint1+=1; // 124
                string tempintstring1 = to_string(tempint1);  // "124"
                string string1 = tempintstring1.substr(0,tempintstring1.length()); //"124"
                reverse(string1.begin(),string1.end()); // "421"

                long long tempint2 = stoll(temp); // 123
                tempint2-=1; // 122
                string tempintstring2 = to_string(tempint2);  // "122"
                string string2 = tempintstring2.substr(0,tempintstring2.length()); // "122"
                reverse(string2.begin(),string2.end()); // "221"

                string strless = tempintstring2 + string2; // "122221"
                string strgreater = tempintstring1 + string1; // "124421"

                if((stoll(n)-stoll(strless))>(stoll(strgreater)-stoll(n))){
                    ans=strgreater;
                }
                else{
                    ans = strless;
                }
            }
        }
        else{
            if(n.length()%2!=0){

                // eg: "123"
                int divide = n.length()/2;
                string temp = n.substr(0,divide+1);  // "12"

                string temp1 = n.substr(0,divide); // "1"
                reverse(temp1.begin(),temp1.end()); // "1"

                long long tempint = stoll(temp); // 12
                tempint+=1; // 13
                string tempintstring1 = to_string(tempint);  // "13"
                string string1 = tempintstring1.substr(0,tempintstring1.length()-1); // "1"
                reverse(string1.begin(),string1.end()); // "1"

                long long tempint2 = stoll(temp); // 12
                tempint2-=1; // 11
                string tempintstring2 = to_string(tempint2);  // "11"
                string string2 = tempintstring2.substr(0,tempintstring2.length()-1); // "1"
                reverse(string2.begin(),string2.end()); // "1"

                string strequal = temp + temp1;  // "121"
                string strgreater = tempintstring1+string1; // "131"
                string strless = tempintstring2+string2; // "111"


                long long valueequal = abs(stoll(n)-stoll(strequal));
                long long valueless = abs(stoll(n)-stoll(strless));
                long long valuegreater = abs(stoll(strgreater)-stoll(n));
              
                long long value = min({valueequal,valueless,valuegreater});
                
                if(value==valueless){
                    ans=strless;
                }
                else if(value==valueequal){
                    ans = strequal;
                }
                else{
                    ans = strgreater;
                }
            }
            else{
                // eg: "120956"
                int divide = n.length()/2;
                string temp = n.substr(0,divide);  // "120"

                string temp1 = n.substr(0,divide); // "120"
                reverse(temp1.begin(),temp1.end()); // "021"

                long long tempint = stoll(temp); // 120
                tempint+=1; // 121
                string tempintstring1 = to_string(tempint);  // "121"
                string temp2 = tempintstring1.substr(0,tempintstring1.length()); // "121"
                reverse(temp2.begin(),temp2.end()); // "121"


                long long tempint2 = stoll(temp); // 120
                tempint2-=1; // 119
                string tempintstring2 = to_string(tempint2);  // "119"
                string string2 = tempintstring2.substr(0,tempintstring2.length()); // "119"
                reverse(string2.begin(),string2.end()); // "911"


                string strequal = temp + temp1;  // "120021"
                string strgreater = tempintstring1+temp2;  // "1121121"
                string strless = tempintstring2+string2; // "119911"

                long long valueequal = abs(stoll(n)-stoll(strequal));
                long long valueless = abs(stoll(n)-stoll(strless));
                long long valuegreater = abs(stoll(strgreater)-stoll(n));
              
                long long value = min({valueequal,valueless,valuegreater});
                
                if(value==valueless){
                    ans=strless;
                }
                else if(value==valueequal){
                    ans = strequal;
                }
                else{
                    ans = strgreater;
                }
            }
        }

        return ans;
    }
};


