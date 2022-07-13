#include <stdio.h>
#include <math.h>
#include <time.h>

double p(unsigned long long int N, int i) {
   
}

int main() {
   int N;
   tm tarr[1000] = {};
   int varr[1000] = {};
   scanf("%d", &N);
   for(int i = 0, y, mo, d, h, mi, s; i != N; i++) {
      scanf("%4d/%2d/%2d %2d:%2d:%2d %d", &y, &mo, &d, &h, &mi, &s, varr + (i << 2));
      tarr[i] = (tm) {.tm_sec = s, .tm_min = mi, .tm_hour = h, .tm_mday = d, .tm_mon = mo, .tm_year = y - 1900};
   }
   printf("%lld\n", mktime(&tarr[1]) - mktime(&tarr[0]));
   printf("%d", varr[1]);
   return 0;
}