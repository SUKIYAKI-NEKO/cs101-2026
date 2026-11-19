#include <stdio.h>
#include <string.h>

#define NUM_BOOKS 6

typedef struct Books {
    int id;
    int price;
    char title[64];
} book_t;

/* 計算所有書籍的總價錢 */
void total_price(book_t books[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += books[i].price;
    printf("總共價錢：%d\n", sum);
}

/* 輸出書籍資料到螢幕 */
void list_books(book_t books[], int n) {
    printf("%-4s %-6s %s\n", "Id", "Price", "Title");
    for (int i = 0; i < n; i++)
        printf("%-4d %-6d %s\n", books[i].id, books[i].price, books[i].title);
}

int main() {
    book_t books[NUM_BOOKS] = {
        {1, 1000, "All the Light We Cannot See"},
        {2,  300, "The 38 Letters from J.D. Rockefeller to his son"},
        {3, 1000, "The Ballad of Songbirds and Snakes"},
        {4,  550, "Killers of the Flower Moon"},
        {5,  870, "Elon Musk"},
        {6, 1344, "Milk and Honey 12-Month 2024"}
    };

    /* 把書籍資料以二進位存到 Book.bin */
    FILE *fp = fopen("Book.bin", "wb");
    if (fp == NULL) {
        printf("無法開啟 Book.bin\n");
        return 1;
    }
    fwrite(books, sizeof(book_t), NUM_BOOKS, fp);
    fclose(fp);

    list_books(books, NUM_BOOKS);
    total_price(books, NUM_BOOKS);
    return 0;
}
