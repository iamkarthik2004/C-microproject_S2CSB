/*******************************************************
C PROGRAMMING MICROPROJECT - CSE B - SJCET PALAI (2023-27 BATCH)

SUBMITTED TO:
Prof. Smitha Jacob
Assistant Professor
Department of Computer Science & Engineering

PROJECT SUBMITTED BY:
KARTHIK KRISHNAN
CSE - B
ROLL NO: 45
2023-27 BATCH

SUBMITTED DATE:
15th July 2024
-----------------------------------------

project Name: Auction Management System
Short Description: Manage auctions
Detailed Description: Create a system for conducting auctions, managing item listings, bidding processes, and closing auctions


*******************************************************
*/


#include <stdio.h>
#include <string.h>

// Define constants
#define MAX_ITEMS 100

// Define structure for auction item
struct AuctionItem {
    int itemID;
    char name[50];
    char description[200];
    float startingBid;
    float currentBid;
    int status; // 0 for Open, 1 for Closed
};

// Declare array of auction items and counter for number of items
struct AuctionItem items[MAX_ITEMS];
int itemCount = 0;

// Function prototypes
void addItem();
void listItems();
void placeBid();
void closeAuction();

// Main menu function
int main() {
    int choice;

    do {
        printf("\nAuction Management System\n");
        printf("1. Add Item\n");
        printf("2. List Items\n");
        printf("3. Place Bid\n");
        printf("4. Close Auction\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addItem();
                break;
            case 2:
                listItems();
                break;
            case 3:
                placeBid();
                break;
            case 4:
                closeAuction();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 5);

    return 0;
}

// Function to add a new item to the auction
void addItem() {
    if(itemCount >= MAX_ITEMS) {
        printf("Cannot add more items.\n");
        return;
    }

    struct AuctionItem newItem;
    newItem.itemID = itemCount + 1;

    printf("Enter item name: ");
    scanf(" %[^\n]%*c", newItem.name);
    printf("Enter item description: ");
    scanf(" %[^\n]%*c", newItem.description);
    printf("Enter starting bid: ");
    scanf("%f", &newItem.startingBid);

    newItem.currentBid = newItem.startingBid;
    newItem.status = 0; // Set status to Open

    items[itemCount++] = newItem;

    printf("Item added successfully.\n");
}

// Function to list all items in the auction
void listItems() {
    if(itemCount == 0) {
        printf("No items available.\n");
        return;
    }

    printf("\nList of Auction Items\n");
    for(int i = 0; i < itemCount; i++) {
        printf("Item ID: %d\n", items[i].itemID);
        printf("Name: %s\n", items[i].name);
        printf("Description: %s\n", items[i].description);
        printf("Starting Bid: %.2f\n", items[i].startingBid);
        printf("Current Bid: %.2f\n", items[i].currentBid);
        printf("Status: %s\n", items[i].status == 0 ? "Open" : "Closed");
        printf("---------------------------------------------\n");
    }
}

// Function to place a bid on an item in the auction
void placeBid() {
    int itemID;
    float bidAmount;

    printf("Enter item ID to place bid: ");
    scanf("%d", &itemID);

    if(itemID < 1 || itemID > itemCount) {
        printf("Invalid item ID.\n");
        return;
    }

    struct AuctionItem *item = &items[itemID - 1];

    if(item->status == 1) {
        printf("Auction for this item is closed.\n");
        return;
    }

    printf("Current Bid for %s: %.2f\n", item->name, item->currentBid);
    printf("Enter your bid amount: ");
    scanf("%f", &bidAmount);

    if(bidAmount <= item->currentBid) {
        printf("Bid amount must be higher than the current bid.\n");
        return;
    }

    item->currentBid = bidAmount;
    printf("Bid placed successfully.\n");
}

// Function to close an auction for a specific item
void closeAuction() {
    int itemID;

    printf("Enter item ID to close auction: ");
    scanf("%d", &itemID);

    if(itemID < 1 || itemID > itemCount) {
        printf("Invalid item ID.\n");
        return;
    }

    struct AuctionItem *item = &items[itemID - 1];

    if(item->status == 1) {
        printf("Auction is already closed for this item.\n");
        return;
    }

    item->status = 1; // Set status to Closed

    printf("Auction closed for the item: %s\n", item->name);
    printf("Final Bid: %.2f\n", item->currentBid);
}


