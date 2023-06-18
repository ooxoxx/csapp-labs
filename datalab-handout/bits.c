/*
 * CS:APP Data Lab
 *
 * author: leolhr
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
// 1
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) { return ~(~(~x & y) & ~(x & ~y)); }
/*
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) { return 1 << 31; }
// 2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) { return (!(~(x + 1) ^ x)) & (!!(x + 1)); }
/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int oddBits = 0xAA + (0xAA << 8) + (0xAA << 16) + (0xAA << 24);
  return !((x & oddBits) ^ oddBits);
}
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) { return ~x + 1; }
// 3
/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0'
 * to '9') Example: isAsciiDigit(0x35) = 1. isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  return !((x + ~0x30 + 1) >> 31) & !((0x39 + ~x + 1) >> 31);
}
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  int cond = 1 + ~!x; // 0 || 0xFFFFFFFF
  return (cond & z) + (~cond & y);
}
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  // if x and y have different signs, and convert bool 0/1 to int 0/-1
  int cond = ~!((x ^ y) >> 31) + 1;
  // right shifts are arithmatic with two's complement
  int isNeg = !!(x >> 31);
  int normal = !((y + ~x + 1) >> 31);
  return (~cond & isNeg) + (cond & normal);
}
// 4
/*
 * logicalNeg - implement the ! operator, using all of
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int logicalNeg(int x) {
  int neg = 1 + ~x; // 0 ^ neg(0) == 0 TODO
  // x ^ neg(x)
  int cond1 = ((x ^ neg) >> 31) + 1;
  int cond2 = (neg >> 31) + 1; // edge case x=0x80000000
  return cond1 & cond2;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  // 1 bit:   -1   0
  // 2 bits:  -2   1
  // 3 bits:  -4   3
  // 4 bits:  -8   7
  // the range is symetric. only consider the positive half.
  // question: for a positive number, the position of highest bit plus 1(sign
  // bit).
  // 16: 0x7fff       : 24 : 8 +16
  // 24: 0x01111111   : 28 : 4 +8
  // 28: 0x0111       : 30 : 2 +4
  // 30: 0x01         : 31 : 1 +2
  // 31: 0x0          : 33 : 0 +1
  int isNeg = x >> 31;
  int t = (isNeg & ~x) + (~isNeg & x);
  int res = 1;
  int lower;
  int nextMove;
  int move = 16;
  lower = ~!(t >> move) + 1;
  res += ~lower & 16;
  nextMove = 8;
  move = (~lower & (move + nextMove)) + (lower & (move + ~nextMove + 1));

  lower = ~!(t >> move) + 1;
  res += ~lower & 8;
  nextMove = 4;
  move = (~lower & (move + nextMove)) + (lower & (move + ~nextMove + 1));

  lower = ~!(t >> move) + 1;
  res += ~lower & 4;
  nextMove = 2;
  move = (~lower & (move + nextMove)) + (lower & (move + ~nextMove + 1));

  lower = ~!(t >> move) + 1;
  res += ~lower & 2;
  nextMove = 1;
  move = (~lower & (move + nextMove)) + (lower & (move + ~nextMove + 1));

  lower = ~!(t >> move) + 1;
  res += ~lower & 1;

  lower = ~!t + 1;
  res += ~lower & 1;
  return res;
}

// float
/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  unsigned exp, sign, frac;
  exp = (uf >> 23) & 0xff;
  if (exp == 0xff) {
    return uf;
  }

  sign = uf & 0x80000000;
  // denormalized
  if (exp == 0) {
    // '&' and '+' ORDER matters!!
    return ((uf << 1) & 0x7fffffff) + sign;
  }

  // normalized
  frac = uf & 0x7fffff;
  exp = exp + 1;
  exp = exp & 0xff;
  return sign + (exp << 23) + frac;
}
/*
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  unsigned exp, sign, frac, move, res;
  exp = (uf >> 23) & 0xff;
  if (exp < 0x7f) {
    return 0;
  }
  if (exp > 158) {
    return 0x80000000;
  }

  // the result is determined by some key fracs and corresponding exps.
  // each time raise over these fracs, plus one.
  // exp           E             frac
  // 01111111b     1             1.0 = 0x000000
  // 10000000b     2             1.5 = 0x400000
  // 10000000b     4             1.25 = 0x200000, 1.75 = 0x600000
  // 10000010b     8             1.125 = 0x100000, 1.375 = 0x300000,
  //                             1.625 = 0x500000, 1.875 = 0x700000

  sign = (uf >> 31) & 1;
  frac = uf & 0x7fffff;
  move = exp - 127;
  res = (frac >> (23 - move)) & ((1 << (move + 1)) - 1);
  res += 1;

  if (sign) {
    return ~res + 1;
  }
  // printf("move: %d\n", move);
  // printf("res: %d\n", res);

  return res;
}
/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatPower2(int x) {
  // printf("floatPower2\n");
  if (x < -127) {
    return 0;
  }
  if (x > 128) {
    return 0x7f800000;
  }

  return (x + 127) << 23;
}
