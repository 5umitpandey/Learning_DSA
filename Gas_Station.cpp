//https://leetcode.com/problems/gas-station/

//Approach 1 | Bruteforce
    // int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    // {
    //     int n = gas.size();
    
    //     for (int start = 0; start < n; ++start) 
    //     {
    //         int tank = 0;
    //         int completedStations = 0;
    //         int current = start;

    //         while (completedStations < n) 
    //         {
    //             tank += gas[current] - cost[current];
    //             if (tank < 0) break; // Failed at some station
    //             current = (current + 1) % n; // Move to the next station
    //             ++completedStations;
    //         }

    //         if (completedStations == n) return start;
    //     }

    //     return -1;
    // }
    //O(n^2)
    //O(1)
    

    //Approach 2 | Greedy
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int total_gas = 0, current_gas = 0, start_index = 0;

        for (int i = 0; i < gas.size(); i++) 
        {
            total_gas += gas[i] - cost[i];
            current_gas += gas[i] - cost[i];

            // If the current gas becomes negative, reset the journey
            if (current_gas < 0) 
            {
                start_index = i + 1;
                current_gas = 0;
            }
        }

        // Check if total gas is sufficient
        return total_gas >= 0 ? start_index : -1;
    }
    //O(n)
    //O(1)
