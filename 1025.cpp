
#include <bits/stdc++.h>
using namespace std;

namespace p1025 {
int N;
struct Test {
  int64_t registration;
  int score;
  int location;
  int local_rank;
  int global_rank;
};
bool comp(const Test &a, const Test &b) {
  if (a.score != b.score) {
    return a.score > b.score;
  }
  return a.registration < b.registration;
}
int main() {
  cin >> N;
  vector<vector<Test>> tests;
  for (int i = 0; i < N; ++i) {
    int K;
    cin >> K;
    tests.emplace_back();
    auto &location_tests = tests.back();
    for (int j = 0; j < K; ++j) {
      location_tests.emplace_back();
      auto &test = location_tests.back();
      cin >> test.registration >> test.score;
      test.location = i + 1;
    }
    sort(location_tests.begin(), location_tests.end(), &comp);
    Test tmp;
    tmp.score = -1;
    Test *last = &tmp;
    for (int j = 0; j < K; ++j) {
      auto &curtest = location_tests[j];
      if (last->score == curtest.score) {
        curtest.local_rank = last->local_rank;
      } else {
        curtest.local_rank = j + 1;
      }
      last = &curtest;
    }
  }
  vector<Test> final;
  for (auto &local_tests : tests) {
    final.insert(final.end(), local_tests.begin(), local_tests.end());
  }
  sort(final.begin(), final.end(), &comp);
  Test tmp;
  tmp.score = -1;
  Test *last = &tmp;
  for (int j = 0, je = final.size(); j < je; ++j) {
    auto &curtest = final[j];
    if (last->score == curtest.score) {
      curtest.global_rank = last->global_rank;
    } else {
      curtest.global_rank = j + 1;
    }
    last = &curtest;
  }
  cout << final.size() << '\n';
  for (auto &test : final) {
    cout << setfill('0') << setw(13) << test.registration << ' ' << setw(0)
         << test.global_rank << ' ' << test.location << ' ' << test.local_rank
         << '\n';
  }
  return 0;
}
} // namespace p1025

int main() { return p1025::main(), 0; }
