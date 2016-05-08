LOCAL_PATH := $(call my-dir)
<<<<<<< HEAD
LIBENGINE  := /home/mickael/Programmation/Java/Android/Engine/libs/$(TARGET_ARCH_ABI)/libengine.so
LIBEXPAT   := /opt/android-ndk/platforms/android-19/arch-arm/usr/lib/libexpat.so
=======
LIBENGINE  := /home/mickael/Programmation/Android/AndroidEngine/libs/$(TARGET_ARCH_ABI)/libengine.so
LIBEXPAT   := /home/mickael/Programmation/Android/expat-android/libs/$(TARGET_ARCH_ABI)/libexpat.so
>>>>>>> fbfa4f2a201fdf1a929a5335e2c7fd5aac4216a2

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
LOCAL_C_INCLUDES += $(NDK_APP_PROJECT_PATH)/../Engine/jni/Graphics/
LOCAL_C_INCLUDES += $(NDK_APP_PROJECT_PATH)/../Engine/jni
LOCAL_SHARED_LIBRARIES := engine-prebuilt expat-prebuilt

LOCAL_MODULE := tactics
LOCAL_CFLAGS := -Wall --std=c++11 -g
LOCAL_SHARED_LIBRARIES := engine-prebuilt expat-prebuilt

APP_OPTIM := debug

LOCAL_SRC_FILES := src/TacticsRenderer.cpp src/nativeTacticsRenderer.cpp
LOCAL_SRC_FILES += src/Map/TMap.cpp

LOCAL_LDLIBS    += -llog -landroid -lEGL -lGLESv2 -ljnigraphics -latomic

include $(BUILD_SHARED_LIBRARY)

