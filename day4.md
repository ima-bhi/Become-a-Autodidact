````md
# Recursion Practice Problems in C++ (Pre–In–Post, TOH, Arrays)

This repository contains multiple **classic recursion problems** implemented in C++.
Each example demonstrates a **different recursion pattern**, commonly asked in
**DSA interviews**.

---

## 📌 Concepts Covered

- Pre / In / Post recursion order
- Multiple recursive calls
- Tower of Hanoi
- Recursion on arrays
- Backtracking
- Functional recursion

---

## 🔹 1. Pre–In–Post Recursion Order (`pzz`)

### Problem
Print values in **Pre**, **In**, and **Post** order using recursion.

### Code
```cpp
void pzz(int n) {
    if (n == 0) return;
    cout << "Pre" << n << " ";
    pzz(n - 1);
    cout << "In" << n << " ";
    pzz(n - 1);
    cout << "Post" << n << " ";
}
````

### Example

```cpp
pzz(2);
```

### Output

```
Pre2 Pre1 In1 Post1 In2 Pre1 In1 Post1 Post2
```

### Concept

✔️ Shows **recursion flow**
✔️ Demonstrates **multiple recursive calls**
✔️ Useful to understand **call stack behavior**

---

## 🔹 2. Tower of Hanoi (TOH)

### Problem

Move `n` disks from **source rod** to **destination rod** using a **helper rod**.

### Code

```cpp
void TOH(int n, char s, char d, char h) {
    if (n == 0) return;
    TOH(n - 1, s, h, d);
    cout << "[" << s << " -> " << d << "] ";
    TOH(n - 1, h, d, s);
}
```

### Example

```cpp
TOH(3, 'A', 'B', 'C');
```

### Output

```
[A -> B] [A -> C] [B -> C] [A -> B] [C -> A] [C -> B] [A -> B]
```

### Concept

✔️ Classic recursion problem
✔️ Uses **divide and conquer**
✔️ Time Complexity: `O(2^n)`

---

## 🔹 3. Display Array Using Recursion

### Problem

Print all elements of an array using recursion.

### Code

```cpp
void displayArr(vector<int> arr, int s) {
    if (s == arr.size()) return;
    cout << arr[s] << " ";
    displayArr(arr, s + 1);
}
```

### Example

```cpp
displayArr({1,2,3,4,5}, 0);
```

### Output

```
1 2 3 4 5
```

### Concept

✔️ Forward recursion
✔️ Simple base condition

---

## 🔹 4. Display Array in Reverse (Backtracking)

### Problem

Print array elements in **reverse order** using recursion.

### Code

```cpp
void displayArrReverse(vector<int> arr, int s) {
    if (s == arr.size()) return;
    displayArrReverse(arr, s + 1);
    cout << arr[s] << " ";
}
```

### Example

```cpp
displayArrReverse({1,2,3,4,5}, 0);
```

### Output

```
5 4 3 2 1
```

### Concept

✔️ Backtracking
✔️ Print happens **after recursive call**

---

## 🔹 5. Find Maximum Element in Array (Functional Recursion)

### Problem

Find the maximum value in an array using recursion.

### Code

```cpp
int arrMax(vector<int> arr, int idx) {
    if (idx == arr.size()) return -1;
    int msf = arrMax(arr, idx + 1);
    return max(arr[idx], msf);
}
```

### Example

```cpp
arrMax({1,2,3,4,5}, 0);
```

### Output

```
5
```

### Concept

✔️ Functional recursion
✔️ Uses return values
✔️ Time Complexity: `O(n)`

---

## 🚀 Complete Program

```cpp
#include <bits/stdc++.h>
using namespace std;

void pzz(int n) {
    if (n == 0) return;
    cout << "Pre" << n << " ";
    pzz(n - 1);
    cout << "In" << n << " ";
    pzz(n - 1);
    cout << "Post" << n << " ";
}

void TOH(int n, char s, char d, char h) {
    if (n == 0) return;
    TOH(n - 1, s, h, d);
    cout << "[" << s << " -> " << d << "] ";
    TOH(n - 1, h, d, s);
}

void displayArr(vector<int> arr, int s) {
    if (s == arr.size()) return;
    cout << arr[s] << " ";
    displayArr(arr, s + 1);
}

void displayArrReverse(vector<int> arr, int s) {
    if (s == arr.size()) return;
    displayArrReverse(arr, s + 1);
    cout << arr[s] << " ";
}

int arrMax(vector<int> arr, int idx) {
    if (idx == arr.size()) return -1;
    int msf = arrMax(arr, idx + 1);
    return max(arr[idx], msf);
}

int main() {
    pzz(2);
    cout << endl;

    TOH(3, 'A', 'B', 'C');
    cout << endl;

    vector<int> arr = {1,2,3,4,5};
    displayArr(arr, 0);
    cout << endl;

    displayArrReverse(arr, 0);
    cout << endl;

    cout << arrMax(arr, 0);
}
```

---

## 🧠 Key Takeaways

* Printing **after recursion** = backtracking
* Multiple recursive calls create **tree-like execution**
* Arrays can be processed using recursion with an index
* Tower of Hanoi is a **must-know recursion problem**

---

## ✨ Author

**Abhishek Kumar**
Backend Engineer | DSA | C++

