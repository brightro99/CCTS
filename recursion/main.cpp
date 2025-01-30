#include <iostream>

int fact_down(int n) {
    if (n == 1 || n == 0) return 1;
    return n * fact_down(n - 1);
}

int fact_up(int n) {
    if (n == 100) return 1;
    return fact_up(n + 1);
}

int fact_for(int n) {
    int ret = 1;
    for (int i = 1; i <= n; i++) {
        ret *= i;
    }
    return ret;
}
int fibo(int n) {
    std::cout << "fibo : " << n << "\n";
    if (n == 0 || n == 1) return n;
    return fibo(n - 1) + fibo(n - 2);
}

int main() {
    std::cout << "fact_down : " << fact_down(5) << "\n";
    std::cout << "fact_up : " << fact_up(5) << "\n";
    std::cout << "fact_for : " << fact_for(5) << "\n";
    std::cout << "fibo : " << "\n";
    std::cout << fibo(5) << "\n";
    return 0;
}