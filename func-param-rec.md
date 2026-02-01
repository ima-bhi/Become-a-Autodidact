````md
# Parameterized vs Functional Recursion (C++)

This repository demonstrates **two important recursion techniques** commonly asked in
**DSA interviews**:

1. **Parameterized Recursion**
2. **Functional Recursion**

Both approaches are explained using **sum** and **factorial** examples.

---

## 📌 Concepts Covered

- Recursion fundamentals
- Parameterized recursion
- Functional recursion
- Base case vs recursive case
- Return-based vs parameter-based computation

---

## 🔹 1. Parameterized Recursion (Sum of First N Numbers)

### 🔸 Idea
- Accumulate the result using a parameter
- No value is returned
- Final result is printed in the base case

### Code
```cpp
void fp(int n, int sum) {
    if (n < 1) {
        cout << "sum is : " << sum << endl;
        return;
    }
    fp(n - 1, sum + n);
}
````

### Example Call

```cpp
fp(3, 0);
```

### Output

```
sum is : 6
```

---

## 🔹 2. Functional Recursion (Sum of First N Numbers)

### 🔸 Idea

* Function returns the computed value
* No extra parameter required
* Each recursive call contributes to the final result

### Code

```cpp
int ff(int num) {
    if (num == 0) {
        return 0;
    }
    return num + ff(num - 1);
}
```

### Example Call

```cpp
cout << "sumNew : " << ff(3) << endl;
```

### Output

```
sumNew : 6
```

---

## 🔹 3. Functional Recursion (Factorial of N)

### 🔸 Idea

* Each call returns `n * factorial(n-1)`
* Result bubbles up via return values

### Code

```cpp
int fact(int m) {
    if (m == 1) {
        return 1;
    }
    return m * fact(m - 1);
}
```

### Example Call

```cpp
cout << "fact : " << fact(4) << endl;
```

### Output

```
fact : 24
```

---

## 🔹 4. Parameterized Recursion (Factorial of N)

### 🔸 Idea

* Carry the computed factorial using a parameter
* Final result printed at base case

### Code

```cpp
void factP(int n, int t) {
    if (n == 0) {
        cout << " total :" << t << endl;
        return;
    }
    factP(n - 1, t * n);
}
```

### Example Call

```cpp
factP(4, 1);
```

### Output

```
total : 24
```

---

## 🧠 Key Differences (Interview MUST-KNOW)

| Aspect            | Parameterized Recursion | Functional Recursion |
| ----------------- | ----------------------- | -------------------- |
| Uses parameters   | ✅ Yes                   | ❌ No                 |
| Uses return value | ❌ No                    | ✅ Yes                |
| Result stored     | In parameters           | In return stack      |
| Printing          | Base case               | Caller               |
| Readability       | Slightly complex        | Cleaner              |

---

## 🚀 Interview Tip

> If the interviewer asks
> **“Can you do this without using return?”**
> 👉 Use **Parameterized Recursion**

> If the interviewer asks
> **“Return the result”**
> 👉 Use **Functional Recursion**

---

## 📂 Full Program

```cpp
#include <bits/stdc++.h>
using namespace std;

// Parameterized recursion (sum)
void fp(int n, int sum) {
    if (n < 1) {
        cout << "sum is : " << sum << endl;
        return;
    }
    fp(n - 1, sum + n);
}

// Functional recursion (sum)
int ff(int num) {
    if (num == 0) {
        return 0;
    }
    return num + ff(num - 1);
}

// Functional recursion (factorial)
int fact(int m) {
    if (m == 1) {
        return 1;
    }
    return m * fact(m - 1);
}

// Parameterized recursion (factorial)
void factP(int n, int t) {
    if (n == 0) {
        cout << " total :" << t << endl;
        return;
    }
    factP(n - 1, t * n);
}

int main() {
    fp(3, 0);
    cout << "sumNew : " << ff(3) << endl;
    cout << "fact : " << fact(4) << endl;
    factP(4, 1);
    return 0;
}
```

---

## 🧪 Time & Space Complexity

* **Time Complexity:** `O(N)`
* **Space Complexity:** `O(N)` (recursive stack)

---

## ✨ Author

**Abhishek Kumar**
Backend Engineer | DSA | C++


