#include <stdio.h>
#include <memory.h>
#include <malloc.h>
#include <w32api/mfobjects.h>


size_t __fastcall length(const char **a1) {
    return strlen(*a1);
}

char *__fastcall initialize_string(int a1) {
    char *dest; // ST18_8@1

    dest = (char *) malloc(16);
    *(QWORD *) dest = malloc(a1);
    *((QWORD *) dest + 1) = length;
    strcpy(dest, *(const char **) dest);
    return dest;
}



int main() {
    char *v3; // ST18_8@1
    int v4; // eax@1

    v3 = initialize_string(16384);
    strcpy(*(char **) v3, "test123123\0");
    v4 = (*((int (__fastcall **)(QWORD)) v3 + 1))(v3);
    printf("\n%d", (unsigned int) v4);
    return 0;
}


