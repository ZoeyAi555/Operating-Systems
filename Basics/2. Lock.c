
enqueue(node *new_element) {
    lock
    node *ptr;
    // find tail of queue
    for (ptr=head; ptr->next != NULL; ptr = ptr->next) {}
    unlock

    lock
    // add new element to tail of queue
    ptr->next = new_element;
    new_element->next = NULL;
    unlock
}

// busy waiting
dequeue() {
    qmutex.lock();
    // wait for queue to be non-empty
    while(head->next == NULL) {
        qmutex.unlock();        
        qmutex.lock();
    }
    // remove element
    ptr = head->next;
    head->next = head->next->next;
    qmutex.unlock();
    return(ptr);
}
//correct
enqueue()
    lock
    add new item to tail of queue
    if (dequeuer is waiting) {
        remove waiting dequeuer from waiting set
        wake up dequeuer
    }
    unlock



dequeue()
    lock
    if (queue is empty) {
        add myself to waiting set
        unlock?
        go to sleep and wait for wakeup
        lock?
    }
    remove item from queue
    unlock


wait()  
/*Release lock
Put thread onto waiting set
Go to sleep
After being woken, acquire lock when it’s free*/
queueMutex.unlock()
add myself to waiting set
go to sleep
queueMutex.lock()

wait(mutex)
Release mutex, add thread to waiting set, go to sleep.  After waking, re-acquire mutex (blocking if needed).
Each condition variable is associated with a lock
Invariant must be true when releasing lock

signal() and broadcast()
Wake up one thread (signal) or all threads (broadcast) that are waiting on this condition variable
If no thread is waiting, signal/broadcast does nothing

mutex queueMutex;
cv queueCV;
enqueue()
    queueMutex.lock()
    add new element to tail of queue
    if (dequeuer is waiting) {
        remove waiting dequeuer from waiting set
        wake up deqeuer
    }
    queueMutex.unlock()
dequeue()
    queueMutex.lock()
    if (queue is empty) {
        add myself to waiting set
        unlock
        sleep
        lock
    }
    remove item from queue
    queueMutex.unlock()
    return removed item
