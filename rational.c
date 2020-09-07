/*
 * File: rational.c
 * -------------------
 *  This file implements the rational.h interface.
 *  Author: Zhang XinLei-2019051604096
 */


#include <stdio.h>
#include "rational.h"
#include "simpio.h"
#include "genlib.h"
#include "strlib.h"
int GCD(int x, int y)
{
    int r;
    while (TRUE)
    {
        r = x % y;
        if (r == 0) break;
        x = y;
        y = r;
    }
    return (y);
}
rationalT CreateRational(int num_, int den_)
{
    rationalT f;
    int gcd;
    gcd = GCD(num_, den_);
    f.num = num_ / gcd;
    f.den = den_ / gcd;
    return (f);
}
rationalT AddRational(rationalT r1, rationalT r2)
{
    int fn, fd;
    fn = r1.num * r2.den + r2.num * r1.den;
    fd = r1.den * r2.den;
    return (CreateRational(fn, fd));
}
rationalT MultiplyRational(rationalT r1, rationalT r2)
{
    int fn, fd;
    fn = r1.num * r2.num;
    fd = r1.den * r2.den;
    return (CreateRational(fn, fd));
}
rationalT GetRational(rationalT r)
{
    string str;
    str = GetLine();
    if (str[0]!= '0') {
    	r.num = StringToInteger(CharToString(str[0]));
    	r.den = StringToInteger(CharToString(str[2]));
    }	
    if (str[0] == '0') {
        r.num = r.den = 0;
    }
    return (r);
    
}
void PrintfRational(rationalT r)
{
    printf("%d/%d", r.num, r.den);
}
