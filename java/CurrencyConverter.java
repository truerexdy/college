import java.text.DecimalFormat;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class CurrencyConverter {
    private static final Map<String, Double> EXCHANGE_RATES = new HashMap<>();
    static {
        EXCHANGE_RATES.put("USD", 1.0);
        EXCHANGE_RATES.put("EUR", 0.92);
        EXCHANGE_RATES.put("GBP", 0.79);
        EXCHANGE_RATES.put("JPY", 149.50);
        EXCHANGE_RATES.put("CAD", 1.35);
        EXCHANGE_RATES.put("AUD", 1.52);
        EXCHANGE_RATES.put("CHF", 0.88);
        EXCHANGE_RATES.put("CNY", 7.15);
        EXCHANGE_RATES.put("INR", 83.20);
        EXCHANGE_RATES.put("BRL", 5.00);
    }
    public static double convertCurrency(double amount, String fromCurrency, String toCurrency) {
        if (!EXCHANGE_RATES.containsKey(fromCurrency) || !EXCHANGE_RATES.containsKey(toCurrency)) {
            throw new IllegalArgumentException("Unsupported currency");
        }
        double amountInUSD = amount / EXCHANGE_RATES.get(fromCurrency);
        return amountInUSD * EXCHANGE_RATES.get(toCurrency);
    }
    public static void updateExchangeRate(String currency, double rate) {
        EXCHANGE_RATES.put(currency, rate);
    }
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
                System.out.println("3. Update Exchange Rate");
                System.out.println("4. Exit");
                System.out.print("Enter your choice: ");
                int choice = scanner.nextInt();
                switch (choice) {
                    case 1:
                        System.out.print("Enter amount to convert: ");
                        double amount = scanner.nextDouble();
                        System.out.print("Enter source currency code (e.g., USD): ");
                        String fromCurrency = scanner.next().toUpperCase();
                        System.out.print("Enter target currency code (e.g., EUR): ");
                        String toCurrency = scanner.next().toUpperCase();
                        double convertedAmount = convertCurrency(amount, fromCurrency, toCurrency);
                        System.out.println("\n"+amount + " " + fromCurrency + " = " + df.format(convertedAmount) + " " + toCurrency);
                        break;
                    case 2:
                        listSupportedCurrencies();
                        break;
                    case 3:
                        System.out.print("Enter currency code to update (e.g., EUR): ");
                        String currencyToUpdate = scanner.next().toUpperCase();                        
                        if (!EXCHANGE_RATES.containsKey(currencyToUpdate)) {
                            System.out.println("Currency not found. Use option 2 to see supported currencies.");
                            break;
                        }
                        System.out.print("Enter new exchange rate (1 USD = X " + currencyToUpdate + "): ");
                        double newRate = scanner.nextDouble();
                        updateExchangeRate(currencyToUpdate, newRate);
                        break;
                    case 4:
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
                scanner.nextLine();
            }
        }
    }
}