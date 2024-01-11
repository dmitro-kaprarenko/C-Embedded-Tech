#include <stdio.h>
#include <stdlib.h>

// Structure representing information about a book
struct Book
{
    char title[100];
    float price;
    int pages;
    char language[20];
    float weight;
    int year;
    struct Book *next;
    struct Book *prev;
};

// Function to print information about a book
void printBook(struct Book *book)
{
    printf("Title: %s\n", book->title);
    printf("Price: %.2f\n", book->price);
    printf("Pages: %d\n", book->pages);
    printf("Language: %s\n", book->language);
    printf("Weight: %.2f\n", book->weight);
    printf("Year of publication: %d\n", book->year);
    printf("\n");
}

// Function to add a book to the linked list
void addBook(struct Book **head, struct Book **tail, struct Book book)
{
    struct Book *newBook = (struct Book *)malloc(sizeof(struct Book));
    *newBook = book;
    newBook->next = NULL;

    if (*head == NULL)
    {
        // If the list is empty, set the new book as both head and tail
        *head = newBook;
        *tail = newBook;
    }
    else
    {
        // Add the new book to the end of the list
        (*tail)->next = newBook;
        newBook->prev = *tail;
        *tail = newBook;
    }
}

int main()
{
    // Creating a doubly linked list of books
    struct Book *head = NULL;
    struct Book *tail = NULL;

    // Array of Harry Potter books
    struct Book harryPotterBooks[] = {
        {"Harry Potter and the Philosopher's Stone", 19.99, 320, "English", 0.7, 1997},
        {"Harry Potter and the Chamber of Secrets", 22.50, 352, "English", 0.8, 1998},
        {"Harry Potter and the Prisoner of Azkaban", 24.95, 416, "English", 0.9, 1999},
        {"Harry Potter and the Goblet of Fire", 27.99, 608, "English", 0.95, 2000},
        {"Harry Potter and the Order of the Phoenix", 29.99, 870, "English", 0.92, 2003},
        {"Harry Potter and the Half-Blood Prince", 32.50, 652, "English", 0.94, 2005},
        {"Harry Potter and the Deathly Hallows", 34.95, 784, "English", 0.97, 2007}};

    // Adding Harry Potter books to the linked list
    for (int i = 0; i < sizeof(harryPotterBooks) / sizeof(harryPotterBooks[0]); ++i)
    {
        addBook(&head, &tail, harryPotterBooks[i]);
    }

    // Printing information about the Harry Potter books
    struct Book *current = head;
    while (current != NULL)
    {
        printBook(current);
        current = current->next;
    }

    // Freeing memory, deleting the linked list
    current = head;
    while (current != NULL)
    {
        struct Book *nextBook = current->next;
        free(current);
        current = nextBook;
    }

    return 0;
}
