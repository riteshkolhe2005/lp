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