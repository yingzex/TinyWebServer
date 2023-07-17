#include "config.h"

int main(int argc, char *argv[])
{
    string user = "root";
    string passwd = "root";
    string databasename = "qgydb";

    // Command line parsing
    Config config;
    config.parse_arg(argc, argv);

    WebServer server;

    server.init(config.PORT, user, passwd, databasename, config.LOGWrite, 
                config.OPT_LINGER, config.TRIGMode,  config.sql_num,  config.thread_num, 
                config.close_log, config.actor_model);
    

    server.log_write();

    // database
    server.sql_pool();

    server.thread_pool();

    server.trig_mode();

    server.eventListen();

    // run
    server.eventLoop();

    return 0;
}