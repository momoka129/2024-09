#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    // Stack corruption
    char buf2[16] = "overwriteme";
    char buf1[16]; //may have random characters 
    strncpy(buf2, "", sizeof(buf2) - 1);  // 使用 strncpy 限制长度
    buf2[sizeof(buf2) - 1] = '\0';        // 确保字符串结束符存在
    printf("buf1 val: %s\n", buf1);
    printf("buf2 val: %s\n", buf2);
    printf("buf1 addr: %p\n", (void *)buf1);
    printf("buf2 addr: %p\n", (void *)buf2);

    // Heap corruption
    char *buf3 = malloc(12 * sizeof(char));
    char *buf4 = malloc(12 * sizeof(char));

    strncpy(buf4, "mywordshere", 12);     // 使用 strncpy 避免溢出
    buf4[11] = '\0';                      // 强制字符串结束符
    strncpy(buf3, "", 12);
    buf3[11] = '\0';                      // 确保结束符

    printf("buf3 val: %s\n", buf3);
    printf("buf4 val: %s\n", buf4);
    printf("buf3 addr: %p\n", (void *)buf3);
    printf("buf4 addr: %p\n", (void *)buf4);

    // 释放堆内存
    free(buf3);
    free(buf4);

    return 0;
}
