# B3 measurement instructions and interpretation

Build with optimisation as required: `g++ -std=c++17 -O2 -Wall -Wextra benchmark.cpp -o benchmark` and run `./benchmark 1000`, `./benchmark 1000000`, and `./benchmark 10000000`. Record each run in `measurements.csv` with CPU, OS, compiler, run count and median. Run `exception_benchmark` with 1,000,000 items to compare 0%, 1% and 50% invalid cases.

The supplied benchmark compares separate typed containers (no per-element virtual call; it is a compile-time/static-dispatch baseline), a tagged switch, and `std::variant` + `std::visit`. It is not a literal heap-allocated virtual-base-pointer benchmark; use the Task01 hierarchy and add a vector of `unique_ptr<Bill>` if your instructor expects that exact measurement. Cache, allocation, branch prediction and compiler optimisation affect timings. All approaches are O(n) total time and O(n) storage for n bills. `variant` element size is at least the largest alternative plus a discriminator/padding. Do not compare single noisy runs as definitive evidence.

| Approach | Extension | Heterogeneous list | Typical trade-off |
|---|---|---|---|
| Virtual | Add derived class | Natural through base pointers | Extensible interface; indirect call |
| Switch | Edit type + switch | Natural tagged records | Centralised dispatch; switch changes for new type |
| Variant | Add alternative + visitor cases | Natural variant vector | Closed set of types; visit dispatch |

Use exceptions for exceptional failures, not routine high-frequency validation failures. Use return codes/optional for expected invalid user input where rejection is a normal outcome.
