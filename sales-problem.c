#include <stdio.h>

// Define the number of months in a year
#define NUM_MONTHS 12

// Print the sales report for the year
void printSalesReport(float sales[], char* months[]) {
    printf("Monthly sales report for 2022:\n");
    printf("Month          Sales\n"); 
    for (int i = 0; i < NUM_MONTHS; i++) {
        printf("%-14s$%.2f\n", months[i], sales[i]); 
    }
}


// Print the sales summary for the year
void printSalesSummary(float sales[], char* months[]) {
    float min = sales[0];
    float max = sales[0];
    float sum = sales[0];
    for (int i = 1; i < NUM_MONTHS; i++) {
        if (sales[i] < min) {
            min = sales[i];
        }
        if (sales[i] > max) {
            max = sales[i];
        }
        sum += sales[i];
    }
    float average = sum / NUM_MONTHS;

    printf("Sales summary:\n");
    printf("Minimum sales: $%.2f (%s)\n", min, months[0]);
    printf("Maximum sales: $%.2f (%s)\n", max, months[NUM_MONTHS - 1]);
    printf("Average sales: $%.2f\n", average);
}

// Print the six-month moving average report
void printMovingAverages(float sales[], char* months[]) {
    printf("Six-Month Moving Average Report:\n");
    for (int i = 0; i < NUM_MONTHS - 5; i++) {
        float sum = 0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        float average = sum / 6;
        printf("%s - %s $%.2f\n", months[i], months[i + 5], average);
    }
}

// Print the sales report in descending order
void printSalesReportDescending(float sales[], char* months[]) {
    printf("Sales Report (Highest to Lowest):\n");
    printf("Month          Sales\n"); // Adjusted tab width
    for (int i = NUM_MONTHS - 1; i >= 0; i--) {
        printf("%-14s$%.2f\n", months[i], sales[i]); // Adjusted width for month column
    }
}


// Main function
int main() {
    // Array of sales data for each month
    float sales[NUM_MONTHS]; 

    // Array of month names
    char* months[NUM_MONTHS] = {"January", "February", "March", "April", "May", "June",
                                "July", "August", "September", "October", "November", "December"};

    // Open the file for reading
    FILE *file = fopen("sales_data.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read the sales data from the file
    for (int i = 0; i < NUM_MONTHS; i++) {
        if (fscanf(file, "%f", &sales[i]) != 1) {
            printf("Error reading sales data from file.\n");
            fclose(file);
            return 1;
        }
    }

    // Close the file
    fclose(file);

    // Print the sales report
    printSalesReport(sales, months);
    printf("\n");
    printSalesSummary(sales, months);
    printf("\n");
    printMovingAverages(sales, months);
    printf("\n");
    printSalesReportDescending(sales, months);

    return 0;
}
