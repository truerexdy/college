import java.util.Scanner;

public class lin_search {
    public static void main(String a[]){
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the size of array: ");
        int n = s.nextInt();
        int array[] = new int[n];
        System.out.println("Enter the elements in the array: ");
        for(int i=0; i<n; i++){
            array[i] = s.nextInt();
        }
        System.out.println("Enter the key: ");
        int key = s.nextInt();

        int i;
        boolean flag = false;
        for(i=0; i<n; i++){
            if(array[i] == key){
                flag = true;
                break;
            }
        }
        if(flag == true){
            System.out.println("Key " + key + " Found at position " + (i+1));
        }
        else{
            System.out.println("Key " + key + " Not found");
        }
    }
}
