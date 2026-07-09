# Private School 🧑‍🏫

**Private School** is a C++ console program designed to help manage a private school structure.  
It supports setting up a school, adding classrooms, managing classroom students, and browsing a report dashboard with school, classroom, student, and statistics views.

## ✨ Features
- Create a school and enter its name
- Open an about page from the main menu
- Add classrooms to the school
- Manage classrooms from an interactive menu
- Edit classroom subjects
- Add students to a classroom
- Validate inputs for names and numbers
- Open a report menu with school summary, classrooms, students, and statistics

## 🚀 Getting Started

### Prerequisites
- A C++ compiler (e.g., `g++`, `clang++`)
- Git (to clone the repo)

make

### Build
```bash
git clone https://github.com/habibma/private_teacher.git private_teacher
cd private_teacher
```

### Dependencies
This project uses the [nlohmann/json](https://github.com/nlohmann/json) library.

### Compile and Run

``` bash
git clone https://github.com/nlohmann/json.git external/json
make
./program
```

### Menu Flow
1. Start the program and enter the school name if no saved school exists.
2. Use `ABOUT` to open the program description page.
3. Use `MANAGE SCHOOL` to open the school setup menu.
4. In the school menu, use `ADD CLASSROOM` or `MANAGE CLASSROOMS`.
5. Use `VIEW REPORT` to open the report dashboard.
6. Use `EXIT` to close the program.

### Main Menu
- `ABOUT` - open the program description page
- `MANAGE SCHOOL` - open the school setup menu
- `VIEW REPORT` - open the report dashboard
- `EXIT` - close the program

### School Menu
- `ADD CLASSROOM` - add a classroom to the school
- `MANAGE CLASSROOMS` - select and manage an existing classroom
- `DELETE SCHOOL` - remove the saved school data and start over
- `BACK` - return to the main menu

### Classroom Menu
- `EDIT CLASSROOM` - update the classroom subject
- `ADD STUDENT` - add a student to the selected classroom
- `BACK` - return to the school menu

## 🛠️ Future Roadmap
- Persist classrooms, students, and report data to disk
- Improve delete/update flows with safer record handling
- Add richer reporting and filtering for classroom statistics

## 📝 Current Persistence
- The current save/load flow restores the school name from `data/school_data.txt`.
- Classrooms and students are managed in memory during the session and are not yet persisted.

## 🤝 Contributing
Contributions are welcome!
Please fork the repo and submit a pull request.

## 📜 License
This project is licensed under the MIT License – see [LICENSE](/LICENSE) for details.
