class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
      //initialize the element sum and digit sum
        int e_sum=0, d_sum=0;
      //iterate through nums
        for(auto n:nums){
          
          // sum each element
            e_sum += n;
       while(n>0){
         //sum each digit 
            d_sum = d_sum + n%10;
            n= n/10;
        }
        }
      //difference between element sum and digit sum
        return abs(e_sum - d_sum);
        
    }
};
