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

		std::string _encrypt_aes256_input_1;
		std::string _encrypt_aes256_input_2;
		std::string _encrypt_aes256_input_3;
		std::string _encrypt_aes256_input_4;
		bool _encrypt_aes256_input_5;
		bool _encrypt_aes256_input_6;

		std::string _decrypt_aes256_input_1;
		std::string _decrypt_aes256_input_2;
		std::string _decrypt_aes256_input_3;
		std::string _decrypt_aes256_input_4;
		bool _decrypt_aes256_input_5;
		bool _decrypt_aes256_input_6;

		std::string _hash_argon2id_input_1;
		std::string _hash_argon2id_input_2;
		bool _hash_argon2id_input_3;
		bool _hash_argon2id_input_4;

		std::string _verify_argon2id_input_1;
		std::string _verify_argon2id_input_2;
		std::string _verify_argon2id_input_3;
		bool _verify_argon2id_input_4;
		bool _verify_argon2id_input_5;

		std::string _hash_sha256_input_1;
		std::string _hash_sha256_input_2;
		bool _hash_sha256_input_3;
		bool _hash_sha256_input_4;

		std::string _verify_sha256_input_1;
		std::string _verify_sha256_input_2;
		std::string _verify_sha256_input_3;
		bool _verify_sha256_input_4;
		bool _verify_sha256_input_5;

		std::string _run_vs2022_input_1;
		std::string _run_vs2022_input_2;
		std::string _run_vs2022_input_3;
		bool _run_vs2022_input_4;
		
		std::string _run_executable_input_1;
		bool _run_executable_input_2;

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
		
		bool _setup_generate_command();

		bool _setup_encrypt_command();

		bool _setup_decrypt_command();
		
		bool _setup_hash_command();

		bool _setup_verify_command();

		bool _setup_run_command();

		bool _setup_build_command();

		bool _setup_get_command();

		bool _setup_set_command();

		bool _setup_setup_command();

		bool _setup_deploy_command();

		bool _setup_template_command();		
	};
}

/*

static std::string hklm_registry_path_setup_command =
	"\n[Registry]\nRoot: HKLM; Subkey: \"SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Environment\"; ValueType: expandsz; ValueName: \"Path\"; ValueData: \"{olddata};{app}\"\n";

		bool _setup_sha256_command();

		bool _setup_aes256_command();

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


/*
	bool Application::_setup_deploy_command()
	{
		try
		{
			CLI::App* deploy_command =
				_application.add_subcommand(
					"deploy",
					"Deploy commands: inno_setup"
				);
			CLI::App* deploy_inno_setup_command =
				deploy_command->add_subcommand(
					"inno-setup",
					"Creates an application installation executable via Inno Setup"
				);

			deploy_inno_setup_command
				->add_option("--input-folder-path",
					_setup_installer_input_1,
					"Selected input folder path")
				->default_val(".\\");
			deploy_inno_setup_command
				->add_option("--output-folder-path",
					_setup_installer_input_2,
					"Selected output folder path")
				->default_val(".\\");
			deploy_inno_setup_command
				->add_option("--is-verbose-logging-enabled",
					_setup_installer_input_3,
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["deploy-inno-setup"] = std::make_pair(
				deploy_inno_setup_command,
				[this]() -> bool
				{
					try
					{
						UTILITIES.log_running_timestamp_async(_setup_installer_input_3);

						std::string path_2 =
							_setup_installer_input_1 +
							qlogicae_private_file_path;
						std::string path_3 =
							_setup_installer_input_1 +
							public_qlogicae_scripts_inno_run_file_path;
						std::string path_4 =
							_setup_installer_input_1 +
							public_qlogicae_scripts_inno_setup_file_path;
						std::string path_5 =
							_setup_installer_input_1 +
							public_qlogicae_scripts_inno_target_file_path;
						std::string path_6 =
							_setup_installer_input_1 +
							public_qlogicae_scripts_folder_path;
						std::string path_7;

						client_private_file.set_file_path(path_2);
						client_inno_run_file.set_file_path(path_3);
						client_inno_setup_file.set_file_path(path_4);
						client_inno_setup_target_file.set_file_path(path_5);

						_remove_file_or_folder_if_found(path_5);
						_copy_file_or_folder(path_4, path_5);

						std::string client_input_folder_path =
							std::filesystem::absolute(
								client_private_file.get_string(
									{ "inno_setup", "input_folder_path" }
								)
							).string();

						client_public_file.set_file_path(
							client_input_folder_path +
							"\\" + public_qlogicae_configurations_public_file_path
						);
						client_public_file.update_string(
							{ "environment", "selected" }, "release"
						);
						client_public_file.set_file_path(
							_setup_installer_input_1 +
							"\\" + public_qlogicae_configurations_public_file_path
						);

						std::string client_inno_setup_target_file_output = "";
						std::unordered_map<std::string, std::any> client_languages =
							client_private_file.get_object(
								{ "languages" }
							);
						client_inno_setup_target_file_output += "\n[Languages]\n";
						for (const auto& [name, properties] : client_languages)
						{
							std::unordered_map<std::string, std::any> object =
								std::any_cast<std::unordered_map<
								std::string, std::any>>(properties);
							if (std::any_cast<bool>(object["is_enabled"]))
							{
								client_inno_setup_target_file_output +=
									"Name: \"" + name +
									"\"; MessagesFile: \"" +
									std::any_cast<std::string>(
										object["message_file"]
									) + "\"\n";
							}
						}

						std::unordered_map<std::string, std::any>
							client_hkcu_secrets =
							client_private_file.get_object(
								{
									"windows_registry",
									"release",
									"hkcu"
								}
							);
						std::string client_application_id =
							client_public_file
							.get_string(
								{
									"application",
									"id"
								}
							);
						std::string client_release_id =
							client_public_file
							.get_string(
								{
									"environment",
									"selections",
									"release"
								}
							);

						client_inno_setup_target_file_output +=
							hklm_registry_path_setup_command;

						for (const auto& [key, value] : client_hkcu_secrets)
						{
							client_inno_setup_target_file_output +=
								"Root: HKCU; Subkey: \"Software\\QLogicae\\" +
								client_application_id +
								"\\" + client_release_id +
								"\"; ValueType: string; ValueName: \"" +
								std::any_cast<std::string>(key) +
								"\"; ValueData: \"" +
								std::any_cast<std::string>(value) +
								"\"; Flags: uninsdeletekeyifempty\n";
						}
						client_inno_setup_target_file.append(
							client_inno_setup_target_file_output
						);

						system(inno_setup_command.c_str());

						_remove_file_or_folder_if_found(path_5);

						client_public_file.update_string(
							{ "environment", "selected" }, "development"
						);

						UTILITIES.log_complete_timestamp_async(_setup_installer_input_3);

						return true;
					}
					catch (const std::exception& exception)
					{
						UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_deploy_command(): ") + exception.what(), _setup_installer_input_3);

						return false;
					}
				}
				);

				return true;
		}
		catch (const std::exception& exception)
		{
			UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_deploy_command(): ") + exception.what(), _setup_installer_input_3);

			return false;
		}
	}

	bool Application::_setup_template_command()
	{
		try
		{
			CLI::App* setup_command =
				_application.add_subcommand(
					"setup",
					"Setup commands: vs2022 application"
				);
			CLI::App* setup_vs2022_command =
				setup_command->add_subcommand(
					"vs2022",
					"Visual Studio 2022 specific templates"
				);
			CLI::App* setup_vs2022_application_command =
				setup_vs2022_command->add_subcommand(
					"application",
					"Creates an application template developed under Visual Studio 2022"
				);

			setup_vs2022_application_command
				->add_option(
					"--output-folder-path",
					_setup_vs2022_application_input_1,
					"Selected output folder path")
				->default_val(".");
			setup_vs2022_application_command
				->add_option("--is-verbose-logging-enabled",
					_setup_vs2022_application_input_2,
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["setup-vs2022-application"] = std::make_pair(
				setup_vs2022_application_command,
				[this]() -> bool
				{
					try
					{
						UTILITIES.log_running_timestamp_async(_setup_vs2022_application_input_2);

						std::string output_path =
							application_directory_name_string + "\\" +
							public_qlogicae_folder_path + "\\" +
							qlogicae_cli_folder_path + "\\" +
							templates_folder_name_string + "\\" +
							vs2022_folder_name_string + "\\" +
							application_folder_name_string;

						system(("xcopy \"" + output_path + "\" \"" + _setup_vs2022_application_input_1 + "\" /E /Y /I").c_str());

						client_public_file.set_file_path(
							_setup_vs2022_application_input_1 + "\\" +
							public_qlogicae_configurations_public_file_path
						);

						client_public_file.update_string(
							{ "application", "id" },
							QLogicaeCore::GENERATOR.random_uuid4()
						);
						client_public_file.update_string(
							{ "environment", "selections", "development" },
							QLogicaeCore::GENERATOR.random_uuid4()
						);
						client_public_file.update_string(
							{ "environment", "selections", "debug" },
							QLogicaeCore::GENERATOR.random_uuid4()
						);
						client_public_file.update_string(
							{ "environment", "selections", "test" },
							QLogicaeCore::GENERATOR.random_uuid4()
						);
						client_public_file.update_string(
							{ "environment", "selections", "release" },
							QLogicaeCore::GENERATOR.random_uuid4()
						);

						UTILITIES.log_complete_timestamp_async(_setup_vs2022_application_input_2);

						return true;
					}
					catch (const std::exception& exception)
					{
						UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_template_command(): ") + exception.what(), _setup_vs2022_application_input_2);

						return false;
					}
				}
				);

				return true;
		}
		catch (const std::exception& exception)
		{
			UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_template_command(): ") + exception.what(), _setup_vs2022_application_input_2);

			return false;
		}
	}

	*/
