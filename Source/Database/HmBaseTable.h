#ifndef HMBASETABLE_H
#define HMBASETABLE_H

#include <sqlite3.h>
#include <string>

class HmBaseTable {
  public:
    HmBaseTable(sqlite3 * db, std::string table_name);
    ~HmBaseTable();
    virtual bool createTable() const = 0;
    bool dropTable() const;

  private:
    sqlite3 * m_db; 
    std::string m_table_name;
};

#endif // HM_BASE_TABLE_H
