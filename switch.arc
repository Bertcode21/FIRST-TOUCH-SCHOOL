---------------------------------------------------------------
---------------------------------------------------------------
Updating the visual template 

system architecture
                  FIRSTTOUCH ECOSYSTEM

        ┌──────────────────────────────────────┐
        │        Desktop Application           │
        │        (Qt/C++ + SQLite/PostgreSQL)  │
        └──────────────────────────────────────┘
                 ▲
                 │
                 │ School Network / Internet
                 ▼
        ┌──────────────────────────────────────┐
        │           Backend API                │
        │      Authentication & Business       │
        └──────────────────────────────────────┘
                 ▲
        ┌────────┴────────┐
        │                 │
        ▼                 ▼
  Student Portal      Parent Portal
      (Web)              (Web)