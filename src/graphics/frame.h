#ifndef T_GRAPHICS_FRAME_H
#define T_GRAPHICS_FRAME_H

#include "../misc/define.h"

namespace t {
	namespace graphics {
		class Frame {
			public:
				Frame();
				Frame(unsigned int, unsigned int, unsigned int, float);
				~Frame();

				const unsigned int getID() { return m_id; }
				float getDuration() { return m_duration; }
				unsigned int getNextFrameId() { return m_nextId; }
				unsigned int getAssetId() { return m_graphicsId; }
			protected:
			private:
				const unsigned int m_id;
				const unsigned int m_nextId;
				const unsigned int m_graphicsId; // Necessary?
				const float m_duration;
		}; // class Frame
		//typedef boost::shared_ptr<Frame> SPFRAME;
		//typedef boost::shared_ptr<std::vector<SPFRAME> > SPFRAMES; //TODO: Ska det vara map<pair<uns int, frame> istallet?
	} // namespace graphics
} // namespace t

#endif // T_GRAPHICS_FRAME_H
