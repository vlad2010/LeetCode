/*

622. Design Circular Queue

Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

Implementation the MyCircularQueue class:

    MyCircularQueue(k) Initializes the object with the size of the queue to be k.
    int Front() Gets the front item from the queue. If the queue is empty, return -1.
    int Rear() Gets the last item from the queue. If the queue is empty, return -1.
    boolean enQueue(int value) Inserts an element into the circular queue. Return true if the operation is successful.
    boolean deQueue() Deletes an element from the circular queue. Return true if the operation is successful.
    boolean isEmpty() Checks whether the circular queue is empty or not.
    boolean isFull() Checks whether the circular queue is full or not.
*/


class MyCircularQueue {
private:
    vector<int> buf;
    int readPtr=0;
    int writePtr=0;
    bool isEmptyFlag = true;
    
    void moveWritePointer()
    {
        isEmptyFlag=false;
        writePtr++;
        if(writePtr==buf.size())
            writePtr=0;
    }

    void moveReadPointer()
    {
        readPtr++;
        if(readPtr==buf.size())
            readPtr=0;
        
        if(readPtr == writePtr)
            isEmptyFlag = true;
    }
    
    
    void Status()
    {
        cout << "Status: readPtr:" << readPtr << " writePtr:" << writePtr << " isEmptyFlag:" << isEmptyFlag << endl;
        
        for(auto i: buf)
        {
            cout << i << " "; 
        }
    }

public:
    
    MyCircularQueue(int k) {
        buf.resize(k,0);
    }
    
    bool enQueue(int value) {
        
        if(!isFull())
        {
           buf[writePtr] = value;
           moveWritePointer();
           return true;
        }
        
        //cout << "enQueue is full ! " << endl; 
        
        return false;
    }
    
    bool deQueue() {
        
        if(isEmpty())
            return false;
        
        moveReadPointer();
        
        return true;
    }
    
	// next element to read on the front 
    int Front() {
        
        if(isEmpty())
            return -1;
        
        return buf[readPtr];
    }
    
	// just written element 
    int Rear() {
        
        //Status();
        
        if(isEmpty())
            return -1;
        
        if(writePtr==0)
            return buf[buf.size()-1];    

        //return buf[readPtr];
        return buf[writePtr-1];
    }
    
    bool isEmpty() {
        
        if(isEmptyFlag)
            return true;
        
        return false;
    }
    
    bool isFull() {

        if(!isEmptyFlag && writePtr==readPtr)
           return true;

        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */