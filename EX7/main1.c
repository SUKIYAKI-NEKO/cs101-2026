#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main() {
    int n;
    int lotto[5][7];
    int used[70];
    int i, j, k, tmp;
 
    srand((unsigned)time(NULL));
 
    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問您要買幾組樂透彩：");
    scanf("%d", &n);
    if (n < 1 || n > 5) {
        printf("組數必須是 1 ~ 5\n");
        return 1;
    }
 
    /* 每一組：七個 01~69 不重複的數字 */
    for (i = 0; i < n; i++) {
        for (j = 0; j < 70; j++) used[j] = 0;
        for (j = 0; j < 7; j++) {
            int num;
            do {
                num = rand() % 69 + 1;
            } while (used[num]);
            used[num] = 1;
            lotto[i][j] = num;
        }
        /* 前六個由小到大排序，第七個是特別號（和範例一樣） */
        for (j = 0; j < 5; j++)
            for (k = 0; k < 5 - j; k++)
                if (lotto[i][k] > lotto[i][k + 1]) {
                    tmp = lotto[i][k];
                    lotto[i][k] = lotto[i][k + 1];
                    lotto[i][k + 1] = tmp;
                }
    }
 
    FILE *fp = fopen("lotto.txt", "w");
    if (fp == NULL) {
        printf("無法開啟 lotto.txt\n");
        return 1;
    }
 
    time_t now = time(NULL);
    char *date = ctime(&now);          /* 例如 Thu Nov 19 16:10:00 2026\n */
    date[24] = '\0';                   /* 去掉最後的換行 */
 
    fprintf(fp, "========= lotto649 =========\n");
    fprintf(fp, "= %s =\n", date);
    for (i = 0; i < 5; i++) {
        fprintf(fp, "[%d]:", i + 1);
        for (j = 0; j < 7; j++) {
            if (i < n) fprintf(fp, " %02d", lotto[i][j]);
            else       fprintf(fp, " --");
        }
        fprintf(fp, "\n");
    }
    fprintf(fp, "========= csie@CGU =========\n");
    fclose(fp);
 
    printf("已為您購買的 %d 組樂透組合輸出至 lotto.txt\n", n);
    return 0;
}
