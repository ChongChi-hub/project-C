#include <stdio.h>
#include <stdlib.h>
#include "function.c"

int main(int argc, char *argv[]) {
    do{
        int choice;
        showMenu(); // Hien thi menu
        scanf("%d", &choice); 
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                // Chuc nang sua thong tin sach
                break;
            case 4:
                // Chuc nang xoa sach 
                break;
            case 5:
                // Chuc nang tim kiem sach
                break;
            case 6:
                // Chuc nang sap xep sach theo gia tien 
                break;
            case 7:
                // Chuc nang luu tru du lieu
                break;
            case 8:
                printf("Thoat chuong trinh...\n");
                return 0; // Ket thuc chuong trinh
            default:
                printf("Your selection is invalid, please re-enter.\n");
        }
    }   while (choice != 8);  // Lap lai chuong trinh neu chon lua khac 8

    return 0;
}