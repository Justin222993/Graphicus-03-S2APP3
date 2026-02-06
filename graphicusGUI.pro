TEMPLATE     = vcapp
TARGET       = Graphicus-03-S2APP3
CONFIG      += warn_on qt debug windows console
HEADERS      += projectDefinitions.h \
                canevas.h \
                couche.h \
                vecteur.h \
                forme.h \
                carre.h \
                cercle.h \
                rectangle.h \

SOURCES      += Graphicus-03-S2APP3.cpp \
                projectDefinitions.cpp \
                canevas.cpp \
                couche.cpp \
                forme.cpp \
                carre.cpp \
                cercle.cpp \
                rectangle.cpp

INCLUDEPATH += ./Libraries
LIBS        += ./Libraries/graphicusGUI.lib
QT          += widgets