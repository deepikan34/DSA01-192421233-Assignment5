# Task A3 – Abstract payer interface

```text
             <<abstract>> Payer
       + amountCovered(const Bill&) : double = 0
              ▲          ▲             ▲
           SelfPay    Insurance   GovernmentScheme
                      -coverLimit   -package table
                      -copayRate
```
`SelfPay` covers zero (patient pays the full bill). `Insurance` calculates the covered amount subject to the policy limit and co-payment. `GovernmentScheme` uses a fixed rate for the bill category. A new `CorporatePayer : Payer` can be added and implement `amountCovered()` without modifying existing payer classes or the bill-processing loop (open/closed principle).

Alternative: store a function pointer or `std::function<double(const Bill&)>` per policy. Each invocation is O(1); the callable may capture policy data such as cover limit. Abstract classes group data and behaviour in a named type; `std::function` is flexible but may incur type-erasure/storage overhead. Both allow run-time selection.
