#ifndef USER_H
#define USER_H

#define MAX_USER 100
#define MAX_CHAR_NAME 50

#include <stdbool.h>

typedef struct {
    int id;
    char name[MAX_CHAR_NAME];
} User;

extern User listUser[MAX_USER];
extern int numUsers;

bool create_user(int id, char* name);
bool verify_data(int id, char* name);

User* get_user(char* name);

#endif /* USER_H */
