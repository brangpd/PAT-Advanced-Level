
#include <bits/stdc++.h>
using namespace std;

namespace p1098 {
int N;
enum { maxn = 105 };
int arr[maxn];
int arrbackup[maxn];
int part[maxn];
void print(const char *method) {
  cout << method;
  for (int i = 0; i < N; ++i) {
    cout << " \n"[i == 0] << arr[i];
  }
}
int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> arrbackup[i];
  }
  for (int j = 0; j < N; ++j) {
    cin >> part[j];
  }
  copy(arrbackup, arrbackup + N, arr);
  for (int i = 1; i < N; ++i) {
    for (int j = i - 1; j >= 0; --j) {
      if (arr[j + 1] < arr[j]) {
        swap(arr[j], arr[j + 1]);
      }
    }
    if (equal(part, part + N, arr)) {
      ++i;
      for (int j = i - 1; j >= 0; --j) {
        if (arr[j + 1] < arr[j]) {
          swap(arr[j], arr[j + 1]);
        }
      }
      print("Insertion Sort");
      return 0;
    }
  }
  copy(arrbackup, arrbackup + N, arr);
  int heaplen = N;
  make_heap(arr, arr + heaplen);
  while (true) {
    if (!equal(part, part + N, arr)) {
      swap(arr[0], arr[--heaplen]);
      make_heap(arr, arr + heaplen);
    } else {
      swap(arr[0], arr[--heaplen]);
      make_heap(arr, arr + heaplen);
      print("Heap Sort");
      break;
    }
  }

  return 0;
}
} // namespace p1098

int main() { return p1098::main(), 0; }
