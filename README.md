# Entry Test Management System

## Overview

This C program simulates an entry test management system that allows students to register, take tests (SAT, ECAT, Military), and view their results. Administrators can log in to view the records and append new questions to the tests.

## Features

- **Student Registration**: Students can register with their name, CNIC, age, and gender.
- **Test Taking**: Registered students can take the SAT, ECAT, and Military tests.
- **Result Viewing**: After taking a test, students can view their scores. Administrators can view the complete results for all students or specific students.
- **Administrator Interface**: Allows the admin to view student records, append questions to the tests, and more.

## Files

- `main.c`: The main program file containing all the logic for the application.
- `SAT.txt`: Contains SAT questions.
- `sat_key.txt`: Contains the correct answers for SAT.
- `ECAT.txt`: Contains ECAT questions.
- `ecat_key.txt`: Contains the correct answers for ECAT.
- `Military.txt`: Contains Military theory test questions.
- `militarykey.txt`: Contains the correct answers for the Military theory test.
- `military_iq.txt`: Contains Military IQ test questions.
- `military_iq_key.txt`: Contains the correct answers for the Military IQ test.
- `dynamic_way.c`: Contains the code for dynamic file handling.
- `Eresult.txt`: Stores the results of the ECAT test.
- `Mresult.txt`: Stores the results of the Military test.
- `Sresult.txt`: Stores the results of the SAT test.
- `project.c`: Additional code used for managing the project structure.

## Usage

### Administrator Interface
- Login: Admins can log in using a predefined password.
- View Records: Admins can view the results of all students or a specific student.
- Append Questions: Admins can add new questions to SAT, ECAT, or Military tests.
### Student Interface
- Register: Students can register by providing their details.
- Take Test: After registration, students can take the SAT, ECAT, or Military tests.
- View Results: After taking the tests, students can view their results.

## Contribution

If you would like to contribute to this project, please fork the repository and submit a pull request.

