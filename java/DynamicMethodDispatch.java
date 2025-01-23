class laptop{
    void greet(){
        System.out.println("Hi, I am a Laptop.");
    }
}

class asus_laptop extends laptop{
    void greet(){
        System.out.println("Hi, I am a ASUS Laptop.");
    }
}

public class DynamicMethodDispatch {
    public static void main(String [] a){
        laptop mylaptop;
        mylaptop = new laptop();
        mylaptop.greet();
        mylaptop = new asus_laptop();
        mylaptop.greet();
    }
}
