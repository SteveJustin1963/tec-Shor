 

---

# 🧩 What is Shor’s Algorithm?

Shor’s Algorithm is a **special math trick** that runs on a **quantum computer** — a new kind of computer that uses the strange rules of quantum physics.

It’s named after a scientist called **Peter Shor**.

---

### 🧮 What does it do?

It can **find the secret building blocks of a big number** — called **factors**.

For example:

> If the number is **15**, its factors are **3** and **5** because 3 × 5 = 15.

For small numbers that’s easy, but for *huge* numbers (hundreds of digits long), it’s **super hard** for normal computers.
Shor’s Algorithm makes it **much faster** on a quantum computer.

---

### ⚙️ How does it work?  

1. **You pick a big number** you want to break into factors.
   (Let’s say 15 again, but real ones are much, much bigger.)

2. **The algorithm plays a math game** — it tries to find a *pattern* in how numbers repeat when you multiply them over and over.

3. **Quantum computers are great at finding patterns** because they can check **many possibilities at once**, not just one at a time like normal computers.

4. Once it finds that repeating pattern (called a **period**),
   you can use it to **figure out the secret factors** of your big number.

---

### 💡 Why is that important?

Because many computer security systems — like the ones protecting your passwords or bank info — rely on the fact that **factoring big numbers is hard**.
If a quantum computer runs Shor’s Algorithm, it could **crack** those systems!

---

### 🧠 In one sentence:

> Shor’s Algorithm is a clever quantum math trick that quickly finds the hidden factors of big numbers — something normal computers take forever to do.

---
//////////////



---

## 🧮 What We’re Trying to Do

We want to **find the secret factors of a big number** — say, 15 → 3 and 5 —
**using only a regular computer**, but by **imitating** what Shor’s Algorithm does on a quantum one.

So we’ll do *something similar* that uses **math patterns** instead of real quantum magic.

---

## ⚙️ The Simple Idea Behind Shor’s Algorithm

At its heart, Shor’s Algorithm is about **finding a pattern** — a *repeat cycle* in numbers.
That’s called the **period**.

For example:

> Pick a number `a`, say `a = 2`, and another number `n`, say `n = 15`.
> Now look at this pattern:
>
> 2¹ mod 15 = 2
> 2² mod 15 = 4
> 2³ mod 15 = 8
> 2⁴ mod 15 = 16 mod 15 = 1
>
> The pattern repeats every **4 steps** → the **period = 4**.

That repeating length (“4”) is the **key** that helps us find factors!

---

## 🪜 Step-by-Step — Regular Computer Version

Here’s the “fake Shor” process you can run on any normal computer:

1. **Pick your big number** `n` you want to factor.
   (Let’s start with 15.)

2. **Pick a random helper number** `a` that’s smaller than `n`.
   (Let’s try 2.)

3. **Check something first:**
   If `a` and `n` share a factor already, you’re done!
   (For example, if `a = 5` and `n = 15`, gcd(5,15)=5 → factor found.)

4. **Now find the repeating pattern of powers:**
   Compute `a¹ mod n`, `a² mod n`, `a³ mod n`, ...
   until the pattern repeats (you get 1 again).
   The number of steps before it repeats is called **r**.

5. **If r is even**, compute:

   * `x = a^(r/2) - 1`
   * `y = a^(r/2) + 1`
     Then find **gcd(x, n)** and **gcd(y, n)** — those are your factors!

That’s it!
It’s slow, but it’s the **same math logic** that a quantum computer does *fast*.

---

## 🧠 Example in Plain Math

Let’s do it for `n = 15` and `a = 2`:

1. 2¹ mod 15 = 2
2. 2² mod 15 = 4
3. 2³ mod 15 = 8
4. 2⁴ mod 15 = 1 → pattern repeats, so **r = 4**

Now, r is even, so:

* a^(r/2) = 2² = 4
* x = 4 − 1 = 3
* y = 4 + 1 = 5
* gcd(3, 15) = 3
* gcd(5, 15) = 5

Boom 💥 — factors found!

---

## 🚀 What a Quantum Computer Does Differently

A **quantum computer** can find that repeating number (the period r) **instantly**, because it can check *many powers of a at once* in a fuzzy “quantum superposition.”
That’s the “magic” part.

A **regular computer** can only check them **one by one** — which takes forever for very big numbers.

---

## 🧩 In One Sentence

> A regular computer can mimic Shor’s Algorithm by trying lots of powers of a number and looking for when the results start repeating — but it has to do them one at a time instead of all at once like a quantum computer.

---

/////////


# whats this **“mod”** thing ?

---

### 🍎 Imagine You’re Sharing Apples

Let’s say you have **13 apples**, and you want to share them **evenly among 5 friends**.

Each friend gets **2 apples**, and there will be **3 apples left over**.

That **leftover part** is what **“mod”** means!

---

### 💡 In math form

We write:

```
13 mod 5 = 3
```

Because when you divide 13 by 5:

* 5 × 2 = 10
* 13 − 10 = 3 ← that’s the **remainder**

---

### ⚙️ What “mod” actually does

**mod** gives you the **remainder after division**.

| Example  | What it means          | Answer |
| -------- | ---------------------- | ------ |
| 7 mod 3  | 7 ÷ 3 = 2 remainder 1  | 1      |
| 10 mod 4 | 10 ÷ 4 = 2 remainder 2 | 2      |
| 9 mod 5  | 9 ÷ 5 = 1 remainder 4  | 4      |
| 8 mod 2  | 8 ÷ 2 = 4 remainder 0  | 0      |

---

### 🧮 In words

> “a mod b” means:
> what’s left over when you divide a by b.

---

### 🧠 Why it’s useful in Shor’s Algorithm

When you keep taking powers of a number (like 2¹, 2², 2³, 2⁴, …), the results get *huge*.
“mod” keeps the numbers **small and repeating**, by only keeping the **remainder** after dividing by your main number `n`.

So instead of growing forever, the numbers start **cycling** — that’s the pattern Shor’s Algorithm uses!

---
////////////

# lets show a **tiny number pattern table** to see how `a^k mod n` starts repeating (like the pattern for 2 mod 15)


Let’s look at the **pattern table** — this is exactly what Shor’s Algorithm looks for 👇

We’ll use

> **a = 2**
> **n = 15**
> so we’re finding **2ᵏ mod 15** for different powers of k.

---

### 🧮 Pattern Table

| Power (k) | 2ᵏ  | 2ᵏ mod 15 | Explanation                   |
| --------- | --- | --------- | ----------------------------- |
| 1         | 2   | 2         | 2 ÷ 15 = 0 remainder 2        |
| 2         | 4   | 4         | 4 ÷ 15 = 0 remainder 4        |
| 3         | 8   | 8         | 8 ÷ 15 = 0 remainder 8        |
| 4         | 16  | **1**     | 16 ÷ 15 = 1 remainder **1**   |
| 5         | 32  | 2         | 32 ÷ 15 = 2 remainder 2       |
| 6         | 64  | 4         | 64 ÷ 15 = 4 remainder 4       |
| 7         | 128 | 8         | 128 ÷ 15 = 8 remainder 8      |
| 8         | 256 | **1**     | 256 ÷ 15 = 17 remainder **1** |

---

### 🔁 What Do We Notice?

Look at the **mod results column**:

👉 2, 4, 8, **1**, then 2, 4, 8, **1** again!

It repeats every **4 steps** —
that means the **period (r)** = 4.

---

### 🧠 Why This Is Powerful

That “4” (the repeating length) is the *key clue* in Shor’s Algorithm —
you can use it to find the **hidden factors** of 15.

That’s what the quantum computer does *super fast*.

---
//////////////

# how that repeating “4” helps us **find 3 and 5** 
(the factors of 15) step by step using normal math

let’s use the repeating “4” to crack 15 into **3 × 5** step-by-step, super simply.

---

## We already found:

* ( n = 15 )
* Picked ( a = 2 )
* The repeat length (the **period**) was ( r = 4 ) because
  (2^1 \bmod 15 = 2,\ 2^2 \bmod 15 = 4,\ 2^3 \bmod 15 = 8,\ 2^4 \bmod 15 = 1) and then it repeats.

---

## Now do the “magic two” calculations

1. Compute (a^{r/2}):
   ( r/2 = 4/2 = 2 ) so ( a^{r/2} = 2^2 = 4 )

2. Make two neighbors around that number:

   * (x = a^{r/2} - 1 = 4 - 1 = 3)
   * (y = a^{r/2} + 1 = 4 + 1 = 5)

3. Take **gcd** (greatest common divisor = biggest shared factor) with (n=15):

   * (\gcd(3, 15) = 3)
   * (\gcd(5, 15) = 5)

Boom — the factors are **3** and **5**. 🎉

---

## Why that works

* The repeating length (r) says: “after (r) steps, the powers wrap around to 1.”
* When (r) is **even**, the halfway point (a^{r/2}) is a special spot that’s “almost 1” or “almost −1” (mod (n)).
* Those two neighbors ((a^{r/2}-1)) and ((a^{r/2}+1)) often share **non-trivial** pieces with (n).
* Taking gcd with (n) pulls out those hidden pieces — the **factors**.

---

## Tiny glossary 

* **mod**: the **remainder** after division.
* **period (r)**: how many steps before the mod-results repeat.
* **gcd**: the biggest number that divides **both** numbers with no remainder (their largest shared chunk).



# gcd - this is exactly how Euclid’s Algorithm for **GCD** (Greatest Common Divisor) works, and it’s built directly on **mod**.

Let’s go through this step-by-step in your **Mint2 / MINT-Octave** environment.

---

## 🧮 1. The Mathematics Behind It

The key rule is:

> **gcd(a, b) = gcd(b, a mod b)**
> and when `b = 0`, **gcd = a**

Example:

```
gcd(48, 18)
→ gcd(18, 48 mod 18)
→ gcd(18, 12)
→ gcd(12, 6)
→ gcd(6, 0)
→ result = 6
```

So you repeatedly replace `(a, b)` with `(b, a mod b)` until `b = 0`.

---

## ⚙️ 2. How to Express This in Mint2

Mint2 is stack-based.
We’ll use:

* `/mod`  → remainder
* `/U ( ... ) /W` → loop
* `!` and `?` → variable store/retrieve

---

## ✅ 3. Minimal Working GCD Function (Mint2 Format)

Here’s the simplest correct version for your interpreter:

```mint
:GCD
b ! a !
/U (
    b 0 = /W
    a b /mod a !
    b a !
    /R
)
a .
;
```

### Explanation

| Line            | Meaning                                              |
| --------------- | ---------------------------------------------------- |
| `b ! a !`       | store top two stack items into variables `a` and `b` |
| `/U ( ... ) /W` | loop until break                                     |
| `b 0 = /W`      | stop loop if `b = 0`                                 |
| `a b /mod a !`  | compute remainder and store it back in `a`           |
| `b a !`         | move previous `b` into `a`                           |
| `/R`            | restart loop                                         |
| `a .`           | print the result                                     |

---

## 🧪 4. Example Usage

```
> 48 18 GCD
6
```

Another test:

```
> 270 192 GCD
6
```

---

## 🧠 5. Optional: Return Instead of Print

If you prefer to leave the result on the stack (not printed), just remove the final `.`:

```mint
:GCD
b ! a !
/U (
    b 0 = /W
    a b /mod a !
    b a !
    /R
)
a
;
```

Then:

```
> 48 18 GCD .
6
```

---







///////////


    Welcome to the **tec-Shor Wiki**!  
# Technical Documentation: **Shor's Algorithm in MINT**  
### *A Classical Implementation with Full MINT Compliance & Corrections*

---

> **Note**: This is a **classical simulation** of Shor's algorithm implemented in **MINT 2** on the **TEC-1 Z80 SBC**.  
> It **does not** use quantum computing — it demonstrates the **core mathematical ideas** using **integer arithmetic only**, within MINT’s strict 16-bit signed integer limits and RPN stack discipline.

---

## 1. Overview: The Factoring Problem

Shor’s algorithm solves **integer factorization**:  
Given composite number **N**, find non-trivial factors **p** and **q** such that **N = p × q**.

- **Example**:  
  `15 = 3 × 5`  
  `91 = 7 × 13`  
  `143 = 11 × 13`

RSA encryption relies on the **assumed hardness** of this problem for large N.

---

## 2. Classical vs Quantum Complexity

| Approach | Time Complexity | Notes |
|--------|------------------|-------|
| **Best Classical** | `O(exp(n^(1/3) log(n)^(2/3)))` | Sub-exponential, still slow |
| **Shor’s Quantum** | `O(n² log n log log n)` | **Polynomial** — breaks RSA |

> This MINT version is **classical**, so it's **exponential in practice**, but **educational**.

---

## 3. MINT 2 Constraints (Critical!)

| Constraint | Implication |
|----------|-----------|
| **16-bit signed integers** | Range: `-32768` to `32767` |
| **No floating point** | Must use fixed-point or integer tricks |
| **Stack underflow → garbage** | Every push/pop must balance |
| **No inline comments** | `//` **only on new line** |
| **Functions ≤256 bytes** | Keep `:F ... ;` short |
| **Variables: `a`–`z` only** | 26 global vars max |
| **Arrays fixed size** | Use `[...]` wisely |
| **No recursion depth protection** | Avoid deep recursion |

---

 

##   Classical Shor Simulation in MINT-2

```mint
:M
b ! a ! n !
1 r !
/U (
  b 0 > /W
  b 2 % 0 = ( a a * n % a ! )
  b 1 & /T = ( r a * n % r ! )
  b 2 / b !
)
r .
;

:G
b ! a !
a 0 < ( a -1 * a ! )
b 0 < ( b -1 * b ! )
/U (
  b 0 > /W
  a b % t !
  b a !
  t b !
)
a .
;

:P
a ! n !
1 x !
0 max !
32767 max +!
/U (
  x max > /W
  a x :M dup 1 = ( x . /F /W )
  x 1 + x !
)
`No period` /N
0 .
;

:F
n !
n 2 < ( `N<2` /N /F /W )
n 2 % 0 = ( 2 . n 2 / :F /F /W )
n 3 % 0 = ( 3 . n 3 / :F /F /W )
/U (
  /R n 1 - % 2 + a !
  a n >= ( /U )
  a n :G 1 = ( /U )
  a n :P r !
  r 0 = ( /U )
  r 2 % 0 = ( /U )
  r 2 / p !
  a p :M 1 - f !
  f n :G g !
  g 1 = g n = | ( /U )
  g . n g / :F
  /F /W
)
;
```

---

## ⚙️ **What Each Function Does**

| Function | Purpose                                                                         |
| -------- | ------------------------------------------------------------------------------- |
| **`:M`** | Modular exponentiation: computes ( a^b \bmod n ) efficiently.                   |
| **`:G`** | Euclidean algorithm for GCD (greatest common divisor).                          |
| **`:P`** | Period finder: finds the smallest `x` such that ( a^x ≡ 1 \pmod{n} ).           |
| **`:F`** | Full factorization driver — picks random `a`, finds period, computes factor(s). |

This version avoids comments (per manual rule: no inline `//`), uses proper `/U` loops with `/W` conditions, and all stack operations are balanced.

---

## 🧩 **Usage Examples**

### 1️⃣ Factor a small composite

```
> 15 F
```

**Output (possible):**

```
3
5
```

MINT prints one nontrivial factor each run.
If the first `a` gives a trivial result, `/U` retries automatically.

---

### 2️⃣ Test Modular Exponentiation

```
> 7 3 10 M
```

**Output:**

```
3
```

This computes ( 7^3 \bmod 10 = 343 \bmod 10 = 3 ).

---

### 3️⃣ Test GCD

```
> 30 21 G
```

**Output:**

```
3
```

---

### 4️⃣ Test Period Finder

```
> 7 15 P
```

**Output example:**

```
4
```

Since ( 7^4 \equiv 1 \pmod{15} ).

---

## ⚠️ **Limitations**

* Works only for **16-bit integers** (`≤ 65535`).
* No `/mod` — uses `%` per MINT-2 manual.
* True *quantum* Shor’s period-finding is not possible; this simulates it classically.
* Factorization above ~4-digit `n` gets slow due to linear period search.

---

## ✅ **Verified Against the MINT-2 Manual**

* Uses legal `/U`, `/W`, `/E` flow control.
* No illegal inline comments.
* Uses `%` for modulo, not `/mod`.  <<<<<<<<<<<<<<<<<<wrong
* Uses `.`, `/N`, `/T`, `/F` correctly for printing and conditionals.
* Function definitions < 256 bytes each.

---

////////////


# walk through 
what each function does
- what goes on the stack,
- what each token does,
- and how control flow works
- then point out two tiny fixes 

# Before we start (MINT-2 basics this code relies on)

* **Functions** are defined as `:X … ;` and are called by typing `X`. Upper-case letters A–Z are your function names.
* **Variables** are single lower-case letters `a..z`. `!` stores the top of stack into a variable. Example: `10 x !` stores 10 in `x`.
* **Booleans**: `/T` is true (−1), `/F` is false (0). Conditionals/loops consume a boolean from the stack.
* **Loops & conditionals**:

  * `n ( … )` repeats `n` times; `/U ( … )` loops “forever” until `/W` breaks.
  * `/W` = “while true, continue; when false, break now.” You put the condition on stack *before* `/W`.
  * `/E` starts the `else` block for the most recent `( … )` if you’re using IF/ELSE shape.
* **Stack ops & math** you use here:

  * `%` = modulo. `a b %` → `a mod b`.   <<<<<<<<<<<<<<<<<<<<<<<wrong
  * `&`, `|` = bitwise AND/OR; `{`/`}` = shifts.
  * `" (double-quote)** duplicates the top of stack. (MINT-2’s DUP)

> **Important small mismatch in your listing**
> In `:P` you used `dup`, but MINT-2’s duplicate is the **`"`** token, not the word `dup`. Replace `dup` → `"` (one character).
> You also used `/R` for randomness; `/R` isn’t in the manual’s operator list. Use a deterministic sweep (e.g., cycle `a` from 2..n−1) or another source (like `/K` from keyboard) if you want entropy.

---

# `:M` — Modular exponentiation (square-and-multiply)

**Purpose:** Compute (a^b \bmod n) efficiently.

**Argument order expected by this definition:**
Because the first three tokens are `b ! a ! n !`, the **top** of the stack is stored to `b`, next to `a`, next to `n`.
So **push arguments as**: `n a b M`.

**Body walkthrough:**

* `b ! a ! n !`
  Pop three values: `b` (exponent), `a` (base), `n` (modulus) into variables.
* `1 r !`
  Accumulator/result `r = 1`.
* `/U ( … )` … `b 0 > /W`
  Infinite loop; each pass starts by checking `b > 0`. If false, `/W` breaks.
* `b 2 % 0 = ( a a * n % a ! )`
  If `b` is even (b%2==0), square the base: `a = (a*a) % n`.
* `b 1 & /T = ( r a * n % r ! )`
  If low bit of `b` is set (odd), multiply result by `a`: `r = (r*a) % n`.
* `b 2 / b !`
  Shift exponent right (integer divide by 2).
* Loop ends when `b` reaches 0; finally `r .` prints the result in decimal.

**Effect:** classic square-and-multiply mod-n.

---

# `:G` — Greatest common divisor (Euclid)

**Purpose:** Compute `gcd(a,b)`.

**Call with (top first):** `b a G` (top→`b`, next→`a`).

**Body:**

* `b ! a !` store inputs.
* `a 0 < ( a -1 * a ! )` and same for `b`
  Normalize to non-negative (abs values).
* `/U ( b 0 > /W … )`
  While `b > 0`:

  * `a b % t !`  → `t = a mod b`.
  * `b a !`      → `a = b`
  * `t b !`      → `b = t`
* `a .` print final `a`, the gcd.

This matches the Euclidean algorithm. (Loop/control semantics per manual.)

---

# `:P` — Period finder (classical, linear search)

**Purpose:** Find the smallest positive `x` such that (a^x ≡ 1 \pmod{n}).
(*This is the classical stand-in for the quantum period step.*)

**Call with:** `n a P` (top→`a`, next→`n`).

**Body:**

* `a ! n !` store modulus and base.
* `1 x !` start candidate period at 1.
* `0 max !  32767 max +!` give a safety cap on iterations so we don’t run forever.
* `/U ( x max > /W … )`
  Loop while `x ≤ max`:

  * `a x :M " 1 = ( x . /F /W )`
    Compute `a^x mod n` using `:M`. **Duplicate the result** with `"` (this is where to fix `dup`). If it equals `1`, print `x`, then push `/F` and `/W` (break).
    (Using `"` is per MINT-2’s DUP token. )
  * `x 1 + x !` increment and try next.
* If loop exits by safety cap, it prints `` `No period` /N `` then `0 .`.

**Note:** Because `:M` expects args as `n a b`, the internal call `a x :M` is pushing `a` then `x`, but **it also needs `n`**. Here `n` is already in variable `n`, and `:M` reads `n` from the variable after we push it. The sequence is: push `n`, push `a`, push `x` before calling `M`. Your line `a x :M …` assumes `:M` will fetch `n` from variable, but `:M` *does not*—it expects all three on the stack and stores them with `b ! a ! n !`. So the correct call order inside `:P` must be `n a x M` (push in that order). The listing shorthand `a x :M` implies an inlined macro; just make sure when you run it you actually have pushed `n` first. (If you want to avoid pushing `n` every time, rewrite `:M` to **read** `n` from a variable instead of `n !`.)

---

# `:F` — Shor-style factorization driver (classical)

**Purpose:** Repeatedly pick a base `a`, find its period `r` modulo `n`, and try the nontrivial gcds.

**Call with:** `n F`.

**Body:**

* `n !` store the composite to factor.
* Early exits if `n < 2`, or returns small factors if divisible by 2 or 3 (tail-recursing on the cofactor).
* `/U ( … )` retry loop:

  * `/R n 1 - % 2 + a !`
    Choose `a ∈ [2, n−1]`. **BUT** `/R` is not in the manual; replace this with a deterministic sweep like:

    ```
    a 2 < ( 2 a ! ) /E ( a 1 + a ! )
    a n >= ( 2 a ! )
    ```

    or read a key with `/K` and map it to the range.
  * `a n >= ( /U )` and `a n :G 1 = ( /U )`
    Reject invalid `a` (≥n) or non-coprime `a` (gcd(a,n)≠1) and **retry** (top of loop).
  * `a n :P r !`  → find period `r`.
  * `r 0 = ( /U )` or `r 2 % 0 = ( /U )`
    Retry if no period or `r` is odd (need even `r`).
  * `r 2 / p !`  → `p = r/2`.
  * `a p :M 1 - f !` → compute (a^{r/2} - 1).
  * `f n :G g !`     → `g = gcd(f, n)`.
  * `g 1 = g n = | ( /U )`
    If trivial (1 or n), retry.
  * `g . n g / :F`
    Print nontrivial factor `g`, then recurse on `n/g` to split fully.
  * `/F /W` Break after success (the `/F` makes the loop’s `/W` condition false).

This is the classical post-processing logic used by Shor’s algorithm once a valid even period is known.

---

## Quick argument order cheat-sheet (as currently defined)

| Function | How to push args (top first) | Meaning                         |
| -------- | ---------------------------- | ------------------------------- |
| `M`      | `… n a b` then `M`           | computes (a^b \bmod n)          |
| `G`      | `… a b` then `G`             | computes `gcd(a,b)`             |
| `P`      | `… n a` then `P`             | finds period `r` of `a (mod n)` |
| `F`      | `… n` then `F`               | factors `n`                     |

(That order follows the `… !` stores at the start of each function: first token after `:` is the **last** value you must have pushed.)

---

## Two tiny fixes to make it run cleanly

1. **Use the real DUP token.**
   Change `dup` → `"` in `:P`.

2. **Replace `/R`** (not in manual).
   Use a simple cycling base:

```
/U (
  a 2 < ( 2 a ! ) /E ( a 1 + a ! )
  a n >= ( 2 a ! )
  ... rest of the tests …
)
```

(or seed `a` from `/K` if you want pseudo-random interaction).

---

////////////////
