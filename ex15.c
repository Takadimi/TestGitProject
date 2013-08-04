#include <stdio.h>

void first_way(int ages[], char *names[], int count, int i) {

    // i = 0;

    // for (i = 0; i < count; i++) {
    //     printf("%s has %d years alive.\n", names[i], ages[i]);
    // }

    while (i < count) {
        printf("%s has %d years alive.\n", names[i], ages[i]);
        i++;
    }

}

void second_way(int *cur_age, char **cur_name, int count, int i) {

    // i = 0;

    // for (i = 0; i < count; i++) {
    //     printf("%s is %d years old.\n", *(cur_name + i), *(cur_age + i));
    // }

    while (i < count) {
        printf("%s is %d years old.\n", *(cur_name + i), *(cur_age + i));
        i++;
    }

}

void third_way(int *cur_age, char **cur_name, int count, int i) {

    // for (i = 0; i < count; i++) {
    //     printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);
    // }

    while (i < count) {
        printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);
        i++;
    }

    *cur_age = 1000;

}

void fourth_way(int *cur_age, char **cur_name, int ages[], char *names[], int count) {

    // for (cur_name = names, cur_age = ages; (cur_age - ages) < count;
    //     cur_name++, cur_age++) {

    //     printf("%s lived %d years so far.\n", *cur_name, *cur_age);

    // }

    cur_name = names;
    cur_age = ages;

    printf("Address before pointer arithmetic :: %d, %d\n", cur_name, cur_age);
    printf("---\n");

    while ((cur_age - ages) < count) {
        printf("%s lived %d years so far.\n", *cur_name, *cur_age);
        cur_name++;
        cur_age++;
    }

    printf("Address after pointer arithmetic :: %d, %d\n", cur_name, cur_age);
    printf("---\n");

}

int main(int argc, char *argv[])
{
    // create two arrays we care about
    int ages[] = {23, 43, 12, 89, 2};
    char *names[] = {
        "Alan", "Frank",
        "Mary", "John", "Lisa"
    };

    // safely get the size of ages
    int count = sizeof(ages) / sizeof(int);
    int i = 0;

    // first way using indexing

    first_way(ages, names, count, i);

    printf("---\n");

    // setup the pointers to the start of the arrays
    int *cur_age = ages;
    char **cur_name = names;

    // second way using pointers
    second_way(cur_age, cur_name, count, i);

    printf("---\n");

    // third way, pointers are just arrays
    third_way(cur_age, cur_name, count, i);

    printf("---\n");

    printf("Value at pointer cur_age :: %d\n", *cur_age);
    printf("Value at pointer cur_name :: %s\n", *cur_name);

    printf("---\n");

    // fourth way with pointers in a stupid complex way
    fourth_way(cur_age, cur_name, ages, names, count);

    return 0;
}