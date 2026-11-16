
// SPDX-License-Identifier: MIT
pragma solidity ^0.8.20;


// Bank account: Deposit Ether, withdraw Ether, and show balance.
contract Bank
{
    // Stores the Ether balance for each wallet address.
    mapping(address => uint256) public balances;

    // Deposit Ether into the caller's account.
    function deposit() public payable
    {
        require(msg.value > 0, "Enter a valid amount");
        balances[msg.sender] += msg.value;
    }

    // Withdraw Ether from the caller's account.
    function withdraw(uint256 amount) public
    {
        require(amount > 0, "Invalid amount");
        require(balances[msg.sender] >= amount, "Insufficient balance");

        // Update the recorded balance before transferring Ether.
        balances[msg.sender] -= amount;
        payable(msg.sender).transfer(amount);
    }

    // Show the caller's recorded account balance (in Wei).
    function getBalance() public view returns (uint256)
    {
        return balances[msg.sender];
    }

    // Show the total Ether held by this contract (in Wei).
    function getContractBalance() public view returns (uint256)
    {
        return address(this).balance;
    }
}

/*
================================================================
1. HOW TO EXPLAIN THIS PROGRAM TO AN EXTERNAL EXAMINER
================================================================

"Sir/Mam, this program implements a simple Bank Smart Contract
using Solidity.

A smart contract is a program stored and executed on a
Blockchain.

This Bank contract allows users to deposit Ether, withdraw
Ether, and check their account balance.

First, we declare a mapping that stores the Ether balance
of each user's wallet address.

The deposit() function is declared as payable because it
allows the contract to receive Ether from users.

It checks whether the deposited amount is greater than zero
using the require() statement.

Then, it updates the user's account balance.

The withdraw() function allows users to withdraw their Ether.

It checks whether the withdrawal amount is valid and whether
the user has sufficient balance.

Before transferring Ether, it reduces the user's recorded
balance.

Then, it transfers Ether to the user's wallet address.

The getBalance() function displays the caller's account
balance.

The getContractBalance() function displays the total Ether
held by the smart contract.

Thus, this contract demonstrates basic banking operations
using Solidity and Ethereum."


================================================================
2. IMPORTANT CONCEPTS
================================================================

1. SOLIDITY:
   Solidity is a high-level programming language used to
   develop smart contracts on Ethereum and compatible
   blockchain platforms.

2. SMART CONTRACT:
   A smart contract is a program deployed on a blockchain
   that executes according to predefined conditions.

3. BLOCKCHAIN:
   Blockchain is a distributed digital ledger that stores
   transactions in a secure and tamper-resistant manner.

4. ETHER:
   Ether (ETH) is the native cryptocurrency of the Ethereum
   blockchain.

5. WEI:
   Wei is the smallest unit of Ether.

   1 Ether = 10^18 Wei.

6. CONTRACT:
   The contract keyword is used to define a smart contract.

7. MAPPING:
   A mapping is a key-value data structure.

   Here:
   mapping(address => uint256) public balances;

   Address is the key and uint256 is the stored balance.

8. ADDRESS:
   It represents a blockchain account address.

9. UINT256:
   An unsigned integer data type that stores non-negative
   integer values.

10. PAYABLE:
    The payable keyword allows a function to receive Ether.

11. MSG.SENDER:
    It represents the address of the account that called
    the current function.

12. MSG.VALUE:
    It represents the amount of Ether sent with the
    current transaction, measured in Wei.

13. REQUIRE():
    It checks a condition. If the condition is false,
    the transaction is reverted.

14. PUBLIC:
    It makes a function or variable accessible externally.

15. VIEW:
    It indicates that a function reads blockchain state
    without modifying it.

16. TRANSFER():
    It transfers Ether from the contract to another address.

17. ADDRESS(THIS).BALANCE:
    It returns the total Ether balance held by the contract.

18. SPDX LICENSE:
    It specifies the license under which the source code
    is distributed.

19. PRAGMA:
    It specifies the Solidity compiler version.

20. GAS:
    Gas is the unit used to measure computational work
    performed during blockchain transactions.


================================================================
3. SAMPLE INPUT / EXECUTION
================================================================

Assume the contract is deployed on an Ethereum test network.

USER A:

Wallet Address: 0xUserA

Operation 1: Deposit 2 ETH

Operation 2: Deposit 1 ETH

Operation 3: Check Balance

Operation 4: Withdraw 1 ETH

Operation 5: Check Balance


USER B:

Wallet Address: 0xUserB

Operation 1: Deposit 3 ETH

Operation 2: Check Balance


================================================================
4. EXPECTED OUTPUT
================================================================

USER A:

After depositing 2 ETH:

Account Balance = 2 ETH

After depositing 1 ETH:

Account Balance = 3 ETH

After withdrawing 1 ETH:

Account Balance = 2 ETH


USER B:

After depositing 3 ETH:

Account Balance = 3 ETH


TOTAL CONTRACT BALANCE:

2 ETH + 3 ETH = 5 ETH

NOTE:
The contract balance is the total Ether held by the
smart contract.

Individual account balances are stored separately
using the mapping.

Actual transaction execution also requires gas fees.


================================================================
5. STEP-BY-STEP LOGIC / DRY RUN
================================================================

STEP 1: CONTRACT DEPLOYMENT

Deploy the Bank smart contract.

Initially:

User A Balance = 0 ETH
User B Balance = 0 ETH

Contract Balance = 0 ETH


STEP 2: USER A DEPOSITS 2 ETH

Call:

deposit()

Send Value = 2 ETH

The contract checks:

require(msg.value > 0)

Condition = TRUE

Update:

balances[msg.sender] += msg.value

User A Balance = 2 ETH

Contract Balance = 2 ETH


STEP 3: USER A DEPOSITS 1 ETH

Call:

deposit()

Send Value = 1 ETH

Update:

User A Balance = 2 + 1 = 3 ETH

Contract Balance = 3 ETH


STEP 4: USER A WITHDRAWS 1 ETH

Call:

withdraw(1 ETH)

Check 1:

require(amount > 0)

Condition = TRUE

Check 2:

require(balances[msg.sender] >= amount)

3 ETH >= 1 ETH

Condition = TRUE

Update:

balances[msg.sender] -= amount

User A Balance = 3 - 1 = 2 ETH

Transfer 1 ETH to User A.

Contract Balance = 2 ETH


STEP 5: USER B DEPOSITS 3 ETH

Call:

deposit()

Send Value = 3 ETH

User B Balance = 3 ETH

Contract Balance = 2 + 3 = 5 ETH


STEP 6: CHECK USER BALANCE

Call:

getBalance()

For User A:

Output = 2 ETH

For User B:

Output = 3 ETH


STEP 7: CHECK CONTRACT BALANCE

Call:

getContractBalance()

Output = 5 ETH


STEP 8: FINAL RESULT

User A Balance = 2 ETH
User B Balance = 3 ETH

Total Contract Balance = 5 ETH


================================================================
6. EXPECTED EXTERNAL VIVA QUESTIONS WITH ANSWERS
================================================================

Q1. What is Solidity?

Ans: Solidity is a high-level programming language used
to write smart contracts.

Q2. What is a smart contract?

Ans: A smart contract is a program deployed on a blockchain
that executes predefined instructions.

Q3. What is Ethereum?

Ans: Ethereum is a blockchain platform that supports
smart contracts and decentralized applications.

Q4. What is Ether?

Ans: Ether is the native cryptocurrency of Ethereum.

Q5. What is Wei?

Ans: Wei is the smallest unit of Ether.

1 ETH = 10^18 Wei.

Q6. What is the purpose of pragma?

Ans: Pragma specifies the compiler version required
to compile the Solidity program.

Q7. What is the purpose of SPDX-License-Identifier?

Ans: It specifies the license of the source code.

Q8. What is mapping in Solidity?

Ans: Mapping is a key-value data structure used to store
and retrieve values using keys.

Q9. Why do we use mapping(address => uint256)?

Ans: To store the Ether balance associated with each
user's wallet address.

Q10. What is msg.sender?

Ans: It represents the address of the account that called
the current function.

Q11. What is msg.value?

Ans: It represents the amount of Ether sent with the
current transaction in Wei.

Q12. What is payable?

Ans: Payable allows a function to receive Ether.

Q13. Why is deposit() declared payable?

Ans: Because users must be able to send Ether while
calling the deposit function.

Q14. What is require()?

Ans: Require checks a condition. If the condition is false,
the transaction is reverted.

Q15. Why do we use require(msg.value > 0)?

Ans: To prevent users from depositing zero Ether.

Q16. What is uint256?

Ans: It is an unsigned 256-bit integer data type.

Q17. What is public?

Ans: Public allows a function or variable to be accessed
externally.

Q18. What is view?

Ans: View indicates that a function reads contract data
without modifying blockchain state.

Q19. Why is getBalance() declared as view?

Ans: Because it only reads the user's stored balance
and does not modify it.

Q20. What is address(this).balance?

Ans: It returns the total Ether balance held by the
current smart contract.

Q21. What is transfer()?

Ans: Transfer sends Ether from the contract to the
specified payable address.

Q22. Why do we update the balance before transferring Ether?

Ans: To follow the Checks-Effects-Interactions pattern
and reduce reentrancy risk.

Q23. What is reentrancy?

Ans: Reentrancy is a smart contract vulnerability in which
an external contract repeatedly calls a function before
the original execution finishes.

Q24. What is gas?

Ans: Gas measures the computational work required to
execute operations on the Ethereum blockchain.

Q25. What is gas fee?

Ans: It is the fee paid for executing transactions and
smart contract operations.

Q26. What happens if a user withdraws more than their balance?

Ans: The require condition fails and the transaction
is reverted with "Insufficient balance".

Q27. What happens if a user deposits zero Ether?

Ans: The transaction is reverted with "Enter a valid amount".

Q28. What is the difference between getBalance() and
getContractBalance()?

Ans:
getBalance():
Returns the caller's recorded account balance.

getContractBalance():
Returns the total Ether held by the contract.

Q29. What is the difference between public and private?

Ans:
Public:
Can be accessed externally and internally.

Private:
Can only be accessed within the contract in which
it is declared.

Q30. Where are smart contracts used?

Ans:
1. Banking applications.
2. Decentralized Finance (DeFi).
3. Supply chain management.
4. Digital identity.
5. NFT applications.
6. Decentralized applications.


================================================================
7. EXECUTION COMMANDS / STEPS
================================================================

REQUIREMENT:

1. Remix IDE or a local Solidity development environment.
2. Internet connection for Remix IDE.
3. MetaMask (optional, for wallet-based test transactions).
4. Ethereum test network or Remix VM.

METHOD 1: USING REMIX IDE

Step 1:
Open:

https://remix.ethereum.org/

Step 2:
Create a new file:

Bank.sol

Step 3:
Paste the Solidity code into the editor.

Step 4:
Open Solidity Compiler.

Step 5:
Select compiler version:

0.8.20 or a compatible newer 0.8.x compiler.

Step 6:
Click Compile Bank.sol.

Step 7:
Open Deploy & Run Transactions.

Step 8:
Select Environment:

Remix VM.

Step 9:
Select the Bank contract.

Step 10:
Click Deploy.

Step 11:
After deployment, use the following functions:

deposit():
Enter an amount in the Value field and select Ether
as the unit before clicking deposit.

withdraw():
Enter the withdrawal amount in Wei.

getBalance():
Displays the caller's recorded balance in Wei.

getContractBalance():
Displays the contract's total balance in Wei.


METHOD 2: USING SOLC COMMAND LINE

Compile:

solc --version

For compilation using solc:

solc --bin --abi Bank.sol

NOTE:
The Remix IDE method is simpler for beginners because
it provides an interface to compile, deploy, and interact
with the smart contract.


================================================================
8. IMPORTANT POINTS TO REMEMBER BEFORE VIVA
================================================================

1. Language: Solidity.
2. Platform: Ethereum Blockchain.
3. Contract Name: Bank.
4. Data Structure: Mapping.
5. Key: Wallet Address.
6. Value: Account Balance.
7. Data Type: uint256.
8. Deposit Function: deposit().
9. Withdrawal Function: withdraw().
10. Balance Function: getBalance().
11. Contract Balance: getContractBalance().
12. Ether Receiving Keyword: payable.
13. Caller Address: msg.sender.
14. Sent Ether: msg.value.
15. Condition Checking: require().
16. Read-Only Function: view.
17. Ether Transfer: transfer().
18. Ether Unit: Wei.
19. Compiler Version: ^0.8.20.
20. Deployment Tool: Remix IDE.

ONE-LINE CONCLUSION:

The Bank Smart Contract is a Solidity-based blockchain
application that allows users to deposit Ether, withdraw
Ether, and check individual and total contract balances
using smart contract functions.

================================================================
*/
