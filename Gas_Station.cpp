//https://leetcode.com/problems/gas-station/

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int n = gas.size();
    
        for (int start = 0; start < n; ++start) 
        {
            int tank = 0;
            int completedStations = 0;
            int current = start;

            while (completedStations < n) 
            {
                tank += gas[current] - cost[current];
                if (tank < 0) break; // Failed at some station
                current = (current + 1) % n; // Move to the next station
                ++completedStations;
            }

            if (completedStations == n) return start;
        }

        return -1;
    }

