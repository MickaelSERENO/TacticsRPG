LOCAL_PATH := $(call my-dir)
LIBENGINE  := /home/mickael/Programmation/Android/AndroidEngine/libs/$(TARGET_ARCH_ABI)/libengine.so
LIBEXPAT   := /home/mickael/Programmation/Android/expat-android/libs/$(TARGET_ARCH_ABI)/libexpat.so

include $(CLEAR_VARS)
LOCAL_MODULE := engine-prebuilt
LOCAL_SRC_FILES := $(LIBENGINE)
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := expat-prebuilt
LOCAL_SRC_FILES := $(LIBEXPAT)
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_C_INCLUDES += $(NDK_APP_PROJECT_PATH)/jni/include
LOCAL_C_INCLUDES += $(NDK_APP_PROJECT_PATH)/../AndroidEngine/jni/Graphics/
LOCAL_C_INCLUDES += $(NDK_APP_PROJECT_PATH)/../AndroidEngine/jni
LOCAL_SHARED_LIBRARIES := engine-prebuilt expat-prebuilt

LOCAL_MODULE := tactics
LOCAL_CFLAGS := -Wall --std=c++11 -g
LOCAL_SHARED_LIBRARIES := engine-prebuilt expat-prebuilt

APP_OPTIM := debug

LOCAL_SRC_FILES := src/TacticsRenderer.cpp src/nativeTacticsRenderer.cpp
LOCAL_SRC_FILES += src/Map/TMap.cpp
LOCAL_SRC_FILES += src/nativeFileManager.cpp src/UnitStats.cpp
LOCAL_SRC_FILES += src/Contexts/Game.cpp src/Contexts/Start.cpp
LOCAL_SRC_FILES += src/GameResources.cpp

LOCAL_LDLIBS    += -llog -landroid -lEGL -lGLESv2 -ljnigraphics -latomic

include $(BUILD_SHARED_LIBRARY)

