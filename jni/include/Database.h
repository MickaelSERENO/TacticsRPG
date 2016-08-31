#ifndef  DATABASE_INC
#define  DATABASE_INC

#include "sqlite3.h"
#include <iostream>
#include "stdlib.h"

class Database
{
	public:
		static void initSingleton(const char* path);
		static Database* getSingleton();
		~Database();
		sqlite3* getDatabase();
	private:
		Database(const char* path);
		static Database* m_singleton;
		sqlite3* m_sql;
};

#endif
