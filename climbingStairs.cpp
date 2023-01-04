// This function returns the number of ways to climb n stairs
// by taking either 1 or 2 steps at a time
int climbStairs(int n) {
  // If there are no stairs, there are no ways to climb them
  if(n==0)
  return 0;

  // If there is only 1 stair, there is only 1 way to climb it
  if(n==1)
  return 1;

  // If there are 2 stairs, there are 2 ways to climb them
  // (1 step at a time, or 2 steps at once)
  if(n==2)
  return 2;

  // Initialize variables to keep track of the number of ways
  // to climb 1 and 2 stairs at a time
  int total_steps = 0;
  int forOneStep =  2;
  int forTwoStep =  1;

  // Loop through the remaining stairs, starting from the 3rd stair
  for(int i=2;i<n;i++){
    // The total number of ways to climb the current number of stairs
    // is the sum of the number of ways to climb 1 and 2 stairs at a time
    // on the previous step
    total_steps = forOneStep + forTwoStep;

    // Update the number of ways to climb 2 stairs at a time to be
    // the previous number of ways to climb 1 stair at a time
    forTwoStep = forOneStep;

    // Update the number of ways to climb 1 stair at a time to be
    // the total number of ways for the current step
    forOneStep = total_steps;
  }

  // Return the total number of ways to climb the stairs
  return total_steps;
}
