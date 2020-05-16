
#include <bits/stdc++.h>
using namespace std;

namespace p1069 {
bool play(string &n) {
  string first, second;
  first = n, second = n;
  sort(begin(first), end(first), greater<char>());
  sort(begin(second), end(second));
  if (first[0] == second[0]) {
    cout << n << " - " << n << " = 0000\n";
    return false;
  }
  int firsti, secondi;
  firsti = stoi(first), secondi = stoi(second);
  auto resulti = firsti - secondi;
  ostringstream oss;
  oss << setfill('0') << setw(4) << resulti;
  n = oss.str();
  cout << first << " - " << second << " = " << n << '\n';
  return n != "6174";
}
int main() {
  int N;
  cin >> N;
  ostringstream oss;
  oss << setfill('0') << setw(4) << N;
  string n = oss.str();
  while (play(n))
    ;
  return 0;
}
} // namespace p1069

int main() { return p1069::main(), 0; }
