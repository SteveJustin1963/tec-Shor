Here's the clean MINT code implementation of Shor's algorithm without comments:

```mint
:M
x ! a ! n !
n 1 < (`Invalid modulus`)
a 0 < (`Invalid base`)
1 r !
/U (
    x 0 = /W
    x 2 % 1 = (
        r a * n % r !
    )
    x 2 / x !
    a a * n % a !
)
r .
;

:G
b ! a !
a 0 < (0 a - a !)
b 0 < (0 b - b !)
b 0 = (
    a . /W
)
/U (
    b 0 = /W
    b a b % b !
    a b !
)
a .
;

:P
a ! n !
n 1 < (`Invalid modulus`)
a n >= (`Base too large`)
1 x !
n 1 + max !
/U (
    x max >= (`Period not found`)
    1 a x M = (
        x . /W
    )
    x 1 + x !
)
;

:S
n !
n 2 < (`N must be >= 2`)
n 2 % 0 = (2 . /W)
/U (
    n 3 % 0 = (3 . /W)
    /R n % 2 + a !
    a n G 1 != /L
    a n P r !
    r 2 % 0 != /L
    r 2 / p !
    a p M 1 - f !
    f n G g !
    g 1 = g n = | /L
    g .
    /W
)
;
```

The code consists of 4 modules:
1. M - Modular exponentiation
2. G - Greatest Common Divisor (GCD)
3. P - Period finding 
4. S - Main Shor's algorithm implementation

Each module can be called independently. For example, to factor a number N you would call:

```mint
15 S
```

This would attempt to find factors of 15 using Shor's algorithm.
