class MyPoint{
    int x;
    int y;
    MyPoint(){
        this.x = 0;
        this.y = 0;
    }
    MyPoint(int x, int y){
        this.x = x;
        this.y = y;
    }
    void setXY(int x, int y){
        this.x = x;
        this.y = y;
    }
    int[] getXY(){
        int[] coords = new int[2];
        coords[0]=this.x;
        coords[1]=this.y;
        return coords;
    }
    String ToString(){
        String temp = "X=" + this.x + " Y=" + this.y;
        return temp;
    }
    double Distance(int x, int y){
        double d = Math.sqrt((double)(Math.pow(this.x-x,2)+Math.pow(this.y-y,2)));
        return d;
    }
    double Distance(MyPoint point){
        double d = Math.sqrt((double)(Math.pow(this.x-point.x,2)+Math.pow(this.y-point.y,2)));
        return d;
    }
    double Distance(){
        double d = Math.sqrt((double)(Math.pow(this.x,2)+Math.pow(this.y,2)));
        return d;
    }
}

public class TestMyPoint{
    public static void main(String a[]){
        MyPoint p1 = new MyPoint();
        MyPoint p2 = new MyPoint(5, 10);
        p1.setXY(3, 6);
        int[] p1coords = new int[2];
        p1coords = p1.getXY();
        System.out.println("P1 X="+ p1coords[0]+" Y="+ p1coords[1]);
        System.out.println("P1 "+p2.ToString());
        System.out.println(String.format("Distance of p1 from (3,12) is %.2f", p1.Distance(3, 12)));
        System.out.println(String.format("Distance of p1 from p2 is %.2f", p1.Distance(p2)));
        System.out.println(String.format("Distance of p1 from Origin is %.2f", p1.Distance()));
    }
}