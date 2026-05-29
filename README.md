# 📚 LearnFlow - Task Manager Desktop App

> A modern, feature-rich task management desktop application built with **Qt/C++**. Manage your tasks, organize your schedule, and stay on top of your productivity with an intuitive and visually appealing interface.

![License](https://img.shields.io/badge/License-OFL%201.1-blue)
![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?logo=cplusplus)
![Qt](https://img.shields.io/badge/Qt-6%2F5-41CD52?logo=qt)

---

## ✨ Features

### 🏠 Home Dashboard
- Quick overview of your most important tasks
- Visual task list with priority indicators
- Immediate access to add new tasks
- Empty state messaging for better UX

### ✅ Task Management
- **Create Tasks** with detailed information:
  - Title and description
  - Priority levels (High, Medium, Low)
  - Project/Category assignment
  - Start and end dates
  - Due times with custom scheduling
  
- **Filter & Search**:
  - View all tasks
  - Filter by overdue tasks
  - Filter by high-priority tasks
  - Real-time search functionality

### 📅 Calendar & Timeline View
- Interactive calendar navigation (previous/next month)
- Mini calendar sidebar for quick date selection
- Timeline view for visualizing task schedule
- Day-based task filtering

### 🎨 Modern UI
- Clean, contemporary design with rounded elements
- Custom fonts (Inter, Manrope, Patrick Hand, Pecita)
- Smooth navigation between Home, Tasks, and Calendar views
- Dark and light theme support
- Responsive layout with scroll areas

### 🏷️ Organization
- Project/Category-based task grouping
- Priority-based task management
- Visual indicators for task status

---

## 🛠️ Tech Stack

| Component | Technology |
|-----------|-----------|
| **Language** | C++ (C++17 standard) |
| **GUI Framework** | Qt 5/6 |
| **Build System** | CMake 3.16+ |
| **UI Design** | Qt Designer (.ui files) |
| **Platform** | Cross-platform (Windows, macOS, Linux) |

---

## 📁 Project Structure

```
LearnFlow_cpp/
├── main.cpp                          # Application entry point
├── mainwindow.h / mainwindow.cpp     # Main application window
├── mainwindow.ui                     # Main UI design
├── addtaskdialog.h / addtaskdialog.cpp  # Task creation dialog
├── tasks.ui                          # Tasks view UI
├── LightLearnFlow.ui                 # Alternative light theme UI
├── CMakeLists.txt                    # Build configuration
├── resources.qrc                     # Resource file (fonts, images, icons)
├── Patrick_Hand/                     # Font resources
├── Roboto_Flex/                      # Font resources
├── build/                            # Build output directory
├── BackgroundPattern.png             # Background imagery
├── profileImage.png                  # User profile image
├── calendar.png, tasks.png, home.png # Navigation icons
├── Inter-VariableFont_*.ttf          # Typography
├── Manrope-VariableFont_wght.ttf     # Typography
└── Pecita.otf                        # Typography
```

### Key Source Files

#### **main.cpp**
Entry point that initializes the Qt application and displays the main window.

#### **mainwindow.h / mainwindow.cpp**
Core application logic:
- Navigation between Home, Tasks, and Calendar views
- Task list rendering and management
- Calendar/timeline visualization
- Filter and search functionality
- Signal/slot connections for UI interactions

#### **addtaskdialog.h / addtaskdialog.cpp**
Dialog window for creating new tasks:
- Form inputs for task details (title, description)
- Date and time selection
- Priority and category dropdowns
- Task creation signals

#### **UI Files** (.ui)
XML-based UI layouts designed in Qt Designer:
- `mainwindow.ui`: Main application window layout
- `tasks.ui`: Tasks view layout
- `LightLearnFlow.ui`: Light theme variant

---

## 🚀 Getting Started

### Prerequisites
- **Qt 5.15+** or **Qt 6+**
- **CMake 3.16+**
- **C++ compiler** supporting C++17 (GCC, Clang, MSVC)

### Installation

1. **Clone the repository**
   ```bash
   git clone https://github.com/AHMEDxHAGAG/LearnFlow_cpp.git
   cd LearnFlow_cpp
   ```

2. **Install Qt**
   - Download from [qt.io](https://www.qt.io/download)
   - Or install via package manager:
     ```bash
     # Ubuntu/Debian
     sudo apt install qt5-qmake qtbase5-dev qttools5-dev
     
     # macOS (Homebrew)
     brew install qt
     
     # Windows (vcpkg)
     vcpkg install qt5:x64-windows
     ```

3. **Build the project**
   ```bash
   mkdir build && cd build
   cmake ..
   cmake --build .
   ```

4. **Run the application**
   ```bash
   # Linux/macOS
   ./LearnFlow
   
   # Windows
   LearnFlow.exe
   ```

---

## 📋 Usage Guide

### Creating a Task
1. Click the **FAB (Floating Action Button)** or **"Add Schedule"** button
2. Fill in task details:
   - **Title** (required)
   - **Description** (optional)
   - **Priority** (High/Medium/Low)
   - **Project/Category**
   - **Start Date** and **End Date**
   - **Due Time** and **End Time**
3. Click **Create** to add the task

### Navigating Views
- **Home**: Overview dashboard with main tasks
- **Tasks**: Comprehensive task list with filters
- **Calendar**: Timeline and calendar-based view

### Filtering Tasks
- **All**: Show all tasks
- **Overdue**: Show only overdue tasks
- **High Priority**: Show only high-priority tasks

### Searching Tasks
- Use the search bar to filter tasks in real-time
- Search by task title and description

### Calendar Navigation
- Use **Previous/Next** buttons to navigate months
- Click on dates in the mini calendar for quick navigation
- View timeline for selected date

---

## 🎯 Architecture & Design Patterns

### Design Patterns Used
- **MVC (Model-View-Controller)**: Separation of UI and logic
- **Observer Pattern**: Qt's signal/slot mechanism
- **Builder Pattern**: UI component construction

### Key Classes
| Class | Purpose |
|-------|---------|
| `MainWindow` | Central application controller and main UI |
| `AddTaskDialog` | Modal dialog for task creation |
| Task Management | Internal task list and filtering logic |
| Calendar Manager | Calendar view rendering and navigation |

---

## 🎨 Customization

### Themes
The application includes theme support through UI files:
- `mainwindow.ui` - Default theme
- `LightLearnFlow.ui` - Light theme variant

### Fonts
Custom fonts are embedded and can be modified:
- **Display**: Patrick Hand, Pecita
- **Body**: Inter, Manrope, Roboto Flex

### Colors & Styling
Modify stylesheets in source files or `.ui` files using Qt Designer.

---

## 📝 License

This project is licensed under the **SIL Open Font License 1.1** (OFL.txt) - primarily for the included font files.

For project code, please refer to the repository's licensing information.

---

## 👨‍💻 Author

**AHMEDxHAGAG**
- GitHub: [@AHMEDxHAGAG](https://github.com/AHMEDxHAGAG)
- Project: [LearnFlow_cpp](https://github.com/AHMEDxHAGAG/LearnFlow_cpp)

---

## 🤝 Contributing

Contributions are welcome! Feel free to:
1. Fork the repository
2. Create a feature branch
3. Commit your changes
4. Push to your branch
5. Open a Pull Request

---

## 📞 Support & Issues

Found a bug or have a feature request? Please open an [issue](https://github.com/AHMEDxHAGAG/LearnFlow_cpp/issues) on GitHub.

---

## 🔗 Related Resources

- [Qt Documentation](https://doc.qt.io/)
- [CMake Documentation](https://cmake.org/documentation/)
- [C++ Reference](https://en.cppreference.com/)

---

## 📊 Project Stats

- **Language**: C++ (98.7%)
- **Repository Size**: ~25 MB
- **Created**: March 6, 2026
- **Last Updated**: May 29, 2026

---

<div align="center">

### ⭐ If you find this project helpful, please give it a star!

Made with ❤️ by AHMEDxHAGAG

</div>
