#ifndef T_ENTITY_H
#define T_ENTITY_H

#include "../misc/typedef.h"

namespace t {
	namespace entity {
		namespace type {
			enum Enum { GFX = 0, SFX, PFX, AI, MAX };
		}

		//template <class T>
		class Entity {
			public:
				Entity(unsigned int, unsigned int, unsigned int);
				Entity();
				~Entity();

				const int& getPosX() const { return m_posX; }
				const int& getPosY() const { return m_posY; }
				void setPos(int x, int y) { m_posX = x; m_posY = y; }
				void setVisible(const bool i) { m_isVisible = i; }
				void setActive(const bool i) { m_isActive = i; }
				void setDead(const bool i) { m_isDead = i; }
				//TODO: const references
				const unsigned int& getGFXId() const { return m_ids[type::GFX]; }
				const unsigned int& getSFXId() const { return m_ids[type::SFX]; }
				const unsigned int& getPFXId() const { return m_ids[type::PFX]; }
				const bool& isVisible() const { return m_isVisible; }
				const bool& isActive() const { return m_isActive; }
				const bool& isDead() const { return m_isDead; }
				int update(const unsigned int&);
				//int draw();
				//t::graphics::Message fetchGraphics();
				//int fetchSound();
				//int fetchPhysics();

			protected:

			private:
				int updatePhysics(const float&);
				int updateGraphics(const float&);
				int updateSound(const float&);

				int m_posX, m_posY;
				t::graphics::Animation* m_pAnimation;
				float m_lastTime;
				unsigned int m_ids[type::MAX];
				bool m_isVisible, m_isActive, m_isDead;
		}; // class Entity
	} // namespace entity
} // namespace t

#endif // T_ENTITY_H
