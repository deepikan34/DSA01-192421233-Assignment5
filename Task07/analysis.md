# B2 error engineering and predictions

## Prediction for `predict.cpp`
```text
ok done caught negative [log too large] caught too large
```
`100` passes validation; `-5` throws `invalid_argument`, which is not caught by the inner `out_of_range` handler, so it reaches the outer `std::exception` handler without being logged there. `2e6` throws `out_of_range`, is logged in `process`, then `throw;` rethrows the same exception to main.

## Claim program expected output
```text
approved 40000
audit: exceeds cover
claim rejected: exceeds cover
error: negative amount
```
`throw;` rethrows the currently handled exception unchanged. `throw e;` creates a new exception object based on the static type of `e`; when caught as a base reference this can slice derived-type information. `std::optional<double>` avoids exceptions for expected rejection; check `has_value()`. Both do O(1) work per claim; optional stores a value/presence state per result, while exceptions have runtime-dependent handling cost and are best for exceptional conditions.

For 1,000,000 claims, test invalid ratios 0%, 1%, 50% using the included benchmark in Task08. Do not invent timings: record the values produced on your own hardware.

A forced `bad_alloc` test is intentionally not included as an actual huge allocation because it can destabilise the machine. The standard exception type is `std::bad_alloc`; a safe demonstration can use a deliberately bounded allocator/test seam. Text passed to `std::stod` that is not numeric throws `std::invalid_argument`.
