// This function determines if a circular route can be completed with a given set of gas stations. 
// The function takes in two vectors representing the amount of gas and cost at each station.
// It returns the starting point of the circular route that can be completed, or -1 if no such route exists.
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
   // total_gas and total_cost represent the total amount of gas and cost for the entire route
   int total_gas =0, total_cost =0;
   // curr_gas represents the current amount of gas in the car's tank
   int curr_gas=0;
   // starting_point represents the index of the starting gas station for a potential route
   int starting_point =0;
   
   // Iterate through each gas station
   for(int i=0;i<gas.size();i++) {
      // Add the amount of gas and cost at this station to the total for the entire route
      total_gas += gas[i];
      total_cost += cost[i];
        
      // Add the amount of gas gained at this station to the current gas in the tank
      // and subtract the cost of traveling to the next station
      curr_gas += gas[i]- cost[i];

      // If the current gas in the tank is negative, we cannot complete the route from this starting point
      // So, we reset the starting point to the next gas station and reset the current gas to 0
      if(curr_gas<0) {
         starting_point = i+1;
         curr_gas=0;
      }
   }

   // If the total gas is less than the total cost, we know it is not possible to complete the route
   // So, we return -1
   // Otherwise, we return the starting point of the route that can be completed
   return (total_gas<total_cost) ? -1 : starting_point;
}
