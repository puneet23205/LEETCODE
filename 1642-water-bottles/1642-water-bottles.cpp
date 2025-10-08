class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
       int numRem;
       int numEmpty =numBottles; 
       while(numEmpty>=numExchange){
         numBottles=(numEmpty/numExchange)+numBottles;
         numRem=numEmpty%numExchange;
         numEmpty=(numEmpty/numExchange)+numRem;
       }
       return numBottles;
    }
};