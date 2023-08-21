#include <bits/stdc++.h>
#include <sys/time.h>
//solvedac2022

using namespace std;

int N;

int main(void) {
    scanf("%d", &N);
    if (N == 0){
        printf("%d", N);
        return 0;
    }
    // difLi = new int[N];
    // dateInfoLi = new dateInfo[N];
    tm tarr[1000] = {};
    int varr[1000] = {};
    long double denom;
    long double numer;
    for(int i = 0, y, mo, d, h, mi, s; i<N; i++) {
        scanf("%4d/%2d/%2d %2d:%2d:%2d %d", &y, &mo, &d, &h, &mi, &s, &varr[i]);
        tarr[i] = (tm) {.tm_sec = s, .tm_min = mi, .tm_hour = h, .tm_mday = d, .tm_mon = mo-1, .tm_year = y - 1900};
        // if (i == N-2){
        //     scanf("%4d/%2d/%2d %2d:%2d:%2d %d", &y, &mo, &d, &h, &mi, &s, &varr[N-1]);
        //     tarr[N-1] = (tm) {.tm_sec = s, .tm_min = mi, .tm_hour = h, .tm_mday = d, .tm_mon = mo, .tm_year = y - 1900};
        // }
    }
    for (int i=0; i<N; i++){
        long long tmp2 = mktime(&tarr[N-1]) - mktime(&tarr[i]);
        //printf("%lld\n", tmp2);
        long double tmp3 = tmp2/(365.0*86400.0);
        //printf("tmp3: %Lf\n", tmp3);
        long double tmp = powl(0.5, tmp3);
        //printf("%Lf\n", tmp);
        // denom += max(double(tmp), double(powl(0.9, N-1-i)));
        denom += max(tmp, powl(0.9, N-1-i));
        //numer += (max(double(tmp), double(powl(0.9, N-1-i))) * varr[i]);
        numer += (max(tmp, powl(0.9, N-1-i)) * varr[i]);
        //printf("%Lf\n", numer);
    }
    //printf("%lld\n", mktime(&tarr[1]) - mktime(&tarr[0]));
    //printf("%Lf", numer/denom);
    int ans = numer/denom + 0.5;
    // int ans2 = round(numer/denom);
    printf("%d", ans);
    return 0;
    //printf("%d",dateInfoLi[0].hour);
}