## Product 2
## by Gran Sabandal

You are provided with the following data structures and helper functions (already implemented and available for use):

Date structure representing a date with fields: date, month (0 for January to 11 for December), and year.
Product structure containing product details including a manufacturing date (prodMFG).
ProductList structure representing a dynamic collection of Product items, with fields for the product array pointer, current item count, and maximum capacity.

## Helper functions for date-related operations:

**isLeapYear(int year)** — determines if a year is a leap year.

**daysInMonth(int month, int year)** — returns the number of days in the given month and year.

**totalDays(Date d)** — returns the total number of days since a reference point for the given date.

**differenceDate(Date d1, Date d2)** — calculates the difference in days between two dates.

## Your task is to implement the following function:
**bool addItemSortedByMFG(ProductList *list, Product p);**

This function must:

Add the provided product p into the list such that the array remains sorted in ascending order by manufacturing date (prodMFG). The earliest manufacturing date should be placed first.
If the list has reached its maximum capacity (list->count == list->max), the function must not add the product and return false.
If there is capacity, insert the product at the correct sorted position, adjust the count accordingly, and return true.
Constraints and Notes:

You do not need to implement or modify the helper functions; they can be used for accurate date comparisons.
The product list is a dynamically allocated array; resizing is not required.
Focus solely on maintaining the sorted order based on manufacturing dates when adding new items.
The month field in dates ranges from 0 (January) to 11 (December).