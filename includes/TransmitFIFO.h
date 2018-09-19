#ifndef _TRANSMITFIFO_H_
#define _TRANSMITFIFO_H_

#include<string.h>
#include<stdlib.h>

typedef struct InterthreadQueue {
        struct PointerFIFO* mQ;
        struct Mutex* mLock;
        struct Signal* mWriteSignal;
}InterthreadQueue;


typedef struct dataSocket{
        char* msgdata;
        int size;
}dataSocket;

class TransmitFIFO{

    public:

    struct InterthreadQueue* QueueOpen();
    /** Delete contents. */
    void  QueueClose(struct InterthreadQueue* tq);

    /* get Queue Size */
    unsigned GetQueueSize(struct InterthreadQueue* tq);
/**

  Blocking read.
  @return Pointer to object (will not be NULL).
 */
    void* readBlock(struct InterthreadQueue* tq);

};

    void* readNoBlock(struct InterthreadQueue* tq);

/** Non-blocking write. */
    void Write(struct InterthreadQueue* tq,void* val);

#endif
