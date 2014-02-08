TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += ./src \
    ./includes

SOURCES += ./src/main.c \
    ./src/getfunctions.c \
    ./src/calculations.c \
    ./src/fileread.c

HEADERS += \
    ./include/definitions.h \
    ./include/typedefs.h \
    ./include/getfunctions.h \
    ./include/calculations.h \
    ./include/fileread.h

OTHER_FILES += \
    data.txt \
    LICENSE.md \
    README.md
