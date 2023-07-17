#ifndef CONFIG_H
#define CONFIG_H

#include "webserver.h"

using namespace std;

class Config
{
public:
    Config();
    ~Config(){};

    void parse_arg(int argc, char*argv[]);

    int PORT;

    // method of writing log
    int LOGWrite;

    // Trigger combination mode
    int TRIGMode;

    // listenfd trigger mode
    int LISTENTrigmode;

    //connfd trigger mode
    int CONNTrigmode;

    //close connections elegantly
    int OPT_LINGER;

    // count of connection pool in the database
    int sql_num;

    // count of threads in the thread pool
    int thread_num;

    int close_log;

    // concurrency model
    int actor_model;
};

#endif