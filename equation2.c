#include <stdio.h>

typedef struct _fraction{
  int num;
  int den;
}frac;

int gcd(int x, int y) {
  while(x!=y && x*y!=0){
    int a = x>y? x : y;
    int b = x>y? y : x;

    x = a - b;
    y = b;
  }
  //if(y==0){puts("error: division by zero");}
  return y;
}


frac reduce(frac x){
  int g = gcd(abs(x.num),abs(x.den));
  frac a;
  a.num=x.num/g;
  a.den=x.den/g;
  if(a.den<0){
    a.den=-a.den;
    a.num=-a.num;
  }
  return a;
}
frac mul(frac x, frac y){
  frac ans;
  ans.num = x.num * y.num;
  ans.den = x.den * y.den;
  ans = reduce(ans);

  return ans;
}
frac add(frac x,frac y){
  frac ans;
  ans.num = x.num*y.den + y.num*x.den;
  ans.den = x.den*y.den;
  ans = reduce(ans);
  return ans;
}
frac sub(frac x,frac y){
  y.num *= -1;
  return add(x,y);
}
int equals(frac x,frac y){
  if(x.num==0 && y.num==0) return 1;
  return (x.num==y.num)&&(x.den==y.den);
}
int iszero(frac x){
  return x.num==0;
}
frac int2frac(int n){
  frac ans;
  ans.num=n;
  ans.den=1;
  return ans;
}
frac zero(){
  return int2frac(0);
}
frac one(){
  return int2frac(1);
}
void set(frac* p,frac x){
  p->num = x.num;
  p->den = x.den;
}
frac inverse(frac x){
  frac ans;
  ans.num = x.den;
  ans.den = x.num;
  ans = reduce(ans);
  return ans;
}
void print_frac(FILE* f,frac x){
  if (x.num == 0) {
    fprintf(f,"%d",0);
    return;
  }
  if (x.den == 1) {
    fprintf(f,"%d",x.num);
    return;
  }
  //printf(" ");
  if(x.num<0){fprintf(f,"-");}
  fprintf(f,"\\cfrac{%d}",abs(x.num));
  fprintf(f,"{%d}",x.den);
}
void print_coeff_int(FILE *f,int n){
  if(n==1) fprintf(f,"");
  else if(n==-1) fprintf(f,"-");
  else fprintf(f,"%d",n);
}
void print_coeff_frac(FILE *f,frac n){
  if(n.den==1) print_coeff_int(f,n.num);
  else{
    n.num<0 ? fprintf(f,"-"):fprintf(f,"");
    fprintf(f,"\\cfrac{%d}{%d}",abs(n.num),n.den);
  }
}
