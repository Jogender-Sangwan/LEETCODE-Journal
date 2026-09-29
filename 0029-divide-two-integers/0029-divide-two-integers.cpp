class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow edge case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        if (dividend == INT_MIN && divisor == 1) {
            return INT_MIN;
        }

        // Determine the sign of the result
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert both to long long and make them positive to prevent overflow issues with INT_MIN
        long long dvd = abs((long long)dividend);
        long long dvs = abs((long long)divisor);
        long long quotient = 0;

        while (dvd >= dvs) {
            long long temp = dvs, multiple = 1;
            // Shift divisor left until it's just larger than remaining dividend
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            quotient += multiple;
        }

        return negative ? -quotient : quotient;
    }
};
