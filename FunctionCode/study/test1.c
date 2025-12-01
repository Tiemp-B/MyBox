#include <stdio.h>
 
typedef struct student {
    char* name;
    int score[3];
} Student;
 
int dec(int enc) {
    return enc & 0xA5;
}
 
int sum(Student* p) {
	printf("%X %X %X\n", dec(p->score[0]) , dec(p->score[1]) , dec(p->score[2]));
    return dec(p->score[0]) + dec(p->score[1]) + dec(p->score[2]);
}
 
int main() {
    Student s[2] = { "Kim", {0xA0, 0xA5, 0xDB}, "Lee", {0xA0, 0xED, 0x81} };
    Student* p = s;
    int result = 0;
 
    for (int i = 0; i < 2; i++) {
		printf("%s\n", s[i].name);
        result += sum(&s[i]);
    }
    printf("%X", result);
    return 0;
}
