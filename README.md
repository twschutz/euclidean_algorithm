# Euclidean Algorithm Calculator
## What is the Euclidean Algorithm
The Euclidean Algorithm is used to quickly compute the greatest common divisor of two integers.\
For the purpose of simplicity, I have made this program work only with non-negative integers.\
The Euclidean Algorithm finishes when it finds a number that both integers are divisible by\
with a remainder of zero.
### The Euclidean Algorithm in Action
Find the greatest common divisor (gcd) of 351 and 135
  1. gcd(351, 135) = 351 - 2 * 135 + 81
  2. gcd(135, 81) = 135 - 1 * 81 + 54
  3. gcd(81, 54) = 81 - 1 * 54 + 27
  4. gcd(54, 27) = 54 - 2 * 27 + 0\
Since the remainder in step 4 is zero, the greatest common divisor of 351 and 135 is 27!
## Implementing the Euclidean Algorithm
According to an article from the [Massachusetts Institute of Technology](http://web.mit.edu/6.857/OldStuff/Fall02/handouts/L07-generators.pdf)
the Euclidean Algorithm is implemented as below:\
Assuming `a >= 0` and `b >= 0`
```
if b = 0
   gcd(a,b) = a
else
   gcd(a,b) = gcd(b, a % b)
```
The Euclidean Algorithm in this program was implemented recursively such that when the remainder `a % b`\
is zero, the base case is fulfilled and the program ends. The Euclidean Algorithm will never run indefinitey\
because `a % b < b` is always true.


