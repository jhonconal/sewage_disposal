#############################################################################
# Makefile for building: sewage_disposal
# Generated by qmake (2.01a) (Qt 4.8.7) on: ?? 8? 23 15:29:37 2017
# Project:  sewage_disposal.pro
# Template: app
# Command: /usr/lib/x86_64-linux-gnu/qt4/bin/qmake -spec /usr/share/qt4/mkspecs/linux-g++-64 -o Makefile sewage_disposal.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -D_TTY_POSIX_ -DQT_NO_DEBUG -DQT_SQL_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtSql -I/usr/include/qt4 -I. -Ihelper -IinputTool -I3rdparty/qserialport -IinputTool -I. -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -lQtSql -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/lib/x86_64-linux-gnu/qt4/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		mainwidget.cpp \
		qcustomplot.cpp \
		sewagecurve.cpp \
		3rdparty/qserialport/posix_qextserialport.cpp \
		3rdparty/qserialport/qextserialbase.cpp \
		3rdparty/qserialport/qextserialport.cpp \
		helper/iconhelper.cpp \
		qanimationstackedwidget.cpp \
		inputTool/frminput.cpp moc_mainwidget.cpp \
		moc_qcustomplot.cpp \
		moc_sewagecurve.cpp \
		moc_qextserialbase.cpp \
		moc_qextserialport.cpp \
		moc_iconhelper.cpp \
		moc_qanimationstackedwidget.cpp \
		moc_frminput.cpp \
		qrc_resources.cpp
OBJECTS       = main.o \
		mainwidget.o \
		qcustomplot.o \
		sewagecurve.o \
		posix_qextserialport.o \
		qextserialbase.o \
		qextserialport.o \
		iconhelper.o \
		qanimationstackedwidget.o \
		frminput.o \
		moc_mainwidget.o \
		moc_qcustomplot.o \
		moc_sewagecurve.o \
		moc_qextserialbase.o \
		moc_qextserialport.o \
		moc_iconhelper.o \
		moc_qanimationstackedwidget.o \
		moc_frminput.o \
		qrc_resources.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		inputTool/inputTool.pri \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		sewage_disposal.pro
QMAKE_TARGET  = sewage_disposal
DESTDIR       = 
TARGET        = sewage_disposal

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_mainwidget.h ui_sewagecurve.h ui_frminput.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: sewage_disposal.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		inputTool/inputTool.pri \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtSql.prl \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++-64 -o Makefile sewage_disposal.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_phonon.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
inputTool/inputTool.pri:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/shared.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtSql.prl:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++-64 -o Makefile sewage_disposal.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/sewage_disposal1.0.0 || $(MKDIR) .tmp/sewage_disposal1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/sewage_disposal1.0.0/ && $(COPY_FILE) --parents mainwidget.h qcustomplot.h sewagecurve.h helper/helper.h 3rdparty/qserialport/posix_qextserialport.h 3rdparty/qserialport/qextserialbase.h 3rdparty/qserialport/qextserialport.h helper/iconhelper.h qanimationstackedwidget.h inputTool/frminput.h .tmp/sewage_disposal1.0.0/ && $(COPY_FILE) --parents resources.qrc .tmp/sewage_disposal1.0.0/ && $(COPY_FILE) --parents main.cpp mainwidget.cpp qcustomplot.cpp sewagecurve.cpp 3rdparty/qserialport/posix_qextserialport.cpp 3rdparty/qserialport/qextserialbase.cpp 3rdparty/qserialport/qextserialport.cpp helper/iconhelper.cpp qanimationstackedwidget.cpp inputTool/frminput.cpp .tmp/sewage_disposal1.0.0/ && $(COPY_FILE) --parents mainwidget.ui sewagecurve.ui inputTool/frminput.ui inputTool/frminput.ui .tmp/sewage_disposal1.0.0/ && (cd `dirname .tmp/sewage_disposal1.0.0` && $(TAR) sewage_disposal1.0.0.tar sewage_disposal1.0.0 && $(COMPRESS) sewage_disposal1.0.0.tar) && $(MOVE) `dirname .tmp/sewage_disposal1.0.0`/sewage_disposal1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/sewage_disposal1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_mainwidget.cpp moc_qcustomplot.cpp moc_sewagecurve.cpp moc_qextserialbase.cpp moc_qextserialport.cpp moc_iconhelper.cpp moc_qanimationstackedwidget.cpp moc_frminput.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwidget.cpp moc_qcustomplot.cpp moc_sewagecurve.cpp moc_qextserialbase.cpp moc_qextserialport.cpp moc_iconhelper.cpp moc_qanimationstackedwidget.cpp moc_frminput.cpp
moc_mainwidget.cpp: sewagecurve.h \
		3rdparty/qserialport/qextserialport.h \
		3rdparty/qserialport/posix_qextserialport.h \
		3rdparty/qserialport/qextserialbase.h \
		qcustomplot.h \
		qanimationstackedwidget.h \
		mainwidget.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) mainwidget.h -o moc_mainwidget.cpp

moc_qcustomplot.cpp: qcustomplot.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) qcustomplot.h -o moc_qcustomplot.cpp

moc_sewagecurve.cpp: 3rdparty/qserialport/qextserialport.h \
		3rdparty/qserialport/posix_qextserialport.h \
		3rdparty/qserialport/qextserialbase.h \
		qcustomplot.h \
		sewagecurve.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) sewagecurve.h -o moc_sewagecurve.cpp

moc_qextserialbase.cpp: 3rdparty/qserialport/qextserialbase.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) 3rdparty/qserialport/qextserialbase.h -o moc_qextserialbase.cpp

moc_qextserialport.cpp: 3rdparty/qserialport/posix_qextserialport.h \
		3rdparty/qserialport/qextserialbase.h \
		3rdparty/qserialport/qextserialport.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) 3rdparty/qserialport/qextserialport.h -o moc_qextserialport.cpp

moc_iconhelper.cpp: helper/iconhelper.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) helper/iconhelper.h -o moc_iconhelper.cpp

moc_qanimationstackedwidget.cpp: qanimationstackedwidget.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) qanimationstackedwidget.h -o moc_qanimationstackedwidget.cpp

moc_frminput.cpp: helper/iconhelper.h \
		inputTool/frminput.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) inputTool/frminput.h -o moc_frminput.cpp

compiler_rcc_make_all: qrc_resources.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_resources.cpp
qrc_resources.cpp: resources.qrc \
		Resc/database/pinyin.db \
		Resc/images/loading_2.gif \
		Resc/images/loading_3.gif \
		Resc/images/loading.gif \
		Resc/images/loading_4.gif \
		Resc/icons/item.png \
		Resc/icons/square.png \
		Resc/icons/down_arrow.png \
		Resc/icons/curve.png \
		Resc/icons/fontawesome-webfont.ttf \
		Resc/icons/setting.png \
		Resc/icons/home.png
	/usr/lib/x86_64-linux-gnu/qt4/bin/rcc -name resources resources.qrc -o qrc_resources.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwidget.h ui_sewagecurve.h ui_frminput.h ui_frminput.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwidget.h ui_sewagecurve.h ui_frminput.h ui_frminput.h
ui_mainwidget.h: mainwidget.ui \
		qanimationstackedwidget.h \
		qcustomplot.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic mainwidget.ui -o ui_mainwidget.h

ui_sewagecurve.h: sewagecurve.ui \
		qcustomplot.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic sewagecurve.ui -o ui_sewagecurve.h

ui_frminput.h: inputTool/frminput.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic inputTool/frminput.ui -o ui_frminput.h

ui_frminput.h: inputTool/frminput.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic inputTool/frminput.ui -o ui_frminput.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mainwidget.h \
		sewagecurve.h \
		3rdparty/qserialport/qextserialport.h \
		3rdparty/qserialport/posix_qextserialport.h \
		3rdparty/qserialport/qextserialbase.h \
		qcustomplot.h \
		qanimationstackedwidget.h \
		helper/helper.h \
		inputTool/frminput.h \
		helper/iconhelper.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwidget.o: mainwidget.cpp mainwidget.h \
		sewagecurve.h \
		3rdparty/qserialport/qextserialport.h \
		3rdparty/qserialport/posix_qextserialport.h \
		3rdparty/qserialport/qextserialbase.h \
		qcustomplot.h \
		qanimationstackedwidget.h \
		ui_mainwidget.h \
		helper/iconhelper.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwidget.o mainwidget.cpp

qcustomplot.o: qcustomplot.cpp qcustomplot.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qcustomplot.o qcustomplot.cpp

sewagecurve.o: sewagecurve.cpp sewagecurve.h \
		3rdparty/qserialport/qextserialport.h \
		3rdparty/qserialport/posix_qextserialport.h \
		3rdparty/qserialport/qextserialbase.h \
		qcustomplot.h \
		ui_sewagecurve.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sewagecurve.o sewagecurve.cpp

posix_qextserialport.o: 3rdparty/qserialport/posix_qextserialport.cpp 3rdparty/qserialport/posix_qextserialport.h \
		3rdparty/qserialport/qextserialbase.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o posix_qextserialport.o 3rdparty/qserialport/posix_qextserialport.cpp

qextserialbase.o: 3rdparty/qserialport/qextserialbase.cpp 3rdparty/qserialport/qextserialbase.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qextserialbase.o 3rdparty/qserialport/qextserialbase.cpp

qextserialport.o: 3rdparty/qserialport/qextserialport.cpp 3rdparty/qserialport/qextserialport.h \
		3rdparty/qserialport/posix_qextserialport.h \
		3rdparty/qserialport/qextserialbase.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qextserialport.o 3rdparty/qserialport/qextserialport.cpp

iconhelper.o: helper/iconhelper.cpp helper/iconhelper.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o iconhelper.o helper/iconhelper.cpp

qanimationstackedwidget.o: qanimationstackedwidget.cpp qanimationstackedwidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qanimationstackedwidget.o qanimationstackedwidget.cpp

frminput.o: inputTool/frminput.cpp ui_frminput.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o frminput.o inputTool/frminput.cpp

moc_mainwidget.o: moc_mainwidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwidget.o moc_mainwidget.cpp

moc_qcustomplot.o: moc_qcustomplot.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_qcustomplot.o moc_qcustomplot.cpp

moc_sewagecurve.o: moc_sewagecurve.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_sewagecurve.o moc_sewagecurve.cpp

moc_qextserialbase.o: moc_qextserialbase.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_qextserialbase.o moc_qextserialbase.cpp

moc_qextserialport.o: moc_qextserialport.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_qextserialport.o moc_qextserialport.cpp

moc_iconhelper.o: moc_iconhelper.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_iconhelper.o moc_iconhelper.cpp

moc_qanimationstackedwidget.o: moc_qanimationstackedwidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_qanimationstackedwidget.o moc_qanimationstackedwidget.cpp

moc_frminput.o: moc_frminput.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_frminput.o moc_frminput.cpp

qrc_resources.o: qrc_resources.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_resources.o qrc_resources.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

