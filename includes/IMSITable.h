#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <pthread.h>
#include <assert.h>
#include "sqlite3.h"
#include "MessageParse.h"
using namespace std;

#ifndef SQLITE_API
#define SQLITE_API
#endif

int sqlite3_prepare_statement(sqlite3* DB, sqlite3_stmt **stmt, const char* query);

int sqlite3_run_query(sqlite3* DB, sqlite3_stmt *stmt);

bool sqlite3_exists(sqlite3* DB, const char *tableName,
                const char* keyName, const char* keyData);

bool sqlite3_single_lookup(sqlite3* DB, const char* tableName,
                const char* keyName, const char* keyData,
                const char* valueName, char* &valueData);

bool sqlite3_command(sqlite3* DB, const char* query);


class IMSITable{
    private:
    sqlite3* mDB;
    public:
    int open(const char* wpath);
    unsigned assign(Msg_Imsi* responseimsi,bool fAccess);
    ~IMSITable();
};

