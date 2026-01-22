// Problem:  Best Time to Buy and Sell Stock
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Difficulty: Easy
// Tags: Array, Dynamic, Programming

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX; // Iniciamos con un valor muy alto
        int max_profit = 0;      // Ganancia inicial es 0

        for (int price : prices) {
            // 1. ¿Es este precio más bajo que el mínimo que he visto antes?
            if (price < min_price) {
                min_price = price; // Actualizamos el mínimo para futuras ventas
            } 
            // 2. Si vendiera hoy, ¿gano más que mi récord actual?
            else if (price - min_price > max_profit) {
                max_profit = price - min_price;
            }
        }
        
        return max_profit;
    }
};
