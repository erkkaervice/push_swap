# Push_swap

A highly efficient sorting algorithm project that sorts data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed, one must manipulate various types of algorithms and choose the most appropriate solution (optimized for data sorting) for optimized data sorting.

## 💡 Overview

The project involves two stacks: **Stack A** and **Stack B**.
* **Stack A**: Initially contains a random amount of non-duplicated negative and/or positive numbers.
* **Stack B**: Initially empty.
* **Goal**: Sort the numbers in Stack A in ascending order.

## 🛠️ Algorithm Details

This implementation uses a **Cost-Based Greedy Algorithm** (often referred to as a "Turk Algorithm" variant) which is significantly more efficient than Radix or Quick Sort for the specific constraints of this project.

### The Strategy
1.  **Validation**: Arguments are validated for integers, non-duplicates, and limits.
2.  **Indexing**: Input values are assigned a rank (0 to N) to simplify comparisons.
3.  **Presort / Chunking (Stack A to B)**:
    * The algorithm pushes elements from A to B (`ft_dartagnan`).
    * It uses a pivot/median strategy to push smaller elements first, keeping B partially sorted and reducing the cost of the return phase.
    * 3 elements are kept in A and sorted instantly.
4.  **Greedy Sort (Stack B to A)**:
    * This is the core logic. For *every* element in Stack B, the algorithm calculates the **exact cost** (number of rotations) to place it correctly into Stack A (`ft_clicker`).
    * It identifies the "cheapest" node—the one requiring the fewest moves (`ft_fastrotate`).
    * It executes simultaneous rotations (`rr`, `rrr`) whenever possible to optimize move count.
5.  **Final Alignment**: Once all elements are back in A, the stack is rotated until the smallest element is at the top (`ft_rearrange`).

## 📦 Installation & Compilation

Clone the repository and compile both the mandatory program and the bonus checker:

```bash
git clone <repository-url>
cd push_swap
make        # Compiles 'push_swap'
make bonus  # Compiles 'checker'
```

## 🚀 Usage

### Sorting
Run `push_swap` with a list of integers. It will output the instructions to sort them.

```bash
./push_swap 2 1 3 6 5 8
```

Output Example:
```text
pb
pb
ra
sa
...
```

### Checking (Bonus)
The `checker` program reads instructions from stdin and verifies if they actually sort the stack.

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```
* Outputs `OK` if sorted.
* Outputs `KO` if not.
* Outputs `Error` if inputs are invalid.

## 📜 Operations

| Code  | Instruction | Action |
| :--- | :--- | :--- |
| **sa** | Swap A | Swap the first 2 elements at the top of stack A. |
| **sb** | Swap B | Swap the first 2 elements at the top of stack B. |
| **ss** | Swap Both | `sa` and `sb` at the same time. |
| **pa** | Push A | Take the first element at the top of B and put it at the top of A. |
| **pb** | Push B | Take the first element at the top of A and put it at the top of B. |
| **ra** | Rotate A | Shift all elements of stack A up by 1. First becomes last. |
| **rb** | Rotate B | Shift all elements of stack B up by 1. First becomes last. |
| **rr** | Rotate Both | `ra` and `rb` at the same time. |
| **rra** | Rev. Rotate A | Shift all elements of stack A down by 1. Last becomes first. |
| **rrb** | Rev. Rotate B | Shift all elements of stack B down by 1. Last becomes first. |
| **rrr** | Rev. Rotate Both | `rra` and `rrb` at the same time. |

## 📂 Project Structure

* **`src/1-validation.c`**: Input parsing, string-to-long conversion, and duplicate checking.
* **`src/2-stacking.c`**: Linked list initialization and node management.
* **`src/3-indexing.c`**: Assigning relative ranks/indices and calculating target positions (`ft_tindex`).
* **`src/4a-sorting.c`**: Main sorting controller and logic for small stacks (size 3).
* **`src/4b-tools.c`**: Heuristics calculators (`ft_clicker`), initial pushing logic (`ft_dartagnan`), and final stack arrangement.
* **`src/5-moving.c`**: Move execution logic, optimizing for double rotations (`rr`, `rrr`).
* **`src/checker_bonus.c`**: Validation program to test the output of `push_swap`.

## ⚠️ Key Performance Features
* **Cost Calculation:** Calculates `ABS(Rot_A) + ABS(Rot_B)` for every node to find the absolute minimum path.
* **Move Optimization:** Converts `ra + rb` into `rr` and `rra + rrb` into `rrr` to save instructions.
* **Memory Management:** Full cleanup of stacks and split arguments to prevent leaks (`ft_freee`).
