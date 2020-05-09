
#include <bits/stdc++.h>
using namespace std;

namespace p1022 {
int N;
struct Book {
  string id;
  string title;
  string author;
  vector<string> keywords;
  string publisher;
  string year;
};
struct PtrComp {
  bool operator()(const shared_ptr<Book> &a, const shared_ptr<Book> &b) const {
    return a->id < b->id;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin >> N;
  cin.ignore();
  using map_t = unordered_map<string, set<shared_ptr<Book>, PtrComp>>;
  map_t mtitle, mauthor, mkeywords, mpublisher, myear;
  for (int i = 0; i < N; ++i) {
    auto p = make_shared<Book>();
    getline(cin, p->id);
    getline(cin, p->title);
    mtitle[p->title].insert(p);
    getline(cin, p->author);
    mauthor[p->author].insert(p);
    string keywords;
    getline(cin, keywords);
    istringstream isskw(keywords);
    istream_iterator<string> it(isskw), ite;
    copy(it, ite, back_inserter(p->keywords));
    for (auto &&kw : p->keywords) {
      mkeywords[kw].insert(p);
    }
    getline(cin, p->publisher);
    mpublisher[p->publisher].insert(p);
    getline(cin, p->year);
    myear[p->year].insert(p);
  }
  int M;
  cin >> M;
  while (M--) {
    string op, str;
    map_t::iterator it, ite;
    cin >> op;
    cin.ignore();
    getline(cin, str);
    cout << op << ' ' << str << '\n';
    switch (op[0] - '0') {
    case 1:
      tie(it, ite) = mtitle.equal_range(str);
      break;
    case 2:
      tie(it, ite) = mauthor.equal_range(str);
      break;
    case 3:
      tie(it, ite) = mkeywords.equal_range(str);
      break;
    case 4:
      tie(it, ite) = mpublisher.equal_range(str);
      break;
    case 5:
      tie(it, ite) = myear.equal_range(str);
      break;
    }
    if (it == ite) {
      cout << "Not Found\n";
    } else {
      for (auto &&p : it->second) {
        cout << p->id << '\n';
      }
    }
  }
  return 0;
}
} // namespace p1022

int main() { return p1022::main(), 0; }
