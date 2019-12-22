#ifndef COM_MODULES_OLDLOADING
#include "$CurrentDir:missions\\DayZCommunityOfflineMode.deerIsle\\core\\BaseModuleInclude.c"
#endif
/*
    Define used for optional compilations
*/
#define MODULE_UIEXTENDER

// #define COM_NEW_INVENTORY

/*
    Include of all .c files that belong to this module
*/
#ifdef COM_MODULES_OLDLOADING
#include "$CurrentDir:missions\\DayZCommunityOfflineMode.deerIsle\\core\\modules\\UIExtender\\UIExtender.c"

#include "$CurrentDir:missions\\DayZCommunityOfflineMode.deerIsle\\core\\modules\\UIExtender\\gui\\PauseButton.c"
#include "$CurrentDir:missions\\DayZCommunityOfflineMode.deerIsle\\core\\modules\\UIExtender\\gui\\InGameMenu.c"
#endif

#ifndef COM_MODULES_OLDLOADING
void RegisterModule()
{
    GetModuleManager().RegisterModule( new UIExtender );
}
#endif