#ifndef _CONNECTION_POOL_
#define _CONNECTION_POOL_

#include <stdio.h>
#include <list>
#include <mysql/mysql.h>
#include <error.h>
#include <string.h>
#include <iostream>
#include <string>
#include "../lock/locker.h"
#include "../log/log.h"

using namespace std;

class connection_pool
{
public:
	MYSQL *GetConnection();				 //Getting a database connection 
	bool ReleaseConnection(MYSQL *conn); 
	int GetFreeConn();					 //Getting Connection
	void DestroyPool();					 //Destroying all connections

	// sinleton 
	static connection_pool *GetInstance();

	void init(string url, string User, string PassWord, string DataBaseName, int Port, int MaxConn, int close_log); 

private:
	connection_pool();
	~connection_pool();

	int m_MaxConn;  // count of max connections
	int m_CurConn;  // count of current connections
	int m_FreeConn; // count of free connections
	locker lock;
	list<MYSQL *> connList; // connection pool
	sem reserve;

public:
	string m_url;			 // host addrss
	string m_Port;		 // database port number
	string m_User;		 // username of database
	string m_PassWord;	 // password of database
	string m_DatabaseName; // name of database
	int m_close_log;	// Log on/off
};

class connectionRAII{

public:
	connectionRAII(MYSQL **con, connection_pool *connPool);
	~connectionRAII();
	
private:
	MYSQL *conRAII;
	connection_pool *poolRAII;
};

#endif
