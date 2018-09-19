#include <iostream>
#define REP(i,n)for(int i=0;i<n;i++)

using namespace std;

namespace sorts {
  void qsort(int* b, int* e){
    if (e-b<=1) return;

  }

  void msort(int* b, int* e, int* buffer){
    if (e-b<=1) return;
    int* m = b + (e-b)/2;
    msort(b, m, buffer);
    msort(m, e, buffer);

    int* lpos = b;
    int* rpos = m;
    for(int i=0;i<e-b;i++){
      int val = 0;
      if (lpos==m) {
        val = *(rpos++);
      }
      else if (rpos==e) {
        val = *(lpos++);
      }
      else if ((*lpos) < (*rpos)) {
        val = *(lpos++);
      } else {
        val = *(rpos++);
      }
      buffer[i] = val;
    }
    for(int i=0;i<e-b;i++){
      b[i] = buffer[i];
    }
  }

  void bubble_sort(int* b, int* e){
    for(int i=0;i<(e-b);i++){
      for(int* it=b;it!=(e-1);it++){
        if (*it > *(it+1)) {
          int p = *it;
          *it = *(it+1);
          *(it+1) = p;
        }
      }
    }
  }
}

int arr[10000000];
int buffer[10000000];

void solve(){
  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }
  sorts::bubble_sort(arr, arr+n);


  for(int i=0;i<n;i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main(){
  int t;
  cin >> t;
  for(int i=0;i<t;i++){
      solve();
  }
}
