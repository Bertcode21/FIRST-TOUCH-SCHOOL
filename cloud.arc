                    CLOUD ENVIRONMENT

              ┌────────────────────────┐
              │       Cloud Server      │
              │                        │
              │  Express.js Backend    │
              │  Authentication        │
              │  REST API              │
              │  Sync Engine           │
              └───────────┬────────────┘
                          │
                          │
              ┌───────────▼────────────┐
              │    Cloud Database       │
              │                         │
              │ MySQL / PostgreSQL      │
              └───────────┬────────────┘
                          │
             ┌────────────┴─────────────┐
             │                          │
             ▼                          ▼

    React Student Portal        React Parent Portal


             ▲
             │
             │ Internet
             │


       Desktop Application
          (Qt/C++)

             │

             ▼

        Local SQLite DB

/////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
 RESULT FLOW
        Teacher/Desktop
      |
      |
      ▼
Qt Desktop Application
      |
      |
      ▼
Local SQLite Database
      |
      |
      ▼
Sync Engine
      |
      |
      ▼
Cloud API (Express.js)
      |
      |
      ▼
Cloud Database
      |
      |
      ▼
React Web Portal
      |
      |
      ▼
Student Login
      |
      |
      ▼
Student Views Results

widgets
│
└── class
    │
    ├── ClassWidget.h
    ├── ClassWidget.cpp
    │
    ├── ClassCardWidget.h
    ├── ClassCardWidget.cpp
    │
    ├── ClassDetailsWidget.h
    ├── ClassDetailsWidget.cpp
    │
    ├── ClassStatisticsWidget.h
    ├── ClassStatisticsWidget.cpp
    │
    ├── ClassStudentTableWidget.h
    ├── ClassStudentTableWidget.cpp
    │
    ├── ClassActionBarWidget.h
    ├── ClassActionBarWidget.cpp