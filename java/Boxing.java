// Way to convert primitive datatypes into wrapper classes
public class Boxing {
    public static void main(String a[]){
        int i = 9;
        Integer I = i; // Here i is auto-boxed to I
        System.out.println("This is a Integer:"+I);
        I = 6;
        i = I; // Here I is auto-unboxed to i
        System.out.println("This is a int:"+i);
    }
}
