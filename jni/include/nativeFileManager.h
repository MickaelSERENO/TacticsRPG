#ifndef  NATIVEUNITSTATS_INC
#define  NATIVEUNITSTATS_INC

#include <jni.h>
#include <UnitStats.h>

extern "C"
{
	JNIEXPORT void JNICALL Java_com_gaulois94_FileManager_FileManagerInitDB(JNIEnv* jenv, jclass jcls, jstring pathDB);
};

#endif   /* ----- #ifndef NATIVEUNITSTATS_INC  ----- */
