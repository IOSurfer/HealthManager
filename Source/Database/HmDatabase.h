#ifndef HMDATABASE_H
#define HMDATABASE_H
#include <iostream>
#include <sqlite3.h>
#include <string>
#include <vector>

class HmDatabase {
  public:
    HmDatabase();
    ~HmDatabase();

    bool openDatabase(const std::string &db_path);
    void closeDatabase();
    sqlite3 *getDatabase() const;
    bool isDatabaseOpen() const;

  private:
    sqlite3 *m_db{nullptr};  // SQLite数据库指针
    bool m_is_open{false}; // 数据库是否已打开
};

#endif
