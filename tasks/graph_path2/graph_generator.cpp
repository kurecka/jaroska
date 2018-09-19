#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <vector>

#define REP(i, n) for(int i=0; i<n; i++)

using namespace std;

struct node {
  vector<int> next;
  node* comp;
};

struct query {
  char c;
  int a,b;
};

node* get_comp(node* a){
  if (a->comp == a) return a;
  node* res = get_comp(a->comp);
  a->comp = res;
  return res;
}

node arr[1000000];
vector<query> q;

void gen_sample(int s, int it, ofstream& out){
  if (s>3){
    int n;
    switch (s) {
      case 4:
        n = 10;
        break;
      case 5:
        n = 1000;
        break;
      case 6:
        n = 100000;
        break;
    }
    out << n << " " << 2*n << endl;
    REP(i, n){
      int a = rand()%n;
      int b = rand()%n;
      out << "U " << a << " " << b << endl;
    }
    REP(i, n){
      int a = rand()%n;
      int b = rand()%n;
      out << "Q " << a << " " << b << endl;
    }

    return;
  }

  int n;
  switch (s) {
    case 1:
      n = 10;
      break;
    case 2:
      n = 1000;
      break;
    case 3:
      n = 100000;
      break;
  }

  q.clear();

  REP(i, n-1){
    int pos = i+1;
    int a = rand()%max(1, pos-1);
    int b = pos-1;
    // get_comp(arr+a)->comp = get_comp(arr+b);
    q.push_back({'U', a, b});
    a = rand()%pos;
    b = rand()%pos;
    q.push_back({'Q', a, b});
    a = rand()%pos;
    b = pos+rand()%(n-pos);
    q.push_back({'Q', a, b});
  }
  out << n << " " << q.size() << endl;
  REP(i, q.size()){
    out << q[i].c << " " << q[i].a << " " << q[i].b << endl;
  }

  out << n << " " << 2*n << endl;
  REP(i, n){
    int a = rand()%n;
    int b = rand()%n;
    out << "Q " << a << " " << b << endl;
    a = rand()%n;
    b = rand()%n;
    out << "U " << a << " " << b << endl;
  }
}
