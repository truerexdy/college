import java.text.DecimalFormat;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class CurrencyConverter {
    // Map to store exchange rates relative to USD
    private static final Map<String, Double> EXCHANGE_RATES = new HashMap<>();
    
    // Static initializer block to set up initial exchange rates
    static {
        EXCHANGE_RATES.put("USD", 1.0);        // US Dollar
        EXCHANGE_RATES.put("EUR", 0.92);       // Euro
        EXCHANGE_RATES.put("GBP", 0.79);       // British Pound
        EXCHANGE_RATES.put("JPY", 149.50);     // Japanese Yen
        EXCHANGE_RATES.put("CAD", 1.35);       // Canadian Dollar
        EXCHANGE_RATES.put("AUD", 1.52);       // Australian Dollar
        EXCHANGE_RATES.put("CHF", 0.88);       // Swiss Franc
        EXCHANGE_RATES.put("CNY", 7.15);       // Chinese Yuan
        EXCHANGE_RATES.put("INR", 83.20);      // Indian Rupee
        EXCHANGE_RATES.put("BRL", 5.00);       // Brazilian Real
    }
    
    // Method to convert currency
    public static double convertCurrency(double amount, String fromCurrency, String toCurrency) {
        // First convert to USD, then to target currency
        if (!EXCHANGE_RATES.containsKey(fromCurrency) || !EXCHANGE_RATES.containsKey(toCurrency)) {
            throw new IllegalArgumentException("Unsupported currency");
        }
        
        // Convert from source to USD
        double amountInUSD = amount / EXCHANGE_RATES.get(fromCurrency);
        
        // Convert from USD to target currency
        return amountInUSD * EXCHANGE_RATES.get(toCurrency);
    }
    
    // Method to add or update exchange rates
    public static void updateExchangeRate(String currency, double rate) {
        EXCHANGE_RATES.put(currency, rate);
    }
    
    // Method to list all supported currencies
    public static void listSupportedCurrencies() {
        System.out.println("Supported Currencies:");
        for (String currency : EXCHANGE_RATES.keySet()) {
            System.out.println(currency + " (1 USD = " + EXCHANGE_RATES.get(currency) + " " + currency + ")");
        }
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        DecimalFormat df = new DecimalFormat("#.##");
        
        while (true) {
            try {
                System.out.println("\n--- Currency Converter ---");
                System.out.println("1. Convert Currency");
                System.out.println("2. List Supported Currencies");
                System.out.println("3. Exit");
                System.out.print("Enter your choice: ");
                
                int choice = scanner.nextInt();
                
                switch (choice) {
                    case 1:
                        // Currency Conversion
                        System.out.print("Enter amount to convert: ");
                        double amount = scanner.nextDouble();
                        
                        System.out.print("Enter source currency code (e.g., USD): ");
                        String fromCurrency = scanner.next().toUpperCase();
                        
                        System.out.print("Enter target currency code (e.g., EUR): ");
                        String toCurrency = scanner.next().toUpperCase();
                        
                        double convertedAmount = convertCurrency(amount, fromCurrency, toCurrency);
                        
                        System.out.println(amount + " " + fromCurrency + " = " + 
                                           df.format(convertedAmount) + " " + toCurrency);
                        break;
                    
                    case 2:
                        // List Supported Currencies
                        listSupportedCurrencies();
                        break;
                    
                    case 3:
                        // Exit the program
                        System.out.println("Thank you for using the Currency Converter!");
                        scanner.close();
                        System.exit(0);
                    
                    default:
                        System.out.println("Invalid choice. Please try again.");
                }
            } catch (IllegalArgumentException e) {
                System.out.println("Error: " + e.getMessage());
            } catch (Exception e) {
                System.out.println("An unexpected error occurred. Please try again.");
                scanner.nextLine(); // Clear input buffer
            }
        }
    }
}