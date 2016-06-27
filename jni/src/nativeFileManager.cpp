#include "nativeFileManager.h"

JNIEXPORT void JNICALL Java_com_gaulois94_FileManager_FileManagerInitDB(JNIEnv* jenv, jclass jcls, jstring pathDB)
{
	const char* t = jenv->GetStringUTFChars(pathDB, 0);
	UnitStats::getSingleton().init(t);
}
