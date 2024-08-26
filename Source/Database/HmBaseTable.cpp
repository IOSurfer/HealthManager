#include "Database/HmBaseTable.h"
#include <iostream>

HmBaseTable::HmBaseTable(sqlite3 *db, std::string table_name) : m_db(db), m_table_name(table_name) {
}

HmBaseTable::~HmBaseTable() {
}

// 删除数据表
bool HmBaseTable::dropTable() const {
    std::string sql = "DROP TABLE IF EXISTS " + m_table_name + ";";

    char *err_msg = nullptr;
    int rc = sqlite3_exec(m_db, sql.c_str(), nullptr, nullptr, &err_msg);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << err_msg << std::endl;
        sqlite3_free(err_msg);
        return false;
    }
    return true;
}