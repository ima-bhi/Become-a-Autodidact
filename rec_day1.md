````md
# Printing Numbers Using Recursion & Backtracking (C++)

This file demonstrates **four different recursive approaches** to print numbers.
Each approach highlights **where the print statement is placed** and whether it is
**normal recursion or backtracking**.

---

## 📌 Concepts Covered

- Recursion fundamentals
- Backtracking (printing during return phase)
- Call stack behavior
- Difference between forward recursion and backtracking

---

## 🔹 Code 1: Print 1 to N (Backtracking using decreasing parameter)

### Idea
- Recursively go down to `0`
- Print while returning
- This is **pure backtracking**

### Code
```cpp
#include <bits/stdc++.h>
using namespace std;

void print(int i, int n) {
    if (i == 0) return;     // base condition
    print(i - 1, n);        // recursive call
    cout << i << endl;  // backtracking print
}

int main() {
    print(5, 5);
    return 0;
}
````

### Output

```
1
2
3
4
5
```

✔️ Backtracking
✔️ Printing happens **after recursion**

---

## 🔹 Code 2: Print N to 1 (Backtracking using forward index)

### Idea

* Move forward (`i → n`)
* Print while returning

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

void printBacktrack(int i, int n) {
    if (i > n) return;          // base condition
    printBacktrack(i + 1, n);  // forward recursion
    cout << i << endl;  // backtracking print
}

int main() {
    printBacktrack(1, 5);
    return 0;
}
```

### Output

```
5
4
3
2
1
```

✔️ Backtracking
✔️ Printing during unwind phase

---

## 🔹 Code 3: Print 1 to N (Backtracking using single parameter)

### Idea

* Recursively reduce `n`
* Print while returning

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

void print(int n) {
    if (n == 0) return;    // base condition
    print(n - 1);          // recursive call
    cout << n << endl;  // backtracking print
}

int main() {
    print(5);
    return 0;
}
```

### Output

```
1
2
3
4
5
```

✔️ Backtracking
✔️ Cleaner version of Code 1

---

## 🔹 Code 4: Print N to 1 (Normal Recursion – NOT Backtracking)

### Idea

* Print **before** recursive call

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

void print(int n) {
    if (n == 0) return;    // base condition
    cout << n << endl;
    print(n - 1);          // recursive call
}

int main() {
    print(5);
    return 0;
}
```

### Output

```
5
4
3
2
1
```

❌ Not backtracking
❌ Printing happens before recursion

---

## 🧠 Final Comparison Table

| Code   | Technique        | Print Position   | Output |
| ------ | ---------------- | ---------------- | ------ |
| Code 1 | Backtracking     | After recursion  | 1 → N  |
| Code 2 | Backtracking     | After recursion  | N → 1  |
| Code 3 | Backtracking     | After recursion  | 1 → N  |
| Code 4 | Normal recursion | Before recursion | N → 1  |

---

## 🚀 Key Interview Takeaway

> **Backtracking = doing work while recursion returns**

If logic executes **after** the recursive call, it is backtracking.

---



## ✨ Author

**Abhishek Rana**
Backend Engineer | DSA | C++

