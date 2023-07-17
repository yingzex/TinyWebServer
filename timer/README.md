Timers handle inactive connections
===============
Since inactive connections take up connection resources and seriously affect server performance, a server timer is implemented to handle such inactive connections and free up connection resources. The SIGALRM signal is triggered periodically using the alarm function, and the signal processing function for this signal uses a pipe to notify the main loop to execute the timed task on the timer chain table.
> * Unified event source
> * Timer based on ascending chain list.
> * Handles inactive connections