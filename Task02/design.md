# Task A2 – Runtime binding

- **Early binding:** the compiler selects a non-virtual function from the static type.
- **Late binding:** a virtual call through `Bill*` selects the final overrider for the object's dynamic type.
- In `b->show()`, `show()` is non-virtual but executes `total()`. Because `total()` is virtual, that inner call dispatches to `OPBill::total()`.

## Conceptual vtables
```text
Bill vtable:             OPBill vtable:           InPatientBill vtable:
[ destructor ]           [ OP destructor ]        [ IP destructor ]
[ total = pure ]         [ total = OP::total ]    [ total = IP::total ]
```
A typical object stores a hidden vptr referring to its class vtable. Exact ABI layout is compiler-specific; this is a conceptual model, not a mandated C++ memory layout.

A virtual base destructor ensures `delete basePointer` invokes the derived destructor and then the base destructor. Removing `virtual` makes deletion through a base pointer with a different dynamic type undefined behaviour; do not rely on a particular destructor output. AddressSanitizer may not diagnose every instance of this language-level error.

## Prediction (write before running)
For the supplied OPBill program:
```text
500 ~OPBill ~Bill
```
The trailing newline follows. `show()` calls virtual `total()`; deleting `b` invokes derived then base destructor.

Alternative with `dynamic_cast`: test each possible derived type and call its concrete method. For k types this may require up to k casts per bill, compared with one virtual dispatch. Both are O(1) for fixed k, but casts add branching and become harder to maintain. Typical polymorphic objects carry a vptr-sized overhead; exact size is ABI-dependent.
