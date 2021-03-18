#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int maxN = 1e7 + 5;
int mp[maxN];
vector<int> primes;

vector<int> smallest_factor;
vector<bool> prime;

void sieve(int maximum) {
    maximum = max(maximum, 1);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {};

    for (int p = 2; p <= maximum; p++)
        if (prime[p]) {
            smallest_factor[p] = p;
            primes.push_back(p);

            for (int64_t i = int64_t(p) * p; i <= maximum; i += p)
                if (prime[i]) {
                    prime[i] = false;
                    smallest_factor[i] = p;
                }
        }
}

// Prime factorizes n in worst case O(sqrt n / log n). Requires having run `sieve` up to at least sqrt(n).
// If we've run `sieve` up to at least n, takes O(log n) time.
vector<pair<int, int>> prime_factorize(int n) {
    int sieve_max = int(smallest_factor.size()) - 1;
    if (1 <= n && n <= sieve_max * sieve_max) {
        vector<pair<int, int>> result;

        if (n <= sieve_max) {
            while (n != 1) {
                int p = smallest_factor[n];
                int exponent = 0;

                do {
                    n /= p;
                    exponent++;
                } while (n % p == 0);

                result.emplace_back(p, exponent);
            }

            return result;
        }

        for (auto p : primes) {
            if (p * p > n)
                break;

            if (n % p == 0) {
                result.emplace_back(p, 0);

                do {
                    n /= p;
                    result.back().second++;
                } while (n % p == 0);
            }
        }

        if (n > 1)
            result.emplace_back(n, 1);

        return result;
    }
}

int main() {
    sieve(maxN);
    vector<pair<int, int>> p = prime_factorize(33);
    for ( auto pa : p) {
        cout << pa.first << " " << pa.second << endl;
    }
    return 0;
}