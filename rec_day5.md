````md
# First and Last Index of an Element Using Recursion (C++)

This repository demonstrates how to find the **first** and **last occurrence**
of a target element in an array using **recursion**.

Two different recursion techniques are used:
- **Forward recursion** (First Index)
- **Backtracking** (Last Index)

---

## 📌 Concepts Covered

- Recursion on arrays
- Base case handling
- Forward recursion
- Backtracking (work done during return)
- Index-based traversal

---

## 🔹 1. First Index of an Element (Forward Recursion)

### Problem
Find the **first index** at which a target element appears in the array.

### Idea
- Traverse array from left to right
- Return immediately when the target is found
- No backtracking required

### Code
```cpp
int firstIndex(vector<int> arr, int idx, int target) {
    if (idx == arr.size()) {
        return -1;
    }

    if (arr[idx] == target) {
        return idx;
    }

    return firstIndex(arr, idx + 1, target);
}
```

````

### Example

```cpp
firstIndex({1,2,3,4,4,5}, 0, 4);
```

### Output

```
3
```

✔️ Forward recursion
✔️ Stops at the first match
✔️ Time Complexity: `O(n)`

---

## 🔹 2. Last Index of an Element (Backtracking)

### Problem

Find the **last index** at which a target element appears in the array.

### Idea

* First go till the end of the array
* While returning, check if the element exists later
* If found later, return that index
* Otherwise, check current index

### Code

```cpp
int lastIndex(vector<int> arr, int idx, int target) {
    if (idx == arr.size()) {
        return -1;
    }

    int llI = lastIndex(arr, idx + 1, target);

    if (llI != -1) return llI;

    return (arr[idx] == target) ? idx : -1;
}
```

### Example

```cpp
lastIndex({1,2,3,4,4,5}, 0, 4);
```

### Output

```
4
```

✔️ Backtracking
✔️ Print/check during recursion return
✔️ Time Complexity: `O(n)`

---

## 🧠 Key Difference (Interview Must-Know)

| Aspect         | First Index  | Last Index                   |
| -------------- | ------------ | ---------------------------- |
| Traversal      | Left → Right | Right → Left (via recursion) |
| Recursion Type | Forward      | Backtracking                 |
| Return timing  | Immediate    | During unwind                |
| Complexity     | O(n)         | O(n)                         |

---

## 🚀 Complete Program

```cpp
#include <bits/stdc++.h>
using namespace std;

int firstIndex(vector<int> arr, int idx, int target) {
    if (idx == arr.size()) {
        return -1;
    }
    if (arr[idx] == target) {
        return idx;
    }
    return firstIndex(arr, idx + 1, target);
}

int lastIndex(vector<int> arr, int idx, int target) {
    if (idx == arr.size()) {
        return -1;
    }

    int llI = lastIndex(arr, idx + 1, target);

    if (llI != -1) return llI;

    return (arr[idx] == target) ? idx : -1;
}

int main() {
    cout << firstIndex({1,2,3,4,4,5}, 0, 4) << endl;
    cout << lastIndex({1,2,3,4,4,5}, 0, 4);
    return 0;
}
```

---

## ⏱️ Time & Space Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(n)` (recursion stack)

---

## 🎯 Interview Tip

> To find the **first occurrence**, return early.
> To find the **last occurrence**, let recursion go deep and decide while returning.

---

## ✨ Author

**Abhishek Kumar**
Backend Engineer | DSA | C++


Just tell me 👍
```
