# Plan
## Long Term
- ~~Fix B+Tree object deletion~~ 
- ~~Implement Select~~
- ~~Fix Table Insertion~~
- Clean Code
- Record deletion algorithm
- Joins
- Persistant Storage
## Immediate
- ~~Fix B+Tee Object Deletion~~
    - ~~Allocate Nodes to the Heap~~
    - ~~Implement Destruction~~
- ~~Implement Select~~
    - ~~Simple Select~~
    - ~~Select specified attributes~~
    - ~~Check valid specified attributes~~
    - ~~Bug: If user inputs the same attribute multiple times there is undefined behavior~~
    - ~~where clause~~
- ~~Fix table insertion~~
    - ~~Strings aren't inserted in the correct way~~
    - ~~Currently can't handle doubles~~
    - ~~Catch situations where user inputs an integer when db expects string~~