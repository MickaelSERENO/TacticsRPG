#ifndef NATIVE_ZOMBIERENDERER
#define NATIVE_ZOMBIERENDERER

#include <jni.h>
#include <android/native_window.h>
#include <android/native_window_jni.h>
#include "TacticsRenderer.h"

extern "C"
{
	JNIEXPORT jlong JNICALL Java_com_gaulois94_TacticsRenderer_createTacticsRenderer(JNIEnv* jenv, jclass jcls, jlong parent);
};

#endif

