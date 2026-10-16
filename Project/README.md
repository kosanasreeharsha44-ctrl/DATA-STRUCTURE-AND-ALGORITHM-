**Employee Record Storage Using Hash Tables**

**Project Overview**

Employee Record Storage Using Hash Tables is a Java-based Data Structures and Algorithms (DSA) project designed to manage employee records efficiently. It uses a hash table with separate chaining to store and retrieve employee information.

The system provides a menu-driven interface for inserting, searching, updating, and deleting employee records.

**Objectives**

- Store employee records using a hash table.
- Use Employee ID as a unique key.
- Perform insertion, searching, updating, and deletion.
- Handle hash collisions using separate chaining.
- Monitor the load factor and improve performance through rehashing.

**Technologies Used**

- Programming Language: Java
- Data Structure: Hash Table
- Collision Handling: Separate Chaining
- Additional Concept: Linked Lists and Rehashing

Employee Details

Each employee record contains:

- Employee ID
- Name
- Age
- Qualification
- Position
- Salary

**Features**

1. Insert Employee: Add a new employee record.
2. Search Employee: Find an employee using their ID.
3. Update Employee: Modify existing employee details.
4. Delete Employee: Remove an employee record.
5. Display All Employees: View all stored employee records.
6. Hash Table Statistics: Display table size, employee count, load factor, collisions, and maximum chain length.
7. Automatic Rehashing: Increase the table size when the load factor exceeds 0.75.
8. Exit: Terminate the program.

**How It Works**

The project calculates the hash-table index using the Employee ID and table size.

Hash Function:

index = employeeID % tableSize;

For example, when the table size is 5:

- Employee ID 101 → Index 1
- Employee ID 106 → Index 1
- Employee ID 111 → Index 1

These records are stored in the same bucket using separate chaining, which connects collided records through linked nodes.

**Algorithm**

1. Start the program.
2. Display the menu.
3. Read the user's choice.
4. Perform the selected employee operation.
5. Calculate the hash index using the Employee ID.
6. Handle collisions using separate chaining.
7. Check the load factor and rehash when necessary.
8. Display the result.
9. Repeat until the user selects Exit.

Time Complexity

Operation| Average Case| Worst Case
Insertion| O(1)| O(n)
Searching| O(1)| O(n)
Updating| O(1)| O(n)
Deletion| O(1)| O(n)

Note: These complexities assume a well-distributed hash function for average-case performance.

**Advantages**

- Fast employee record access.
- Efficient record management.
- Handles hash collisions.
- Supports automatic rehashing.
- Provides useful hash-table statistics.
- Demonstrates practical applications of hash tables and linked lists.

**Limitations**

- Performance depends on hash distribution.
- Long chains can increase search time.
- Linked nodes require additional memory.
- Rehashing requires moving existing records.
- Records are stored only during program execution unless permanent storage is implemented.

**Future Enhancements**

- Database integration.
- Graphical User Interface (GUI).
- Permanent file-based storage.
- Advanced employee filtering.
- Authentication and access control.
- Export employee records to CSV or PDF.

**Conclusion**

This project demonstrates how hash tables and linked lists can be used to manage employee records efficiently. Separate chaining handles collisions, while rehashing helps maintain performance as the number of records increases.

The project provides practical experience with core DSA concepts and employee record management using Java.

Author

Developed as a Data Structures and Algorithms (DSA) project.
