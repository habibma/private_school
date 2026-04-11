# Private Teacher 🧑‍🏫

**Private Teacher** is a C++ console program designed to help manage a private school structure.  
It now supports building a school, adding teachers, managing teacher profiles, creating classrooms, adding students, and printing a school report with class averages.

## ✨ Features
- Create a school and enter its name
- Add teachers to the school
- Manage teachers from an interactive menu
- Edit teacher names
- Add classrooms to a teacher profile
- Add students to a classroom
- Validate inputs for names and numbers
- Print a report showing teachers, classrooms, and class averages

## 🚀 Getting Started

### Prerequisites
- A C++ compiler (e.g., `g++`, `clang++`)
- Git (to clone the repo)

### Build and Run
```bash
git clone https://github.com/habibma/private_teacher.git
cd private_teacher
make
./program
```

### Menu Flow
1. Start the program and enter the school name.
2. Use `START` to open the school builder menu.
3. In the builder menu, use `ADD` to create a teacher.
4. Use `MANAGE` to edit a teacher, add classrooms, or add students.
5. Use `REPORT` from the main menu to print the school summary.
6. Use `EXIT` to close the program.

### Builder Commands
- `START` - open the school building menu
- `ADD` - add a new teacher
- `MANAGE` - select and manage an existing teacher
- `BACK` - return to the main menu
- `EDIT` - update a teacher's first and last name
- `ADD_CLASS` - add a classroom to a teacher
- `ADD_STUDENT` - add a student to one of the teacher's classrooms
- `DELETE` - remove a teacher from the school

## 🛠️ Future Roadmap
- Save/load data from files
- Support persistence for schools, teachers, classrooms, and students
- Improve delete/update flows with safer record handling
- Add richer reporting for teachers and classrooms

## 🤝 Contributing
Contributions are welcome!
Please fork the repo and submit a pull request.

## 📜 License
This project is licensed under the MIT License – see [LICENSE](/LICENSE) for details.
