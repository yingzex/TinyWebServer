Semi-Synchronous/Half-Reactor Thread Pool
===============
The use of a work queue completely decouples the main thread from the worker threads: the main thread inserts tasks into the work queue, and the worker threads compete to get the task and execute it.
> * Synchronous I/O simulation proactor mode
> * Semi-synchronous/half-proactor
> * Thread pooling