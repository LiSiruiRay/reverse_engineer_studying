Overview
Compilers are a fundamental piece of software infrastructure. They enable programmers to write programs in high-level programming languages and obtain efficient, executable code that can run on a variety of hardware platforms. This course covers the design and implementation of compilers. We will see how to structure compilers as a series of discrete, well-defined transformations between different representations of programs. Throughout the course of the semester, students will implement a complete compiler for a small yet powerful typed, functional programming language.

Logistics
Lectures are in Room 312 in Warren Weaver Hall, 7:10pm - 9:10pm on Mondays. Lectures are also streamed over the Zoom link given above on the BrightSpace page.

Office hours will be held at 3pm - 4pm on Mondays in Rm 401 of 60 Fifth Avenue.

Grades and Assessment
Grades will be determined entirely on the basis of two components:

(80% of grade) Periodic homework assignments in which students implement the compiler for the course. Given their varying complexity and difficulty, some assignments affect the overall score in the course more than others. In particular, each assignment will be weighted with an assigned number of points. A student's overall "raw" score for the homework component will be the sum total of all points from the assignments. 
The tentative list of assignments is as follows:

0. OCaml warm-up (6 pts)
1. RISC-V Simulator (6 pts)
2. Parsing (6 pts)
3. Fortran-ish → RISC-V (12 pts)
4. C-ish → RISC-V (8 pts)
5. Scheme-ish → C-ish (10 pts)
6. ML-ish → Scheme-ish (10 pts)
7. Control-flow Graph Analysis (15 pts 20 pts)
8. Register Allocator (10 pts) ) (UPDATE: no longer required as a separate assignment, though implementing a decent register allocator is one way to get full credit on the miniproject) 

The number, subject, and point values of assignments are subject to change from the above list. The definitive point weighting of each assignment is given on GradeScope.

(20% of grade) A larger scale project where your goal will be to improve and optimize the basic compiler infrastructure we have built during the semester in the main assignments. Students may work individually or in groups of up to 3. In addition to code implementing the optimized compiler, groups will be expected to submit a brief (2-3 pages) project "report" summarizing what was done. More details to come as we complete the main assignments of the course. (UPDATE: the scope of the project was reduced from my original plans given timing constraints for how long it took us to get through the main course content., so group work is no longer appropriate. In addition, there is no longer a requirement to submit a report summarizing what was done.)

The overall course grade will be based on the weighted average of the above two components, using the weight percentages indicated above.


Late Assignment Policy
Assignments submitted after their deadline are considered late. Late assignments are treated as follows. Students may take up to 3 "no questions asked" late days throughout the semester. Each late day used grants a 24 hour extension. Each late day used must be used in its entirety (e.g. you cannot use "half" a late day to get a 24 extension). You may use multiple late days on a single assignment. You must notify the instructor that you are using a late day. If a student has no remaining late days, a late assignment will only be accepted under extenuating circumstances: illness, death in the family, etc. Please let me know if such circumstances arise. Otherwise, the late assignment will receive 0 credit.

"No questions asked" late days may not be used for the project deliverables, only for the above described assignments. However, extenuating circumstances such as illness, death in the family, etc. may be used to justify extensions for project deliverables.

Textbook and Resources
There is no official or required textbook for the course. The book that most closely follows what we are doing is Modern Compiler Implementation in ML by Andrew Appel. (Note: there are several textbooks by Andrew Appel with a similar name that vary in terms of what language the example compiler is implemented in. You want the "in ML" version as Standard ML is closest to OCaml, the language we are using).

Accommodations
Students who have a disability that requires accommodations must inform the instructor that they require such accommodations as soon as possible. Please submit documentation through the Moses Center for Student Accessibility (CSA). You can learn more about NYU's accessibility accommodations policy on the CSA website: https://www.nyu.edu/students/communities-and-groups/student-accessibility.html