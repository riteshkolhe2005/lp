// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract StudentManager {
    
    // 1. STRUCTURE: Defining the Student data type
    struct Student {
        uint id;
        string name;
        uint age;
    }

    // 2. ARRAY: Creating an array to hold multiple Student structs
    Student[] public students;
    
    // A variable to track the total number of students added
    uint public studentCount;

    // Function to add a new student to the array
    function addStudent(string memory _name, uint _age) public {
        studentCount++;
        // Creating a new Student struct and pushing it into the array
        students.push(Student(studentCount, _name, _age));
    }

    // Function to retrieve a student's details by their index in the array
    function getStudent(uint _index) public view returns (uint, string memory, uint) {
        require(_index < students.length, "Student does not exist");
        Student memory s = students[_index];
        return (s.id, s.name, s.age);
    }

    // 3. FALLBACK: A function that executes when a non-existent function is called 
    // or when Ether is sent without any data.
    fallback() external payable {
        // You can add logic here. For this example, we just leave it empty 
        // to accept the Ether, or you could revert to block it.
    }

    // Optional: Receive function (modern alternative to fallback for plain Ether transfers)
    receive() external payable {}
}

/*
===============================================================================
ADDED EXPLANATION AND EXTERNAL VIVA NOTES
The contract above is preserved exactly as uploaded. Only this comment block
has been appended; no Solidity statement, variable, function, or logic changed.
===============================================================================

1. PROGRAM PURPOSE
------------------
This is a simple Solidity smart contract named StudentManager. It stores
student records on the blockchain. Each record contains an ID, name, and age.
A user can add a student and retrieve a student using the array index.
The contract also defines payable fallback and receive functions to accept
Ether under different call conditions.

2. LINE-BY-LINE EXPLANATION
---------------------------

// SPDX-License-Identifier: MIT
- Declares the source-code license identifier.
- MIT is a permissive open-source license.
- SPDX identifiers help tools and users identify the license.

pragma solidity ^0.8.0;
- Specifies the Solidity compiler version range.
- The caret means compiler versions from 0.8.0 up to, but not including,
  0.9.0 are allowed.
- Solidity 0.8.x checks arithmetic overflow and underflow by default.

contract StudentManager {
- Declares a smart contract named StudentManager.
- A contract is similar to a class: it groups data and functions.
- After deployment, the contract receives an address on the blockchain.

struct Student {
- Defines a custom data type called Student.
- A struct groups multiple related fields into one record.

uint id;
- Stores the student's numeric ID.
- uint is an unsigned integer; uint is an alias for uint256 by default.

string name;
- Stores the student's name as text.

uint age;
- Stores the student's age as an unsigned integer.

Student[] public students;
- Declares a dynamic array containing Student records.
- Dynamic means its length can grow while the contract runs.
- The public visibility automatically creates a getter function.
- The generated getter can return a record's fields for a valid array index.
- The array is a state variable, so its contents persist in contract storage.

uint public studentCount;
- Stores the total number of records added through addStudent.
- public automatically creates a getter named studentCount().
- It starts at zero because Solidity initializes an unassigned uint state
  variable to its default value, zero.

function addStudent(string memory _name, uint _age) public {
- Declares a function that adds a student record.
- public means it can be called from outside the contract and internally.
- _name is the supplied student name.
- memory means the string parameter is temporary during this function call;
  it is not itself a permanent state variable.
- _age is the supplied age.

studentCount++;
- Increments the number of students by one.
- The incremented value is used as the new student's ID.
- Solidity 0.8.x reverts if this arithmetic operation overflows.

students.push(Student(studentCount, _name, _age));
- Creates a Student struct using the current count, name, and age.
- push appends this struct to the end of the dynamic students array.
- The new record is written to the contract's persistent storage.

function getStudent(uint _index) public view returns
    (uint, string memory, uint) {
- Declares a function to retrieve a student by array index.
- _index identifies the position in the students array.
- view states that this function reads contract state but does not modify it.
- returns declares the three returned values: ID, name, and age.
- string memory means the returned string is provided in memory for the call.

require(_index < students.length, "Student does not exist");
- Checks that the requested index is within the array bounds.
- Valid indexes range from zero to students.length - 1.
- If the condition is false, execution reverts and returns the error message.
- A failed require also rolls back state changes made in that call.

Student memory s = students[_index];
- Reads the selected Student record from storage into a memory variable s.
- memory is temporary for the duration of the call.
- This function only needs to read the record, so it does not update storage.

return (s.id, s.name, s.age);
- Returns the selected student's ID, name, and age as a tuple.

fallback() external payable {
- Declares the fallback function.
- fallback is called when a call does not match any function in the contract,
  subject to Solidity's fallback/receive dispatch rules.
- external means it is intended to be called from an external call.
- payable allows the function to receive Ether.
- In this contract, the body is empty, so it accepts the qualifying call
  without performing additional work.

receive() external payable {}
- Declares the receive Ether function.
- It is called when the contract receives a plain Ether transfer with empty
  calldata, provided receive() exists and is payable.
- Because this contract defines receive(), a plain Ether transfer normally
  invokes receive(), not fallback().
- Its body is empty, so it accepts the Ether without recording sender,
  amount, or emitting an event.

}
- Ends the contract definition.

3. COMPLETE PROGRAM LOGIC (HOW TO EXPLAIN TO THE EXTERNAL)
---------------------------------------------------------
"This Solidity program demonstrates how to create and manage student records
using a smart contract.

First, I define a Student structure containing three fields: ID, name, and age.
Then I create a public dynamic array to store multiple Student records and a
counter to keep track of how many students have been added.

When addStudent is called, the contract increments studentCount and pushes a
new Student structure into the array. The incremented count is used as the
student's ID.

To read a record, getStudent accepts an array index. It first uses require to
check that the index exists. If the index is invalid, the transaction or call
reverts with the message 'Student does not exist'. Otherwise, it copies the
record into memory and returns the ID, name, and age.

The contract also has a payable receive function for plain Ether transfers
with empty calldata, and a payable fallback function for calls that do not
match a defined function. Both bodies are empty in this example."

4. IMPORTANT SOLIDITY CONCEPTS
------------------------------

A. Smart contract
A program deployed on a blockchain and executed by the Ethereum Virtual
Machine (EVM). Its state and functions are accessed through its contract
address.

B. Solidity
A high-level, statically typed language used to write smart contracts for
the Ethereum Virtual Machine and compatible environments.

C. Contract
A Solidity unit that contains state variables, structures, events, modifiers,
and functions. StudentManager is the contract in this program.

D. Struct
A user-defined composite data type that groups related fields. Student groups
id, name, and age.

E. Dynamic array
An array whose length can change. students.push(...) appends another record.

F. State variable and storage
students and studentCount are state variables. Their values persist in the
contract's storage between transactions.

G. memory
A temporary data location used while a function executes. The local variable
s and the string parameter/return data use memory in this code.

H. Visibility
public allows external callers to call a function or read a public state
variable through its generated getter. external marks functions intended for
external calls. The code does not declare private or internal members.

I. view function
A function marked view can read state but cannot modify it. getStudent is view.
A view call made off-chain is generally executed as a read-only call and does
not require a state-changing transaction.

J. require()
Checks a condition. If false, execution reverts. It is commonly used for input
validation and access/condition checks.

K. fallback and receive
receive() handles plain Ether transfers with empty calldata. fallback() handles
calls that do not match a function; it can also accept Ether when payable.
When receive() is present, plain Ether transfers with empty calldata go to
receive() rather than fallback().

L. payable
A function marked payable is permitted to receive Ether. Without payable, a
function cannot accept Ether as part of the call.

M. EVM
The Ethereum Virtual Machine executes smart-contract bytecode.

N. Gas
Gas measures the computational work required by EVM operations. State-changing
transactions consume gas, and the sender pays the transaction fee.

O. Transaction versus read call
addStudent changes blockchain state and must be sent as a transaction when
called on a deployed contract. getStudent is view and can normally be called
as a read-only call without sending a state-changing transaction.

5. EXPECTED EXTERNAL VIVA QUESTIONS WITH ANSWERS
------------------------------------------------

Q1. What is Solidity?
Ans. Solidity is a high-level, statically typed programming language used to
write smart contracts that run on the Ethereum Virtual Machine.

Q2. What is a smart contract?
Ans. A smart contract is code deployed on a blockchain that executes according
to its programmed rules.

Q3. What is the name of this contract?
Ans. StudentManager.

Q4. What is the purpose of this program?
Ans. To add student records to a blockchain-based array and retrieve them by
index.

Q5. What is a struct?
Ans. A struct is a user-defined type that groups related variables. Here,
Student groups id, name, and age.

Q6. Why is a struct used here?
Ans. It keeps the details of one student together as a single record.

Q7. What is an array?
Ans. An array is a collection of elements of the same declared type.

Q8. What is a dynamic array?
Ans. A dynamic array can grow or shrink in length. The students array is dynamic.

Q9. What does students.push() do?
Ans. It appends a new Student record to the end of the students array.

Q10. What is a state variable?
Ans. A variable declared at contract level whose value is stored persistently
in the contract's blockchain state.

Q11. Which variables are state variables in this program?
Ans. students and studentCount.

Q12. What does uint mean?
Ans. It is an unsigned integer type. uint is shorthand for uint256.

Q13. What is the default value of an uninitialized uint state variable?
Ans. Zero.

Q14. What is the purpose of studentCount?
Ans. It tracks the number of students added and is also used to assign IDs.

Q15. Why is studentCount incremented before push()?
Ans. So the first student's ID is 1 rather than 0, and each later student gets
the next sequential ID.

Q16. Does the array index equal the student ID?
Ans. In this implementation, the ID is index + 1, because array indexes start
at zero while studentCount starts at one for the first record.

Q17. What does public mean?
Ans. It allows a function or state variable to be accessed externally. Public
state variables also receive automatically generated getter functions.

Q18. What getter is created for studentCount?
Ans. A getter named studentCount() is generated automatically.

Q19. Does public students generate a getter?
Ans. Yes. Solidity generates an indexed getter for the public array, returning
the struct's accessible fields for a given index.

Q20. What is the purpose of addStudent()?
Ans. It increments the student counter and appends a new student record.

Q21. What does memory mean?
Ans. It is a temporary data location used during function execution. Its data
does not persist as contract storage after the call ends.

Q22. What is storage?
Ans. Storage is the persistent data area of a smart contract. State variables
such as students and studentCount are stored there.

Q23. What is the difference between memory and storage?
Ans. memory is temporary for a call; storage persists as part of the contract
state.

Q24. What is the purpose of getStudent()?
Ans. It returns the ID, name, and age for the student at a given array index.

Q25. Why is getStudent() marked view?
Ans. It only reads contract state and does not modify it.

Q26. What does returns (uint, string memory, uint) mean?
Ans. The function returns three values: a uint ID, a string name, and a uint age.

Q27. What is require() used for?
Ans. It checks a condition and reverts execution if the condition is false.

Q28. What happens if an invalid index is passed to getStudent()?
Ans. require fails, the call reverts, and the error message is
'Student does not exist'.

Q29. What is an array index?
Ans. It is the zero-based position of an element in an array.

Q30. What is the first valid index in students?
Ans. Zero, provided at least one student has been added.

Q31. What is fallback()?
Ans. It is a special function called when a message call does not match a
function in the contract; it can be payable to accept Ether.

Q32. What is receive()?
Ans. It is a special payable function called when the contract receives plain
Ether with empty calldata.

Q33. What is the difference between fallback() and receive()?
Ans. receive() is selected for empty-calldata Ether transfers. fallback() is
selected for unmatched calls and can accept Ether if declared payable.

Q34. If plain Ether is sent to this contract, which function is called?
Ans. receive(), because the contract defines a payable receive function.

Q35. Why is fallback() marked payable?
Ans. So it can accept Ether when it is selected for a call with value.

Q36. What does external mean?
Ans. The function is exposed for calls from outside the contract. External
functions can be invoked by transactions or other contracts.

Q37. What does payable mean?
Ans. It allows a function to receive Ether along with the call.

Q38. What is the EVM?
Ans. The Ethereum Virtual Machine is the execution environment for Ethereum
smart-contract bytecode.

Q39. What is gas?
Ans. Gas is the unit used to measure the computational work of EVM execution.
Transactions that change state require gas.

Q40. Does getStudent() change blockchain data?
Ans. No. It is marked view and only reads the stored record.

Q41. Does addStudent() change blockchain data?
Ans. Yes. It changes studentCount and the students array, so it requires a
state-changing transaction on a deployed contract.

Q42. Is this contract restricted to an administrator?
Ans. No. There is no owner check or access-control modifier. Any account that
can call the deployed contract can call addStudent().

Q43. Does this contract validate the age?
Ans. No. The current code accepts any uint value as age; it does not check a
minimum or maximum age.

Q44. Is studentCount guaranteed to equal students.length?
Ans. Under the current addStudent function, both increase together. The contract
has no function that removes array entries, so they remain equal when records
are added only through this implementation.

Q45. Can two students have the same name?
Ans. Yes. The contract does not check for duplicate names.

Q46. Can two students receive the same ID through addStudent()?
Ans. Not during normal successful calls to this function, because the counter
is incremented for each new record.

Q47. What happens if studentCount overflows?
Ans. In Solidity 0.8.x arithmetic overflow is checked by default, so the
increment reverts rather than silently wrapping around.

Q48. What is a transaction?
Ans. A signed operation submitted to the blockchain. A state-changing call
such as addStudent() is executed as a transaction.

Q49. What is a contract address?
Ans. It is the blockchain address at which a deployed smart contract can be
accessed.

Q50. Can this contract store Ether?
Ans. Yes. Its payable receive() and fallback() functions allow it to receive
Ether under their respective call conditions.

Q51. Is there a function to withdraw the Ether?
Ans. No. The uploaded contract has no withdrawal function, so Ether sent to it
cannot be withdrawn through the functions currently provided.

Q52. Does the fallback function record who sent Ether?
Ans. No. Its body is empty and it does not store the sender or amount.

Q53. What is the purpose of the SPDX line?
Ans. It identifies the source-code license, here MIT.

Q54. What is the purpose of pragma?
Ans. It specifies the compiler version range compatible with the source file.

Q55. What is the difference between a contract and a struct?
Ans. A contract contains executable functions and state. A struct is a custom
data type used to group fields into a record.

Q56. Why does getStudent copy the array element into memory?
Ans. It creates a temporary local copy so the fields can be returned without
modifying the stored Student record.

Q57. What is a tuple return value?
Ans. It is a return containing multiple values together. getStudent returns
three values as a tuple.

Q58. What happens when require fails?
Ans. The current call reverts. Any state changes made in that call are rolled
back, and the supplied revert reason is returned where supported.

Q59. What is one limitation of this example?
Ans. It has no access control, age validation, duplicate checking, update or
delete function, event logging, or Ether withdrawal function.

Q60. How could the contract be improved?
Ans. Add input validation, access control if only an administrator should add
records, events for record creation, update/delete rules if required, and a
carefully designed Ether management policy. Any Ether withdrawal feature
should be designed with security checks.

6. SAMPLE INPUT / TEST DATA AND EXPECTED RESULTS
------------------------------------------------
Solidity contracts do not read keyboard input using Scanner or input(). You
interact with a deployed contract through a wallet, Remix, a test script, or
another contract. The values below are function arguments to enter in Remix.

Test 1: Add the first student
Function: addStudent
Arguments:
  _name = "Ritesh"
  _age  = 21
Expected effect:
  studentCount becomes 1
  students[0] becomes (id: 1, name: "Ritesh", age: 21)

Test 2: Add another student
Function: addStudent
Arguments:
  _name = "Amit"
  _age  = 22
Expected effect:
  studentCount becomes 2
  students[1] becomes (id: 2, name: "Amit", age: 22)

Test 3: Retrieve the first student
Function: getStudent
Argument:
  _index = 0
Expected returned values:
  1, "Ritesh", 21

Test 4: Retrieve the second student
Function: getStudent
Argument:
  _index = 1
Expected returned values:
  2, "Amit", 22

Test 5: Try an invalid index
Function: getStudent
Argument:
  _index = 2
Expected result:
  The call reverts with "Student does not exist" because the array has
  indexes 0 and 1 only.

Note: The array index is zero-based, but the IDs assigned by this contract
start at one.

7. HOW TO COMPILE AND DEPLOY ON WINDOWS AND LINUX
-------------------------------------------------
IMPORTANT: A Solidity file is not run directly like a Java, C++, or Python
program. It must be compiled to EVM bytecode and deployed to an EVM-compatible
blockchain or a local development environment. Then you call its functions.

EASIEST METHOD — REMIX IDE (WINDOWS AND LINUX)
1. Open https://remix.ethereum.org in a browser.
2. Create a file named StudentManager.sol.
3. Paste the original contract source from this file (the part above this
   added explanation block) into Remix.
4. Open the Solidity Compiler tab.
5. Select a compiler version 0.8.x, for example 0.8.20, because the pragma is
   ^0.8.0.
6. Click Compile StudentManager.sol.
7. Open Deploy & Run Transactions.
8. Select Remix VM as the environment and click Deploy.
9. Expand the deployed StudentManager contract.
10. Use addStudent with "Ritesh" and 21.
11. Call studentCount() and getStudent(0) to inspect the result.
12. Try getStudent(1) after adding a second student.

COMMAND-LINE COMPILATION — WINDOWS (PowerShell or CMD)
Prerequisite: Install Node.js and npm. Then install the Solidity compiler
package in the project directory:

  npm init -y
  npm install --save-dev solc

Compile the file (assuming it is named StudentManager.sol):

  npx solcjs --bin --abi .\StudentManager.sol -o .\build

LINUX (Ubuntu / Debian)
Prerequisite: Install Node.js and npm, then in the project directory run:

  sudo apt update
  sudo apt install nodejs npm
  npm init -y
  npm install --save-dev solc

Compile the file:

  npx solcjs --bin --abi ./StudentManager.sol -o ./build

To check the installed compiler package version on either operating system:

  npx solcjs --version

The build directory contains compiled contract bytecode and ABI files. These
artifacts are used by deployment tools or scripts. Compilation alone does not
deploy the contract. For a beginner-friendly interactive deployment and test,
use Remix as described above.

8. QUICK REVISION BEFORE VIVA
-----------------------------
Contract name       : StudentManager
Language            : Solidity
Compiler pragma     : ^0.8.0
Main data type      : struct Student
Collection          : Student[] public students
Counter             : uint public studentCount
Add function        : addStudent(string memory, uint)
Read function       : getStudent(uint) — view
Validation          : require(_index < students.length, ...)
Ether functions     : fallback() external payable; receive() external payable
First student ID    : 1
First array index   : 0

MOST IMPORTANT POINTS TO SAY:
1. A struct groups a student's ID, name, and age.
2. The dynamic array stores all student records.
3. addStudent increments the counter and pushes a new struct into the array.
4. getStudent checks the index with require before returning the record.
5. getStudent is view because it only reads state.
6. receive handles plain Ether transfers with empty calldata; fallback handles
   unmatched calls. In this contract, plain Ether goes to receive().
7. This contract has no access control and no Ether withdrawal function.

END OF ADDED EXPLANATION AND VIVA NOTES
===============================================================================
*/
