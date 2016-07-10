/*
  There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
  You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). 
  You begin the journey with an empty tank at one of the gas stations.
  Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
  Note:
  The solution is guaranteed to be unique.

  Solution: The circuit can be completed only if the total gas is greater or equal to the total cost.
  If the circuit can be completed, start from any point, e.g., 0, and run on the circuit.
  Exit when all startions are visited.
  If the current gas remaining is not larger than 0, set the new start point to be the next station
  of the current one. Use modulo to set the index to be 0, if the index is the size of the stations.
*/

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	int num = gas.size();
        long long total_gas = 0;
        long long total_cost = 0;
        for(int i = 0; i < num; ++i)
        {
		total_gas += gas[i];
		total_cost += cost[i];
        }
        
        if(total_gas < total_cost)
		return -1;
            
        int start = 0;
        for(int i = 0, stations = 1, current = 0; stations <= num;)
        {
		current += gas[i] - cost[i];
		i = (i + 1) % num;
		if(current < 0)
		{
			start = i;
			current = 0;
			stations = 1;
		}
		else
			++stations;
        }
        
        return start;
}
