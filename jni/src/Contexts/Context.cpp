#include "Contexts/Context.h"
#include "Contexts/Game.h"

Context::Context(Game* g) : Updatable(g), m_game(g)
{}

void Context::onStart(void* data){}

void Context::onClose(void* data){}
