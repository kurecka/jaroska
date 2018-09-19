#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <algorithm>

using namespace std;

void reverse(string& a){
  for(int i=0;i<a.size()/2;i++){
    swap(a[i], a[a.size()-i-1]);
  }
}

string itos(int a){
  if (a==0) return string("0");
  string str;
  while(a){
    str += '0'+(a%10);
    a /= 10;
  }
  reverse(str);
  return str;
}

void gen_sample(int n, int ma, ofstream& out){
  out << n << endl;
  for(int i=0;i<n;i++){
    if (i) out << " ";
    out << rand() % ma;
  }
  out << endl;
}

void gen_set(int n, int ma, int num_of_smaples, int set_number){
  ofstream out(string("input/input"+string(itos(set_number))+string(".txt")));
  out << num_of_smaples << endl;
  for(int i=0;i<num_of_smaples;i++){
    gen_sample(n, ma, out);
  }
  out.close();
}

int main(){
  srand(time(NULL));
  int set = 1;
  gen_set(1, 1000000, 1, set++);
  gen_set(2, 1000000, 1, set++);
  gen_set(10, 1000000, 1, set++);
  gen_set(1000, 1000000, 5, set++);
  // gen_set(10000000, 1000000, 5, set++);
  gen_set(100000, 1000000000, 5, set++);
}
