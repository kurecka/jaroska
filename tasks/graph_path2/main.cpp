#include <iostream>
#include <vector>

#define REP(i,n)for(int i=0;i<n;i++)

using namespace std;

struct node {
  vector<int> next;
  int f;
  node* comp;
};

node arr[10000000];
vector< pair<int, int> > stack;

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
  vector<int> path();

  stack.push_back({s, 0});
  bool f = false;

  while(stack.size()){
    pair<int, int> p = stack.back();
    if (f) {
      path.push_back(p.first);
    }

    stack.pop_back();
    if (p.first == e) {
      good = 1;

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
