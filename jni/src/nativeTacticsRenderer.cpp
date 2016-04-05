#include "nativeTacticsRenderer.h"
#include "utils.h"

JNIEXPORT jlong JNICALL Java_com_gaulois94_TacticsRenderer_createTacticsRenderer(JNIEnv* jenv, jclass jcls, jlong parent, jobject surface)
{
	TacticsRenderer* renderer = new TacticsRenderer((Updatable*)parent);
	ANativeWindow* window = ANativeWindow_fromSurface(jenv, surface);
	renderer->initializeContext(window);

	return (jlong)renderer;
}
