<font face="times new roman">
  
# ? Data-Structure in ![](https://img.shields.io/badge/C%2B%2B-blue?logo=c%2B%2B&logoColor=white)

Book : Fundamentals of Data Structures in C++ 2nd Edition

- Author:
  1. Ellis Horowitz
  2. Sartaj Sahni
  3. Dinesh Mehta

# Chapter 1 Basic Concepts

- **Data Abstraction** (<font face="標楷體">資料抽象化</font>) : Is the separation between the _specification_(<font face="標楷體">規範</font>) of data object and its _implementation_(<font face="標楷體">實現</font>).
- **Data Encapsulation** (<font face="標楷體">資料封裝</font>) : Is the concealing of the implementation details of a data object from the outside world.

- **Algorithm** : <font face="標楷體">有限指令構成的集合，解決某個特定問題。</font>
  1. **Input** : 0 or more quantities are externally supplied.
  2. **Output** : At least one quantity is produced.
  3. **Definiteness** (<font face="標楷體">明確性</font>) : Each instruction is clear and unambiguous.
  4. **Finiteness** (<font face="標楷體">有限性</font>) : If we trace out the instructions of an algorithm,then for all cases,the algorithm terminates.
  5. **Effectiveness**(<font face="標楷體">有效性</font>) : Every instruction must be basic enough to be carried out,in principle,by a person using only pencil and paper. It is enough that each operation be definite as in **Definiteness**;it also must be feasible.

* Recursive Algorithms : Algorithm (or program) <font face="標楷體">存在自我呼叫的敘述。</font>
* **Space Complexity** : The amount of memory it needs to run to completion.
  - def. _S_(_p_) = _c_ (a fixed part) + _S~p~_ (a variable part)
* **Time Complexity** : The amount of computer time it needs to run to completion.

  - def. _T_(_p_) = _c_ (compile time) + _T~p~_ (execution time)

* Asymptotic Notation (_O_、$\Omega$、$\Theta$)

  - **Definition [*Big "oh"*]**: _f_(_n_) = _O_(_g_(_n_)) if and only if there exist positive constants _c_ and _n_~0~ such that _f_(_n_) $\leq$ _cg_(_n_) for all _n_, _n_$\geq$ _n_~0~.

    1. 3*n* + 2 = _O_(_n_)

       - _f_(_n_) = 3*n* + 2, _g_(_n_) = _n_. when _c_ = 4 and _n_~0~ = 2, that 3*n* + 2 $\leq$ 4*n*, for all _n_ $\geq$ 2. so 3*n* + 2 = _O_(_n_).

    2. 3*n* + 3 = _O_(_n_)
       - _f_(_n_) = 3*n* + 3, _g_(_n_) = n,when _c_ = 4 and _n_~0~ = 3, that 3*n* + 3 $\leq$ 4*n*, for all _n_ $\geq$ 3. so 3*n* + 3 = _O_(_n_).

  * **Definition [Omega]**: _f_(_n_) = $\Omega$(_g_(_n_)) iff there exist positive constants _c_ and _n_~0~ such that _f_(_n_) $\geq$ _cg_(_n_) for all _n_, _n_$\geq$ _n_~0~.

  1. 3*n* + 2 = $\Omega$(_n_)

  - when _c_ = 3 and _n_~0~ = 1, that 3*n* + 2 $\geq$ 3*n*, for all _n_ $\geq$ 1. so 3*n* + 2 = $\Omega$(_n_).

  2. 10*n*^2^ + 4*n* + 2 = $\Omega$(_n_^2^)

  - when _c_ = 10 and _n_~0~ = 1, that 10*n*^2^ + 4*n* + 2 $\geq$ 10*n*^2^, for all _n_ $\geq$ 1 . so 10*n*^2^ + 4*n* + 2 = $\Omega$(_n_^2^)

  * **Definition [Theta]**: _f_(_n_) = $\Theta$(_g_(_n_)) iff there exist positive constants _c_~1~,_c_~2~ and _n_~0~ such that _c_~1~ _g_(_n_)$\leq$ _f_(_n_) $\leq$ _c_~2~ _g_(_n_) for all _n_, _n_$\geq$ _n_~0~.

  1. 3*n* + 2 = $\Theta$(n)

  - when _c_~1~ = 3, _c_~2~ = 4, _n_~0~ = 2, that 3*n* $\leq$ 3*n* + 2 $\leq$ 4*n*, for all _n_ $\geq$ 2. so 3*n* + 2 = $\Theta$(n).

  2. 10*n*^2^ + 4 _n_ + 2 = $\Theta$(_n_^2^)

  - when _c_~1~ = 10, _c_~2~ = 13 ,_n_~0~ = 2, that 10*n*^2^ $\leq$ 10*n*^2^ + 4 _n_ + 2 $\leq$ 13*n*^2^, for all _n_ $\geq$ _n_~0~. so 10*n*^2^ + 4 _n_ + 2 = $\Theta$(_n_^2^).

# Chapter 2 Arrays

- Array
- Polynomial
- Sparse Matrix
- String

# Chapter 3 Stacks and Queues

- Stack
- Queue
- Mazing Problem
- Evaluation of Expressions
  1. Postfix
  2. Infix
  3. Postfix

# Chapter 4 Linked Lists

- Singly Linked Lists
- Circular Lists
- Available Space Lists
- Doubly Linked Lists
- Generalized Lists

# Chapter 5 Trees

- Tree Traversal
  1. Inorder
  2. Preorder
  3. Postorder
- Binary Tree
- Threaded Binary Tree
- Heaps
- Binary Search Tree
- Selection Tree
- Forests
- Disjoint Sets
- Counting Binary Tree

# Chapter 6 Graphs

- Graph Representation
- Depth-First-Search
- Breadth-First-Search
- Minimum Cost Spanning Tree
- Shortest Paths and Transitive Closure
- Activity Networks

# Chapter 7 Sorting

- Insertion Sort
- Quick Sort
- Merge Sort
- Heap Sort
- List and Table Sort

</font>
