
#include <bits/stdc++.h>
using namespace std;

namespace p1012 {
int N, M;
struct Student {
  int id;
  int c, m, e;
  int a;
  int rank;
  int currank;
  char sym;
};
enum { inf = numeric_limits<int>::max() };
vector<Student> students;
void work(char sym, function<int(Student const &)> getField) {
  sort(students.begin(), students.end(),
       [&getField](Student const &a, Student const &b) {
         return getField(a) > getField(b);
       });
  Student guard;
  guard.a = guard.c = guard.m = guard.e = -1;
  guard.rank = 0;
  Student *last = &guard;
  for (int i = 0; i < N; ++i) {
    auto &student = students[i];
    int rank;
    if (getField(*last) != getField(student)) {
      rank = i + 1;
    } else {
      rank = last->currank;
    }
    student.currank = rank;
    last = &student;
    if (student.rank > rank) {
      student.rank = rank;
      student.sym = sym;
    }
  }
}
int main() {
  cin >> N >> M;
  students.resize(N);
  for (int i = 0; i < N; ++i) {
    auto &student = students[i];
    cin >> student.id >> student.c >> student.m >> student.e;
    student.a = student.c + student.m + student.e;
    student.rank = inf;
    student.sym = 0;
  }
  work('A', [](Student const &student) { return student.a; });
  work('C', [](Student const &student) { return student.c; });
  work('M', [](Student const &student) { return student.m; });
  work('E', [](Student const &student) { return student.e; });
  for (int i = 0; i < M; ++i) {
    int id;
    cin >> id;
    auto it = find_if(students.begin(), students.end(),
                      [id](Student const &s) { return s.id == id; });
    if (it == students.end()) {
      cout << "N/A\n";
    } else {
      cout << it->rank << ' ' << it->sym << '\n';
    }
  }

  return 0;
}
} // namespace p1012

int main() { return p1012::main(), 0; }
