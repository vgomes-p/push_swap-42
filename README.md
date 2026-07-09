This project has been created as part
of the 42 curriculum by danda-si, vigomes-
# Push_swap (because Swap_push doesn’t feel as natural)

<!-- Description -->
## DESCRIPTION
A “Description” section that clearly presents the project, including its goal and a brief overview.

## INTRODUCTION
<!-- Instructions -->
An “Instructions” section containing any relevant information about compilation, installation, and/or execution.

## HOW TO TEST
```bash
shuf -i 0-9999 -n 500 > args.txt ; ./push_swap --bench $(cat args.txt) 2> bench.txt | cat bench.txt
```

```bash
ARG="4 67 3 87 23"; ./push_swap --bench --adaptive $ARG 2> bench.txt | cat bench.txt
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

## ALGORITHMS CHOISES
<!-- Algorithms selection explanation and justification -->
A detailed explanation and justification of the algorithms selected for this project must also be included.

# RESOURCES
<!-- Resources -->
[`Acelera 42`](https://rodsmade.notion.site/Acelera-Push_swap-083ab844f9b44456a176e4e4c875bc73)
[`Trello | Kanban`](https://trello.com/b/ah0lgJDc/pushswap)
[`Miro`](https://miro.com/app/board/uXjVHNAdLmE=/?share_link_id=47446866977)
[`AI`](temp.temp)

### AI prompts
#### Prompt used to ...
```txt
```