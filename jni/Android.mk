LOCAL_PATH := $(call my-dir)
LIBENGINE  := /home/mickael/Programmation/Java/Android/AndroidEngine/libs/$(TARGET_ARCH_ABI)/libengine.so

include $(CLEAR_VARS)
LOCAL_C_INCLUDES += $(NDK_APP_PROJECT_PATH)/jni/INCLUDE
LOCAL_C_INCLUDES += $(NDK_APP_PROJECT_PATH)/../AndroidEngine/jni/Graphics/
LOCAL_C_INCLUDES += $(NDK_APP_PROJECT_PATH)/../AndroidEngine/jni
LOCAL_SHARED_LIBRARIES := engine-prebuilt
LOCAL_MODULE := tactics
LOCAL_CFLAGS := -Wall --std=c++11 -g
APP_OPTIM := debug

LOCAL_SRC_FILES := src/TacticsRenderer.cpp src/nativeTacticsRenderer.cpp
LOCAL_SRC_FILES += src/Map/Map.cpp

LOCAL_LDLIBS    += -llog -landroid -lEGL -lGLESv2 -ljnigraphics -latomic -l${LIBENGINE} -lexpat

include $(BUILD_SHARED_LIBRARY)

