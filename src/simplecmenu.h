#ifndef __SIMPLECMENU__H
#define __SIMPLECMENU__H

// Menu function pointer
typedef int (*scm_MenuCommand)(void);

// Menu Entry text
typedef const char* scm_MenuText;

// Basic Menu Item with a corresponding command (function pointer)
typedef const struct scm_MenuEntry_st {
    scm_MenuText        EntryText;
    scm_MenuCommand     Command;
} scm_MenuEntry;

// 9 entries + 1 termination
#define SCM_MAX_SUBMENUS 10

// Array of menu elements
typedef scm_MenuEntry scm_MenuArray[SCM_MAX_SUBMENUS];

// Termination menu item
#define SCM_MENUENTRY(text,command) { .EntryText = text, .Command = command }
#define SCM_MENU_TERM { .EntryText = NULL, .Command = NULL }


#define SCM_ELEMENTS_START .Elements= [
#define SCM_ELEMENTS_END SCM_MENU_TERM ]

typedef struct scm_Menu_st {
    scm_MenuText        Title;
    scm_MenuArray       Elements;
} scm_Menu;

#define scm_printf(...) printf(__VA_ARGS__)
#define scm_getchar() getch()
#define scm_putchar(c) putchar(c)

int scm_RunMenu(scm_Menu Menu);


#endif // __SIMPLECMENU__H
