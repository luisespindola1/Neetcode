int maxProfit(int* prices, int pricesSize) {


    int max_profit = 0;
    int min_price = prices[0];

    for(int i = 0; i < pricesSize; i++){
        if(prices[i] < min_price){
            min_price = prices[i];
        }
        else if(prices[i] - min_price > max_profit){
            max_profit = prices[i] - min_price;
        }
    }
    return max_profit;
}