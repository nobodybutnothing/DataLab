/*
 * CS:APP Data Lab
 *
 * <Please put your name and userid here>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.
  4. Interprets integer expressions using the Data Lab 32-bit bit-vector
     model: results outside the signed range retain their low 32 bits.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */

#endif
#include "bits.h"

// P1
/*
 * signMask - return a mask with only the most significant bit set (0x80000000)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int signMask(void)
{
  return 0x80000000;
}

// P2
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1, bitXor(7, 7) = 0
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 2
 */
int bitXor(int x, int y)
{
  return ~((~(~x & y)) & (~(~y & x)));
}

// P3
/*
 * negativePart - return -x if x < 0, otherwise return 0
 *   Examples: negativePart(-10) = 10, negativePart(5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int negativePart(int x)
{
  return (x >> 31) & (~x + 1);
}

// P4
/*
 * copyByteWithin - copy byte src of x to byte dst, leaving all other bytes unchanged
 *   Bytes are numbered from 0 (least significant) to 3 (most significant).
 *   You can assume 0 <= src <= 3 and 0 <= dst <= 3.
 *   Example: copyByteWithin(0x11223344, 0, 2) = 0x11443344
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int copyByteWithin(int x, int src, int dst)
{
  int b = (x >> (src << 3)) & 0xFF;
  int mask = ~(0xFF << (dst << 3));
  return (x & mask) | (b << (dst << 3));
}

// P5
/*
 * logicalShift - shift x to the right by n bits, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int logicalShift(int x, int n)
{
  int mask = ~(((1 << 31) >> n) << 1);
  return (x >> n) & mask;
}

// P6
/*
 * swapNibblePairs - swap the low and high 4 bits within each byte of x
 *   Examples: swapNibblePairs(0xAB) = 0xBA
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 18
 *   Rating: 4
 */
int swapNibblePairs(int x)
{
  return ((x & 0x0F0F0F0F) << 4) | ((x >> 4) & 0x0F0F0F0F);
}

// P7
/*
 * secondLowestZeroBit - return a mask that marks the position of the second least significant 0 bit
 *   Examples: secondLowestZeroBit(0xFFFFFFFA) = 0x4, secondLowestZeroBit(0x7FFFFFFF) = 0
 *             secondLowestZeroBit(-1) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 4
 */
int secondLowestZeroBit(int x)
{
  int lowest = ~x & (x + 1);
  int y = x | lowest;
  return ~y & (y + 1);
}

// P8
/*
 * oddParity - return the odd parity bit of x, that is,
 *      when the number of 1s in the binary representation of x is even, then the return 1, otherwise return 0.
 *   Examples: oddParity(5) = 1, oddParity(7) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 56
 *   Rating: 5
 */
int oddParity(int x)
{
  x ^= x >> 16;
  x ^= x >> 8;
  x ^= x >> 4;
  x ^= x >> 2;
  x ^= x >> 1;
  return ~(x & 1);
}

// P9
/*
 * rotateRightBits - rotate x to right by n bits
 *   you can assume n >= 0
 *   Examples: rotateRightBits(0x12345678, 8) = 0x78123456
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 5
 */
int rotateRightBits(int x, int n)
{
  int m = n & 31;
  int r = (x >> m) & ~(((1 << 31) >> n) << 1);
  int l = x << ((32 + ~m + 1) & 31);
  return l | r;
}

// P10
/*
 * roundEvenPow2 - round nonnegative x to the nearest multiple of 2^n.
 *   If x is exactly halfway between two multiples, choose the multiple whose
 *   quotient by 2^n is even.
 *   You can assume 0 <= x <= 0x3fffffff and 1 <= n <= 16.
 *   Examples: roundEvenPow2(10, 2) = 8, roundEvenPow2(14, 2) = 16
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 5
 */
int roundEvenPow2(int x, int n)
{
  int m = 1 << n;
  int half = m >> 1;
  int a = x >> n;
  int bias = half + ~0 + (a & 1);
  return ((x + bias) >> n) << n;
}

// P11
/*
 * midpointTowardFirst - return the exact mathematical midpoint (x+y)/2
 *   without overflow. If the exact midpoint lies halfway between two
 *   integers, choose the adjacent integer that is closer to the first
 *   argument x.
 *   Examples: midpointTowardFirst(4, 7) = 5,
 *             midpointTowardFirst(7, 4) = 6
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 32
 *   Rating: 5
 */
int midpointTowardFirst(int x, int y)
{
  int floor = (x & y) + ((x ^ y) >> 1);
  int same_si = (x >> 31) ^ (y >> 31);
  int plus_one = (same_si & ((x + ~y + 1) >> 31)) | (~same_si & ~(x >> 31));
  int res = ((x ^ y) & 1) & plus_one + floor;
  return res;
}

// P12
/*
 * isBetweenEitherOrder - return 1 when x lies in the inclusive interval whose
 *   endpoints are a and b. The endpoints may be given in either order.
 *   Example: isBetweenEitherOrder(5, 8, 3) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 48
 *   Rating: 7
 */
int isBetweenEitherOrder(int x, int a, int b)
{
  int big1 = (x + ~a + 1) >> 31;
  int small1 = (b + ~x + 1) >> 31;
  int big2 = (x + ~b + 1) >> 31;
  int small2 = (a + ~x + 1) >> 31;
  return (big1 & small1) | (big2 & small2);
}

// P13
/*
 * mul5Sat - return x*5, and if x*5 overflow, change the result to
 * INT_MAX(0x7fffffff) or INT_MIN(0x80000000) correspondingly
 *   Examples: mul5Sat(1) = 0x5, mul5Sat(0x40000000) = 0x7fffffff
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 7
 */
int mul5Sat(int x)
{
  int a = x << 2;
  int b = a + x;
  int six = x >> 31;
  int sib = b >> 31;
  int over = !!(((a >> 2) ^ x) | (six ^ sib));
  int li = six ^ ~(1 << 31);
  int mask = ~over + 1;
  return (mask & li) | (~mask & b);
}

// P14
/*
 * classifyAdd3 - classify the exact mathematical sum x+y+z.
 *   Return 1 if the sum is greater than INT_MAX, -1 if it is less than
 *   INT_MIN, and 0 otherwise. You may not use a wider integer type.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 52
 *   Rating: 7
 */
int classifyAdd3(int x, int y, int z)
{
  int s1 = x + y;
  int s2 = s1 + z;
  int c1 = (((x & y) | ((x | y) & ~s1)) >> 31) & 1;
  int c2 = (((s1 & z) | ((s1 | z) & ~s2)) >> 31) & 1;
  int high = (x >> 31) + (y >> 31) + (z >> 31) + c1 + c2;
  int neg_low = (s2 >> 31) & 1;
  int high_pos = !(high >> 31) & !!high;
  int high_0 = !high;
  int high_neg1 = !(high + 1);
  int high_smaller = ((high + 1) >> 31) & 1;
  int pos_ov = high_pos | (high_0 & neg_low);
  int neg_ov = high_smaller | (high_neg1 & !neg_low);
  return pos_ov + (~neg_ov + 1);
}

// P15
/*
 * floatScaleThreeHalves - Return bit-level equivalent of expression f*3/2 for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   Use round-to-nearest-even. Preserve the sign of both +0 and -0.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 60
 *   Rating: 7
 */
unsigned floatScaleThreeHalves(unsigned uf)
{
  unsigned sign = uf & (1u << 31);
  unsigned exp = (uf >> 23) & 0xFFu;
  unsigned frac = uf & 0x7FFFFFu;

  if (exp == 0xFFu)
  {
    return uf;
  }
  if (exp == 0u)
  {
    if (frac == 0u)
    {
      return uf;
    }
    unsigned m3 = (frac << 1) + frac;
    unsigned n = m3 >> 1;
    if ((m3 & 1u) && (n & 1u))
      n = n + 1;
    if (n < (1u << 23))
      return sign | n;
    return sign | (1u << 23) | (n & 0x7FFFFFu);
  }

  unsigned m = frac | (1u << 23);
  unsigned m3 = m + (m << 1);
  unsigned n, e;

  if (m3 < (1u << 25))
  {
    n = m3 >> 1;
    if ((m3 & 1u) && (n & 1u))
      n = n + 1;
    e = exp;
    if (n >> 24)
    {
      n = n >> 1;
      e = e + 1;
    }
    else
    {
      n = m3 >> 2;
      if ((m3 >> 1) & 1u && (m3 & 1u || n & 1u))
      {
        n = n + 1;
      }
      e = exp + 1;
    }
  }

  if (e >= 255u)
  {
    return sign | 0x7F800000u;
  }
  return sign | (e << 23) | (n & 0x7FFFFFu);
}

// P16
/*
 * floatRoundEven - round the floating-point value represented by uf to the
 *   nearest integer, with halfway cases rounded to the even integer. Return
 *   the bit-level representation of that integer as a single-precision float.
 *   If rounding produces zero, preserve the input sign; thus a negative
 *   value that rounds to zero returns -0. When uf is NaN or infinity,
 *   return uf unchanged.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 65
 *   Rating: 10
 */
unsigned floatRoundEven(unsigned uf)
{
  unsigned sign = uf & 0x80000000u;
  unsigned exp = (uf >> 23) & 0xFFu;
  unsigned frac = uf & 0x7FFFFFu;

  if (exp == 0xFFu)
    return uf;
  if (exp >= 150u)
    return uf;
  if (exp < 126u)
    return sign;

  unsigned M = frac | 0x800000u;
  unsigned k = 150u - exp;

  unsigned R = (M + ((1u << (k - 1)) - 1u) + ((M >> k) & 1u)) >> k;

  if (R == 0u)
    return sign;
  unsigned t = R, p = 0;
  if (t >> 16)
  {
    t >>= 16;
    p += 16;
  }
  if (t >> 8)
  {
    t >>= 8;
    p += 8;
  }
  if (t >> 4)
  {
    t >>= 4;
    p += 4;
  }
  if (t >> 2)
  {
    t >>= 2;
    p += 2;
  }
  if (t >> 1)
  {
    p += 1;
  }

  unsigned e = 127u + p;
  unsigned m = (R << (23u - p)) & 0x7FFFFFu;
  return sign | (e << 23) | m;
}

// P17
/*
 * float_i2f - Return bit-level equivalent of expression (float) x.
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 40
 *   Rating: 10
 */
unsigned float_i2f(int x)
{
  if (x == 0)
    return 0u;

  unsigned ux = (unsigned)x;
  unsigned sign = ux & 0x80000000u;
  unsigned ax = sign ? (~ux + 1) : ux;

  int p = 0;
  unsigned t = ax;
  while (t >> 1)
  {
    t >>= 1;
    p++;
  }

  if (p <= 23)
  {
    unsigned m = ax << (23 - p);
    return sign | ((unsigned)(127 + p) << 23) | (m & 0x7FFFFFu);
  }

  int shift = p - 23;
  unsigned N = ax >> shift;
  unsigned guard = (ax >> (shift - 1)) & 1u;
  unsigned sticky = (ax & ((1u << (shift - 1)) - 1u)) != 0u;
  if (guard && (sticky || (N & 1u)))
    N++;
  if (N >> 24)
  {
    N >>= 1;
    p++;
  }

  return sign | ((unsigned)(127 + p) << 23) | (N & 0x7FFFFFu);
}

// P18
/*
 * bitCount - return count of number of 1's in the binary representation of x
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 10
 */
int bitCount(int x)
{
  int m1 = (0x55 << 8) | 0x55;
  m1 = (m1 << 16) | m1;
  int m2 = (0x33 << 8) | 0x33;
  m2 = (m2 << 16) | m2;
  int m4 = (0x0F << 8) | 0x0F;
  m4 = (m4 << 16) | m4;

  x = x + ~((x >> 1) & m1) + 1;
  x = (x & m2) + ((x >> 2) & m2);
  x = (x + (x >> 4)) & m4;
  x = x + (x >> 8);
  x = x + (x >> 16);
  return x & 0x3F;
}

// P19
/*
 * bitReverse - Reverse bits in an 32-bit integer
 *   Examples: bitReverse(0x80000004) = 0x20000001
 *             bitReverse(0x7FFFFFFF) = 0xFFFFFFFE
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 34
 *   Rating: 10
 */
int bitReverse(int x)
{
  unsigned u = (unsigned)x;
  u = ((u >> 1) & 0x55555555u) | ((u & 0x55555555u) << 1);
  u = ((u >> 2) & 0x33333333u) | ((u & 0x33333333u) << 2);
  u = ((u >> 4) & 0x0F0F0F0Fu) | ((u & 0x0F0F0F0Fu) << 4);
  u = ((u >> 8) & 0x00FF00FFu) | ((u & 0x00FF00FFu) << 8);
  u = (u >> 16) | (u << 16);
  return (int)u;
}
