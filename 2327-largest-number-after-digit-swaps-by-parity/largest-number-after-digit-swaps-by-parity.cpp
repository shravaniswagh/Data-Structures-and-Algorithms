#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int largestInteger(int num) {
        vector<int> digits, evens, odds;
        int temp = num;
        
        //Extract digits and store them
        while (temp > 0) {
            int digit = temp % 10;
            digits.push_back(digit);
            if (digit % 2 == 0) evens.push_back(digit);
            else odds.push_back(digit);
            temp /= 10;
        }
        
        // Since we extracted digits in reverse order, reverse them to get the correct order
        reverse(digits.begin(), digits.end());

        // Step 2: Sort even and odd digits in descending order
        sort(evens.rbegin(), evens.rend());
        sort(odds.rbegin(), odds.rend());

        // Step 3: Reconstruct the number
        int evenIdx = 0, oddIdx = 0;
        int result = 0;

        for (int digit : digits) {
            result *= 10; // Shift left
            if (digit % 2 == 0) {
                result += evens[evenIdx++]; // Replace with the largest available even
            } else {
                result += odds[oddIdx++];  // Replace with the largest available odd
            }
        }

        return result;
    }
};
