package practicals.slip9;
/*
    b) Write a program to using  marker interface create a class  product(product_id, 
    product_name, product_cost, product_quantity) define a default and parameterized 
    constructor. Create  objects of class product and display the contents of each object 
    and Also display the object count
 */
import java.util.Scanner;

//Empty interface is called marker interface
interface ProductInfo {

}

class Product implements ProductInfo {
    int product_id;
    String product_name;
    float product_cost;
    String product_quality;

    static int TOTAL_PRODUCT = 0;

    Product() {

    }

    Product(int product_id, String product_name, float product_cost, String product_quality) {
        this.product_id = product_id;
        this.product_name = product_name;
        this.product_cost = product_cost;
        this.product_quality = product_quality;
        TOTAL_PRODUCT++;
    }

    void showDetails() {
        System.out.println("\nProduct id :" + this.product_id);
        System.out.println("Product name : " + this.product_name);
        System.out.println("Product cost :" + this.product_cost);
        System.out.println("Product Quality :" + this.product_quality);
    }

    public static void showTotalProduct() {
        System.out.println("\nTotal products :" + TOTAL_PRODUCT);
    }
}

public class Ex2 {
    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        System.out.print("Enter total products wants to create :");
        int n = scan.nextInt();

        Product[] arrProduct = new Product[n];
        for (int i = 0; i < n; i++) {
            System.out.print("\nEnter product id :");
            int id = scan.nextInt();

            scan.nextLine();
            System.out.print("Enter product name :");
            String name = scan.nextLine();

            System.out.print("Enter product cost :");
            float cost = scan.nextFloat();

            scan.nextLine();
            System.out.print("Enter Quality :");
            String quality = scan.nextLine();

            arrProduct[i] = new Product(id, name, cost, quality);

        }

        Product.showTotalProduct();
        for (int i = 0; i < n; i++) {
            arrProduct[i].showDetails();
        }

    }
}