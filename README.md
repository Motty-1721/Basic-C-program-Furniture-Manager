# Basic-C-program-Furniture-Manager
I aim to apply fundamental principles of the C language to this furniture application, focusing on tracking user information and purchase history through effective file handling techniques.

The &quot;Tagalog Furniture Purchase Manager&quot; is a user-friendly program that lets the user
explore and experience the feeling of purchasing furniture items from the comfort of
their own computer. When you run the program, you&#39;ll be greeted with a welcoming
message that includes the current date and time.

To get started, the program presents you with a main menu. From there, you have a few
options to choose from. If you select &quot;Buy Furniture,&quot; you can browse through a
selection of furniture items available for purchase. Each item is listed with its name and
price. You simply need to enter the corresponding number of the item you want to buy.

Once you&#39;ve made a selection, you can choose to add more items to your purchase or
proceed to checkout. If you decide to add more items, the program will prompt you to
make additional selections. It will keep track of the items you&#39;ve chosen and calculate
the total price for you.

When you&#39;re done with your shopping, you can choose the &quot;Exit&quot; option from the main
menu to finish the program. It will display a closing message, and you can close the
program window.

Throughout the process, the program will ask for your full name so that it can
personalize your experience and keep a record of your purchases. The program will
store the details of your purchases, including the item names and prices, in a file named
&quot;purchases.txt&quot; for future reference.

The &quot;Tagalog Furniture Purchase Manager&quot; program aims to provide a convenient and
enjoyable way for you to explore and buy furniture items. Whether you&#39;re looking for a
new chair, table, sofa, or any other furniture piece, this program will assist you in
making your choices and keeping track of your purchases.

Arrays Used
1. custName[MAX_NAME]; - This array of characters stores the full name of the
customer. It allows the program to personalize the customer&#39;s experience and
include their name in the purchase records.
2. names[MAX_FURNITURE][MAX_NAME_LENGTH]; - This array of strings stores the
names of the available furniture items. Each row represents a furniture item, and

each column represents a character in the name. The maximum length of each name
is defined by MAX_NAME_LENGTH.
3. prices[MAX_FURNITURE]; - This array of floats stores the prices of the furniture
items. Each element corresponds to the price of the furniture item at the same index
in the names array.
4. purchases[MAX_FURNITURE][MAX_NAME_LENGTH]; -This array of strings stores the
names of the furniture items that the customer has purchased. Each row represents
a purchased item, and each column represents a character in the name. The
maximum length of each name is defined by MAX_NAME_LENGTH.
5. purchasePrices[MAX_FURNITURE]; - This array of floats stores the prices of the
furniture items that the customer has purchased. Each element corresponds to the
price of the purchased item at the same index in the purchases array.
