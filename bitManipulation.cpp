class Solution {
  public:
    void bitManipulation(int num, int i) {
        // check if the i-th bit of num is set (1) or not (0)
        i= i-1; 
        if((num>>i)%2){ 
            cout<<1<<" ";
        }
        else cout<<0<<" ";
        
        // set the i-th bit of num
        cout<<(num | (1<<i))<<" ";
        
        // clear the i-th bit of num
        cout<< (num & ~(1<<i))<<" ";
        
    }
};
