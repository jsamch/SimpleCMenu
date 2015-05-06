#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "simplecmenu.h"

static void scm_LineOfStars(const char* title, int extra) {
    int len,ii;

    len = strlen(title);
    for(ii = 0 ; ii < (len+extra) ; ii++ ) {
        scm_putchar('*');
    }
    scm_putchar('\n');
}

// Pretty print the menu
static int scm_PrintMenu(scm_Menu Menu) {
    int itemcnt, index;

    scm_putchar('\n');
    scm_LineOfStars(Menu.Title,10);
    scm_printf("  %s\n", Menu.Title);
    scm_LineOfStars(Menu.Title,10);

    index = 0;
    while( Menu.Elements[index].EntryText != NULL ) {
        scm_printf("  %d: %s\n", index+1, Menu.Elements[index].EntryText);
        index++;
    }
    itemcnt = index;
    scm_printf("  0: RETURN\n  z: EXIT\n");
    scm_LineOfStars(Menu.Title,10);
    scm_printf("Command ? ");
    return(itemcnt);
}

// Run a given menu
int scm_RunMenu(scm_Menu Menu) {
    int itemcnt;
    char keyin;

    itemcnt = scm_PrintMenu(Menu);

    keyin = 0;
    do {
        keyin = scm_getchar();
        if(keyin >= '1' && keyin < '1'+itemcnt) {
            scm_printf("'%c' selected, calling...\n", keyin);
            if( Menu.Elements[keyin-'1'].Command() == 1) return(1);
            scm_PrintMenu(Menu);
        } else if (keyin == '0') {
            return(0);
        } else if (keyin == 'z') {
            return(1);
        } else {
            scm_printf("Invalid choice\n");
            scm_PrintMenu(Menu);
        }
    } while(1);
}

