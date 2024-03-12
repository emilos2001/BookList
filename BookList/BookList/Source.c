//directive is specific to Microsoft's Visual Studio compiler and is used to suppress 
// warning messages related to the use of certain "unsafe" or deprecated functions.
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

#define MAX_SIZE 1000 
#define SUCCESS 0
#define POSITION_INIT 1
#define INVALID_POSITION 2
#define POSITION_EMPTY 3
#define LIST_FULL 4

typedef struct {
	char title[100];
	char author[50];
	int releaseYear;
} Book;

typedef struct {
	Book book[MAX_SIZE];
	int size;
} BookList;
//initialize the book list
void init_list(BookList* list) {
	list->size = 0;
}
//verify if book list is empty
int isEmpty(BookList* list) {
	if (list->size != 0) {
		printf("Book list is not empty\n");
	}
	else {
		printf("No book in the book list\n");
	}
}
//insert the book in book list
int insertBook(BookList* list, Book book) {
	if (list->size < MAX_SIZE) {
		list->book[list->size] = book;
		list->size++;
		return SUCCESS;
	}
	else {
		return LIST_FULL;
	}
}
//show book list
void showListBook(BookList* list) {
	if (list->size == 0) {
		printf("The booklist is empty\n");
	}
	for (int i = 0; i < list->size; i++) {
		printf("Nr : %d:    Title : %s    |    Author : %s    |    Release in : %d\n",
			i, list->book[i].title,
			list->book[i].author,
			list->book[i].releaseYear
		);
	}
}
//delete book from book list by the author
void deleteBookByTitle(BookList* list, char* title) {
	int found = 0;
	for (int i = 0; i < list->size; i++) {
		if (strcmp(list->book, title) != 0) {
			for (int j = 0; j < list->size - 1; j++) {
				list->book[j] = list->book[j + 1];
			}
			list->size--;
			found = 1;
			break;
		}
	}
	if (found) {
		printf("The book %s has found and delete", title);
		return SUCCESS;
	} else {
		printf("The book %s has no found", title);
	}
}
//show all books in book list write by the same author
void showAllBooksByAuthor(BookList* list, char* author) {
	int found = 0;
	for (int i = 0; i < list->size; i++) {
		if (strcmp(list->book[i].author, author) == 0) {
			found = 1;
			printf("Nr.%d:   title : %s		|		author : %s\n",
				i, list->book[i].title, list->book[i].author
				);
		}
	}
	if (found = 0) {
		printf("The author %s has no found", author);
	}
}
//update the year of release
void updateYearRelease(BookList* list, const char* title, int oldYear, int newYear) {
	int found = 0;
	for (int i = 0; i < list->size; i++) {
		if (strcmp(list->book[i].title, title) == 0) {
			found = 1;
			if (list->book[i].releaseYear == oldYear) {
				list->book[i].releaseYear = newYear;
				printf("At %s, the year of release was changed from: %d to: %d\n",
					title, oldYear, newYear);
			}
		}
	}

	if (!found) {
		printf("Book with title '%s' not found in the list.\n", title);
	}
}

int main() {
	BookList list;
	init_list(&list);
	Book firstBook;
	Book secondBook;
	Book thirdBook;
	Book fourthBook;
	Book fifthBook;
	strcpy(firstBook.title, "King Rat");
	strcpy(firstBook.author, "James Clavel");
	firstBook.releaseYear = 2015;
	strcpy(secondBook.title, "The principles of the changing world order");
	strcpy(secondBook.author, "Ray Dalio");
	secondBook.releaseYear = 2021;
	strcpy(thirdBook.title, "The Principles");
	strcpy(thirdBook.author, "Ray Dalio");
	thirdBook.releaseYear = 2017;
	strcpy(fourthBook.title, "Red Mars");
	strcpy(fourthBook.author, "Kim Stanley Robinson");
	fourthBook.releaseYear = 1992;
	strcpy(fifthBook.title, "Shogun");
	strcpy(fifthBook.author, "James Clavel");
	fifthBook.releaseYear = 2015;
	insertBook(&list, firstBook);
	insertBook(&list, secondBook);
	insertBook(&list, thirdBook);
	insertBook(&list, fourthBook);
	insertBook(&list, fifthBook);
	updateYearRelease(&list, "Red Mars", 1992, 2003);
	showListBook(&list);
	return 0;
}