Server Stress Testing
===============
Webbench is a famous web site stress testing tool, which is developed by [Lionbridge](http://www.lionbridge.com).

> * Tests the performance of different services on the same hardware and the same service on different hardware.
> * Demonstrates two things about a server: the number of requests responded to per second and the amount of data transferred per second.




Test Rules
------------
* Test example

    ```C++
	webbench -c 500 -t 30 http://127.0.0.1/phpionfo.php
    ``
* Parameters

> * `-c` indicates the number of clients
> * `-t` indicates time


Test results
---------
Webbench stress-tested the server, and the stress-tested server can realize tens of thousands of concurrent connections.
> * Total concurrent connections: 10500
> * Access time to the server: 5s
> * Responding to requests per second: 552852 pages/min
> * Data transfer per second: 1031990 bytes/sec
> * All accesses were successful