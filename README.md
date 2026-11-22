# DSA01-192421233-Assignment5

**Student:** N. Deepika  
**Register Number:** 192421233  
**Course:** DSA01 – CO5  
**Assignment:** Assignment 5 – Reliable Software with Runtime Polymorphism and Exceptions

## Compiler
- Tested compiler: `g++ (Debian 14.2.0)`
- Language standard: C++17
- Standard build command: `g++ -std=c++17 -Wall -Wextra source.cpp -o program`
- Sanitizer command: `g++ -std=c++17 -Wall -Wextra -fsanitize=address -fno-omit-frame-pointer source.cpp -o program`
- Optimized benchmark command: `g++ -std=c++17 -O2 -Wall -Wextra benchmark.cpp -o benchmark`

## Run
From a task folder, compile and run, for example:
```bash
g++ -std=c++17 -Wall -Wextra main.cpp -o main
./main
```
On Windows PowerShell, run ` .\main.exe ` after compilation.

## Task map
| Folder | Coverage | Main result |
|---|---|---|
| Task01 | A1 – Bill hierarchy | Abstract Bill interface and polymorphic day total |
| Task02 | A2 – Runtime binding | Early/late binding, vtable concept, virtual destructor and prediction |
| Task03 | A3 – Payer hierarchy | SelfPay, Insurance, GovernmentScheme and extension |
| Task04 | A4 – Exception strategy | Billing exception hierarchy and noexcept decisions |
| Task05 | A5 – Recovery/rethrow | Catch locations, RAII, stack unwinding and prediction |
| Task06 | B1 – Polymorphic billing | Completed TODO program and validation tests |
| Task07 | B2 – Error conditions | Validation, bad input, claim errors and rethrowing |
| Task08 | B3 – Cost investigation | Virtual vs switch vs variant and exception benchmark harness |
| Task09 | B4 – Engineering decision | New bill/payer extension and sanitizer-ready integration demo |

Each task folder contains source code, a `results/` text record and a terminal-style PNG screenshot generated from the captured program output. These are reproducible starter evidence; rerun the programs on your own computer and replace/add screenshots from your own VS Code terminal before submission. Timings vary by hardware and must be measured on your machine.

## GitHub submission
Create a repository named `DSA01-192421233-Assignment5`, then:
```bash
git init
git add .
git commit -m "Add assignment structure and design tasks"
```
Continue with at least one separate commit per task folder, for example:
```bash
git add Task01 && git commit -m "Complete Task 01 bill hierarchy"
```
Repeat for Task02 through Task09. Add the repository URL to the assignment cover page and submit it through Google Classroom.

## Important academic note
Use this package as a working learning draft. Read and understand each program, verify the predictions and measurements on your own compiler, and personalise the explanations with your own observations before submission/viva. Do not claim that a remote GitHub repository was created or pushed by this ZIP; repository creation and commits must be done from your GitHub account.
