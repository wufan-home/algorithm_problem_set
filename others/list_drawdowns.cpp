/*
A drawdown is defined as the maximum value minus the minimum value after it. 
Given a graph, find all the drawdowns of it. 
Note: All the drawdowns should not intersect each other.
*/

#include <iostream>
#include <functional>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

struct data {
    int from;
    int to;
    double delta;
};

float drawdowncalc(vector<double>& price, int n) {
    double res = 0.0;

    int size = price.size();
    if (n == 0 || size < 2) {
        return res;
    }

    stack<double> maxPriceStack;
    maxPriceStack.push(price[0]);
    stack<double> minPriceStack;
    minPriceStack.push(price[0]);
    for (int i = 1; i < size; ++i) {
        if (price[i] > minPriceStack.top()) {
            maxPriceStack.push(price[i]);
            minPriceStack.push(price[i]);
            cout << i << " - push same values: " << maxPriceStack.top() << ", " << minPriceStack.top()  << ", size = " << minPriceStack.size() << endl;
        }
        else if (price[i] < minPriceStack.top()) {
            minPriceStack.pop();
            minPriceStack.push(price[i]);
            cout << i << " - push different values: " << maxPriceStack.top() << ", " << minPriceStack.top() << ", size = " << minPriceStack.size() << endl;
            while (minPriceStack.size() > 1) {
                double minPrice = minPriceStack.top();
                minPriceStack.pop();
                double maxPrice = maxPriceStack.top();
                maxPriceStack.pop();
                if (maxPriceStack.top() > maxPrice && minPriceStack.top() > minPrice) {
                    minPriceStack.pop();
                    minPriceStack.push(minPrice);
                }
                else {
                    maxPriceStack.push(maxPrice);
                    minPriceStack.push(minPrice);
                    break;
                }
            }
            cout << i << " - push different values (adjust): " << maxPriceStack.top() << ", " << minPriceStack.top() << ", si
ze = " << minPriceStack.size() << endl;
        }
    }

    auto comp = [](const double l, const double r) { return l < r; };
    priority_queue<double, vector<double>, decltype(comp)> pq(comp);
    while (!minPriceStack.empty()) {
        cout << "Calculate drawdowns: " << maxPriceStack.top() << ", " << minPriceStack.top() << ", size = " << minPriceStack
.size() << endl;
        if (minPriceStack.top() != maxPriceStack.top()) {
            pq.push(maxPriceStack.top() - minPriceStack.top());
        }
        maxPriceStack.pop();
        minPriceStack.pop();
    }

    while (!pq.empty() && n-- > 0) {
        cout << "pq top = " << pq.top() << endl;
        res += pq.top();
        pq.pop();
    }

    return res;
}

int main() {
    vector<double> test1({1.1, 1.8, 1.1});
    cout << "result1 = " << drawdowncalc(test1, 1) << endl;

    cout << "====" << endl;

    vector<double> test2({1.1, 1.8, 1.1, 2.0, 1.0});
    cout << "result2 = " << drawdowncalc(test2, 2) << endl;

    cout << "====" << endl;

    vector<double> test3({1.1, 1.8, 1.1, 2.0, 1.0, 1.6, 1.2});
    cout << "result3 = " << drawdowncalc(test3, 3) << endl;

    vector<double> test4({1.1, 1.8, 1.1, 2.0, 1.0, 1.6, 1.2});
    cout << "result4 = " << drawdowncalc(test4, 5) << endl;

    vector<double> test5({1.1, 1.8, 1.1, 2.0, 1.9, 1.8, 1.7, 1.6, 1.5, 1.4, 1.3, 1.2, 1.1, 1.0, 1.6, 1.2});
    cout << "result5 = " << drawdowncalc(test5, 3) << endl;

    return 1;
}
