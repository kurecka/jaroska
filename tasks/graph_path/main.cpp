#include <iostream>
#include <vector>

#define REP(i,n)for(int i=0;i<n;i++)

using namespace std;

struct node {
  vector<int> next;
  int f;
};

node arr[10000000];
vector<int> stack;

void solve(){
  int n,m;
  int s,e;
  cin >> n >> m;
  cin >> s >> e;

  REP(i,n){
    arr[i].next.clear();
    arr[i].f = false;
  }

  REP(i, m){
    int a,b;
    cin >> a >> b;
    arr[b].next.push_back(a);
    arr[a].next.push_back(b);
  }

  int good = 0;
  stack.clear();

  stack.push_back(s);

  while(stack.size()){
    int p = stack.back();

    stack.pop_back();
    if (p == e) {
      good = 1;
      break;
    };
    if (arr[p].f) continue;
    arr[p].f = 1;

    REP(i, arr[p].next.size()){
      stack.push_back(arr[p].next[i]);
    }
  }

  if (good) cout << "ANO" << endl;
  else cout << "NE" << endl;
}

int main(){
  int t;
  cin >> t;
  for(int i=0;i<t;i++){
    solve();
  }
}
