# Cross-task test plan

| ID | Input / condition | Expected behaviour |
|---|---|---|
| T01 | OP consultation 500, tests 1200 | Total 1700 |
| T02 | IP 3 days × 2500 + surgery 40000 | Total 47500 |
| T03 | Day-care fixed package 18000 | Total 18000 |
| T04 | Emergency base 2000 + 30 × 100 | Total 5000 |
| T05 | Negative charge | Invalid-charge exception |
| T06 | Claim exceeds cover | ClaimError; audit and rethrow |
| T07 | Unknown package | UnknownPackageError |
| T08 | Invalid numeric text with stod | std::invalid_argument |
| T09 | Missing patient record | MissingPatientError |
| T10 | Allocation failure | std::bad_alloc at allocation boundary |
| T11 | Exception through RAII scope | Destructors release local resources |
| T12 | New Telehealth bill + Corporate payer | Existing interface processes extensions |

The package safely tests representative normal and exception paths. Do not attempt an uncontrolled enormous allocation on a personal machine; use a bounded test allocator or a controlled allocation-failure test harness.
