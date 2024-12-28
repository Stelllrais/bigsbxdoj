#include <stdio.h>
#include <string.h>
#include <ctype.h>

void process_string(char str[], int n) {
    char odd_chars[100]; // ���ڴ洢����λ�õĴ�д��ĸ
    int odd_index = 0;

    // ��һ������������λ�õ�Сд��ĸ��ת��Ϊ��д��ĸ
    for (int i = 1; i < n; i += 2) { // ����λ�ã�1, 3, 5...
        if (islower(str[i])) {       // ��Сд��ĸ
            str[i] = toupper(str[i]); // ת��Ϊ��д
        }
        if (isupper(str[i])) {       // �Ǵ�д��ĸ
            odd_chars[odd_index++] = str[i]; // ��������λ�õĴ�д��ĸ
        }
    }

    // �ڶ�����������λ�õĴ�д��ĸ����
    for (int i = 0; i < odd_index - 1; i++) {
        for (int j = 0; j < odd_index - i - 1; j++) {
            if (odd_chars[j] > odd_chars[j + 1]) {
                char temp = odd_chars[j];
                odd_chars[j] = odd_chars[j + 1];
                odd_chars[j + 1] = temp;
            }
        }
    }

    // ���������������Ĵ�д��ĸ�Ż�ԭ�ַ���������λ��
    odd_index = 0;
    for (int i = 1; i < n; i += 2) { // ����λ��
        if (isupper(str[i])) {
            str[i] = odd_chars[odd_index++];
        }
    }
}

int main() {
    int n;
    char str[100];

    // �����ַ�������
    scanf_s("%d", &n);
    getchar(); // ����������еĻ��з�

    // �����ַ���
    fgets(str, n + 1, stdin);
    str[n] = '\0'; // ȷ���ַ���ĩβ����ֹ��

    // �����ַ���
    process_string(str, n);

    // ����������ַ���
    printf("%s\n", str);

    return 0;
}