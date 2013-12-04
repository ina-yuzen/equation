#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "equation2.c"
int q_num;

void print_header(){
  puts("\\documentclass{jsarticle}");
  puts("\\usepackage{amsmath}");
  puts("\\usepackage{multicol}");
  puts("\\usepackage[flushleft]{paralist}");
  puts("\\begin{document}");
  puts("\\pagestyle{plain}");
  puts("");
  puts("以下の方程式を解け。");
  puts("\\begin{multicols}{2}");
  puts("\\begin{enumerate}[(1)]");
  puts("\\setlength{\\parskip}{0cm} % 段落間");
  puts("\\setlength{\\itemsep}{3cm} % 項目間");
}
void print_footer(){
  puts("\\end{enumerate}");
  puts("\\end{multicols}");
  puts("\\end{document}");
}
void ans_header(){
  fprintf(stderr,"\\documentclass{jsarticle}\n");
  fprintf(stderr,"\\usepackage{amsmath}\n");
  fprintf(stderr,"\\usepackage{multicol}\n");
  fprintf(stderr,"\\usepackage[flushleft]{paralist}\n\n");
  fprintf(stderr,"\\begin{document}\n");
  fprintf(stderr,"\\pagestyle{plain}\n");
  fprintf(stderr,"\n");
  fprintf(stderr,"解答\n");
  fprintf(stderr,"\\begin{multicols}{3}\n");
  fprintf(stderr,"\\begin{enumerate}[(1)]");
  fprintf(stderr,"\\setlength{\\parskip}{0cm} \n");
  fprintf(stderr,"\\setlength{\\itemsep}{0cm} \n");
}
void ans_footer(){
  fprintf(stderr,"\\end{enumerate}\n");
  fprintf(stderr,"\\end{multicols}\n");
  fprintf(stderr,"\\end{document}\n");
}

void print_header2(){
  puts("\\documentclass{jsarticle}");
  puts("\\usepackage{amsmath}");
  puts("\\usepackage{multicol}");
  puts("\\usepackage[flushleft]{paralist}");
  puts("\\usepackage{geometry}");
  puts("\\geometry{left=25mm,right=25mm,top=25mm,bottom=20mm}");
  puts("\\begin{document}");
  puts("\\pagestyle{plain}");
  puts("");
  puts("\\section*{以下の方程式を解け。}");
  puts("\\begin{multicols}{2}");
  puts("\\begin{enumerate}[(1)]");
  puts("\\setlength{\\parskip}{0cm} % 段落間");
  puts("\\setlength{\\itemsep}{7cm} % 項目間");
}
void print_footer2(){
  puts("\\end{enumerate}");
  puts("\\end{multicols}");
  puts("\\end{document}");
}
void ans_header2(){
  fprintf(stderr,"\\documentclass{jsarticle}\n");
  fprintf(stderr,"\\usepackage{amsmath}\n");
  fprintf(stderr,"\\usepackage{multicol}\n");
  fprintf(stderr,"\\usepackage[flushleft]{paralist}\n\n");
  fprintf(stderr,"\\begin{document}\n");
  fprintf(stderr,"\\pagestyle{plain}\n");
  fprintf(stderr,"\n");
  fprintf(stderr,"\\section*{解答}\n");
  fprintf(stderr,"\\begin{multicols}{3}\n");
  fprintf(stderr,"\\begin{enumerate}[(1)]");
  fprintf(stderr,"\\setlength{\\parskip}{0cm} \n");
  fprintf(stderr,"\\setlength{\\itemsep}{0.5cm} \n");
}
void ans_footer2(){
  fprintf(stderr,"\\end{enumerate}\n");
  fprintf(stderr,"\\end{multicols}\n");
  fprintf(stderr,"\\end{document}\n");
}


void print_equa(FILE *f,int* p){
  void g(i){
    if(p[i]!=0){
      print_coeff_int(f,p[i]);
      fprintf(f,"x");
      if(p[i+1]>0)fprintf(f,"+");
    }
    if(p[i+1]!=0)fprintf(f,"%d",p[i+1]);
    if(p[i]==0&&p[i+1]==0)fprintf(f,"0");
  }
  void g2(i){
    if(p[i+1]!=0){
      fprintf(f,"%d",p[i+1]);
      if(p[i]>0)fprintf(f,"+");
    }
    if(p[i]!=0){
      print_coeff_int(f,p[i]);
      fprintf(f,"x");
    }
    if(p[i]==0&&p[i+1]==0)fprintf(f,"0");
  }
  int a=rand()%2;
  if(p[0]==1&&p[1]==0&&p[2]==0) a=0;
  rand()%2==0 ? g(a*2) : g2(a*2);
  fprintf(f,"=");
  rand()%2==0 ? g((1-a)*2) : g2((1-a)*2);
}
int* equa(int* p){
  int x,a,b,c;
  do{
    x = rand() % 20 - 10;
    a = rand() % 20 - 10;
    b = rand() % 20 - 10;
    c = rand() % 20 - 10;
  }while (a*x == 0||(a==1&&b==0&&c==0));

    p[0]=a+b;
  p[1]=c;
  p[2]=b;
  p[3]=x*a+c;
  q_num++;
  int ans[4]={1,0,0,x};
  fprintf(stderr,"\\item $");
  print_equa(stderr,ans);
  fprintf(stderr,"$\n");
  printf("\\item $");
  print_equa(stdout,p);
  puts("$");
  return p;
}
void print_dequa(FILE *f,int *p){
  void g(i){
    if(p[3*i]!=0){
      print_coeff_int(f,p[3*i]);
      fprintf(f,"x");
      if(p[3*i+1]>0) fprintf(f,"+");
    }
    if(p[3*i+1]!=0){
      print_coeff_int(f,p[3*i+1]);
      fprintf(f,"y");
    }
    fprintf(f,"=");
    fprintf(f,"%d",p[3*i+2]);
  }
  fprintf(f,"\\item $");
  fprintf(f,"\\left\\{\\begin{array}{l}");
  g(0);
  fprintf(f,"\\\\");
  g(1);
  fprintf(f,"\\end{array}\\right.$ \n");
}
void dequa(){
  int p[6];
  int x,y,a,b,i;
  do{
    x=rand() % 15 - 7;
    y=rand() % 15 - 7;
  }while(x==0&&y==0);
  do{
    a=rand() % 13 - 6;
    b=rand() % 13 - 6;
  }while(a==0||b==0);
  p[0]=a;
  p[1]=b;
  p[2]=a*x+b*y;
  do{
    a=rand() % 13 - 6;
    b=rand() % 13 - 6;
    p[3]=a;
    p[4]=b;
    p[5]=a*x+b*y;
  }while((a==0)||(b==0)||(a*p[1]==b*p[0]));

  print_dequa(stdout,p);

  p[0]=1;p[1]=0;p[2]=x;
  p[3]=0;p[4]=1;p[5]=y;

  fprintf(stderr,"\\item $x=%d,y=%d$\n",x,y);
}
void print_dfracequa(FILE* f,frac* p){
  void g(int i){
    if(p[i].den!=p[i+1].den || (iszero(p[i])||iszero(p[i+1])) || p[i].den==1){
      if(!iszero(p[i])){
	print_coeff_frac(f,p[i]);
	fprintf(f,"x");
	if(p[i+1].num>0)fprintf(f,"+");
      }
      if(!iszero(p[i+1])){
	print_coeff_frac(f,p[i+1]);
	fprintf(f,"y");
      }
      if(iszero(p[i])&&iszero(p[i+1]))fprintf(f,"0");
      fprintf(f,"=");
      print_frac(f,p[i+2]);
    }else{
      fprintf(f,"\\cfrac{");
      print_coeff_int(f,p[i].num);
      fprintf(f,"x");
      if(p[i+1].num>0)fprintf(f,"+");
      print_coeff_int(f,p[i+1].num);
      fprintf(f,"y");
      fprintf(f,"}{%d}",p[i].den);
      fprintf(f,"=");
      print_frac(f,p[i+2]);
    }
  }
  fprintf(f,"\\item $\\left\\{\\begin{array}{l}");
  g(0);
  fprintf(f,"\\\\");
  g(3);
  fprintf(f,"\\end{array}\\right.$ \n");
}
void dfracequa(){
  frac p[6];
  frac x,y,a,b,c,d;
  int i;
  do{
    x.num=rand()%21 - 10;
    x.den=rand()%11 + 1;
    y.num=rand()%21 - 10;
    y.den=rand()%(12-x.den) + 1;
  }while(iszero(x)&&iszero(y));
  x=reduce(x);
  y=reduce(y);
  do{
    a.num=rand()%11 - 5;
    a.den=rand()%5 + 1;
    c.num=rand()%11 - 5;
    c.den=rand()%5 + 1;
    a=reduce(a);
    c=reduce(c);
  }while(equals(a,c) || iszero(a) || iszero(c));
  b.num=a.den;
  b.den=1;
  d.num=c.den;
  d.den=1;
  b=reduce(b);
  d=reduce(d);
  
  set(&p[0],mul(a,b));
  set(&p[1],sub(zero(),b));
  set(&p[2],mul(b,sub(mul(a,x),y)));
  if(p[2].den>12){
    set(&p[0],mul(p[0],int2frac(p[2].den)));
    set(&p[1],mul(p[1],int2frac(p[2].den)));
    set(&p[2],int2frac(p[2].num));
  }
  set(&p[3],mul(c,d));
  set(&p[4],sub(zero(),d));
  set(&p[5],mul(d,sub(mul(c,x),y)));
  if(p[5].den>12){
    set(&p[3],mul(p[3],int2frac(p[5].den)));
    set(&p[4],mul(p[4],int2frac(p[5].den)));
    set(&p[5],int2frac(p[5].num));
  }

  print_dfracequa(stdout,p);

  /*set(&p[0],one());set(&p[1],zero());set(&p[2],x);
  set(&p[3],zero());set(&p[4],one());set(&p[5],y);
  print_dfracequa(stderr,p);*/
  fprintf(stderr,"\\item $x=");
  print_frac(stderr,x);
  fprintf(stderr,",y=");
  print_frac(stderr,y);
  fprintf(stderr,"$\n");
}
void print_fracequa(FILE *f,frac *q){
  void g(int i){
    if(rand()%2==0){
      if(q[i].num!=0){
	print_coeff_frac(f,q[i]);
	fprintf(f,"x");
	if(q[i+1].num>0)fprintf(f,"+");
      }
      if(q[i+1].num!=0)print_frac(f,q[i+1]);
      if(q[i].num==0&&q[i+1].num==0)fprintf(f,"0");
    }
    else {
      if(q[i+1].num!=0){
	print_frac(f,q[i+1]);
	if(q[i].num>0)fprintf(f,"+");
      }
      if(q[i].num!=0){
	print_coeff_frac(f,q[i]);
	fprintf(f,"x");
      }
      if(q[i].num==0&&q[i+1].num==0)fprintf(f,"0");
    }
  }
  void h(int i){
    if(q[i].num*q[i+1].num==0) g(i);
    else{
      int gd = gcd(q[i].den,q[i+1].den);
      int lm = q[i].den*q[i+1].den/gd;
      if(lm==q[i].den||lm==q[i+1].den){
	g(i);
	return;
      }
      fprintf(f,"\\cfrac{");
      if(rand()%2==0){
	print_coeff_int(f,q[i].num*lm/q[i].den);
	fprintf(f,"x");
	if(q[i+1].num>0)fprintf(f,"+");
	fprintf(f,"%d}",q[i+1].num*lm/q[i+1].den);
      }else{
	fprintf(f,"%d",q[i+1].num*lm/q[i+1].den);
	if(q[i].num>0)fprintf(f,"+");
	print_coeff_int(f,q[i].num*lm/q[i].den);
	fprintf(f,"x}");
      }
      fprintf(f,"{%d}",lm);
    }
  }
  int a=rand()%2;
  if(q[0].num==1&&q[0].den==1&&q[1].num==0&&q[2].num==0) a=0;
  rand()%4==0 ? g(a*2):h(a*2);
  fprintf(f," = ");
  rand()%4==0 ? g((1-a)*2) : h((1-a)*2);
}
frac* fracequa(frac* p){
  frac x,a,b,c;
  do{
    x.num = rand() % 20 - 10;
    x.den = rand() % 9 + 1;
    a.num = rand() % 15 - 7;
    a.den = rand() % 7 + 1;
    b.num = rand() % 15 - 7;
    b.den = rand() % 9 + 1;
    c.num = rand() % 15 - 7;
    c.den = rand() % 9 + 1;
  } while(x.num * a.num == 0||(a.num/a.den==1&&b.num==0&&c.num==0));
  x=reduce(x);
  a=reduce(a);
  b=reduce(b);
  c=reduce(c);

  p[0] = add(a,b);
  p[1] = c;
  p[2] = b;
  p[3] = add(mul(x,a),c);

  q_num++;
  frac ans[4];
  ans[0].num=1;
  ans[0].den=1;
  ans[1].num=0;
  ans[1].den=1;
  ans[2].num=0;
  ans[2].den=1;
  ans[3].num=x.num;
  ans[3].den=x.den;

  fprintf(stderr,"\\item $");
  print_fracequa(stderr,ans);
  fprintf(stderr,"$\n");

  //printf("(%d) ",q_num);
  printf("\\item $");
  print_fracequa(stdout,p);
  printf("$\n");
  return p;
}
void makepage(int max){
  print_header();
  ans_header();
  int i,j;
  int p[4];
  frac q[4];
  
  for(j=0;j<max/6;j++){
    for(i=0;i<6;i++){
      if(rand()%3==0)
	fracequa(q);
      else equa(p);
    }
  if(j<max/6-1&&q_num%6==0)printf("\\columnbreak\n");
  }
  if((j=max%6)!=0){
    printf("\\columnbreak\n");
    for(i=0;i<j;i++){
      if(rand()%5==0)
	fracequa(q);
      else equa(p);
    }
  }
  print_footer();
  ans_footer();
}
void makepage2(int max){
  print_header2();
  ans_header2();
  int i,j;
  for(j=0;j<max/3;j++){
    for(i=0;i<3;i++){
      if(rand()%6 == 0)dfracequa();
      else dequa();
    }
    if(j<max/3-1&&q_num%3==0)printf("\\columnbreak\n");
  }
  if((j=max%3)!=0){
    printf("\\columnbreak\n");
    for(i=0;i<j;i++){
      if(rand()%6 == 0)dfracequa();
      else dequa();
    }
  }
  print_footer2();
  ans_footer2();
}

int main(int argc,char* args[]){
  srand((unsigned) time(NULL));
  q_num=0;
  int q_max;
  if(argc<2)q_max=60;
  else q_max=atoi(args[1]);
  if(argc<3);
  else if(*args[2] == 'd') {
    int i;
    int p[4];
    for(i=0;i<q_max;i++)
      equa(p);
    return 0;
  }
  else if(*args[2] == 'f') {
    int i;
    frac p[4];
    for(i=0;i<q_max;i++)
      fracequa(p);
    return 0;
  }
  else if(*args[2] == 'w') {
    int i;
    for(i=0;i<q_max;i++)
      dequa();
    return 0;
  }
  else if(*args[2] == 'z') {
    int i;
    for(i=0;i<q_max;i++)
      dfracequa();
    return 0;
  }
  else;
  //dequa();
  makepage2(q_max);
  return 0;
}
