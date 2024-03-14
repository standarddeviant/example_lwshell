
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "lwshell.h"

#define BLEADDR "01:23:45:67:89:AB:CD:EF"

/* Command to get called */
int32_t
arg_fn(int32_t argc, char** argv) {
    printf("arg_fn called. Number of argv: %d\r\n", (int)argc);
    for (int32_t i = 0; i < argc; ++i) {
        printf("ARG[%d]: %s\r\n", (int)i, argv[i]);
    }

    /* Successful execution */
    return 0;
}

/* Command to get called */
int32_t
bleaddr_fn(int32_t argc, char** argv) {
    // printf("bleaddr (ignoring args) is called.");
    printf("%s\n", BLEADDR);

    /* Successful execution */
    return 0;
}

/* Example code */
void
example_test(void) {
    /* Init library */
    lwshell_init();

    /* Define shell commands */
    lwshell_register_cmd("arg", arg_fn, "Prints arguments (shell test)");
    lwshell_register_cmd("bleaddr", bleaddr_fn, "Prints BLE Address");

    /* User input to process every character */
    char ch;
    while(read(STDIN_FILENO, &ch, 1) > 0) {
        //do stuff
        lwshell_input(&ch, 1);
    }
    printf("Example has finished\n");

    /* Now insert input */
    // lwshell_input(input_str, strlen(input_str));
}

int main(void) {
    example_test();
    return 0;
}

