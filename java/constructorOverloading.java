class car{
    String name;
    double price;
    car(){
        name = "no-name";
        price = 0;
    }
    car(String n){
        name = n;
        price = 0;
    }
    car(String n, double p){
        name =n;
        price =p;
    }
}

public class constructorOverloading{
    public static void main(String a[]){
        car mycar = new car();
        car hiscar = new car("Maruthi");
        car shecar = new car("kia",709009);
    }
}