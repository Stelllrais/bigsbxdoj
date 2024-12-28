#include <stdio.h>
#include <string.h>
#include <ctype.h>

void process_string(char str[], int n) {
    char odd_chars[100]; // 用于存储奇数位置的大写字母
    int odd_index = 0;

    // 第一步：处理奇数位置的小写字母并转换为大写字母
    for (int i = 1; i < n; i += 2) { // 奇数位置：1, 3, 5...
        if (islower(str[i])) {       // 是小写字母
            str[i] = toupper(str[i]); // 转换为大写
        }
        if (isupper(str[i])) {       // 是大写字母
            odd_chars[odd_index++] = str[i]; // 存入奇数位置的大写字母
        }
    }

    // 第二步：对奇数位置的大写字母排序
    for (int i = 0; i < odd_index - 1; i++) {
        for (int j = 0; j < odd_index - i - 1; j++) {
            if (odd_chars[j] > odd_chars[j + 1]) {
                char temp = odd_chars[j];
                odd_chars[j] = odd_chars[j + 1];
                odd_chars[j + 1] = temp;
            }
        }
    }

    // 第三步：将排序后的大写字母放回原字符串的奇数位置
    odd_index = 0;
    for (int i = 1; i < n; i += 2) { // 奇数位置
        if (isupper(str[i])) {
            str[i] = odd_chars[odd_index++];
        }
    }
}

int main() {
    int n;
    char str[100];

    // 输入字符串长度
    scanf_s("%d", &n);
    getchar(); // 清除缓冲区中的换行符

    // 输入字符串
    fgets(str, n + 1, stdin);
    str[n] = '\0'; // 确保字符串末尾有终止符

    // 处理字符串
    process_string(str, n);

    // 输出处理后的字符串
    printf("%s\n", str);

    return 0;
}