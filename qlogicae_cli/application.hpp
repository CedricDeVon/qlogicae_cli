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

		bool _setup_template_command();
		
		bool _setup_environment_command();

		bool _setup_windows_registry_command();

		bool _setup_deploy_command();

	};
}



/*

jwt encrypt --issuer --data --public-key --private-key --lifetime-in-seconds --is-file-output-enabled --output-file-path --is-verbose-logging-enabled
jwt decrypt --issuer --data --public-key --private-key --lifetime-in-seconds --is-file-output-enabled --output-file-path --is-verbose-logging-enabled
sha hash --text --is-file-output-enabled --output-file-path --is-verbose-logging-enabled
sha verify --hash --text --is-file-output-enabled --output-file-path --is-verbose-logging-enabled
aes encrypt --text --key --nonce --is-file-output-enabled --output-file-path --is-verbose-logging-enabled
aes decrypt --cipher --key --nonce --is-file-output-enabled --output-file-path --is-verbose-logging-enabled

setup vs2022 cink --is-verbose-logging-enabled
setup vs2022 plotica --is-verbose-logging-enabled


mock dataset --is-verbose-logging-enabled





bool Application::_setup_verify_vs2022_application_command()
{
	try
	{
		std::string command_name = "verify-vs2022-application";
		_commands[command_name] = std::make_pair(
			_application.add_subcommand(
				command_name,
				"Verifies a selected Visual Studio 2022 C++ application file system"),
			[this]() -> bool
			{
				try
				{
					_log_running_timestamp_async(
						_verify_vs2022_application_input_2
					);

					if (_verify_vs2022_application_input_1
						.empty()
						)
					{
						return false;
					}

					std::string output_string = "";
					size_t success_count = 0, total_count;
					std::vector<std::string> file_paths =
					{
						_verify_vs2022_application_input_1 +
							assets_folder_path,
						_verify_vs2022_application_input_1 +
							scripts_folder_path,
						_verify_vs2022_application_input_1 +
							configurations_folder_path,
						_verify_vs2022_application_input_1 +
							license_file_path,
						_verify_vs2022_application_input_1 +
							private_file_path,
						_verify_vs2022_application_input_1 +
							assets_icon_file_path,
						_verify_vs2022_application_input_1 +
							scripts_inno_run_file_path,
						_verify_vs2022_application_input_1 +
							scripts_inno_setup_file_path,
						_verify_vs2022_application_input_1 +
							configurations_public_file_path
					};
					total_count = file_paths.size();

					for (const std::string& file_path : file_paths)
					{
						if (std::filesystem::exists(file_path))
						{
							output_string +=
								_transform_log_success_timestamp(
									file_path +
									"' Exists"
								);
							++success_count;
						}
						else
						{
							output_string +=
								_transform_log_exception_timestamp(
									file_path +
									"' Not Found"
								);
						}
					}
					output_string +=
						_transform_log_info_timestamp(
							"Results: " +
							absl::StrCat(success_count) + " / " +
							absl::StrCat(total_count) + " Test Cases Passed"
						);
					QLogicaeCore::CLI_IO.print_async(output_string);

					_log_complete_timestamp_async(
						_verify_vs2022_application_input_2
					);
				}
				catch (const std::exception& exception)
				{
					_log_exception_timestamp_async(std::string("Exception at Application::_setup_verify_vs2022_application_command(): ") + exception.what(), _verify_vs2022_application_input_2);

					return false;
				}

				return true;
			}
		);
		_commands[command_name].first
			->add_option(
				"--input-folder-path",
				_verify_vs2022_application_input_1,
				"Selected input folder path"
			)
			->default_val(".");
		_commands[command_name].first
			->add_option("--is-verbose-logging-enabled",
				_verify_vs2022_application_input_2,
				"Enables or disables verbose console logging"
			)
			->default_val(true);

		return true;
	}
	catch (const std::exception& exception)
	{
		_log_exception_timestamp_async(std::string("Exception at Application::_setup_verify_vs2022_application_command(): ") + exception.what(), _verify_vs2022_application_input_2);

		return false;
	}
}

bool Application::_setup_setup_generic_documentation_command()
{
	try
	{
		std::string command_name = "setup-generic-documentation";
		_commands[command_name] = std::make_pair(
			_application.add_subcommand(
				command_name,
				"Creates documentation"),
			[this]() -> bool
			{
				try
				{
					_log_running_timestamp_async(_setup_documentation_input_2);

					if (!std::filesystem::exists(
						_setup_documentation_input_1)
						)
					{
						_log_exception_timestamp_async(std::string("Exception at Application::_setup_setup_documentation_command(): Folder path '" + _setup_documentation_input_1  + "' is invalid"), _setup_documentation_input_2);

						return false;
					}



					_log_complete_timestamp_async(_setup_documentation_input_2);

					return true;
				}
				catch (const std::exception& exception)
				{
					_log_exception_timestamp_async(std::string("Exception at Application::_setup_setup_documentation_command(): ") + exception.what(), _setup_documentation_input_2);

					return false;
				}
			}
		);
		_commands[command_name].first
			->add_option("--input-folder-path",
				_setup_documentation_input_1,
				"Selected input folder path")
			->default_val("./");
		_commands[command_name].first
			->add_option("--is-verbose-logging-enabled",
				_setup_documentation_input_2,
				"Enables or disables verbose console logging")
			->default_val(true);

		return true;
	}
	catch (const std::exception& exception)
	{
		_log_exception_timestamp_async(std::string("Exception at Application::_setup_setup_documentation_command(): ") + exception.what(), _setup_documentation_input_2);

		return false;
	}
}
*/
