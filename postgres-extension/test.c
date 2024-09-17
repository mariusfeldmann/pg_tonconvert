#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "tonconvert.h"

char *addr_raw = "-1:3333333333333333333333333333333333333333333333333333333333333333";
char *addr_hr = "Uf8zMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzMxYA";
char *addr_hr_bounce = "Ef8zMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzM0vF";

void test_one() {
    GoString go_addr_raw = {addr_raw, strlen(addr_raw)};
    char *addr_return = convert_to_human_readable_c(go_addr_raw);
    assert(strcmp(addr_return, addr_hr) == 0);
}

void test_two() {
    GoString go_addr_raw = {addr_raw, strlen(addr_raw)};
    char *addr_return = convert_to_human_readable_bounceable_c(go_addr_raw);
    assert(strcmp(addr_return, addr_hr_bounce) == 0);
}

int main() {
    test_one();
    test_two();
    printf("Success!\n");
    return 0;
}
