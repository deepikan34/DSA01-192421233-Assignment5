# Task A5 – Recovery, catch and rethrow

Catch low in the system only when the layer can add useful context or recover. A service layer may log context and use `throw;` to preserve the original exception. The application boundary catches known exceptions and reports a clear message to the user; a final `catch(...)` can prevent an exception escaping the top-level boundary, while still reporting an unknown failure.

**Stack unwinding:** when an exception leaves a scope, automatic objects are destroyed in reverse construction order. RAII wrappers (`std::unique_ptr`, `std::vector`, file streams) release resources through destructors without requiring a separate delete in every catch block.

## Prediction for supplied Guard program
```text
~f ~main caught 42
```
`g` is destroyed as `f()` unwinds; then `m` is destroyed while leaving the try block; the matching `catch(int)` prints `caught 42`. `not printed` is skipped because control transfers immediately when `throw 42` executes.

Alternative manual cleanup: every catch/error return must release every acquired resource. Runtime cost is similar, but each new error path adds cleanup obligations and creates leak/double-free risk. RAII centralises cleanup in object lifetime.
