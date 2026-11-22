# Task A4 – Exception strategy

## Error catalogue and hierarchy
```text
std::exception
  └── std::runtime_error
       └── BillingError
            ├── InvalidChargeError
            ├── ClaimError
            ├── UnknownPackageError
            └── MissingPatientError
```
Negative charges → `InvalidChargeError`; claim exceeds policy → `ClaimError`; unknown scheme package → `UnknownPackageError`; absent patient → `MissingPatientError`; allocation failure → standard `std::bad_alloc`.

Functions that validate, parse, allocate or access records may throw. Destructors, cleanup functions and simple accessors should not throw; mark cleanup/accessors `noexcept` only when their operations truly cannot throw. Destructors should not throw because an exception escaping during stack unwinding can call `std::terminate`.

Alternative return-code design: return a `Status` plus output parameter/error message. Normal and error paths both return normally; callers must check every status and pass the message/status through each layer. Runtime work remains O(1) per validation; extra state/message storage and branching are needed. Exceptions separate uncommon error handling from the normal path but must be caught at appropriate boundaries.
