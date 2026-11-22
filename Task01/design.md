# Task A1 – Design the polymorphic Bill hierarchy

## Common interface and shared data
Every bill exposes `total()`, `type()` and `print()`. Shared data: patient identifier/name and a bill/reference number (the example implementation stores the patient name). `total()` is pure virtual because the calculation differs by bill type.

## UML (text form)
```text
                 <<abstract>> Bill
        ---------------------------------
        # patient : string
        + Bill(patient)
        + virtual ~Bill()
        + virtual total() const : double = 0
        + virtual type() const : string
        + print() const
                    ▲
       ┌────────────┼──────────────┐
       │            │              │
 OutPatientBill InPatientBill DayCareBill EmergencyBill
 -consultation  -days, rate    -package     -base, minutes
 -tests         -procedure     -medicines   -rate/minute
 +total()       +total()       +total()     +total()
```

`total()` and destructor are virtual; `total()` is pure virtual in Bill and overridden in each concrete class. `type()` is virtual and may have a base implementation. `print()` is non-virtual and calls virtual functions.

## SIMATS-style pseudocode – total all bills
```text
ALGORITHM CalculateDayTotal(Bills, n)
BEGIN
    SET dayTotal ← 0
    FOR i ← 0 TO n - 1 DO
        IF Bills[i] IS NOT NULL THEN
            dayTotal ← dayTotal + Bills[i].total()
        END IF
    END FOR
    DISPLAY dayTotal
    RETURN dayTotal
END
```

## Alternative: one structure and switch
Store a `type` tag and all possible fields in one structure. `total()` uses `switch(type)` to select the formula. Both approaches take O(n) time to total n bills. A tagged structure can waste space because it reserves fields for all bill types; polymorphic objects store only relevant derived fields plus implementation overhead (commonly a vptr). Adding a type requires editing the switch and the structure; adding a derived class usually leaves existing bill classes and processing loop unchanged.
