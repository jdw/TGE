#include "animation.h"

#include "../misc/define.h"
#include "frame.h"

using namespace t::graphics;

Animation::Animation() {
	m_spFrames = SPFRAMES(new std::vector<SPFRAME>());
    m_currentFrameId = 0;
    m_lastFrameChange = 0.0f;
}

Animation::Animation(SPFRAMES in_frames) {
	m_spFrames = in_frames;
	m_currentFrameId = 0;
    m_lastFrameChange = 0.0f;
}

Animation::~Animation() {

}

int Animation::update(const unsigned int& i_time) { START
	if (m_oldFrameId != m_currentFrameId) {
		m_oldFrameId = m_currentFrameId;
		//TODO: update last frame change to in_time?????? when triggered from outside
	}

	if (m_spFrames.get()->at(m_currentFrameId)->getDuration() < m_lastFrameChange - i_time) {
		m_lastFrameChange = i_time;
		m_currentFrameId = m_spFrames.get()->at(m_currentFrameId)->getNextFrameId();
		m_oldFrameId = m_currentFrameId;
	}
STOP }

/*
int Animation::fetchDrawables() {
	// START

	return 0;
	// STOP
}
*/
