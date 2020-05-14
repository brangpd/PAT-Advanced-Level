
#include <bits/stdc++.h>
using namespace std;

namespace p1083 {
int N;
struct Student {
  string name;
  string id;
  int grade;
  bool operator<(const Student &other) const { return grade < other.grade; }
};
int main() {
  cin >> N;
  set<Student> students;
  for (int i = 0; i < N; ++i) {
    Student s;
    cin >> s.name >> s.id >> s.grade;
    students.insert(s);
  }
  int l, r;
  cin >> l >> r;
  bool none = true;
  for (auto it = students.rbegin(); it != students.rend(); ++it) {
    if (l <= it->grade && it->grade <= r) {
      none = false;
      cout << it->name << ' ' << it->id << '\n';
    }
  }
  if (none) {
    cout << "NONE";
  }
  return 0;
}
} // namespace p1083

int main() { return p1083::main(), 0; }
