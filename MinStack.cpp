#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	// Write your code here.
	stack<pair<int,int>>st;
	int minele;
	public:
		
		// Constructor
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
			
			if(st.empty()){
                 minele = num;
			}
			else{
				minele = std::min(st.top().second,num);
			}
              st.push({num, minele});
                }
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
			if(st.empty()) return -1;
			else{
                 int popped = st.top().first;
				 st.pop();
				 return popped;
			}
			 
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
			if(st.empty())return -1;
			return st.top().first;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
			if(st.empty())return -1;
			return st.top().second;
		}
};
