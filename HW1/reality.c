#include <stdio.h>
#include <stdlib.h>

void reality_1_example_1();
void reality_1_example_2();
void reality_3();
double fun();

typedef struct {
  int a[2];
  double d;
} struct_t;

int main(int argc,char **argv) {
  int n;			/* used to loop for reality_3() */

  reality_1_example_1();
  reality_1_example_2();

  if (argc==1) n = 5;		/* default 5 iter */
  else n = atoi(argv[1]);
  reality_3(n);

  return 0;
}

void reality_1_example_1(){
  float f=50000, total_f;
  int i=40000, total_i;

  /* fill here */
  total_f = f * f;
  printf("reality_1_example_1_float: f=%f\n", f);
  if(total_f >= 0) {
    printf("f*f=%f >= 0\n\n", total_f);
  } else { printf("f*f=%f < 0\n\n", f*f);}

  total_i = i * i;
  printf("reality_1_example_1_int: f=%d\n", i);
  if(total_i >= 0) {
    printf("i*i=%d >= 0\n\n", total_i);
  } else { printf("i*i=%d < 0\n\n", i*i); }

  i=50000;

  /* fill here */
  total_i = i * i;
  printf("reality_1_example_1_int: f=%d\n", i);
  if(total_i >= 0) {
    printf("i*i=%d >= 0\n\n", total_i);
  } else { printf("i*i=%d < 0\n\n", i*i); }
}

void reality_1_example_2(){
  float fx=1e20,fy=-1e20,fz=3.14;
  unsigned int uix=12,uiy=34,uiz=56;
  int six=12,siy=34,siz=56;

  /* fill here */
  printf("reality_1_example_2_unsigned: uix=%d uiy=%d uiz=%d\n", uix, uiy, uiz);
  unsigned int sum1_u = (uix+uiy)+uiz, sum2_u = uix+(uiy+uiz);
  if(sum1_u == sum2_u) {
    printf("((uix+uiy)+uiz)=%d == (uix+(uiy+uiz))=%d\n\n", sum1_u, sum2_u);
  } else { printf("((uix+uiy)+uiz)=%d != (uix+(uiy+uiz))=%d\n\n", sum1_u, sum2_u); }

  printf("reality_1_example_2_signed: six=%d siy=%d siz=%d\n", six, siy, siz);
  int sum1_i = (six+siy)+siz, sum2_i = six+(siy+siz);
  if(sum1_i == sum2_i) { 
    printf("((six+siy)+siz)=%d == (six+(siy+siz))=%d\n\n", sum1_i, sum2_i);
  } else { printf("((six+siy)+siz)=%d != (six+(siy+siz))=%d\n\n", sum1_i, sum2_i); }

  printf("reality_1_example_2_float: fx=%1.6e fy=%1.6e fz=%1.6f\n", fx, fy, fz);
  float sum1_f = (fx+fy)+fz, sum2_f = fx + (fy+fz);
  if(sum1_f == sum2_f) { 
    printf("((fx+fy)+fz)=%1.6e == (fx+(fy+fz))=%1.6e\n\n", sum1_f, sum2_f);
  } else { printf("((fx+fy)+fz)=%1.6e != (fx+(fy+fz))=%1.6e\n\n", sum1_f, sum2_f); }

}

void reality_3(int n) {
  double d;
  int i;

  /* fill here */
  printf("reality_3: n=%d iterations\n", n);
  for(i = 0; i < n; i++) d = fun(i);

}

double fun(int i){
  volatile struct_t s;

  s.d = 3.14;
  s.a[i] = 1073741824;
  printf("fun(%d) -> %f\n",i,s.d);  

  return s.d;
}

/* End of file */