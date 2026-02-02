```md
# Fibonacci Series using Recursion (C++)

This repository demonstrates **two different recursive approaches** to work with the
**Fibonacci sequence**:

1. **Functional Recursion** – returning the nth Fibonacci number  
2. **Parameterized Recursion** – printing the Fibonacci series

---

## 📌 Concepts Covered

- Recursion basics
- Functional recursion
- Parameterized recursion
- Fibonacci sequence
- Recursive call stack behavior

---

## 🔢 Fibonacci Sequence

```

0 1 1 2 3 5 8 ...

````

Each number is the sum of the **previous two numbers**.

---

## 🔹 1. Functional Recursion (Nth Fibonacci Number)

### 🔸 Idea
- Function returns the Fibonacci number
- Uses return values to build the result
- Classic recursive definition

### Code
```cpp
int f(int n) {
    if (n <= 1) {
        return n;
    }
    int last = f(n - 1);
    int slast = f(n - 2);
    return last + slast;
}
````

### Example Call

```cpp
cout << f(5) << endl;
```

### Output

```
5
```

### 🔍 Explanation

```
f(5) = f(4) + f(3)
     = 3 + 2
     = 5
```

---

## 🔹 2. Parameterized Recursion (Print Fibonacci Series)

### 🔸 Idea

* Values are carried as parameters
* No return value
* Output printed during recursion

### Code

```cpp
void printFib(int n, int a, int b) {
    if (n == 0) return;

    cout << a << " ";
    printFib(n - 1, b, a + b);
}
```

### Example Call

```cpp
printFib(5, 0, 1);
```

### Output

```
0 1 1 2 3
```

✔️ Uses **parameterized recursion**
✔️ Efficient for printing series
✔️ No redundant calculations

---

## 🧠 Key Difference (Interview Must-Know)

| Aspect          | Functional Recursion | Parameterized Recursion |
| --------------- | -------------------- | ----------------------- |
| Returns value   | ✅ Yes                | ❌ No                    |
| Uses parameters | ❌ No                 | ✅ Yes                   |
| Use case        | Find nth Fibonacci   | Print Fibonacci series  |
| Time complexity | Exponential          | Linear                  |

---

## 🚀 Complete Program

```cpp
#include <bits/stdc++.h>
using namespace std;

int f(int n){
    if(n <= 1){
        return n;
    }
    int last = f(n - 1);
    int slast = f(n - 2);
    return last + slast;
}

void printFib(int n, int a, int b) {
    if (n == 0) return;
    cout << a << " ";
    printFib(n - 1, b, a + b);
}

int main() {
    cout << f(5) << endl;
    printFib(5, 0, 1);
    return 0;
}
```

---

## ⏱️ Time & Space Complexity

### Functional Fibonacci

* **Time:** `O(2^N)` (overlapping subproblems)
* **Space:** `O(N)` (recursive stack)

### Parameterized Fibonacci

* **Time:** `O(N)`
* **Space:** `O(N)`

---

## 🎯 Interview Tip

> If asked to **print the series**, always use **parameterized recursion**
> If asked to **return nth value**, use **functional recursion**


## ✨ Author

**Abhishek Kumar**
Backend Engineer | DSA | C++
