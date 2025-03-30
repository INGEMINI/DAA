// The error is occurring because variables declared inside a case block must be inside their own scope (inside {} curly braces), or they will interfere with other cases.

// 🔴 Problem in Your Code
//     cpp
//         Copy
//             Edit case 4:
// cout << "enter value";
// cin >> val;
// string ss; // ❌ This is the issue (Declared inside case 4 but affects other cases)
// ss = (l.search(val) ? "found " : "not found");
// cout << ss;
// break;
// Why is this an issue ? The string ss;
// declaration is inside case 4, but before the break; statement.Since C++ treats switch as a jump table, case labels are just labels and don’t create new blocks{}.So, the compiler sees string ss; and then other cases jump over it, causing a "jump case label" error.


// String itself is not treated like a case, but the issue you’re facing happens because C++ switch does not create its own scope and variables inside a case statement need to be properly enclosed.