http connection handler class
===============
The http connection class is encapsulated by master and slave state machines based on state transfer. The master state machine calls the slave state machine internally, and the slave state machine passes the processing status and data to the master state machine.
> * Client sends http connection request.
> * The slave state machine reads the data, updates its own state and receives the data, and passes it to the master state machine.
> * The master state machine updates its own state according to the state of the slave state machine, and decides whether to respond to the request or to continue reading.