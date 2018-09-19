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



void gen_sample(int n, int m, int it, ofstream& out){
  int s,e;
  s = 1+rand()%(n-1);
  e = 1+rand()%(n-1);
  if (e==s) e++;
  if (e>=n) e = 1;
  if (it%2){

    out << n << " " << m << " " << s << " " << e << endl;
    for(int i=0;i<m;i++){
      int a,b;

      do{
        a = rand()%n;
      }while(a==s);

      do{
        b = rand()%n;
      }while(b==s);
      out << a << " " << b << endl;
    }
  } else {
      out << n << " " << m << " " << s << " " << e << endl;
      for(int i=1;i<n;i++){
        int a = rand()%i;
        out << a << " " << i << endl;
      }
      for(int i=n-1;i<m;i++){
        int a,b;
        a = rand()%n;
        b = rand()%n;
        out << a << " " << b << endl;
      }
  }
}

void gen_set(int n, int ma, int num_of_smaples, int set_number){
  ofstream out(string("input/input"+string(itos(set_number))+string(".txt")));
  out << num_of_smaples << endl;
  for(int i=0;i<num_of_smaples;i++){
    gen_sample(n, ma, i, out);
  }
  out.close();
}

int main(){
  srand(time(NULL));
  int set = 1;
  gen_set(2, 1, 2, set++);
  gen_set(5, 5, 2, set++);
  gen_set(5, 10, 10, set++);
  gen_set(1000, 1000, 10, set++);
  gen_set(100000, 100000, 10, set++);
}
