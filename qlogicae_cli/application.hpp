#pragma once

#include "pch.hpp"

#include "globals.hpp"

namespace ErwinCLI
{
	class ErwinCLIApplication
	{
	public:
		bool parse();
		bool setup(int, char**);
	
		static ErwinCLIApplication& get_instance();

	protected:
		ErwinCLIApplication();
		~ErwinCLIApplication() = default;
		ErwinCLIApplication(const ErwinCLIApplication&) = delete;
		ErwinCLIApplication(ErwinCLIApplication&&) noexcept = delete;
		ErwinCLIApplication& operator = (ErwinCLIApplication&&) = delete;
		ErwinCLIApplication& operator = (const ErwinCLIApplication&) = delete;

		int64_t _index_1;
	    int64_t _index_2;
		int64_t _index_3;
		int64_t _index_4;

		int64_t _generate_uuid4_input_1;

		int64_t _generate_string_input_1;
		int64_t _generate_string_input_2;

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
