#include <iostream>
#include <vector>

#define REP(i, n) for(int i=0; i<n; i++)

using namespace std;

struct node {
  vector<int> next;
  node* comp;
};

node* get_comp(node* a){
  if (a->comp == a) return a;
  node* res = get_comp(a->comp);
  a->comp = res;
  return res;
}

node arr[1000000];

void solve(){
  int n, q;
  cin >> n >> q;

  REP(i, n){
    arr[i].comp = arr+i;
  }

  REP(i, q){
    char t;
    int a, b;
    cin >> t >> a >> b;
    if (t == 'U') {
      get_comp(arr+a)->comp = get_comp(arr+b);
    } else {
      if (get_comp(arr+a) == get_comp(arr+b)) cout << "ANO" << endl;
      else cout << "NE" << endl;
    }
  }
}

int main(){
  int t;
  cin >> t;
  REP(i, t){
    solve();
  }
}
