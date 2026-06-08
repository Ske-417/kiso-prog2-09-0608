// step0_with_file.c
// 実行するたびに増えていく — count.txt にデータが残るから
#include <stdio.h>

int main(void) {
    int count = 0;

    // ① 前回の値をファイルから読む
    FILE *fp = fopen("count.txt", "r");
    if (fp != NULL) {
        fscanf(fp, "%d", &count);
        fclose(fp);
        fp = NULL;
    }

    // ② 1 増やして表示
    count++;
    printf("センサーの計測回数: %d 回目\n", count);

    // ③ 新しい値をファイルに書き戻す
    fp = fopen("count.txt", "w");
    if (fp != NULL) {
        fprintf(fp, "%d\n", count);
        fclose(fp);
        fp = NULL;
    }

    return 0;
}
