
#include <bits/stdc++.h>
using namespace std;

namespace p1016 {
using namespace chrono;
enum rec_typ {
  ONLINE,
  OFFLINE,
};
using days = duration<int32_t, ratio<3600 * 24>>;
int tolls[28];
int tollsum;
int N;
using dur = minutes;
map<string, dur> online;
map<string, vector<tuple<dur, rec_typ>>> records;
int month;
string as2Digits(long long n) {
  char buf[4];
  sprintf(buf, "%02lld", n);
  return buf;
}
string asTime(dur t) {
  stringstream ss;
  auto d = duration_cast<days>(t);
  auto h = duration_cast<hours>(t) % 24;
  auto min = duration_cast<minutes>(t) % 60;
  ss << as2Digits(d.count());
  ss << ':';
  ss << as2Digits(h.count());
  ss << ':';
  ss << as2Digits(min.count());
  return ss.str();
}
int64_t calculate(dur beginning, dur ending) {
  int64_t res{};
  for (auto t = duration_cast<hours>(beginning); t <= ending; t += hours(1)) {
    auto tlow = t;
    auto thigh = tlow + hours(1);
    auto idx = tlow.count() % 24;
    auto lower = tlow < beginning ? beginning : tlow;
    auto upper = thigh < ending ? thigh : ending;
    res += tolls[idx] * (duration_cast<minutes>(upper).count() -
                         duration_cast<minutes>(lower).count());
  }
  return res;
}
int64_t charge(dur beginning, dur ending) {
  if (beginning > ending) {
    return 0;
  }
  int64_t res{};
  auto fulldays = duration_cast<days>(ending - beginning);
  res += fulldays.count() * tollsum * 60;
  ending -= fulldays;
  res += calculate(beginning, ending);
  return res;
}
string asDollar(int64_t cents) {
  string res;
  res += to_string(cents / 100);
  res += '.';
  res += as2Digits(cents % 100);
  return res;
}
int main() {
  for (int i = 0; i < 24; ++i) {
    cin >> tolls[i];
    tollsum += tolls[i];
  }
  cin >> N;
  for (int i = 0; i < N; ++i) {
    string name;
    string type;
    char c;
    int d, h, m;
    cin >> name >> month >> c >> d >> c >> h >> c >> m >> type;
    auto t = days(d) + hours(h) + minutes(m);
    if (type == "on-line") {
      records[name].push_back({t, ONLINE});
    } else {
      records[name].push_back({t, OFFLINE});
    }
  }
  for (auto &&[name, record] : records) {
    enum { DUR, RECTYP };
    sort(record.begin(), record.end(),
         [](tuple<dur, rec_typ> const &a, tuple<dur, rec_typ> const &b) {
           return get<DUR>(a) < get<DUR>(b);
         });
    bool shouldOutput{}; // The F**KING inconsistency
    int64_t amount{};
    for (auto it1 = record.begin(), it2 = it1 + 1; it2 != record.end();
         ++it1, ++it2) {
      if (get<RECTYP>(*it1) == ONLINE && get<RECTYP>(*it2) == OFFLINE) {
        if (!shouldOutput) {
          cout << name << ' ' << as2Digits(month) << '\n';
        }
        shouldOutput = true;

        auto beginning = get<DUR>(*it1);
        auto ending = get<DUR>(*it2);
        auto cents = charge(beginning, ending);
        amount += cents;
        auto span = duration_cast<minutes>(ending - beginning).count();
        cout << asTime(beginning) << ' ' << asTime(ending) << ' ' << span
             << ' ';
        cout << '$' << asDollar(cents) << '\n';
      }
    }
    if (shouldOutput) {
      cout << "Total amount: $" << asDollar(amount) << '\n';
    }
  }
  return 0;
}
} // namespace p1016

int main() { return p1016::main(), 0; }
