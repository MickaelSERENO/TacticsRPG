#include "Database.h"

Database* Database::m_singleton = NULL;

void Database::initSingleton(const char* path)
{
	m_singleton = new Database(path);
}

Database* Database::getSingleton()
{
	return m_singleton;
}

Database::Database(const char* path)
{
	sqlite3_open(path, &m_sql);
}

Database::~Database()
{
	sqlite3_close(m_sql);
}

sqlite3* Database::getDatabase()
{
	return m_sql;
}
