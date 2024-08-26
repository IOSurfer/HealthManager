#include "Database/HmDatabase.h"

HmDatabase::HmDatabase() : m_db(nullptr), m_is_open(false) {
}

HmDatabase::~HmDatabase() {
    closeDatabase();
}

bool HmDatabase::openDatabase(const std::string &db_name) {
    if (m_is_open) {
        closeDatabase();
    }
    int result = sqlite3_open(db_name.c_str(), &m_db);
    if (result != SQLITE_OK) {
        std::cerr << "Failed to open database: " << sqlite3_errmsg(m_db) << std::endl;
        return false;
    }
    m_is_open = true;
    return true;
}

void HmDatabase::closeDatabase() {
    if (m_is_open) {
        sqlite3_close(m_db);
        m_db = nullptr;
        m_is_open = false;
    }
}

sqlite3 *HmDatabase::getDatabase() const {
    return m_db;
}

bool HmDatabase::isDatabaseOpen() const {
    return m_is_open;
}