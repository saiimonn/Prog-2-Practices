## Product 1(Review)
## by Patrick Roy Elalto

You are required to implement a set of utility functions to support managing and displaying information related to products and dates within an inventory system. These functions will help in presenting the stored data in a readable and structured format, as well as assist in creating date instances.

## The functions and their requirements are as follows:

**void displayDate(Date d);**
Purpose:
Display a given date in a human-readable format.
Input:
A Date structure that contains integer fields for day (date), month (month), and year (year). The month field is zero-indexed (0 means January, 11 means December).
Output:
Prints the date to the standard output in the format:
DD MMM YYYY
where MMM is the three-letter abbreviation of the month (e.g., Jan, Feb, Mar, ...).
Example:
For input {date=5, month=0, year=2023}, the output should be:
05 Jan 2023


**void displayProduct(Product p);**
Purpose:
Display all details of a single product in a structured format.
Input:
A Product structure containing:
prodID: integer product identifier
prodName: string (char array) for product name
prodShelfLife: integer shelf life in months
prodMFG: Date of manufacturing
prodQty: integer quantity available
Output:
Prints all product attributes to standard output with appropriate labels and formatting. The manufacturing date should be displayed using the displayDate() function.
Example:
Product ID: 101
Product Name: Milk
Shelf Life: 6 months
Manufacturing Date: 15 Jan 2023
Quantity: 20


**void displayProducts(ProductList prodList);**
Purpose:
Display the details of all products contained within a product list.
Input:
A ProductList structure containing:
A dynamically allocated array of Product items (prods)
count: current number of products in the list
max: maximum capacity
Output:
Iterates through each product in the list and displays its details. Products should be separated visually for clarity.


**Date createDate(int date, int month, int year);**
Purpose:
Create and initialize a Date structure instance with provided day, month, and year values.
Input:
date: Day of the month (1-31)
month: Month of the year, zero-indexed (0 for January through 11 for December)
year: Four-digit year value (e.g., 2023)
Output:
Returns a Date struct populated with the given values.
Notes:
This function does not perform date validity checks; assume input values are valid.


**Product createProduct(int prodID, char prodName[], int prodShelfLife, Date prodMFG, int prodQty);**
Purpose:
Create and initialize a Product structure instance with the provided product details.
Input:
prodID: Integer identifier for the product.
prodName: String (character array) representing the product name.
prodShelfLife: Integer denoting the product's shelf life in months.
prodMFG: Date structure representing the manufacturing date of the product.
prodQty: Integer quantity of the product available.
Output:
Returns a Product struct populated with the provided information.

## Notes:
The function should safely copy the product name string into the struct.
No validation of input data is required beyond copying.