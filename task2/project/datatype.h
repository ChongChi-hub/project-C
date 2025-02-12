#define MAX_STRING_LENGTH 100 // Do dai toi da cua chuoi
#define MAX_BOOKS 100 // So luong sach toi da trong thu vien
 
// Cau truc du lieu de luu thong tin sach
struct Book {
    int id; // ID sach
    char title[MAX_STRING_LENGTH]; // Ten sach
    char author[MAX_STRING_LENGTH]; // Tac gia
    int year; // Nam xuat ban
    char genre[MAX_STRING_LENGTH]; // The loai
    float price; // Gia tien
};
struct Book library[MAX_BOOKS]; // Mang chua danh sach sach
struct Book newBook; // Sach moi 
