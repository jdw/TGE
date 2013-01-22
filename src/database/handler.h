#ifndef T_DATABASE_HANDLER_H
#define T_DATABASE_HANDLER_H

#include "../misc/interface/handler.h"
#include "../graphics/animation.h" //TODO: needed?

class sqlite3;
class sqlite3_stmt;

namespace t {
	namespace database {
			namespace type {
				enum Enum {
					GAME = 0,
					LOG,

					MAX // Faulty
				}; // enum Enum
			} // namespace Databases
			class Handler: public t::misc::interface::Handler {
				public:
					~Handler();

					static Handler* instance();
					int setup();
					int teardown();
					int update(const unsigned int&);
					inline int read(const type::Enum, const std::string, sqlite3_stmt*&);
					int readPhysics(unsigned int, unsigned int*);
					int readGraphics(const unsigned int, t::graphics::SPANIMATION&);
					//int readAnimation(unsigned int, unsigned int*);
					int readFrames(const unsigned int /*Animation id*/, t::graphics::SPFRAMES);
					int readSound(unsigned int);
					int log_TEST_TRUE(const char* in_fileName, int in_line, const char* in_funcName, const char* in_log);
					int log_TEST_VALUE(const char* in_fileName, int in_line, const char* in_funcName, const char* in_x, const char* in_y);
					//int log(const char *in_fileName, int in_line, const char *in_funcName, int, const char * in_log, ... );
					//void LogFile(const char *in_fileName, const char *in_funcName, int in_line, const char * in_log, ... )
				protected:
				private:
					Handler();
					int write(const type::Enum, std::string);

					sqlite3* m_pDatabases[type::MAX];
					bool m_isSetup;
					static Handler* m_pInstance;
			}; // class DatabaseHandler
	} // namespace handler
} // namespace t

#endif // T_DATABASEHANDLER_H
