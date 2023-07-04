class Solution {
public:
    int compareVersion(string s1, string s2) {
        int i =0, j=0, c1 =0, c2=0;
        int n = s1.length(), m = s2.length();

        while(i<n || j<m){
          while(i < n && s1[i] !='.'){
            c1 = c1* 10 + (s1[i] - '0');
            i++;
          }while(j<m && s2[j] != '.'){
            c2 = c2 * 10 + (s2[j] - '0');
            j++;
          }
          if( c1 > c2)
          return 1;
          else if(c1 < c2)
          return -1;

          c1 =0, c2 =0;
          i++, j++;
        }
        return 0;
         
    }
};