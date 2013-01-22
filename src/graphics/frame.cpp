#include "frame.h"

using namespace t::graphics;

Frame::Frame()
: m_id(0), m_nextId(0), m_graphicsId(0), m_duration(0.0f) {

}

Frame::Frame(unsigned int in_id, unsigned int in_nextId, unsigned int in_graphicsId, float in_duration)
: m_id(in_id), m_nextId(in_nextId), m_graphicsId(in_graphicsId), m_duration(in_duration) {

}

Frame::~Frame() {

}
