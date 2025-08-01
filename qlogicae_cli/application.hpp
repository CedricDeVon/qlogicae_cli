#pragma once

#include "pch.hpp"

#include "globals.hpp"

namespace QLogicaeCLI
{
	class QLogicaeCLIApplication
	{
	public:
		bool parse();
		bool setup(int, char**);
	
		static QLogicaeCLIApplication& get_instance();

	protected:
		QLogicaeCLIApplication();
		~QLogicaeCLIApplication() = default;
		QLogicaeCLIApplication(const QLogicaeCLIApplication&) = delete;
		QLogicaeCLIApplication(QLogicaeCLIApplication&&) noexcept = delete;
		QLogicaeCLIApplication& operator = (QLogicaeCLIApplication&&) = delete;
		QLogicaeCLIApplication& operator = (const QLogicaeCLIApplication&) = delete;

		void _log_running_timestamp();
		void _log_complete_timestamp();
		void _log_exception_timestamp(const std::string_view);

		uint64_t _index_1;
	    uint64_t _index_2;
		uint64_t _index_3;
		uint64_t _index_4;

		uint64_t _generate_uuid4_input_1;

		uint64_t _generate_string_input_1;
		uint64_t _generate_string_input_2;

		std::string _encrypt_xchacha20poly1305_input_1;
		std::string _encrypt_xchacha20poly1305_input_2;
		std::string _encrypt_xchacha20poly1305_input_3;

		std::string _decrypt_xchacha20poly1305_input_1;
		std::string _decrypt_xchacha20poly1305_input_2;
		std::string _decrypt_xchacha20poly1305_input_3;

		std::string _hash_argon2id_input_1;

		std::string _verify_argon2id_input_1;
		std::string _verify_argon2id_input_2;

		std::string _set_environment_input_1;
		std::string _set_environment_input_2;

		std::vector<std::string> _run_scripts_input_1;
		std::string _run_scripts_input_2;

		std::string _view_windows_registry_input_1;

		std::string _setup_windows_registry_input_1;
		std::string _setup_windows_registry_input_2;
		std::string _setup_windows_registry_input_3;
		std::string _setup_windows_registry_input_4;

		std::string _setup_default_template_input_1;

		std::string _verify_default_template_input_1;

		std::string _setup_installer_input_1;
		std::string _setup_installer_input_2;


		CLI::App _application;
		std::unordered_map<std::string, std::pair<CLI::App*, std::function<bool()>>> _commands;
	};
}
