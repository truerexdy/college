//This is a class whose method will be called by the two threads.
class counter{
    static int i = 1;
    synchronized void count(String threadname){
        i++;
        System.out.println("Incremented by " + threadname + ". Current count " + i);
    }
}

//Thread1 increments the value of i, which is static variable
class thread1 extends Thread{
    counter c = new counter();
    public void run(){
        for(int i=0; i<4; i++){
            c.count("Thread 1");
        }
    }
}

//Thread2 increments the value of i, which is static variable
class thread2 extends Thread{
    counter c = new counter();
    public void run(){
        for(int i=0; i<4; i++){
            c.count("Thread 2");
        }
    }
}

//Since both the threads are trying to increment the same variable so this might cause race condetion
//hence if we use a synchronized keyword for the method only one thread can be used at once

public class sync {
    public static void main(String args[]){
        thread1 a = new thread1();
        thread2 b = new thread2();
        a.start();
        b.start();
    }
}
