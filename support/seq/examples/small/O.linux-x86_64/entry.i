# 1 "../entry.st"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "../entry.st"







program entryTest

option +s;

%%#include "epicsThread.h"

float v;

ss ss1
{
    state low
    {
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
        entry { printf("\nentered high\n"); }
        when(v<=5.0)
        {
            printf("changing to low\n");
        } state low
        when(delay(1.0))
        {
            printf("high, delay timeout, resetting v\n");
            v = 0;
        } state high
    }
}
