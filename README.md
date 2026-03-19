# 🧨 Minesweeper Grid Solver (C++)

## 📌 Problem Description

Given a Minesweeper grid, compute the number of adjacent mines (`*`) for each cell.

* Each cell in the grid is either:

  * `'*'` → represents a mine
  * `'.'` → represents an empty cell

* For every empty cell, replace it with the **count of adjacent mines** (including diagonals).

---

## 🧠 Approach

We treat the grid as a **flattened 1D vector** for better performance and cache efficiency.

### Key Idea:

* Traverse each cell
* If the cell contains a mine (`*`):

  * Mark it in output
  * Update all **8 neighboring cells**

### Directions handled:

```
(-1, 0), (1, 0), (0, 1), (0, -1),
(-1, -1), (-1, 1), (1, -1), (1, 1)
```

---

## 📥 Example

### Input:

```
* * . . .
. . . . .
. * . . .
```

### Output:

```
* * 1 0 0
3 3 2 0 0
1 * 1 0 0
```

---

## ⏱️ Complexity

| Type  | Complexity   |
| ----- | ------------ |
| Time  | O(row × col) |
| Space | O(row × col) |

---

## ⚡ Why 1D Vector?

* Better **cache locality**
* Faster access than `vector<vector<char>>`
* Common optimization in **competitive programming**

---

## 📌 Future Improvements

* Convert to class-based grid abstraction
* Support dynamic input from file/console
* Add visualization for grid

---

## 🤝 Contributing

Feel free to fork this repo and improve the implementation!

---

## ⭐ If you found this helpful, give it a star!

## Author
Umair Hayat
