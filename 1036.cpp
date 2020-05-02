
#include <bits/stdc++.h>
using namespace std;

namespace p1036 {
int N;
struct Student {
  string name;
  char gender;
  string id;
  int grade;
};
int main() {
  cin >> N;
  vector<shared_ptr<Student>> students[2];
  enum { MALE, FEMALE };
  for (int i = 0; i < N; ++i) {
    auto p = make_shared<Student>();
    cin >> p->name >> p->gender >> p->id >> p->grade;
    if (p->gender == 'M') {
      students[MALE].push_back(std::move(p));
    } else {
      students[FEMALE].push_back(std::move(p));
    }
  }
  sort(students[MALE].begin(), students[MALE].end(),
       [](const std::shared_ptr<Student> &a,
          const std::shared_ptr<Student> &b) { return a->grade < b->grade; });
  sort(students[FEMALE].begin(), students[FEMALE].end(),
       [](const std::shared_ptr<Student> &a,
          const std::shared_ptr<Student> &b) { return b->grade < a->grade; });
  auto print = [](vector<std::shared_ptr<Student>> &s) {
    if (s.empty()) {
      cout << "Absent\n";
    } else {
      auto &student = **s.begin();
      cout << student.name << ' ' << student.id << '\n';
    }
  };
  print(students[FEMALE]);
  print(students[MALE]);
  if (students[FEMALE].empty() || students[MALE].empty()) {
    cout << "NA\n";
  } else {
    cout << (**students[FEMALE].begin()).grade -
                (**students[MALE].begin()).grade
         << '\n';
  }
  return 0;
}
} // namespace p1036

int main() { return p1036::main(), 0; }
