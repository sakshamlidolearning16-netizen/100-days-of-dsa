#include <stdio.h>

int integerSqrt(long long n) {
    if (n == 0 || n == 1) return n;

    long long low = 1, high = n, ans = 0;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        
        if (mid * mid == n) {
            return mid;
        } else if (mid * mid < n) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    long long n;
    if (scanf("%lld", &n) != 1) return 0;

    printf("%d\n", integerSqrt(n));

    return 0;
}