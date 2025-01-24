import java.util.Stack;

public class StackDemo {
    public static void main(String s[]){
        Stack<Integer> a = new Stack<>();
        a.push(6);
        a.push(2);
        System.out.println("Top Element is " + a.peek());
        a.pop();
        System.out.println("6 is at " + a.search(6));
    }
}