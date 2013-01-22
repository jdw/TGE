#ifndef T_MISC_INTERFACE_SCENE_H
#define T_MISC_INTERFACE_SCENE_H

#include "../../misc/typedef.h"

#include "../message.h"

namespace t {
	namespace misc {
		namespace interface {
			class Scene  {
				public:
					virtual ~Scene();
					virtual int update(const unsigned int&) = 0;
					virtual int input() = 0;
					virtual int renderGFX() = 0;
					virtual int renderPSX() = 0;

					void isDone(bool i) { m_isDone = i; }
					bool isDone() { return m_isDone; }
					void setQue(t::subsystem::Name, t::misc::MSGQUE*);
					void setInputMessage(t::input::Message* i) { this->m_pInputMessage = i; }
				protected:
					Scene(int in_id);
					int getIdAsInt() { return m_id; }
					t::misc::Message& getNextMessage(t::subsystem::Name);
					t::input::Message* getInputMessage() { return this->m_pInputMessage; }
					bool m_isDone;

				private:
					t::entity::SPENTITYS m_spEntitys;
					t::misc::MSGQUE* m_ques[t::subsystem::MAX];

					const int m_id;
					t::input::Message* m_pInputMessage;
			}; // class Scene
		} // namespace interface
	} // namespace misc
} // namespace t

#endif // T_SCENE_H
