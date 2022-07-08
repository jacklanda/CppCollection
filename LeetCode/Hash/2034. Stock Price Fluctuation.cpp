class StockPrice {
private:
    int max_timestamp = INT_MIN;
    std::unordered_map<int, int> time2price;
    std::multiset<int> prices;

public:
    StockPrice() {}

    void update(int timestamp, int price) {
        max_timestamp = std::max(timestamp, max_timestamp);
        if (time2price.count(timestamp) > 0) {
            auto it = prices.find(time2price[timestamp]);
            prices.erase(it);
        }
        time2price[timestamp] = price;
        prices.emplace(price);
    }

    int current() { return time2price[max_timestamp]; }

    int maximum() { return *prices.rbegin(); }

    int minimum() { return *prices.begin(); }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
