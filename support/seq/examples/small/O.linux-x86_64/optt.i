# 1 "../optt.st"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "../optt.st"




program opttTest



%%#include "epicsThread.h"

float v;



ss ss1
{
 state low
 {
       option -t;
     entry
     {
  printf("Print something on entry to low\n");
  printf("Also pause on entry to low\n");
  epicsThreadSleep(1.0);
     }
     when(v>5.0)
     {
  printf("low, v = %g, now changing to high\n",v);
     } state high
     when(delay(2.0))
     {
  printf("low, delay timeout, incr v and now reenter low\n");
  v = v+1.0;
  printf("v = %g\n",v);
     } state low
     exit
     {
  printf("low, print this on exit of low\n");
     }

 }

 state high
 {
     entry { printf("\nEntered high\n"); }
     when(v==0)
     {
  printf("changing to low\n");
     } state low
     when(delay(3.0))
     {
  printf("high, delay 3.0 timeout, decr v and re-enter high\n");
  v = v-1.0;
  printf("v = %g\n",v);
     } state high
 }
}
