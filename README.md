This program in c called BookList, is designed to manage a list of book using dat structure "BookList", 
each book in booklist is represented by a structure named Book, which has 
fields for the book's title, author, and release year.
The program includes functions for initializing the book list, checking if the list is empty, inserting
a new book into the list, and updating the release year of a book based on its title and the old release year.
Book is a data structure represents fields: title, author and releaseYear.
BookList is a data sturcture which contains an array of Book structures, book, and an integer, size, 
representing the current number of books in the list.
Function:
init_list: Initializes a book list by setting its size to 0.
isEmpty: Checks if the book list is empty and prints a message accordingly.
insertBook: Inserts a new book into the book list, given a book structure.
showListBook: show all books in your book  list.
showAllBooksByAuthor: show all books in your book list write by the same author.
updateYearRelease: Updates the release year of a book in the list based on the title, old release year to new release year.
booksReleaseBetweenYears: show the books from your book list released between year1 and year2
deleteBookByTitle: delete book from your book list after title
In main: initializes an empty book list using init_list, where the book will be stored, the book has a specific field title, author and realese year 
