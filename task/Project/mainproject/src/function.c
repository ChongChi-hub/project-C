#include "datatype.h"
#include <stdio.h>
#include <string.h>

//Show menu
void showMenu() {
    printf("\n********** LIBRARY MANAGEMENT MENU **********\n");
        printf("---------------------------------------------\n");
        printf("|%-43s|\n","1. Add new books.");
        printf("|%-43s|\n","2. Show list of books.");
        printf("|%-43s|\n","3. Edit book information");
        printf("|%-43s|\n","4. Delete books.");
        printf("|%-43s|\n","5. Search for books.");
        printf("|%-43s|\n","6. Sort books by price.");
        printf("|%-43s|\n","7. Data storage.");
        printf("|%-43s|\n","8. Exit!!!");
        printf("---------------------------------------------\n");
        printf("Enter your choice: ");
}

int bookCount = 0; //Khai bao bien moi de luu sach moi 

//Them sach vao thu vien
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Thu vien da day!!!\n"); // Neu so luong sach co trong thu vien lon hon so luong toi da thi khong the them
        return; // Ket thuc ham, khong chay phan ham ben duoi
    }
    newBook.id = bookCount + 1; // Gan ID moi cho sach
    printf("Enter the name of the book: "); //Nhap ten cua sach
    scanf(" %[^\n]", newBook.title); // %[^\n]: Doc toan bo chuoi cho den khi gap dau xuong dong
    printf("Enter the author's name: ");
    scanf(" %[^\n]", newBook.author);
    printf("Enter the year of publication of the book: ");
    scanf("%d", &newBook.year);
    printf("Enter the book's genre: ");
    scanf(" %[^\n]", newBook.genre);
    printf("Enter the price of the book: ");
    scanf("%f", &newBook.price);

    library[bookCount] = newBook;  // Luu sach vao vi tri hien tai
    bookCount++;     // Tang so luong sach

    printf("Added books successfully!!!\n");
}

//Hien thi danh sach sach trong thu vien
void displayBooks() {
    if (bookCount == 0) {
        printf("The library doesn't have any books yet.\n"); //Trong thu vien chua co sach nao
        return;
    }
    printf("\n**************************** LIST OF BOOKS AVAILABLE IN THE LIBRARY ****************************\n");
    printf("------------------------------------------------------------------------------------------------\n");
    printf("|%-3s|%-30s|%-21s|%-10s|%-15s|%-10s|\n", "ID", "Name's book", "Author", "Year", "Genre", "Price");
    printf("------------------------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < bookCount; i++) {
        printf("|%-3d|%-30s|%-21s|%-10d|%-15s|%-10.2f|\n", 
               library[i].id, library[i].title, library[i].author, 
               library[i].year, library[i].genre, library[i].price);
               printf("------------------------------------------------------------------------------------------------\n");
    }
}