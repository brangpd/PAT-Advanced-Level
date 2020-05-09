
#include <bits/stdc++.h>
using namespace std;

namespace p1084 {
string a, b;
int main() {
  cin >> a >> b;
  set<char> worn;
  auto ait = a.begin(), aite = a.end();
  auto bit = b.begin(), bite = b.end();
  while (bit != bite) {
    while (ait != aite && *ait != *bit) {
      char output = toupper(*ait++);
      bool inserted;
      tie(ignore, inserted) = worn.insert(output);
      if (inserted) {
        cout << output;
      }
    }
    ++ait;
    ++bit;
  }
  return 0;
}
} // namespace p1084

int main() { return p1084::main(), 0; }
