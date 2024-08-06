class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int totalCost = 0;
        int totalGas = 0;

        for(auto g: gas) {
            totalGas += g;
        }

        for(auto c: cost) {
            totalCost += c;
        }

        if(totalCost>totalGas) {
            return -1;
        }

        int currentGas = 0;
        int startingIndex = 0;
        for(int i=0;i<gas.size();i++) {
            currentGas += gas[i];

            if(currentGas-cost[i]<0) {
                currentGas=0;
                startingIndex = i+1;
            } else {
                currentGas -= cost[i];
            }
        }

        return startingIndex;
    }
};