# CS300-Portfolio
Overview

This section of my portfolio showcases my work in data structures and algorithms. Project One focused on analyzing runtime and memory tradeoffs between vector, hash table, and binary search tree implementations. Project Two involved building a working C++ advising assistance program that loads course data, stores it in a tree-based structure, and prints courses in alphanumeric order.

What Problem Was I Solving?

The problem I was solving was how to efficiently store and retrieve course information for an advising system. The program needed to load course data from a file, print all courses in sorted alphanumeric order, and allow users to look up course details and prerequisites. The main challenge was choosing the correct data structure to balance performance, memory use, and simplicity.

How I Approached the Problem

I approached the problem by first analyzing different data structures and their runtime complexity. Understanding Big O notation helped me compare vector, hash table, and binary search tree implementations. Since the advisor requirement included printing courses in alphanumeric order, I selected a tree-based structure because it naturally maintains sorted order through in-order traversal. This reinforced how important it is to understand data structures before writing code.

Overcoming Roadblocks

One roadblock I encountered was understanding how runtime changes depending on worst-case versus average-case behavior. For example, a binary search tree can degrade to linear time if unbalanced. I overcame this by reviewing how insert operations affect tree structure and thinking through how the data would realistically behave. Another challenge was file parsing and input validation in C++, which required careful string handling and testing to avoid crashes.

How This Expanded My Software Design Approach

This project changed how I think about designing software. Instead of jumping straight into coding, I now consider performance tradeoffs first. I learned that selecting the right data structure can simplify implementation and improve efficiency. I also became more intentional about separating concerns, such as isolating file reading logic from data storage logic.

Writing Maintainable, Readable, and Adaptable Code

Through this project, I focused more on clean structure and readability. I used clear naming conventions, consistent formatting, and modular functions to make the program easier to understand. I also implemented error handling and input validation to make the program more robust. Thinking about adaptability helped me write code that could later be extended, such as replacing a basic tree with a self-balancing version if needed.
