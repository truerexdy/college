enum days{
    mon, tue, wed, thu, fri, sat, sun
}

public class Enum {
    public static void main(String args[]){
        days day = days.mon;
        System.out.println(day);
        //Values is used to return an iterator for all the values in an enum
        System.out.println("Iterator:");
        for(days i : days.values()){
            System.out.println(i);
        }
        //ValueOf() is used to convert a string into a value of an enum
        day = days.valueOf("fri");
        System.out.println("After using value of:");
        System.out.println(day);

    }
}
