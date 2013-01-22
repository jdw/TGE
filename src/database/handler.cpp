#include "handler.h"

#include "../misc/define.h"
#include "../misc/include.h"
#include "../graphics/frame.h"

#include <sqlite3.h>

using namespace t::database;

Handler::Handler()
: t::misc::interface::Handler(), m_isSetup(false) {
	//TODO: Don't set up log db if not in DEBUG_DATABASE mode ???
	for (int i = 0; i < type::MAX; i++)
		m_pDatabases[i] = (sqlite3*)0;
}

Handler::~Handler() {

}

int Handler::setup() { START
	if (SQLITE_OK != sqlite3_open("data/assets.db", &m_pDatabases[type::GAME])) {
		std::cout << "!!! Failed to open game.db" << std::endl;
		ERROR_INCREMENT
	}

	//if DEBUG ....
	if (SQLITE_OK != sqlite3_open("data/log.db", &m_pDatabases[type::LOG])) {
		std::cout << "!!! Failed to open log.db" << std::endl;
		ERROR_INCREMENT
	}

	m_isSetup = true;
STOP }

int Handler::teardown() { START
	for (int i = 0; i < type::MAX; i++)
		if ((sqlite3*)0 != m_pDatabases[i])
			sqlite3_close(m_pDatabases[i]);
STOP }

int Handler::update(const unsigned int&) { START

STOP }

int Handler::read(const type::Enum i_id, const std::string i_query, sqlite3_stmt*& i_pStmt) { START
	if (SQLITE_OK != sqlite3_prepare(m_pDatabases[i_id], i_query.c_str(), -1, &i_pStmt, NULL)) {
		std::cout << "!!! Error preparing statement" << std::endl;
		ERROR_INCREMENT
	}
STOP }

int Handler::write(const type::Enum in_db, std::string in_statement) { START
	if (!m_isSetup) this->setup();

	sqlite3_stmt* t_pStmt;
	if (SQLITE_OK != sqlite3_prepare(m_pDatabases[in_db], in_statement.c_str(), -1, &t_pStmt, NULL)) {
		std::cout << __FILE__ << __LINE__ << "!!! Error preparing statement" << std::endl;
		ERROR_INCREMENT
	}

	if (SQLITE_DONE != sqlite3_step(t_pStmt)) {
		std::cout << "!!! Error stepping statement" << std::endl;
		ERROR_INCREMENT
	}

	sqlite3_finalize(t_pStmt);
STOP }

int Handler::log_TEST_TRUE(const char *in_fileName, int in_line, const char *in_funcName, const char * in_log) { START
	std::stringstream t_s;
	t_s << "INSERT INTO test_true (file, line, function, message) VALUES ('" << \
		in_fileName << "'," << \
		in_line <<",'" << \
		in_funcName << "','" << \
		in_log << "');";

	this->write(type::LOG, t_s.str());
STOP }

int Handler::log_TEST_VALUE(const char* in_fileName, int in_line, const char* in_funcName, const char* in_x, const char* in_y) { START
	std::stringstream t_s;
	t_s << "INSERT INTO test_value (file, line, function, x, y) VALUES ('" << \
		in_fileName << "'," << \
		in_line <<",'" << \
		in_funcName << "','" << \
		in_x << "','" << \
		in_y << "');";

	this->write(type::LOG, t_s.str());
STOP }

//TODO: Rename to readAnimation?
int Handler::readGraphics(const unsigned int in_id, t::graphics::SPANIMATION& in_a) { START
	if (!m_isSetup) this->setup();

/*	if (!m_isSetup) this->setup();

	std::map<std::string, int> t_columns;
	sqlite3_stmt* t_pStmt = NULL;
	std::stringstream t_s;
	t_s << "SELECT * FROM animation WHERE id=" << in_id << ";";
	//t_s << "SELECT * FROM asset WHERE id=" << in_id << ";";

	if (SQLITE_OK != sqlite3_prepare(m_pDatabases[type::GAME], t_s.str().c_str(), -1, &t_pStmt, NULL)) {
		std::cout << __FILE__ << __LINE__ <<  "!!! Error preparing statement" << std::endl;
		ERROR_INCREMENT
	}

	for (int i = 0; i < sqlite3_column_count(t_pStmt); i++) {
		std::string t_columnName(sqlite3_column_name(t_pStmt, i));
		t_columns[t_columnName] = i;
	}

	t::graphics::SPFRAMES t_spFrames = t::graphics::SPFRAMES(new std::vector<t::graphics::SPFRAME>());
	readFrames(in_id, t_spFrames);

	std::cout << "frames size: " << t_spFrames.get()->size() << std::endl;
	for (unsigned int i = 0; i < t_spFrames.get()->size(); i++) {
		std::cout <<
			t_spFrames.get()->at(i)->getID() << "\t" <<
			t_spFrames.get()->at(i)->getDuration() << "\t" <<
			t_spFrames.get()->at(i)->getNextFrameId() << "\t" <<
			t_spFrames.get()->at(i)->getAssetId() << "\t"
		<< std::endl;
	}
*/
STOP }

int Handler::readFrames(const unsigned int in_animationId, t::graphics::SPFRAMES in_pFrames) { START
	if (!m_isSetup) this->setup();

	std::map<std::string, int> t_columns;
	sqlite3_stmt* t_pStmt = NULL;
	std::stringstream t_s;
	t_s << "SELECT * FROM frame WHERE animation_id=" << in_animationId << ";";
	this->read(type::GAME, t_s.str(), t_pStmt);

	for (int i = 0; i < sqlite3_column_count(t_pStmt); i++) {
		std::string t_columnName(sqlite3_column_name(t_pStmt, i));
		t_columns[t_columnName] = i;
	}

	while (SQLITE_ROW == sqlite3_step(t_pStmt)) {
		int t_id = sqlite3_column_int(t_pStmt, t_columns.find("id")->second);
		int t_nextFrameId = sqlite3_column_int(t_pStmt, t_columns.find("next_frame_id")->second);
		int t_assetId = sqlite3_column_int(t_pStmt, t_columns.find("asset_id")->second);
		float t_duration = (float)sqlite3_column_double(t_pStmt, t_columns.find("duration")->second);

		std::cout <<
		t_id << "\t" <<
		t_duration << "\t" <<
		t_nextFrameId << "\t" <<
		t_assetId << "\t" << std::endl;

		in_pFrames->push_back(t::graphics::SPFRAME(
			new t::graphics::Frame(	t_id,
						t_nextFrameId,
						t_assetId,
						t_duration)));
	}

STOP }

/*
int DatabaseHandler::readPhysics(unsigned int in_id, unsigned int* in_pId) { START

STOP }
*/

Handler* Handler::instance() {
	if (NULL == m_pInstance)
		m_pInstance = new Handler();

	return m_pInstance;
}
