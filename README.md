# Word-Lists

Word-Lists is a command-driven tool for building, transforming, and analyzing collections of words from text files or interactive input, focused on deterministic, scriptable workflows.
It provides list operations such as loading, deduplication, set operations, sorting, statistics, and exporting, geared toward reproducible text processing pipelines.

## What it does
- Loads one or more text sources into in-memory word lists, normalizing tokens and supporting configurable transformations.
- Applies list operations like add, remove, unique, sort, merge, intersect, difference, and save/print for inspection or downstream use.
- Supports command files for batch processing and can be used interactively if invoked without an input filename.

## How to run
- Build
  - Using make:
    - make a1
  - Using g++ directly:
    - g++ -std=c++17 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g a1.cpp -o a1
- Execute
  - From a command file:
    - ./a1 commands.txt
  - Interactive (if supported by the build):
    - ./a1
    - Then enter commands one per line.

## Commands
- Data ingestion
  - LOAD name path/to/file.txt
  - ADD name token
  - CLEAR name
- Transformations
  - UNIQUE name
  - SORT name
  - LOWERCASE name
  - UPPERCASE name
- Set operations (write to dest)
  - MERGE a b dest
  - INTERSECT a b dest
  - DIFF a b dest
- Queries and output
  - PRINT name
  - SIZE name
  - SAVE name path/to/out.txt

## Input and output
- Input is a plain-text file with one command per line, or stdin when no filename is provided.
- Output is printed to stdout for queries like PRINT and SIZE; SAVE writes a normalized list to a file.
- Errors are reported for invalid commands or arguments.

## Data structures and algorithms
- Custom linked list for storage; optional hash sets for UNIQUE and set operations for expected linear time.
- INTERSECT/DIFF via hashed membership checks; MERGE concatenation or dedup-merge per semantics.
- Typical complexity: LOAD O(k), UNIQUE O(n), SORT O(n log n), PRINT/SAVE O(n).

## Implementation details
- C++17; portable CLI workflow.
- make or single-file compilation with strict warnings.
- Token-based command parsing with validation and robust error handling.
- RAII memory management; deterministic ordering semantics.

## Examples
- Example input
  - LOAD A data/words1.txt
  - LOAD B data/words2.txt
  - UNIQUE A
  - INTERSECT A B C
  - SORT C
  - SIZE C
  - PRINT C
  - SAVE C out/common_sorted.txt
- Example output
  - 742
  - [alpha, breadth, delta, epsilon, gamma, …]

## Build configuration
- make: target a1
- g++: g++ -std=c++17 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g a1.cpp -o a1