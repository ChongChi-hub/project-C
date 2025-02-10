#define MAX_STRING_LENGTH 100 // Do dai toi da cua chuoi
#define MAX_BOOKS 100 // So luong sach toi da
struct Book {  // Kieu du lieu Book
    int id; // ID cua sach
    char title[MAX_STRING_LENGTH]; // Ten sach
    char author[MAX_STRING_LENGTH]; // Ten tac gia
    int year; // Nam xuat ban
    char genre[MAX_STRING_LENGTH]; // The loai sach
    float price; // Gia tien
};
struct Book library[MAX_BOOKS]; // Thu vien chua toi da 100 cuon
struct Book newBook; // Sach moi