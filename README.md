This project has been created as part
of the 42 curriculum by danda-si, vigomes-
![push_swap-cover](src/cover-push_swap.png)
# Push_swap (because Swap_push doesn’t feel as natural)
This project involves sorting data on a stack, with a limited set of instructions, and using the smallest number of moves. To succeed, you will have to manipulate various sorting algorithms and choose the most appropriate solution(s) for optimized data sorting.

<!-- Description -->
## DESCRIPTION
The `push_swap` is a program than aims to sort a stack of intergers ascending using as minimal number of operations as possible (program efficiency is the very first challange from this project).
### 1. Implementations
The implementation follows a hybrid approach, users can chose which level of sorting they want to user (`simple`, `medium` or `complex`) or the program will select which algorithm is more appropriated according with the stack size and disorder level.

### 2. Algorithms
The program relies on three sorting algorithms groups, **O(n²)**, **O(n√n)** and **O(n log n)**, which will be called according with the stack disorder (_< 20%_, _< 50%_ and _> 50%_).

### 3. Selector
Indeed, there is a forth algorithm, that is the `ds_global_calculator()`, which is called by the `selector()` to determine which algorithm will sort the stack. The _selector system_ will also check the stack size to determine is a algorithm should be forced or not.

### 4. Benchmark
The _benchmark system_ is responsible to count how many time each operation were called by the algorithms. If called during the execution, it will display the summary of operations and how much operations were made to sort the stack.

### 5. Flags
`--bench`: Shows how many operations were made, which strategy were chosen and how many calls each operation had

`--simple`: Forces to run the algorithm O(n²)

`--medium`: Forces to run the algorithm O(n√n)

`--complex`: Forces to run the algorithm O(n log n)

`--adaptive`:  Will chose the algorithm according with the stack disorder level

### 6. Return
We decided to return how many operations `push_swap` made. If the program returns **_-1_**, it means that the program failed at some point.

![push_swap-approve_at_intra](src/approved.png)

## Requirements

- CC or Clang compiler
- GNU Make
- Linux or any POSIX-compliant operating system

## INTRODUCTION | How to use?
### Simple Usage
#### S.1 - Clone this repository
```bash
git clone https://github.com/vgomes-p/push_swap-42.git
```

#### S.2 - Navigate to the project directory
```bash
cd push_swap-42/project/
```

#### S.3 - Compile the program
```bash
make
```
> Run `make norm` if you want to check norminette return

#### S.4 - Call the program
```bash
./push_swap 5 4 3 2 1
echo $?
```
you can run the flags `--simple`, `--medium`, `--complex`, `--adaptive` and `--bench`
`*Here are some other test you can make:*`
```bash
shuf -i 0-9999 -n 500 > args.txt ; ./push_swap --bench $(cat args.txt) 2> bench.txt && cat bench.txt
```

```bash
ARG="4 67 3 87 23"; ./push_swap --bench --adaptive $ARG 2> bench.txt & cat bench.txt
```

```bash
./push_swap 2 1 3 6 5 8 | ./checker_linux 2 1 3 6 5 8
```

```bash
./push_swap --simple 2 1 3 6 5 8 | ./checker_linux 2 1 3 6 5 8
```

```bash
./push_swap --medium 2 1 3 6 5 8 | ./checker_linux 2 1 3 6 5 8
```

```bash
./push_swap --complex 2 1 3 6 5 8 | ./checker_linux 2 1 3 6 5 8
```
### Visual Usage
#### V.1 - Follow all the intructions from _Simple Useage_
> No need to call the program

#### V.2 - Set the enviroment (ZSH being used as example)
Get into the file
```bash
nano ~/.zshrc
```
Pass the following code block into you shell enviroment setting file
```bash
alias push_swapVisualizer="git clone https://github.com/o-reo/push_swap_visualizer.git psv & cd psv & mkdir build & cd build && cmake .. & make & ./bin/visualizer"
alias push_swapVisualizerClean="rm -rf psv
```
Update the shell
```bash
source ~/.zshrc
```

#### V.3 - Call the visualize from the root of the _project_ directory (the directory where Makefile is `~/push_swap-42/project/`
```bash
push_swapVisualizer
```
> wait it to be created, if you have any doubt, check the [visualizer manual](https://github.com/o-reo/push_swap_visualizer#)

#### V.4 - Clean the testing enviroment
```
push_swapVisualizerClean
make fclean
```

## ALGORITHMS CHOISES
<!-- Algorithms selection explanation and justification -->
A detailed explanation and justification of the algorithms selected for this project must also be included.
### O(n²) | Own Sort
For `O(n²)` I've chosen to try to implement a sort algorithm by myself. The algorithm search for the lower index in the stack A, rotate it to the top of the stack and then push it to the stack B. After pushing everything, B will already have the stack sorted, but descending, so the algorithm start to push everything to A again. But if the stack A get sorted during pushing to B, it will stop pushing to B and start push to A. If the top integer of A minus one is egual to the next value, it will swap both
```c
if ((*a)->next && (*a)->index == (*a)->next->index + 1)
			alg_exec_sa(a, bench, count);
```

### O(n√n) | Chunk Sort
The _Chunk Sort_ devides the stack into small index ranges (aka chunks) and moves each chunk from stack A to stack B before rebuilding the sorted stack. It search for the integers inside the actual chunk, rotate them to the top of stack A, push them to B and, if the integer is smaller or equal to the middle of the chunk, it rotate it to the bottom of B. After pushing everything to B, it start to rotate B when necessary and pushing to A to rebuild the stack sorted.

### O(n log n) | Radix Sort
The _Radix Sort_ sorts elements by examining their binary representation one bit at a bit by bitwise to decide rather the integer should be pushed to B or rotate to the bottom of A until it runs the most significant bit (msb) times. But if A get sorted before getting to the msb, it will stop rotating and pushing to b and start to push evarything from B to A.

### Adaptive | Selector
Adaptive uses the `ds_global_calculator()` to chose which of the sorting algorithm will sort the stack by following the fixed rule:

- Disorder smaller than 20% uses **O(n²) | Own Sort**
- Disorder bigger than 20% and smaller than 50% uses **O(n√n) | Chunk Sort**
- Disorder bigger than 50% uses **O(n log n) | Radix Sort**

But _if the stack size is smaller or equal to 5, it will force to run **O(n²)**_.
```c
static void	slc_adaptive(t_selector *slc, double disorder, t_stack *stack)
{
	if (stack_size(stack) <= 5)
		slc_filler(slc, 3, disorder, "Adaptive");
	(...)
}

static void	slc_filler(t_selector *slc, int id, double disorder, char *flag)
{
	(...)
	else if (id == 3)
	{
		strategy = ft_strjoin(flag, " / Stack smaller than 5 | Forced O(n²)");
		id = 0;
	}
	(...)
}
```
This is an additional rule we made because no other algorithm is as efficient as O(n²) to sort small stacks. This way we follow the rules determined by 42 and still get the most efficient sorting choice.
> One option was setting 25 as parameter to force O(n²), but we decided to keep 5 as parameter for now

# RESOURCES
<!-- Resources -->
[`Acelera 42`](https://rodsmade.notion.site/Acelera-Push_swap-083ab844f9b44456a176e4e4c875bc73)
[`Trello | Kanban`](https://trello.com/b/ah0lgJDc/pushswap)
[`Miro`](https://miro.com/app/board/uXjVHNAdLmE=/?share_link_id=47446866977)
