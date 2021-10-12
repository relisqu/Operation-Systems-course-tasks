#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MB (1000 * 1000)

int main(int argc, char const* argv[]) {
  size_t i = 0;
  for (i = 0; i < 10; ++i) {
    void* mem = malloc(MB*10);
    memset(mem, 0, MB*10);
    sleep(1);
  }
  return 0;
}

/*
 * vmstat output:
[1] 304234
procs -----------memory---------- ---swap-- -----io---- -system-- ------cpu-----
r  b   swpd   free   buff  cache   si   so    bi    bo   in   cs us sy id wa st
0  0      0 9658096 169912 3469104    0    0   101    91  946 2207 25  8 67  0  0
0  0      0 9626716 169920 3469096    0    0     0   192 2005 2297  4  1 95  0  0
0  0      0 9624704 169968 3460868    0    0     0   368  563 1422  1  1 98  0  0
1  0      0 9615380 169992 3460356    0    0     0   212  515 1424  1  0 99  0  0
0  0      0 9604796 169992 3460356    0    0     0     0  536 1493  1  1 99  0  0
0  0      0 9594716 169992 3460356    0    0     0   132  530 1406  1  1 98  0  0
0  0      0 9603284 169992 3460356    0    0     0    44 1168 2134  5  1 94  0  0
0  0      0 9593204 169992 3460356    0    0     0     0  441 1196  1  1 99  0  0
[1]  + 304234 done       ./ex2
 ---
Nothing was swapped or loaded from the swap (si = so = 0).
The amount of free memory decreases as (./ex2) allocates it, so amount of used memory almost constantly increases
Ex2 takes more memory with each second, so it becomes higher in `top -d1` command (the values of RES and %MEM also increase)
 */
