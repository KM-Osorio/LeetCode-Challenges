# 📂 121. Best Time to Buy and Sell Stock

- **Difficulty:** Easy
- **Tags:** `Array` `Dynamic Programming` `Greedy`
- **Link:** [LeetCode Problem Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

---

## 💡 Solution Approach

The problem asks us to maximize profit by choosing a single day to buy and a different day in the future to sell.

I used a **One Pass (Greedy)** approach. Instead of trying to predict the future or comparing every pair ($O(N^2)$), we iterate through the prices while keeping track of two variables:
1.  `min_price`: The lowest price observed **so far**.
2.  `max_profit`: The maximum profit calculated (`current_price - min_price`) encountered so far.

Logic:
- If the current price is lower than our `min_price`, we update `min_price` (finding a new valley).
- Else, if selling at the current price yields a better profit than `max_profit`, we update our record.

---

## 📊 Complexity Analysis

- **Time Complexity:** $O(N)$
  - **Why:** We traverse the `prices` array exactly once, performing constant time operations ($O(1)$) at each step.
- **Space Complexity:** $O(1)$
  - **Why:** We only store two integer variables (`buy` and `profit`), regardless of the input size. No extra arrays or data structures are used.

---

## 🐛 Debugging & Error Log (Post-Mortem)

| Error Type | Issue Description | Root Cause | Fix / Learning |
| :--- | :--- | :--- | :--- |
| **Logic Error** | Tried to find the global minimum first using `min_element` and then search for a selling point after it. | False assumption: The best buy time is always the absolute lowest price in the array (fails if the global min appears after the peak). | Switched to a **One Pass** dynamic approach where `min_price` is updated as we iterate. |
| **Syntax / Safety** | Potential segmentation fault if `prices` array is empty. | Initializing `int buy = prices[0]` without checking `prices.size()`. | Added a guard clause: `if (prices.empty()) return 0;` at the start. |
| **Clean Code** | Unused variable warning (`sell`). | Declared `int sell` but calculated profit directly in the loop condition. | Removed the `sell` variable to reduce memory usage and noise. |

---

## 🧠 Technical Deep Dive: Why Greedy works here?

This problem is a classic example of a **Greedy Algorithm** that simulates a local decision-making process.

Often, stock problems suggest Dynamic Programming. We could define `dp[i]` as the max profit selling on day `i`.
$$dp[i] = prices[i] - \min(prices[0]...prices[i-1])$$

However, notice that to solve `dp[i]`, we don't need the entire history of previous prices; we only need the **minimum** seen so far. By maintaining that state in a single variable (`buy` or `min_price`), we reduce the Space Complexity from $O(N)$ (if we stored a DP array) to $O(1)$. This optimization is critical in High-Frequency Trading (HFT) contexts where memory latency matters.
