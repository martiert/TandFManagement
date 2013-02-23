project(gui)

find_package(Qt4 REQUIRED QtGui QtCore)
include(${QT_USE_FILE})

include_directories(include ${CMAKE_CURRENT_BINARY_DIR}/include)

set(src
    src/main.cpp
    src/mainwindow.cpp
    src/menubar.cpp
    src/aboutdialog.cpp
  )

set(headers
    include/mainwindow.h
    include/menubar.h
    include/aboutdialog.h
    )

set(resources
    resources/resources.qrc
    )

qt4_add_resources(rcc_src ${resources})
qt4_wrap_cpp(headers_moc ${headers})

add_executable(tfm_ui ${src} ${headers_moc} ${rcc_src})
target_link_libraries(tfm_ui tfm ${QT_LIBRARIES})
