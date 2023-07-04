class Solution {
public:
    int compareVersion(string v1, string v2) {
        // d1 d2 -> store the count of .

        int d1 = count (v1.begin(), v1.end(), '.');
        int d2 = count (v2.begin(), v2.end(), '.');


            int dif = abs(d1-d2);
            if(d1>d2){
              // .0
              while(dif--) v2 +=".0";
            }else if(d1<d2){
              // .0
              while(dif--) v1+=".0";
            }

            replace(v1.begin(),v1.end(),'.',' ' );
            replace(v2.begin(),v2.end(),'.',' ' );

            // StringStream sin(" 1  13  45") sin>>x>>y>>z; x=1,y=13,z=45;

            stringstream ssv1(v1), ssv2(v2);

            int n1, n2;

            while( ssv1>>n1){
              ssv2>>n2;

              if(n1<n2) return -1;
              else if(n2<n1) return 1;
            }
            return 0;

    }
};