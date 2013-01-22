#ifndef T_MISC_INTERFACE_GAME_H
#define T_MISC_INTERFACE_GAME_H

#include "../typedef.h"

namespace t {
	namespace misc {
		namespace interface {
			namespace Subsystem {
				enum Enum {
					IO = 0, // IO gotta go first! (Redirects messages, ends game)
					SCENE, // Map (Stuff that is not movable (walls, trees, doors, floor, sea...)
					//ACTORS, // Player, enemies, creatures, NPCs... (anything living)
					//ITEM, // Stones, budles of mud, cookies, swords... (anything movable/usable/interactable, non-living thing)
					//PROPS, // Boulder, wall, floor, ocean of mud (anything unmovable)
					UI, // Last (to see results of last update), shows money, messages, menus...

					MAX // Faulty
				}; // enum Enum
			} // namespace Subsystem

			class Game {
				public:
					virtual ~Game() {}

					virtual int setup() = 0;
					virtual int teardown() = 0;
					virtual int update(const unsigned int&) = 0;
					virtual int run() = 0;

					bool getRunning() { return m_running; }

				protected:
					Game(t::scene::SPSCENES i_spScenes): m_spScenes(i_spScenes), m_running(false), m_currentScene(0) {}
//TODO: const correctnes
					t::misc::interface::Scene* getScene(const int i) const { return m_spScenes.get()->at(i).get(); }
					t::misc::interface::Scene* getScene() const { return m_spScenes.get()->at(m_currentScene).get(); }
					const int& getCurrentScene() const { return m_currentScene; }
					void addScene(const t::scene::SPSCENE i) { m_spScenes.get()->push_back(i); }
					void setRunning(const bool i_running) { m_running = i_running; }
					void setCurrentScene(const int i) { m_currentScene = i; }

				private:
					bool quit;
					t::scene::SPSCENES m_spScenes;
					bool m_running;
					int m_currentScene;
			}; // class Game
		} // namespace interface
	} // namespace misc
} // namespace t

#endif // T_MISC_INTERFACE_GAME_H
