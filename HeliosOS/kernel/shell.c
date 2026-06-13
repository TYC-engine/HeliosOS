#include "screen.h"
#include "keyboard.h"

static char command[64];
static int index = 0;

void shell_update()
{
    char c = keyboard_get_last();

    if(!c)
        return;

    putchar(c);

    if(c == '\n')
    {
        command[index] = 0;

        print("Command received\n");

        index = 0;

        print("helios> ");

        return;
    }

    command[index++] = c;
}
