# 📘 C++ STL — Contest-Oriented Visual Notes

> **Purpose:** Fast STL decisions during contests & interviews

⚠️ **Golden Rule**
Never erase from a container while iterating **unless you use the returned iterator**.

---

## 1️⃣ `vector` — Dynamic Array (CONTIGUOUS)

> **TL;DR:** Use `vector` when you need index access and fast iteration.
> Avoid frequent middle insert/erase.

### Initialization

```cpp
vector<int> v = {1, 2, 3};
```

**State**

```
Index:  0   1   2
Value:  1   2   3
```

---

### 🔹 `push_back`

```cpp
v.push_back(10);
```

```
1   2   3   10
```

* Adds element at end
* May reallocate memory

⏱ **O(1) amortized**
Return ❌ nothing

---

### 🔹 `pop_back`

```cpp
v.pop_back();
```

```
1   2   3
```

* Removes last element
  ⚠️ No `pop_front()` in vector

---

### 🔹 `insert`

```cpp
v.insert(v.begin() + 1, 5);
```

Before:

```
1   2   3
```

After:

```
1   5   2   3
```

⏱ **O(n)**
Return ✔ iterator to inserted element

---

### 🔹 `erase`

```cpp
v.erase(v.begin() + 1);
```

```
1   2   3
```

⏱ **O(n)**
⚠️ Returns iterator to **next element**

---

### 🔹 `find` / `count`

```cpp
find(v.begin(), v.end(), 5);
count(v.begin(), v.end(), 5);
```

⏱ **O(n)**

---

### 🔹 `begin()` / `rbegin()`

```cpp
*v.begin();    // first element
*v.rbegin();   // last element
```

⚠️ Undefined behavior if vector is empty

---

## 2️⃣ `set` — Ordered & Unique

> **TL;DR:** Sorted + unique elements, fast min/max.

```cpp
set<int> st = {1, 3, 5};
```

```
1   3   5
```

### Insert

```cpp
st.insert(4);
```

```
1   3   4   5
```

### Erase

```cpp
st.erase(3);
```

```
1   4   5
```

### Find / Count

```cpp
st.find(4);
st.count(4);
```

### Access

```cpp
*st.begin();   // min
*st.rbegin();  // max
```

---

## 3️⃣ `multiset` — Ordered + Duplicates

> **TL;DR:** Sorted elements, duplicates allowed.

```cpp
multiset<int> ms = {1, 2, 2, 3};
```

```
1   2   2   3
```

⚠️ **Erase difference**

```cpp
ms.erase(2);             // removes all 2s
ms.erase(ms.find(2));    // removes one 2
```

**Use cases**

* Median of stream
* Greedy min/max removal

---

## 4️⃣ `map` — Ordered Key → Value

> **TL;DR:** Sorted keys with mapped values.

```cpp
map<int,int> mp = {{2,20},{1,10},{3,30}};
```

```
1→10   2→20   3→30
```

### Insert

```cpp
mp[4] = 40;
mp.insert({0,5});
```

⚠️ `mp[key]` inserts key if missing (default value = 0)

### Find / Erase

```cpp
mp.find(2);
mp.erase(2);
```

### Access

```cpp
mp.begin()->first;    // smallest key
mp.rbegin()->first;   // largest key
```

---

## 5️⃣ `unordered_set` / `unordered_map` — Hash Table

> **TL;DR:** Fast lookup, no order.

```cpp
unordered_set<int> us = {1,2,3};
unordered_map<int,int> um = {{1,10},{2,20}};
```

```cpp
us.insert(4);
um.erase(2);
```

⏱ **O(1) average**
⚠️ No ordering guaranteed

---

## 6️⃣ `pair` — Two Values Together

```cpp
pair<int,int> p = {1,5};
```

```cpp
p.first;
p.second;
```

**Use cases**

* Coordinates
* Value + index
* Intervals

---

## 7️⃣ Stack / Queue / Priority Queue

### Stack (LIFO)

```cpp
stack<int> st;
st.push(1);
st.pop();
```

Use: recursion, parentheses, undo

---

### Queue (FIFO)

```cpp
queue<int> q;
q.push(1);
q.pop();
```

Use: BFS

---

### Priority Queue (Heap)

```cpp
priority_queue<int> pq; // max heap
priority_queue<int, vector<int>, greater<int>> minpq;
```

Use: top-K, greedy
⚠️ Cannot remove arbitrary elements

---

## 8️⃣ `deque` — Double Ended Queue

```cpp
deque<int> dq = {2,3};
```

```cpp
dq.push_front(1);
dq.push_back(4);
dq.pop_front();
dq.pop_back();
```

Use: sliding window max/min

---

## 🔥 FINAL CONTEST RULE OF THUMB

```
Index needed?        → vector
Sorted + unique?     → set
Sorted + duplicate?  → multiset
Key-value sorted?    → map
Fast frequency?      → unordered_map
Min / Max always?    → priority_queue
FIFO?                → queue
LIFO?                → stack
Window problems?     → deque
```

---

# 🧠 30-SECOND DS DECISION FRAMEWORK

1️⃣ Need order? → set / map
2️⃣ Need duplicates? → multiset
3️⃣ Need fast lookup? → unordered_map
4️⃣ Need min/max repeatedly? → priority_queue
5️⃣ Need index access? → vector

---

# 🔑 IMPORTANT STL ALGORITHMS (Quick Guide)

### `sort`

```cpp
sort(v.begin(), v.end());
```

* `O(n log n)`
* Random access iterators required

---

### `reverse`

```cpp
reverse(v.begin(), v.end());
```

* `O(n)`
* Reverses only (not sorting)

---

### `lower_bound`

```cpp
lower_bound(v.begin(), v.end(), x);
```

* First element **≥ x**
* Sorted range only

---

### `upper_bound`

```cpp
upper_bound(v.begin(), v.end(), x);
```

* First element **> x**

---

### `binary_search`

```cpp
binary_search(v.begin(), v.end(), x);
```

* Returns `true / false`
* `O(log n)`
* Sorted range required

---

# 🧠 PART 1️⃣ — WHEN TO USE / WHEN NOT TO USE (WITH REAL PROBLEMS)

> **Most important section for contests**
> STL syntax is easy. **Choosing the right DS wins AC.**

---

## 1️⃣ `vector`

### ✅ USE WHEN

* Index-based access needed
* Order matters
* Fixed traversal

### 🧩 Example

**Maximum Subarray Sum**

```cpp
vector<int> a(n);
```

### ❌ DO NOT USE WHEN

* Frequent middle insert/delete → **TLE**

---

## 2️⃣ `map` (ordered)

### ✅ USE WHEN

* Sorted keys
* Range queries

### ❌ DO NOT USE WHEN

* Only frequency needed → use `unordered_map`

---

## 3️⃣ `set`

### ✅ USE WHEN

* Unique elements
* Min / max required quickly

### ❌ DO NOT USE WHEN

* Duplicates required

---

## 4️⃣ `multiset`

### ✅ USE WHEN

* Sorted duplicates
* Median / greedy problems

---

## 5️⃣ `unordered_map` / `unordered_set`

### ✅ USE WHEN

* Fast lookup
* Order irrelevant

---

## 🚨 PART 2️⃣ — COMMON WRONG CHOICES

| Requirement       | Wrong  | Correct        |
| ----------------- | ------ | -------------- |
| Frequency         | map    | unordered_map  |
| Sorted duplicates | set    | multiset       |
| Middle insert     | vector | deque          |
| Min repeatedly    | vector | priority_queue |
| BFS               | stack  | queue          |

---

