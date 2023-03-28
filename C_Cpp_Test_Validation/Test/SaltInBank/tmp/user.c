#include "User.h"
#include <string.h>
#include <stddef.h>


bool create_user(int id, char* name) { 
    if (get_user(name) == NULL) {
        if (verify_data(id, name)) {
            User user = { id, name };
            listUser[numUsers] = user;
            numUsers++;
            return true;
        }
        else {
            errno = EINVAL;
            return false;
        }
    }
    else {
        errno = EINVAL;
        return false;
    }
}

User* get_user(char* name) {
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(listUser[i].name, name) == 0) {
            return &listUser[i];
        }
    };
    return NULL;
}

bool verify_data(int id, char* name) {
    if ((id <= -1) || (id >= MAX_USER) || (strlen(name) <= 1) || (strlen(name) > MAX_CHAR_NAME)) {
        return false;
    }
    return true;
}



