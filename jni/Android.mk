LOCAL_PATH := $(call my-dir)
LIBENGINE  := /home/mickael/Programmation/Android/AndroidEngine/libs/$(TARGET_ARCH_ABI)/libengine.so
LIBEXPAT   := /home/mickael/Programmation/Android/expat-android/libs/$(TARGET_ARCH_ABI)/libexpat.so
LIBSQLITE3 := /home/mickael/Programmation/Android/sqlite3-android/libs/$(TARGET_ARCH_ABI)/libsqlite3.so

include $(CLEAR_VARS)
LOCAL_MODULE := engine-prebuilt
LOCAL_SRC_FILES := $(LIBENGINE)
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := expat-prebuilt
LOCAL_SRC_FILES := $(LIBEXPAT)
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := sqlite3-prebuilt
LOCAL_SRC_FILES := $(LIBSQLITE3)
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_C_INCLUDES += $(NDK_APP_PROJECT_PATH)/jni/include
LOCAL_C_INCLUDES += $(NDK_APP_PROJECT_PATH)/../AndroidEngine/jni/Graphics/
LOCAL_C_INCLUDES += $(NDK_APP_PROJECT_PATH)/../AndroidEngine/jni
#LOCAL_C_INCLUDES += $(NDK_APP_PROJECT_PATH)/../Engine/jni/Graphics/
#LOCAL_C_INCLUDES += $(NDK_APP_PROJECT_PATH)/../Engine/jni
LOCAL_SHARED_LIBRARIES := engine-prebuilt expat-prebuilt

LOCAL_MODULE := tactics
LOCAL_CFLAGS := -Wall --std=c++11 -g
LOCAL_SHARED_LIBRARIES := engine-prebuilt expat-prebuilt sqlite3-prebuilt

APP_OPTIM := debug

LOCAL_SRC_FILES := src/TacticsRenderer.cpp src/nativeTacticsRenderer.cpp
LOCAL_SRC_FILES += src/Map/TMap.cpp
LOCAL_SRC_FILES += src/nativeFileManager.cpp src/Database.cpp src/UnitStats.cpp
LOCAL_SRC_FILES += src/Contexts/Context.cpp src/Contexts/Game.cpp src/Contexts/Start.cpp src/Contexts/InGame.cpp
LOCAL_SRC_FILES += src/GameResources.cpp

LOCAL_LDLIBS    += -llog -landroid -lEGL -lGLESv2 -ljnigraphics -latomic

include $(BUILD_SHARED_LIBRARY)

