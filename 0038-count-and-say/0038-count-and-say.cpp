class Solution {
public:
    string countAndSay(int n) {
        if(n==0) return "";
        string res = "1";
        while(n>1){
          string tmp = "";
          int si= res.size();
          for( int i =0; i<si; i++){
            int cnt=1;
            // string tmp = "";
            while(i+1<si && res[i] == res[i+1]){
              cnt++;
              i++;
            }
            tmp+=to_string(cnt)+ res[i];
          }
          res = tmp;
          --n;
        }
        return res;

    }
};