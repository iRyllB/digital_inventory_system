#include "InventorySystem.h"
#include "CUI.h"

int main() {
    InventorySystem system;
    CUI menu(system);
    menu.start();
    return 0;
}


