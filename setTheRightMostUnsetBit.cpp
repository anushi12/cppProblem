class Solution
{
public:
    int setBit(int N)
    {
        // Check if the number N is already a power of 2
        if((N & (N+1)) ==0) return N;
        // If not, return N with the least significant bit set
        return (N|(N+1));
    }
};
