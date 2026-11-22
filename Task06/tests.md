# B1 validation

| Test | Input | Hand calculation | Expected |
|---|---|---|---|
| OP | consultation=500, tests=1200 | 500+1200 | 1700 |
| IP | days=3, perDay=2500, surgery=40000 | 3×2500+40000 | 47500 |
| Combined | both bills | 1700+47500 | 49200 |

Removing `virtual` from `total()` makes the base declaration non-virtual; in this exact sample the base declaration is pure virtual, so the program cannot use virtual dispatch to call the derived override and the source becomes ill-formed if the pure virtual is removed/changed inconsistently. A non-virtual base call resolves using static type; a base pointer cannot dynamically select the derived calculation. Removing the virtual destructor and deleting a derived object through `Bill*` causes undefined behaviour.

Template alternative: use a template function/container per concrete bill type. It avoids virtual dispatch and is generally O(1) per total, but separate containers are needed; a single heterogeneous collection requires a variant/type-erasure/other common representation.
