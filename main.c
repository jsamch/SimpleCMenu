#include <stdio.h>
#include <stdlib.h>
#include "SimpleCMenu.h"


int f1(void);
int f2(void);
int RunUtilMenu(void);

scm_Menu TopMenu = {
    .Title = "Top Menu",
    .Elements = {
        SCM_MENUENTRY("Function 1", &f1),
        SCM_MENUENTRY("Function 2", &f2),
        SCM_MENUENTRY("Utility Menu",&RunUtilMenu),
        SCM_MENU_TERM
    }
};

int util_f1(void);
int util_f2(void);
int util_tbd(void);

scm_Menu UtilMenu = {
    .Title = "Utility Menu",
    .Elements = {
        SCM_MENUENTRY("Utility f1", &util_f1),
        SCM_MENUENTRY("Utility f2", &util_f2),
        SCM_MENUENTRY("Utility 3", &util_tbd),
        SCM_MENUENTRY("Utility 4", &util_tbd),
        SCM_MENUENTRY("Utility 5", &util_tbd),
        SCM_MENU_TERM
    }
};

int RunUtilMenu(void) {
    return(scm_RunMenu(UtilMenu));
}


int f2(void) {
    scm_printf("Function F2 Called\n");
    return(0);
}

int f1(void) {
    scm_printf("Function F1 Called\n");
    return(0);
}

int util_f1(void) {
    scm_printf("Utility 1\n");
    return(0);
}

int util_f2(void) {
    scm_printf("Utility 2\n");
    return(0);
}

int util_tbd(void) {
    scm_printf("To be defined\n");
    return(0);
}

int main()
{
#if 0
    {
        char cc;
        cc = getch();
        printf("Got %c\n", cc);
    }
#endif
    while( scm_RunMenu(TopMenu) == 0 );
    return 0;
}
