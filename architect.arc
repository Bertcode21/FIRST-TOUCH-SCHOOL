+--------------------------------------------------+
|                 QT DESKTOP CLIENT                |
|--------------------------------------------------|
| Login UI | Dashboard | Student Forms | Reports  |
+--------------------------------------------------+
                     |
                     | HTTP / TCP
                     v
+--------------------------------------------------+
|                C++ BACKEND SERVER                |
|--------------------------------------------------|
| Auth | Business Logic | Validation | API Layer  |
+--------------------------------------------------+
                     |
                     | SQL Queries
                     v
+--------------------------------------------------+
|                    MYSQL DATABASE                |
|--------------------------------------------------|
| students | teachers | results | fees | users    |
+--------------------------------------------------+


SYSTEM ARCHITECTURE

                    HOSTINGER MYSQL
                           │
        ┌──────────────────┼──────────────────┐
        │                  │                  │
        ▼                  ▼                  ▼
   Student Portal     Parent Portal     Teacher Portal
      (Web)              (Web)             (Web)

                           ▲
                           │ Sync
                           ▼

                School Administration
                    Desktop App
                     (Qt C++)








                     so now pro