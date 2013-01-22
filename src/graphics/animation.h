#ifndef T_GRAPHICS_ANIMATION_H
#define T_GRAPHICS_ANIMATION_H

#include "../misc/typedef.h"

namespace t {
	namespace graphics {
		class Animation {
			public:
				Animation();
				Animation(SPFRAMES);
				~Animation();

				float getLastFrameChange() { return m_lastFrameChange; }
				int getCurrentFrameId() { return m_currentFrameId; }
				//SPFRAME getCurrentFrame() { return m_spFrames.get()[m_currentFrameId]; }//return m_spFrames[m_currentFrameId]; }
				void setCurrentFrame(int val) { m_currentFrameId = val; }

				int update(const unsigned int&);
				//int fetchDrawables();
			protected:
			private:
				float m_lastFrameChange;
				unsigned int m_currentFrameId;
				unsigned int m_oldFrameId;
				SPFRAMES m_spFrames;
		}; // class Animation
		//typedef boost::shared_ptr<Animation> SPANIMATION;
		//typedef boost::shared_ptr<std::vector<SPANIMATION> > SPANIMATIONS;
	} // namespace graphics
} // namespace t

#endif // __t__ANIMATION_H
