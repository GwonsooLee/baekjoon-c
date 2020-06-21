#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct member {
    int age;
    char name[102];
};

int compare(const void *a, const void *b) {
    struct member memberA = *(struct member *)a;
    struct member memberB = *(struct member *)b;

    if (memberA.age < memberB.age) {
        return -1;
    } else if (memberA.age > memberB.age) {
        return 1;
    }

    return 0;
}

int main()
{
    int n;
    struct member members[100001];
    scanf("%d", &n);

    for (int i=0; i < n; ++i) {
        scanf("%d %s", &members[i].age, &members[i].name);
    }

    qsort(members, n, sizeof(struct member), compare);

    for (int i=0; i < n; ++i) {
        printf("%d %s\n", members[i].age, members[i].name);
    }

    return 0;
}