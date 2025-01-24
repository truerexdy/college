class NegativeOddNumberException extends Exception{
    public NegativeOddNumberException(){
        super("Number is Negative Odd Number");
    }
}

public class Custom_Exception {
    public static void main(String s[]){
        try{
            int i = -5;
            if(i<0 && (i%2 != 0)){
                throw new NegativeOddNumberException();
            }
        }
        catch(NegativeOddNumberException e){
            System.err.println(e.getMessage());
        }
    }
}
