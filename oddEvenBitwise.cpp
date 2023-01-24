class Solution{   
public:
    string oddEven(int N){
        // code here 
      
      //if N & 1 ==0 then N is even else odd
      
      // lets say N = 2 which is 10 in binary which if AND with 1 that is 01 gives 0

        return ((N&1)==0)?"even":"odd";
    }
};
