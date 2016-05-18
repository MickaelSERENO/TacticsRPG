#include "nativeTacticsRenderer.h"
#include "utils.h"

JNIEXPORT jlong JNICALL Java_com_gaulois94_TacticsRenderer_createTacticsRenderer(JNIEnv* jenv, jclass jcls, jlong parent)
{
	JniMadeOf::jenv = jenv;
	TacticsRenderer* renderer = new TacticsRenderer((Updatable*)parent);

	return (jlong)renderer;
}
