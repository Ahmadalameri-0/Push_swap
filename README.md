# Push_swap - Efficient Stack Sorting 📊

## Overview
This project is a core part of the **42 curriculum**, focusing on algorithm design and performance optimization. The goal is to sort a list of integers using two stacks (Stack A and Stack B) and a strictly limited set of operations, aiming for the lowest possible move count.

My implementation features an **Adaptive Strategy** that selects the most efficient algorithm based on input size and data disorder.

---

## 🚀 Features
* **Multiple Sorting Algorithms:** Includes Simple Sort, Chunk Sort, and Radix Sort.
* **Adaptive Selection:** Automatically analyzes input to choose the optimal sorting strategy.
* **Benchmark Mode:** Built-in performance analysis tool using the `--bench` flag.
* **Error Handling:** Robust validation for non-numeric input, duplicates, and integer overflows.

---

## 🛠️ Installation & Usage
### Compilation
Build the executable using `make`:
```bash
make
```
### Usage
```bash
./push_swap [options] <numbers>
```
### Available Options
| Option | Description | Complexit |
| :---  | :--- | :--- |
| `--simple` | Ideal for very small inputs | $O(n^2)$ |
| `--medium` | Chunk-based sorting for medium datasets | $O(n\sqrt{n})$ |
| `--complex` | Radix Sort for large datasets | $O(n \log n)$ |
| `--adaptive` | **(Default)** Auto-selects the best strategy | Dynamic |
| `--bench` | Displays disorder level, strategy, and move count | - |

🧠 Algorithms Implemented

1. **Simple Sort:** Optimized for small sets where overhead is minimal.
2. **Chunk Sort:** Divides data into logical blocks to reduce operation costs.
3. **Radix Sort:** A non-comparative algorithm used for maximum efficiency on large volumes of data.
4. **Adaptive Strategy:** The "brain" of the program, calculating the disorder percentage to pick the winner.

📈 Benchmarking
When running with --bench, the program outputs the following to stderr:
- **Disorder Percentage:** How "unsorted" the initial stack is.
- **Strategy Used:** The specific algorithm selected.
- **Operation Count:** Total moves (sa, pb, ra, etc.) performed.

```bash
./push_swap --bench --adaptive 5 4 6 3 9
```

## 📜 License & Credits

  * **Authors:** Originally created by [Ahmadalameri-0](https://github.com/Ahmadalameri-) and [omardalgamoni44-star](https://github.com/omar-2004-git)


*AI tools were utilized for debugging and refactoring suggestions during development.*
