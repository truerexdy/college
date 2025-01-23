class mythread extends Thread{
    static int count = 0;
    mythread(){
        setName("Child Thread No "+ (++count));
    }
    public void run(){
        System.out.println("This is a child thread "+this.getName());
    }
}


public class Threads{
    public static void main(String [] a){
        mythread obj = new mythread();
        obj.start();
        mythread obj1 = new mythread();
        obj1.start();;
        System.out.println("This is a parent thread");
    }
}