#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h" // Nhung file header de dung ham da khai bao

int bookCount = 0; // Bien dem so luong sach hien co trong thu vien

//Ham hien thi xac thuc admin de quan ly thu vien
void adminLogin() {
    char username[50];
	char password[50];

    while (1) {
        printf("\n**********ADMIN LOGIN**********\n");
        printf("Enter username: ");
        scanf("%s", username);
        printf("Enter password: ");
        scanf("%s", password);

        // Kiem tra tai khoan va mat khau admin 
        if (strcmp(username, "admin") == 0 && strcmp(password, "123") == 0) {
            printf("Login successful! Welcome, Admin.\n");
            break; // Dang nhap thanh cong, thoat khoi vong lap 
        } else {
            printf("Invalid username or password. Please try again.\n");
        }
    }
} 

// Ham hien thi menu chinh 
void showMenu() {
    int choice;
    do {
        printf("\n********** LIBRARY MANAGEMENT SYSTEM **********\n");
        printf("----------------------------------------------\n");
        printf("|%-44s|\n", "1. Book Management");  // Quan ly sach
        printf("|%-44s|\n", "2. Member Management"); // Quan ly khach hang 
        printf("|%-44s|\n", "3. Exit"); // Thoat chuong trinh
        printf("----------------------------------------------\n");
        printf("Choose your option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                showBookMenu(); // Hien thi menu quan ly sach 
                break;
            case 2:
                // Hien thi menu quan ly khach hang 
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (1); //Lap cho den khi co lenh exit 
}

// Ham hien thi menu quan ly sach 
void showBookMenu(){
	int choice;
    do {
        printf("\n********** LIBRARY MANAGEMENT MENU **********\n");
        printf("---------------------------------------------\n");
        printf("|%-43s|\n","1. Add new books."); // Them sach moi
        printf("|%-43s|\n","2. Display book list."); // Hien thi danh sach sach
        printf("|%-43s|\n","3. Edit book info rmation"); // Chinh sua thong tin sach
        printf("|%-43s|\n","4. Delete books."); // Xoa sach
        printf("|%-43s|\n","5. Search book by title."); // Tim kiem sach
        printf("|%-43s|\n","6. Sort books by price."); // Sap xep sach theo gia tien(tang dan/giam dan)
        printf("|%-43s|\n","7. Back to main menu!!!");
        printf("---------------------------------------------\n");
        printf("Choose your option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(); // Them sach vao thu vien 
                break;
            case 2:
                displayBooks(); // Hien thi danh sach sach ra man hinh 
                break;
            case 3:
                editBook(); // Chinh sua thong tin sach 
                break;
            case 4:
                deleteBook(); // Xoa sach khoi thu vien 
                break;
            case 5:
				searchBook(); // Tim kiem sach  
				break;
			case 6:
				sortBooksByPrice(); // Sap xep sach theo gia tien (giam dan/tang dan) 
				 break; 
			case 7:
				 printf("Returning to main menu...\n");
                	return; // quay ve menu chinh 
            default:
                printf("Invalid option! Please try again.\n"); 
        }
    } while (choice != 7);
} 
// Ham hien thi menu quan ly khach hang 
// Ham luu danh sach sach vao file
void saveBooksToFile() {
    FILE *file = fopen("book.bin", "wb"); // Mo file nhi phan de ghi
    if (file == NULL) {
        printf("Cannot open file to write!\n"); // Neu trong file trong thi khong the mo file de viet 
        return;
    }

    fprintf(file, "%d\n", bookCount);  // Ghi so luong sach
    for (int i = 0; i < bookCount; i++) {
        fprintf(file, "%d\n%s\n%s\n%d\n%s\n%f\n", 
                library[i].id, library[i].title, library[i].author,
                library[i].year, library[i].genre, library[i].price);
    }
    fclose(file);
    printf("Book list has been saved to 'book.bin'.\n");
}

// Ham them sach vao thu vien
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full!\n"); // Neu so luong sach trong thu vien da toi da thong bao thu vien day 
        return;
    }

    newBook.id = bookCount + 1; // Gan ID cho sach 

    printf("Enter book title: ");
    scanf(" %[^\n]", newBook.title);
    printf("Enter author name: ");
    scanf(" %[^\n]", newBook.author);
    printf("Enter year of publication: ");
    scanf("%d", &newBook.year);
    printf("Enter book genre: ");
    scanf(" %[^\n]", newBook.genre);
    printf("Enter book price: ");
    scanf("%f", &newBook.price);

    library[bookCount] = newBook; // Luu sach vao mang
    bookCount++; // Tang so luong sach

    saveBooksToFile(); // Luu vao file
    printf("Book has been successfully added!\n");
}

// Ham hien thi danh sach sach
void displayBooks() {
    if (bookCount == 0) {
        printf("The library has no books.\n");
        return;
    }
    
    printf("\n*****************************LIST OF BOOKS AVAILABLE IN THE LIBRARY*****************************\n");
    printf("------------------------------------------------------------------------------------------------\n");
    printf("|%-3s|%-30s|%-21s|%-10s|%-15s|%-10s|\n","ID","Title","Author","Year","Genre","Price");
    printf("------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < bookCount; i++) {
        printf("|%-3d|%-30s|%-21s|%-10d|%-15s|%-10.2f|\n",
               library[i].id, library[i].title, library[i].author,
               library[i].year, library[i].genre, library[i].price);
               printf("------------------------------------------------------------------------------------------------\n");
    }
}

// Ham sua thong tin sach
void editBook() {
	if (bookCount == 0) {
        printf("The library has no books.\n");
        return;
    }
    int id;
    printf("Enter the book ID to edit: ");
    scanf("%d", &id);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            printf("Enter new book title: ");
            scanf(" %[^\n]", library[i].title);
            printf("Enter new author name: ");
            scanf(" %[^\n]", library[i].author);
            printf("Enter new year of publication: ");
            scanf("%d", &library[i].year);
            printf("Enter new genre: ");
            scanf(" %[^\n]", library[i].genre);
            printf("Enter new price: ");
            scanf("%f", &library[i].price);

            printf("Book has been successfully edited!\n");
            saveBooksToFile(); // Luu thong tin sach da chinh sua vao file 
            return;
        }
    }

    printf("Book ID does not exist.\n"); //ID sach khong ton tai
}

// Ham xoa sach khoi thu vien  
void deleteBook() {
	if (bookCount == 0) {
        printf("The library has no books.\n");
        return;
    }
	int id;
    printf("Enter the book ID to delete: ");
    scanf("%d", &id);
    int check = -1; // Bien check dung de luu vi tri sach can xoa, mac dinh -1 nghia la khong tim thay.
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            check = i;
            break;
        }
    }
    if (check == -1) {
        printf("Book ID does not exist.\n");
        return;
    }
    char confirm; // Bien confirm dung de luu lua chon cua nguoi dung khi xac nhan xoa sach
    printf("Are you sure you want to delete this book? (y/n): ");
    scanf(" %c", &confirm);
    if (confirm == 'y' || confirm == 'Y') {
        // Vong lap nay dich chuyen cac sach phia sau len mot vi tri de xoa sach can xoa
        for (int i = check; i < bookCount - 1; i++) {
            library[i] = library[i + 1];
        }
        bookCount--;
        saveBooksToFile();
        printf("Book has been successfully deleted!\n");
    } else {
        printf("Book deletion canceled.\n");
    }
}

//Ham tim kiem sach trong thu vien
void searchBook() {
	if (bookCount == 0) {
        printf("The library has no books.\n");
        return;
    }
	char keyword[MAX_STRING_LENGTH];
    printf("Enter book title to search: ");
    scanf(" %[^\n]", keyword);
    
    int found = 0;
    printf("\n*******************************SEARCH RESULTS*******************************\n");
    printf("------------------------------------------------------------------------------------------------\n");
    printf("|%-3s|%-30s|%-21s|%-10s|%-15s|%-10s|\n","ID","Title","Author","Year","Genre","Price");
    printf("------------------------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < bookCount; i++) {
        if (strstr(library[i].title, keyword) != NULL) { // Kiem tra tu khoa co trong ten sach hay khong
            printf("|%-3d|%-30s|%-21s|%-10d|%-15s|%-10.2f|\n",
               library[i].id, library[i].title, library[i].author,
               library[i].year, library[i].genre, library[i].price);
            printf("------------------------------------------------------------------------------------------------\n");
            found = 1;
        }
    }
    
    if (!found) {
        printf("No books found with the given title keyword.\n");
    }
}

// Ham sap xep sach theo gia tien 
void sortBooksByPrice() {
    if (bookCount == 0) {
        printf("The library has no books to sort.\n");
        return;
    }

    int order;
    do {
        printf("\n********** SORT BOOKS BY PRICE **********\n");
        printf("-----------------------------------------\n");
        printf("|%-39s|\n", "1. Ascending Order (low to high)");  // Sap xep tang dan 
        printf("|%-39s|\n", "2. Descending Order (high to low)"); // Sap xep giam dan 
        printf("|%-39s|\n", "3. Back to Book Menu"); // Quay lai menu sach 
        printf("-----------------------------------------\n");
        printf("Choose your option: ");
        scanf("%d", &order);

        if (order == 3) return; // Quay lai menu truoc do 

        if (order != 1 && order != 2) {
            printf("Invalid option! Please try again.\n");
            continue;
        }

        // Bubble Sort su dung toan tu ba ngoi 
        for (int i = 0; i < bookCount - 1; i++) {
            for (int j = 0; j < bookCount - i - 1; j++) {
                int condition = (order == 1) ? 
                                (library[j].price > library[j + 1].price)  // Tang dan 
								: (library[j].price < library[j + 1].price); // Giam dan 
                
                if (condition) {
                    struct Book temp = library[j];
                    library[j] = library[j + 1];
                    library[j + 1] = temp;
                }
            }
        }

        printf("Books sorted successfully!\n");
		displayBooks(); // Hien thi danh sach sach da sap xep  
    } while (1); // Lap lai neu chon sai 
}

