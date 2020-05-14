
#include <bits/stdc++.h>
using namespace std;

namespace p1081 {
using Int = __int128;
int N;
Int gcd(Int a, Int b) { return __gcd(a, b); }
Int lcm(Int a, Int b) { return a * b / gcd(a, b); }
struct Ratio {
  Int num{}, den{};
  Ratio(long i = 0) : num(i), den(1) {}
  Ratio &operator+=(Ratio other) {
    auto l = lcm(den, other.den);
    num *= l / den;
    den = l;
    other.num *= l / other.den;
    other.den = l;
    num += other.num;
    auto g = gcd(num, den);
    num /= g;
    den /= g;
    return *this;
  }
  Ratio operator+(Ratio const &other) const { return Ratio(*this) += other; }
  friend ostream &operator<<(ostream &os, Ratio const &ratio) {
    if (ratio.num == 0) {
      return os << '0';
    }
    long integer = ratio.num / ratio.den;
    long remain = ratio.num % ratio.den;
    if (integer) {
      os << integer;
      if (remain) {
        os << ' ';
      }
    }
    if (remain) {
      os << remain << '/' << long(ratio.den);
    }
    return os;
  }
  friend istream &operator>>(istream &is, Ratio &ratio) {
    long n, d;
    char c;
    is >> n >> c >> d;
    ratio.num = n;
    ratio.den = d;
    return is;
  }
};
int main() {
  cin >> N;
  vector<Ratio> ratios(N);
  for (int i = 0; i < N; ++i) {
    cin >> ratios[i];
  }
  cout << accumulate(begin(ratios), end(ratios), Ratio{});
  return 0;
}
} // namespace p1081

int main() { return p1081::main(), 0; }
