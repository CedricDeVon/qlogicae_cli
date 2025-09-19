#pragma once

#include "utilities.hpp"

#include "qlogicae_core.hpp"

namespace QLogicaeCLI
{
	class Application
	{
	public:
		bool parse();
		bool setup(int, char**);
	
		static Application& get_instance();

	protected:
		Application();
		~Application() = default;
		Application(const Application&) = delete;
		Application(Application&&) noexcept = delete;
		Application& operator = (Application&&) = delete;
		Application& operator = (const Application&) = delete;

		size_t _generate_uuid4_input_1;
		std::string _generate_uuid4_input_2;
		bool _generate_uuid4_input_3;
		bool _generate_uuid4_input_4;

		size_t _generate_string_input_1;
		size_t _generate_string_input_2;
		std::string _generate_string_input_3;
		std::string _generate_string_input_4;
		bool _generate_string_input_5;
		bool _generate_string_input_6;

		std::string _encrypt_xchacha20poly1305_input_1;
		std::string _encrypt_xchacha20poly1305_input_2;
		std::string _encrypt_xchacha20poly1305_input_3;
		std::string _encrypt_xchacha20poly1305_input_4;
		bool _encrypt_xchacha20poly1305_input_5;
		bool _encrypt_xchacha20poly1305_input_6;

		std::string _decrypt_xchacha20poly1305_input_1;
		std::string _decrypt_xchacha20poly1305_input_2;
		std::string _decrypt_xchacha20poly1305_input_3;
		std::string _decrypt_xchacha20poly1305_input_4;
		bool _decrypt_xchacha20poly1305_input_5;
		bool _decrypt_xchacha20poly1305_input_6;

		std::string _hash_argon2id_input_1;
		std::string _hash_argon2id_input_2;
		bool _hash_argon2id_input_3;
		bool _hash_argon2id_input_4;

		std::string _verify_argon2id_input_1;
		std::string _verify_argon2id_input_2;
		std::string _verify_argon2id_input_3;
		bool _verify_argon2id_input_4;
		bool _verify_argon2id_input_5;

		std::vector<std::string> _run_scripts_input_1;
		bool _run_scripts_input_3;

		std::string _build_vs2022_input_1;
		std::string _build_vs2022_input_2;
		std::string _build_vs2022_input_3;
		std::string _build_vs2022_input_4;
		bool _build_vs2022_input_5;

		bool _get_environment_input_2;

		std::string _set_environment_input_1;
		bool _set_environment_input_3;

		std::string _view_windows_registry_input_1;
		bool _view_windows_registry_input_2;

		std::string _set_windows_registry_input_1;
		std::string _set_windows_registry_input_2;
		std::string _set_windows_registry_input_3;
		bool _set_windows_registry_input_4;

		std::string _setup_windows_registry_input_1;
		bool _setup_windows_registry_input_5;

		std::string _setup_vs2022_application_input_1;
		bool _setup_vs2022_application_input_2;

		std::string _verify_vs2022_application_input_1;
		bool _verify_vs2022_application_input_2;

		std::string _setup_installer_input_1;
		std::string _setup_installer_input_2;
		bool _setup_installer_input_3;

		std::string _setup_documentation_input_1;
		bool _setup_documentation_input_2;

		CLI::App _application;
		std::unordered_map<std::string, std::pair<CLI::App*, std::function<bool()>>> _commands;

		bool _setup_about_command();
		
		bool _setup_uuid4_command();

		bool _setup_string_command();

		bool _setup_xchacha20poly1305_command();

		bool _setup_argon2id_command();

		bool _setup_scripts_command();

		bool _setup_build_command();

		bool _setup_windows_registry_command();

		bool _setup_deploy_command();

		bool _setup_template_command();		
	};
}

/*

static std::string hklm_registry_path_setup_command =
	"\n[Registry]\nRoot: HKLM; Subkey: \"SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Environment\"; ValueType: expandsz; ValueName: \"Path\"; ValueData: \"{olddata};{app}\"\n";

*/

/*

jwt encrypt --issuer --data --public-key --private-key --lifetime-in-seconds --is-file-output-enabled --output-file-path --is-verbose-logging-enabled
jwt decrypt --issuer --data --public-key --private-key --lifetime-in-seconds --is-file-output-enabled --output-file-path --is-verbose-logging-enabled
sha hash --text --is-file-output-enabled --output-file-path --is-verbose-logging-enabled
sha verify --hash --text --is-file-output-enabled --output-file-path --is-verbose-logging-enabled
aes encrypt --text --key --nonce --is-file-output-enabled --output-file-path --is-verbose-logging-enabled
aes decrypt --cipher --key --nonce --is-file-output-enabled --output-file-path --is-verbose-logging-enabled

setup vs2022 cink --is-verbose-logging-enabled
setup vs2022 plotica --is-verbose-logging-enabled

*/
