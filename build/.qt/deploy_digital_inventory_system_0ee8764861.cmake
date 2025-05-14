include("C:/Users/PC/Desktop/testqt/build/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/digital_inventory_system-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE C:/Users/PC/Desktop/testqt/build/digital_inventory_system.exe
    GENERATE_QT_CONF
)
