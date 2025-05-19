include("C:/Users/PC/Documents/GitRepository/digital_inventory_system/build/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/digital_inventory_system-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE C:/Users/PC/Documents/GitRepository/digital_inventory_system/build/digital_inventory_system.exe
    GENERATE_QT_CONF
)
