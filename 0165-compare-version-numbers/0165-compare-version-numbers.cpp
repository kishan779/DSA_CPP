class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i =0, j=0, nn =0, mm=0;
        int n = version1.size(), m = version2.size();

        while(i<n || j<m){
          while(i < n && version1[i] !='.'){
            nn = nn* 10 + (version1[i] - '0');
            i++;
          }while(j<m && version2[j] != '.'){
            mm = mm * 10 + (version2[j] - '0');
            j++;
          }
          if( nn > mm)
          return 1;
          else if(nn < mm)
          return -1;

          nn =0, mm =0;
          i++, j++;
        }
        return 0;
         
    }
};