// SPDX-License-Identifier: MIT
pragma solidity ^0.8.20;


// Bank account: Deposit Ether, withdraw Ether, and show balance.
contract Bank {
    // Stores the Ether balance for each wallet address.
    mapping(address => uint256) public balances;

    // Deposit Ether into the caller's account.
    function deposit() public payable {
        require(msg.value > 0, "Enter a valid amount");
        balances[msg.sender] += msg.value;
    }

    // Withdraw Ether from the caller's account.
    function withdraw(uint256 amount) public {
        require(amount > 0, "Invalid amount");
        require(balances[msg.sender] >= amount, "Insufficient balance");

        // Update the recorded balance before transferring Ether.
        balances[msg.sender] -= amount;
        payable(msg.sender).transfer(amount);
    }

    // Show the caller's recorded account balance (in Wei).
    function getBalance() public view returns (uint256) {
        return balances[msg.sender];
    }

    // Show the total Ether held by this contract (in Wei).
    function getContractBalance() public view returns (uint256) {
        return address(this).balance;
    }
}
