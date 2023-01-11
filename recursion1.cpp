//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    
    void recursion(int n,int b){
        int a= n;
        if(a==b+1){
            return ;
        }
        cout<<a++<<" ";
        recursion(a,b);
    }
    public:
    //Complete this function
    
    void printNos(int N)
    {
      recursion(1,N);
    }
};

//{ Driver Code Starts.
/* Driver program to test printNos */
int main()
{
    int T;
    
    //taking testcases
    cin>>T;
    
    while(T--)
    {
        int N;
        
        //input N
        cin>>N;
        Solution ob;
        //calling printNos() function
        ob.printNos(N);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
