class Solution {
public:
    // This function returns the result of dividing the dividend by the divisor
    int divide(int dividend, int divisor) {
         // If the dividend is the minimum value that an integer can take on (INT_MIN) and the divisor is -1,
         // the result would be greater than the maximum value that an integer can take on (INT_MAX).
         // Therefore, we return INT_MAX in this case.
         if(dividend==INT_MIN && divisor==-1) return INT_MAX;
         // If the dividend is INT_MIN and the divisor is 1, the result would be INT_MIN.
         // Therefore, we return INT_MIN in this case.
         if(dividend==INT_MIN && divisor==1) return INT_MIN;
         // Determine the sign of the result by exclusive ORing the signs of the dividend and divisor.
         // If the signs are different, the result will be negative. Otherwise, it will be positive.
         int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;

         // Take the absolute values of the dividend and divisor to make the division process easier.
         long int D = abs(dividend);
         long int d = abs(divisor);

         int ans=0;
         // Keep dividing the dividend by the divisor until the dividend is less than the divisor.
         while(D>=d){
             // Store the value of the divisor in a temporary variable.
             long temp = d;
             long quotient = 1;
             // Keep doubling the value of temp and the quotient until temp is greater than the dividend.
             while(temp<=D){
                 temp<<=1;
                 quotient <<=1;
                 // Add half the quotient to the result and subtract half the value of temp from the dividend.
                 ans +=quotient>>1;
                 D -=temp>>1;
             }
         }
         // Return the result multiplied by the sign.
         return ans*sign;
    }
};
