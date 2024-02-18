void countPrimes() {
    bool is_prime[1000000] = {};
    memset(is_prime, true, sizeof(is_prime));
  
    int n = 1000000;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= std::sqrt(n); ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}
