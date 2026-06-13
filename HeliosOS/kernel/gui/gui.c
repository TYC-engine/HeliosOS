#define VGA_MEMORY ((unsigned short*)0xB8000)

static int cursor_x=0;
static int cursor_y=0;

void putchar(char c)
{
    if(c=='\n')
    {
        cursor_x=0;
        cursor_y++;
        return;
    }

    VGA_MEMORY[cursor_y*80+cursor_x]=(0x0F<<8)|c;

    cursor_x++;

    if(cursor_x>=80)
    {
        cursor_x=0;
        cursor_y++;
    }
}

void print(const char* s)
{
    while(*s)
        putchar(*s++);
}
