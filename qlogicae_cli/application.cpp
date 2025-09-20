#include "pch.hpp"

#include "application.hpp"

namespace QLogicaeCLI
{
	Application::Application() :
		_application(
			UTILITIES.get_application_full_name()
		)
	{

	}

	bool Application::setup(int argc, char** argv)
	{
		try
		{
			if (!UTILITIES.is_visual_studio_2022_qlogicae_project_found() ||
				!_setup_about_command() ||
				!_setup_build_command() ||
				!_setup_run_command() ||
				!_setup_setup_command() ||
				!_setup_get_command() ||
				!_setup_set_command() ||
				!_setup_generate_command() ||
				!_setup_encrypt_command() ||
				!_setup_decrypt_command() ||
				!_setup_hash_command() ||
				!_setup_verify_command())
			{
				return false;
			}

			/*

			if (				
				!_setup_deploy_command())
				!_setup_template_command())
			{
				return false;
			}

			*/

			try
			{
				_application.parse(argc, argv);
			}
			catch (const CLI::ParseError& exception)
			{
				_application.exit(exception);

				return false;
			}

			return true;
		}
		catch (const std::exception& exception)
		{
			UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::setup(): ") + exception.what());

			return false;
		}
	}

	bool Application::parse()
	{
		try
		{
			for (const auto& [key, value] : _commands)
			{
				if (value.first->parsed())
				{
					return value.second();
				}
			}

			return true;
		}
		catch (const std::exception& exception)
		{
			UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::parse(): ") + exception.what());

			return false;
		}
	}

	Application& Application::get_instance()
	{
		static Application singleton;

		return singleton;
	}

	bool Application::_setup_about_command()
	{
		try
		{
			CLI::App* about_command =
				_application.add_subcommand(
					"about",
					"Project and application details"
				);

			_commands["about"] = std::make_pair(
				about_command,
				[this]() -> bool
				{
					QLogicaeCore::CLI_IO.print(
						UTILITIES.get_application_about_details()
					);

					return true;
				}
			);

			return true;
		}
		catch (const std::exception& exception)
		{
			UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_about_command(): ") + exception.what());

			return false;
		}
	}

	bool Application::_setup_run_command()
	{
		try
		{
			CLI::App* scripts_command =
				_application.add_subcommand(
					"run",
					"vs2022, scripts"
				);

			CLI::App* run_vs2022_command =
				scripts_command->add_subcommand(
					"vs2022",
					"Runs an executable build via Visual Studio 2022"
				);

			run_vs2022_command
				->add_option("--project",
					_run_vs2022_input_1,
					"A Visual Studio 2022 project"
				)
				->default_str("");

			run_vs2022_command
				->add_option("--architecture",
					_run_vs2022_input_2,
					"A Visual Studio 2022 project's instruction architecture"
				)
				->check(CLI::IsMember(
					UTILITIES.VISUAL_STUDIO_2022_BUILD_ARCHITECTURE_TYPES
				))
				->default_val(UTILITIES.VISUAL_STUDIO_2022_BUILD_ARCHITECTURE_TYPES[0]);

			run_vs2022_command
				->add_option("--type",
					_run_vs2022_input_3,
					"A Visual Studio 2022 project's build type"
				)
				->check(CLI::IsMember(
					UTILITIES.VISUAL_STUDIO_2022_BUILD_TYPES
				))
				->default_val(UTILITIES.VISUAL_STUDIO_2022_BUILD_TYPES[0]);

			run_vs2022_command
				->add_option("--is-verbose-logging-enabled",
					_run_vs2022_input_4,
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["run-vs2022"] = std::make_pair(
				run_vs2022_command,
				[this]() -> bool
				{
					try
					{
						UTILITIES.log_running_timestamp_async(_run_vs2022_input_4);

						if (_run_vs2022_input_1.empty())
						{
							UTILITIES.CLIENT_DOT_QLOGICAE_APPLICATION_CONFIGURATION_FILE.set_file_path(
								UTILITIES.RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_CONFIGURATIONS_QLOGICAE_FILE_PATH
							);

							_run_vs2022_input_1 =
								UTILITIES.CLIENT_DOT_QLOGICAE_APPLICATION_CONFIGURATION_FILE.get_string(
									{
										"visual_studio_2022",
										"startup_project_name"
									}
								);
						}

						std::string command = absl::StrCat(
							".\\", _run_vs2022_input_2,
							"\\", _run_vs2022_input_3,
							"\\", _run_vs2022_input_1,
							"\\", _run_vs2022_input_1,
							".exe"
						);

						system(command.c_str());

						UTILITIES.log_complete_timestamp_async(_run_vs2022_input_4);

						return true;
					}
					catch (const std::exception& exception)
					{
						UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_run_command(): ") + exception.what(), _run_vs2022_input_4);

						return false;
					}
				}
			);

			CLI::App* run_executable_command =
				scripts_command->add_subcommand(
					"executable",
					"Runs an executable"
				);

			run_executable_command
				->add_option("--path",
					_run_executable_input_1,
					"A selected path to an executable"
				)
				->required();

			run_executable_command
				->add_option("--is-verbose-logging-enabled",
					_run_executable_input_2,
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["run-executable"] = std::make_pair(
				run_executable_command,
				[this]() -> bool
				{
					try
					{
						UTILITIES.log_running_timestamp_async(_run_executable_input_2);

						system(_run_executable_input_1.c_str());

						UTILITIES.log_complete_timestamp_async(_run_executable_input_2);

						return true;
					}
					catch (const std::exception& exception)
					{
						UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_run_command(): ") + exception.what(), _run_executable_input_2);

						return false;
					}
				}
			);

			CLI::App* scripts_run_command =
				scripts_command->add_subcommand(
					"scripts",
					"Runs one or more QLogicae-defined scripts"
				);

			scripts_run_command
				->add_option("--commands",
					_run_scripts_input_1,
					"Selected script commands")
				->delimiter(',')
				->required();

			scripts_run_command
				->add_option("--is-verbose-logging-enabled",
					_run_scripts_input_3,
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["run-scripts"] = std::make_pair(
				scripts_run_command,
				[this]() -> bool
				{
					try
					{
						UTILITIES.log_running_timestamp_async(_run_scripts_input_3);

						UTILITIES.CLIENT_DOT_QLOGICAE_APPLICATION_CONFIGURATION_FILE.set_file_path(
							UTILITIES.RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_CONFIGURATIONS_QLOGICAE_FILE_PATH
						);
						std::unordered_map<std::string, std::any> scripts =
							UTILITIES.CLIENT_DOT_QLOGICAE_APPLICATION_CONFIGURATION_FILE.get_object({ "scripts" }
							);
						for (const std::string script_command :
						_run_scripts_input_1)
						{
							if (scripts.contains(script_command))
							{
								system(std::any_cast<std::string>(
									scripts[script_command]
								).c_str());
							}
							else
							{
								UTILITIES.log_warning_timestamp_async(
									"Script '" + script_command +
									"' does not exist",
									_run_scripts_input_3
								);
							}
						}

						UTILITIES.log_complete_timestamp_async(_run_scripts_input_3);

						return true;
					}
					catch (const std::exception& exception)
					{
						UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_run_command(): ") + exception.what(), _run_scripts_input_3);

						return false;
					}
				}
			);

			return true;
		}
		catch (const std::exception& exception)
		{
			UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_run_command(): ") + exception.what());

			return false;
		}
	}

	bool Application::_setup_build_command()
	{
		try
		{
			CLI::App* build_command =
				_application.add_subcommand(
					"build",
					"vs2022"
				);

			CLI::App* build_vs2022_command =
				build_command->add_subcommand(
					"vs2022",
					"Building a project via Visual Studio 2022"
				);

			build_vs2022_command
				->add_option("--project",
					_build_vs2022_input_1,
					"An existing Visual Studio 2022 project"
				)
				->required();

			build_vs2022_command
				->add_option("--environment",
					_build_vs2022_input_2,
					"A QLogicae environment type"
				)
				->default_val("development");

			build_vs2022_command
				->add_option("--architecture",
					_build_vs2022_input_3,
					"A Visual Studio 2022 project's instruction architecture"
				)
				->check(CLI::IsMember(
					UTILITIES.VISUAL_STUDIO_2022_BUILD_ARCHITECTURE_TYPES
				))
				->default_val(UTILITIES.VISUAL_STUDIO_2022_BUILD_ARCHITECTURE_TYPES[0]);

			build_vs2022_command
				->add_option("--type",
					_build_vs2022_input_4,
					"A Visual Studio 2022 project's build type"
				)
				->check(CLI::IsMember(
					UTILITIES.VISUAL_STUDIO_2022_BUILD_TYPES
				))
				->default_val(UTILITIES.VISUAL_STUDIO_2022_BUILD_TYPES[0]);

			build_vs2022_command
				->add_option("--is-verbose-logging-enabled",
					_build_vs2022_input_5,
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["build-vs2022"] = std::make_pair(
				build_vs2022_command,
				[this]() -> bool
				{
					try
					{
						UTILITIES.log_running_timestamp_async(_build_vs2022_input_5);

						std::string command = absl::StrCat(
							"powershell -ExecutionPolicy Bypass -File",
							" \"qlogicae/.qlogicae/application/visual_studio_2022/build.ps1\"",
							" -VisualStudio2022InputProject ",
							_build_vs2022_input_1,
							" -EnvironmentType ",
							_build_vs2022_input_2,
							" -VisualStudio2022Architecture ",
							_build_vs2022_input_3,
							" -VisualStudio2022Build ",
							_build_vs2022_input_4
						);

						system(command.c_str());

						UTILITIES.log_complete_timestamp_async(_build_vs2022_input_5);

						return true;
					}
					catch (const std::exception& exception)
					{
						UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_build_command(): ") + exception.what(), _build_vs2022_input_5);

						return false;
					}
				});

			return true;
		}
		catch (const std::exception& exception)
		{
			UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_build_command(): ") + exception.what());

			return false;
		}
	}

	bool Application::_setup_setup_command()
	{
		try
		{
			CLI::App* setup_command =
				_application.add_subcommand(
					"setup",
					"windows-registry"
				);

			CLI::App* setup_windows_registry_command =
				setup_command->add_subcommand(
					"windows-registry",
					"Creates or updates windows registry key-value pairs of a selected QLogicae environment preset"
				);

			setup_windows_registry_command
				->add_option(
					"--environment",
					_setup_windows_registry_input_1,
					"HKCU Selected environment type")
				->default_val("development")
				->required();

			setup_windows_registry_command
				->add_option("--is-verbose-logging-enabled",
					_setup_windows_registry_input_5,
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["setup-windows-registry"] = std::make_pair(
				setup_windows_registry_command,
				[this]() -> bool
				{
					try
					{
						UTILITIES.log_running_timestamp_async(_setup_windows_registry_input_5);

						UTILITIES.log_complete_timestamp_async(_setup_windows_registry_input_5);

						return true;
					}
					catch (const std::exception& exception)
					{
						UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_setup_command(): ") + exception.what(), _setup_windows_registry_input_5);

						return false;
					}
				}
			);

			return true;
		}
		catch (const std::exception& exception)
		{
			UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_setup_command(): ") + exception.what());

			return false;
		}
	}

	bool Application::_setup_generate_command()
	{
		try
		{
			CLI::App* generate_command =
				_application.add_subcommand(
					"generate",
					"uuid4, string"
				);

			CLI::App* generate_uuid4_command =
				generate_command->add_subcommand(
					"uuid4",
					"Random UUID4 generation"
				);
			
			generate_uuid4_command
				->add_option("--count",
					_generate_uuid4_input_1,
					"The number of generated uuid4s")
				->check(CLI::PositiveNumber)
				->default_val(1);

			generate_uuid4_command
				->add_option("--output-file-path",
					_generate_uuid4_input_2,
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");

			generate_uuid4_command
				->add_option("--is-file-output-enabled",
					_generate_uuid4_input_4,
					"Enables or disables the option '--output-file-path'")
				->default_val(false);
			generate_uuid4_command
				->add_option("--is-verbose-logging-enabled",
					_generate_uuid4_input_3,
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["generate-uuid4"] = std::make_pair(
				generate_uuid4_command,
				[this]() -> bool
				{
					try
					{
						UTILITIES.log_running_timestamp_async(_generate_uuid4_input_3);

						std::string output_string = "";
						size_t index_1, size_a = _generate_uuid4_input_1 - 1;

						for (index_1 = 0;
							index_1 < _generate_uuid4_input_1;
							++index_1)
						{
							output_string += QLogicaeCore::GENERATOR.random_uuid4();
							if (index_1 < size_a)
							{
								output_string += "\n";
							}
						}

						QLogicaeCore::CLI_IO.print_with_new_line_async(
							output_string
						);

						if (_generate_uuid4_input_4)
						{
							UTILITIES.TEXT_FILE_IO.set_file_path(
								UTILITIES.setup_result_output_file(
									_generate_uuid4_input_2,
									"uuid4\\generate",
									UTILITIES.RELATIVE_DEFAULT_OUTPUT_FILE_PATH
								)
							);
							UTILITIES.TEXT_FILE_IO.write_async(output_string);
						}

						UTILITIES.log_complete_timestamp_async(_generate_uuid4_input_3);

						return true;
					}
					catch (const std::exception exception)
					{
						UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_generate_command(): ") + exception.what(), _generate_uuid4_input_3);

						return false;
					}
				}
			);

			CLI::App* generate_string_command =
				generate_command->add_subcommand(
					"string",
					"Random string generation"
				);
			generate_string_command
				->add_option("--length",
					_generate_string_input_1,
					"The character length of each individual string output")
				->check(CLI::PositiveNumber)
				->default_val(32);
			generate_string_command
				->add_option("--count",
					_generate_string_input_2,
					"The number of generated string outputs")
				->check(CLI::PositiveNumber)
				->default_val(1);
			generate_string_command
				->add_option("--character-set",
					_generate_string_input_3,
					"A string of characters where each individual character can possibly be found within each string output")
				->default_val("");
			generate_string_command
				->add_option("--output-file-path",
					_generate_string_input_4,
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");
			generate_string_command
				->add_option("--is-file-output-enabled",
					_generate_string_input_6,
					"Enables or disables the option '--output-file-path'")
				->default_val(false);
			generate_string_command
				->add_option("--is-verbose-logging-enabled",
					_generate_string_input_5,
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["generate-string"] = std::make_pair(
				generate_string_command,
				[this]() -> bool
				{
					try
					{
						UTILITIES.log_running_timestamp_async(_generate_string_input_5);

						size_t index_1, size_a = _generate_string_input_2 - 1;
						std::string output_string = "",
							character_set = (_generate_string_input_3.empty()) ?

							QLogicaeCore::Constants::FULL_VISIBLE_ASCII_CHARACTERSET.data() :
							_generate_string_input_3;

						for (index_1 = 0;
							index_1 < _generate_string_input_2;
							++index_1)
						{
							output_string += QLogicaeCore::GENERATOR.random_string(
								_generate_string_input_1,
								character_set
							);
							if (index_1 < size_a)
							{
								output_string += "\n";
							}
						}

						QLogicaeCore::CLI_IO.print_with_new_line_async(
							output_string
						);

						if (_generate_string_input_6)
						{
							UTILITIES.TEXT_FILE_IO.set_file_path(
								UTILITIES.setup_result_output_file(
									_generate_string_input_4,
									"string\\generate",
									UTILITIES.RELATIVE_DEFAULT_OUTPUT_FILE_PATH
								)
							);
							UTILITIES.TEXT_FILE_IO.write_async(output_string);
						}

						UTILITIES.log_complete_timestamp_async(_generate_string_input_5);

						return true;
					}
					catch (const std::exception exception)
					{
						UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_generate_command(): ") + exception.what(), _generate_string_input_5);

						return false;
					}
				}
			);

			return true;
		}
		catch (const std::exception& exception)
		{
			UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_generate_command(): ") + exception.what());

			return false;
		}
	}

	bool Application::_setup_encrypt_command()
	{
		try
		{
			CLI::App* encrypt_command =
				_application.add_subcommand(
					"encrypt",
					"xchacha20poly1305, aes256"
				);

			CLI::App* encrypt_xchacha20poly1305_command =
				encrypt_command->add_subcommand(
					"xchacha20poly1305",
					"Cipher XChaCha20-Poly1305 encryption"
				);

			encrypt_xchacha20poly1305_command
				->add_option("--text",
					_encrypt_xchacha20poly1305_input_1,
					"The string input to be encrypted")
				->required();
			
			encrypt_xchacha20poly1305_command
				->add_option("--key",
					_encrypt_xchacha20poly1305_input_2,
					"Encryption key")
				->required();
			
			encrypt_xchacha20poly1305_command
				->add_option("--nonce",
					_encrypt_xchacha20poly1305_input_3,
					"Encryption nonce. WARNING: Nonces must be 32 characters long")
				->default_val(QLogicaeCore::GENERATOR.random_string(
					32, QLogicaeCore::Constants::ALPHA_NUMERIC_CHARACTERS)
				);
			
			encrypt_xchacha20poly1305_command
				->add_option("--output-file-path",
					_encrypt_xchacha20poly1305_input_4,
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");
			
			encrypt_xchacha20poly1305_command
				->add_option("--is-file-output-enabled",
					_encrypt_xchacha20poly1305_input_6,
					"Enables or disables the option '--output-file-path'")
				->default_val(false);
			
			encrypt_xchacha20poly1305_command
				->add_option("--is-verbose-logging-enabled",
					_encrypt_xchacha20poly1305_input_5,
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["xchacha20poly1305-encrypt"] = std::make_pair(
				encrypt_xchacha20poly1305_command,
				[this]() -> bool
				{
					try
					{
						UTILITIES.log_running_timestamp_async(_encrypt_xchacha20poly1305_input_5);

						if (!_encrypt_xchacha20poly1305_input_1.length() ||
							!_encrypt_xchacha20poly1305_input_2.length() ||
							!_encrypt_xchacha20poly1305_input_3.length())
						{
							UTILITIES.log_complete_timestamp_async(_encrypt_xchacha20poly1305_input_5);

							return false;
						}

						std::string output_string =
							UTILITIES.CRYPTOGRAPHER_1.transform(
								_encrypt_xchacha20poly1305_input_1,
								_encrypt_xchacha20poly1305_input_2,
								_encrypt_xchacha20poly1305_input_3
							) + "\n" +
							_encrypt_xchacha20poly1305_input_3;

						QLogicaeCore::CLI_IO.print_with_new_line_async(
							output_string
						);

						if (_encrypt_xchacha20poly1305_input_6)
						{
							UTILITIES.TEXT_FILE_IO.set_file_path(
								UTILITIES.setup_result_output_file(
									_encrypt_xchacha20poly1305_input_4,
									"xchacha20poly1305\\encrypt",
									UTILITIES.RELATIVE_DEFAULT_OUTPUT_FILE_PATH
								)
							);
							UTILITIES.TEXT_FILE_IO.write_async(output_string);
						}

						UTILITIES.log_complete_timestamp_async(_encrypt_xchacha20poly1305_input_5);

						return true;
					}
					catch (const std::exception exception)
					{
						UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_encrypt_command(): ") + exception.what(), _encrypt_xchacha20poly1305_input_5);

						return false;
					}
				}
			);

			CLI::App* encrypt_aes256_command =
				encrypt_command->add_subcommand(
					"aes256",
					"Cipher AES256 encryption"
				);

			encrypt_aes256_command
				->add_option("--text",
					_encrypt_aes256_input_1,
					"The string input to be encrypted")
				->required();

			encrypt_aes256_command
				->add_option("--key",
					_encrypt_aes256_input_2,
					"Encryption key")
				->required();

			encrypt_aes256_command
				->add_option("--nonce",
					_encrypt_aes256_input_3,
					"Encryption nonce. WARNING: Nonces must be 32 characters long")
				->default_val(QLogicaeCore::GENERATOR.random_string(
					32, QLogicaeCore::Constants::ALPHA_NUMERIC_CHARACTERS)
				);

			encrypt_aes256_command
				->add_option("--output-file-path",
					_encrypt_aes256_input_4,
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");

			encrypt_aes256_command
				->add_option("--is-file-output-enabled",
					_encrypt_aes256_input_6,
					"Enables or disables the option '--output-file-path'")
				->default_val(false);

			encrypt_aes256_command
				->add_option("--is-verbose-logging-enabled",
					_encrypt_aes256_input_5,
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["aes256-encrypt"] = std::make_pair(
				encrypt_aes256_command,
				[this]() -> bool
				{
					try
					{
						UTILITIES.log_running_timestamp_async(_encrypt_aes256_input_5);

						if (!_encrypt_aes256_input_1.length() ||
							!_encrypt_aes256_input_2.length() ||
							!_encrypt_aes256_input_3.length())
						{
							UTILITIES.log_complete_timestamp_async(_encrypt_aes256_input_5);

							return false;
						}

						std::string output_string =
							UTILITIES.CRYPTOGRAPHER_2.transform(
								_encrypt_aes256_input_1,
								_encrypt_aes256_input_2,
								_encrypt_aes256_input_3
							) + "\n" +
							_encrypt_aes256_input_3;

						QLogicaeCore::CLI_IO.print_with_new_line_async(
							output_string
						);

						if (_encrypt_aes256_input_6)
						{
							UTILITIES.TEXT_FILE_IO.set_file_path(
								UTILITIES.setup_result_output_file(
									_encrypt_aes256_input_4,
									"aes256\\encrypt",
									UTILITIES.RELATIVE_DEFAULT_OUTPUT_FILE_PATH
								)
							);
							UTILITIES.TEXT_FILE_IO.write_async(output_string);
						}

						UTILITIES.log_complete_timestamp_async(_encrypt_aes256_input_5);

						return true;
					}
					catch (const std::exception exception)
					{
						UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_encrypt_command(): ") + exception.what(), _encrypt_aes256_input_5);

						return false;
					}
				}
			);

			return true;
		}
		catch (const std::exception& exception)
		{
			UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_encrypt_command(): ") + exception.what());

			return false;
		}
	}

	bool Application::_setup_decrypt_command()
	{
		try
		{
			CLI::App* decrypt_command =
				_application.add_subcommand(
					"decrypt",
					"xchacha20poly1305, aes256"
				);

			CLI::App* decrypt_xchacha20poly1305_command =
				decrypt_command->add_subcommand(
					"xchacha20poly1305",
					"Cipher XChaCha20-Poly1305 decryption"
				);

			decrypt_xchacha20poly1305_command
				->add_option("--cipher",
					_decrypt_xchacha20poly1305_input_1,
					"The string cipher to be decrypted")
				->required();

			decrypt_xchacha20poly1305_command
				->add_option("--key",
					_decrypt_xchacha20poly1305_input_2,
					"Encryption key")
				->required();
			
			decrypt_xchacha20poly1305_command
				->add_option("--nonce",
					_decrypt_xchacha20poly1305_input_3,
					"Encryption nonce. WARNING: Nonces must be 32 characters long")
				->required();
			
			decrypt_xchacha20poly1305_command
				->add_option("--output-file-path",
					_decrypt_xchacha20poly1305_input_4,
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");
			
			decrypt_xchacha20poly1305_command
				->add_option("--is-file-output-enabled",
					_decrypt_xchacha20poly1305_input_6,
					"Enables or disables the option '--output-file-path'")
				->default_val(false);
			
			decrypt_xchacha20poly1305_command
				->add_option("--is-verbose-logging-enabled",
					_decrypt_xchacha20poly1305_input_5,
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["decrypt-xchacha20poly1305"] = std::make_pair(
				decrypt_xchacha20poly1305_command,
				[this]() -> bool
				{
					try
					{
						UTILITIES.log_running_timestamp_async(_decrypt_xchacha20poly1305_input_5);

						if (!_decrypt_xchacha20poly1305_input_1.length() ||
							!_decrypt_xchacha20poly1305_input_2.length() ||
							!_decrypt_xchacha20poly1305_input_3.length())
						{
							UTILITIES.log_complete_timestamp_async(_decrypt_xchacha20poly1305_input_5);

							return false;
						}

						std::string output_string =
							UTILITIES.CRYPTOGRAPHER_1.reverse(
								_decrypt_xchacha20poly1305_input_1,
								_decrypt_xchacha20poly1305_input_2,
								_decrypt_xchacha20poly1305_input_3
							);

						QLogicaeCore::CLI_IO.print_with_new_line_async(
							output_string
						);

						if (_decrypt_xchacha20poly1305_input_6)
						{
							UTILITIES.TEXT_FILE_IO.set_file_path(
								UTILITIES.setup_result_output_file(
									_decrypt_xchacha20poly1305_input_4,
									"xchacha20poly1305\\decrypt",
									UTILITIES.RELATIVE_DEFAULT_OUTPUT_FILE_PATH
								)
							);
							UTILITIES.TEXT_FILE_IO.write_async(output_string);
						}

						UTILITIES.log_complete_timestamp_async(_decrypt_xchacha20poly1305_input_5);

						return true;
					}
					catch (const std::exception exception)
					{
						UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_decrypt_command(): ") + exception.what(), _decrypt_xchacha20poly1305_input_5);

						return false;
					}
				}
			);

			CLI::App* decrypt_aes256_command =
				decrypt_command->add_subcommand(
					"aes256",
					"Cipher AES256 decryption"
				);

			decrypt_aes256_command
				->add_option("--cipher",
					_decrypt_aes256_input_1,
					"The string cipher to be decrypted")
				->required();

			decrypt_aes256_command
				->add_option("--key",
					_decrypt_aes256_input_2,
					"Encryption key")
				->required();

			decrypt_aes256_command
				->add_option("--nonce",
					_decrypt_aes256_input_3,
					"Encryption nonce. WARNING: Nonces must be 32 characters long")
				->required();

			decrypt_aes256_command
				->add_option("--output-file-path",
					_decrypt_aes256_input_4,
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");

			decrypt_aes256_command
				->add_option("--is-file-output-enabled",
					_decrypt_aes256_input_6,
					"Enables or disables the option '--output-file-path'")
				->default_val(false);

			decrypt_aes256_command
				->add_option("--is-verbose-logging-enabled",
					_decrypt_aes256_input_5,
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["decrypt-aes256"] = std::make_pair(
				decrypt_aes256_command,
				[this]() -> bool
				{
					try
					{
						UTILITIES.log_running_timestamp_async(_decrypt_aes256_input_5);

						if (!_decrypt_aes256_input_1.length() ||
							!_decrypt_aes256_input_2.length() ||
							!_decrypt_aes256_input_3.length())
						{
							UTILITIES.log_complete_timestamp_async(_decrypt_aes256_input_5);

							return false;
						}

						std::string output_string =
							UTILITIES.CRYPTOGRAPHER_2.reverse(
								_decrypt_aes256_input_1,
								_decrypt_aes256_input_2,
								_decrypt_aes256_input_3
							);

						QLogicaeCore::CLI_IO.print_with_new_line_async(
							output_string
						);

						if (_decrypt_aes256_input_6)
						{
							UTILITIES.TEXT_FILE_IO.set_file_path(
								UTILITIES.setup_result_output_file(
									_decrypt_aes256_input_4,
									"aes256\\decrypt",
									UTILITIES.RELATIVE_DEFAULT_OUTPUT_FILE_PATH
								)
							);
							UTILITIES.TEXT_FILE_IO.write_async(output_string);
						}

						UTILITIES.log_complete_timestamp_async(_decrypt_aes256_input_5);

						return true;
					}
					catch (const std::exception exception)
					{
						UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_decrypt_command(): ") + exception.what(), _decrypt_aes256_input_5);

						return false;
					}
				}
			);

			return true;
		}
		catch (const std::exception& exception)
		{
			UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_decrypt_command(): ") + exception.what());

			return false;
		}
	}

	bool Application::_setup_hash_command()
	{
		try
		{
			CLI::App* encrypt_command =
				_application.add_subcommand(
					"hash",
					"argon2id, sha256"
				);

			CLI::App* encrypt_argon2id_command =
				encrypt_command->add_subcommand(
					"argon2id",
					"Hash Argon2ID creation"
				);

			encrypt_argon2id_command
				->add_option("--text",
					_hash_argon2id_input_1,
					"The string text to be hashed")
				->required();

			encrypt_argon2id_command
				->add_option("--output-file-path",
					_hash_argon2id_input_2,
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");
			
			encrypt_argon2id_command
				->add_option("--is-file-output-enabled",
					_hash_argon2id_input_4,
					"Enables or disables the option '--output-file-path'")
				->default_val(false);
			
			encrypt_argon2id_command
				->add_option("--is-verbose-logging-enabled",
					_hash_argon2id_input_3,
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["hash-argon2id"] = std::make_pair(
				encrypt_argon2id_command,
				[this]() -> bool
				{
					try
					{
						UTILITIES.log_running_timestamp_async(_hash_argon2id_input_3);

						std::string output_string =
							UTILITIES.CRYPTOGRAPHER_3.transform(
								_hash_argon2id_input_1
							);

						QLogicaeCore::CLI_IO.print_with_new_line_async(
							output_string
						);

						if (_hash_argon2id_input_4)
						{
							UTILITIES.TEXT_FILE_IO.set_file_path(
								UTILITIES.setup_result_output_file(
									_hash_argon2id_input_2,
									"argon2id\\hash",
									UTILITIES.RELATIVE_DEFAULT_OUTPUT_FILE_PATH
								)
							);
							UTILITIES.TEXT_FILE_IO.write_async(output_string);
						}

						UTILITIES.log_complete_timestamp_async(_hash_argon2id_input_3);

						return true;
					}
					catch (const std::exception exception)
					{
						UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_hash_command(): ") + exception.what(), _hash_argon2id_input_3);

						return false;
					}
				}
			);

			CLI::App* encrypt_sha256_command =
				encrypt_command->add_subcommand(
					"sha256",
					"Hash SHA256 creation"
				);

			encrypt_sha256_command
				->add_option("--text",
					_hash_sha256_input_1,
					"The string text to be hashed")
				->required();

			encrypt_sha256_command
				->add_option("--output-file-path",
					_hash_sha256_input_2,
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");

			encrypt_sha256_command
				->add_option("--is-file-output-enabled",
					_hash_sha256_input_4,
					"Enables or disables the option '--output-file-path'")
				->default_val(false);

			encrypt_sha256_command
				->add_option("--is-verbose-logging-enabled",
					_hash_sha256_input_3,
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["hash-sha256"] = std::make_pair(
				encrypt_sha256_command,
				[this]() -> bool
				{
					try
					{
						UTILITIES.log_running_timestamp_async(_hash_sha256_input_3);

						std::string output_string =
							UTILITIES.CRYPTOGRAPHER_4.transform(
								_hash_sha256_input_1
							);

						QLogicaeCore::CLI_IO.print_with_new_line_async(
							output_string
						);

						if (_hash_sha256_input_4)
						{
							UTILITIES.TEXT_FILE_IO.set_file_path(
								UTILITIES.setup_result_output_file(
									_hash_sha256_input_2,
									"sha256\\hash",
									UTILITIES.RELATIVE_DEFAULT_OUTPUT_FILE_PATH
								)
							);
							UTILITIES.TEXT_FILE_IO.write_async(output_string);
						}

						UTILITIES.log_complete_timestamp_async(_hash_sha256_input_3);

						return true;
					}
					catch (const std::exception exception)
					{
						UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_hash_command(): ") + exception.what(), _hash_sha256_input_3);

						return false;
					}
				}
			);

			return true;
		}
		catch (const std::exception& exception)
		{
			UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_hash_command(): ") + exception.what());

			return false;
		}
	}

	bool Application::_setup_verify_command()
	{
		try
		{
			CLI::App* verify_command =
				_application.add_subcommand(
					"verify",
					"argon2id, sha256"
				);
			
			CLI::App* verify_argon2id_command =
				verify_command->add_subcommand(
					"argon2id",
					"Hash Argon2ID verification"
				);

			verify_argon2id_command
				->add_option("--hash",
					_verify_argon2id_input_1,
					"The string hash to be verified")
				->required();

			verify_argon2id_command
				->add_option("--key",
					_verify_argon2id_input_2,
					"The original text to be compared with the hash")
				->required();
			
			verify_argon2id_command
				->add_option("--output-file-path",
					_verify_argon2id_input_3,
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");
			
			verify_argon2id_command
				->add_option("--is-file-output-enabled",
					_verify_argon2id_input_5,
					"Enables or disables the option '--output-file-path'")
				->default_val(false);
			
			verify_argon2id_command
				->add_option("--is-verbose-logging-enabled",
					_verify_argon2id_input_4,
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["verify-argon2id"] = std::make_pair(
				verify_argon2id_command,
				[this]() -> bool
				{
					try
					{
						UTILITIES.log_running_timestamp_async(_verify_argon2id_input_4);

						if (!_verify_argon2id_input_1.length() ||
							!_verify_argon2id_input_2.length())
						{
							UTILITIES.log_complete_timestamp_async(_verify_argon2id_input_4);

							return false;
						}

						std::string output_string =
							(UTILITIES.CRYPTOGRAPHER_3.reverse(
								_verify_argon2id_input_1,
								_verify_argon2id_input_2
							)) ? "true" : "false";

						QLogicaeCore::CLI_IO.print_with_new_line_async(
							output_string
						);

						if (_verify_argon2id_input_5)
						{
							UTILITIES.TEXT_FILE_IO.set_file_path(
								UTILITIES.setup_result_output_file(
									_verify_argon2id_input_3,
									"argon2id\\verify",
									UTILITIES.RELATIVE_DEFAULT_OUTPUT_FILE_PATH
								)
							);
							UTILITIES.TEXT_FILE_IO.write_async(output_string);
						}

						UTILITIES.log_complete_timestamp_async(_verify_argon2id_input_4);

						return true;
					}
					catch (const std::exception exception)
					{
						UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_verify_command(): ") + exception.what(), _verify_argon2id_input_4);

						return false;
					}
				}
			);

			CLI::App* verify_sha256_command =
				verify_command->add_subcommand(
					"sha256",
					"Hash SHA256 verification"
				);

			verify_sha256_command
				->add_option("--hash",
					_verify_sha256_input_1,
					"The string hash to be verified")
				->required();

			verify_sha256_command
				->add_option("--key",
					_verify_sha256_input_2,
					"The original text to be compared with the hash")
				->required();

			verify_sha256_command
				->add_option("--output-file-path",
					_verify_sha256_input_3,
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");

			verify_sha256_command
				->add_option("--is-file-output-enabled",
					_verify_sha256_input_5,
					"Enables or disables the option '--output-file-path'")
				->default_val(false);

			verify_sha256_command
				->add_option("--is-verbose-logging-enabled",
					_verify_sha256_input_4,
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["verify-sha256"] = std::make_pair(
				verify_sha256_command,
				[this]() -> bool
				{
					try
					{
						UTILITIES.log_running_timestamp_async(_verify_sha256_input_4);

						if (!_verify_sha256_input_1.length() ||
							!_verify_sha256_input_2.length())
						{
							UTILITIES.log_complete_timestamp_async(_verify_sha256_input_4);

							return false;
						}

						std::string output_string =
							(UTILITIES.CRYPTOGRAPHER_4.reverse(
								_verify_sha256_input_1,
								_verify_sha256_input_2
							)) ? "true" : "false";

						QLogicaeCore::CLI_IO.print_with_new_line_async(
							output_string
						);

						if (_verify_sha256_input_5)
						{
							UTILITIES.TEXT_FILE_IO.set_file_path(
								UTILITIES.setup_result_output_file(
									_verify_sha256_input_3,
									"sha256\\verify",
									UTILITIES.RELATIVE_DEFAULT_OUTPUT_FILE_PATH
								)
							);
							UTILITIES.TEXT_FILE_IO.write_async(output_string);
						}

						UTILITIES.log_complete_timestamp_async(_verify_sha256_input_4);

						return true;
					}
					catch (const std::exception exception)
					{
						UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_verify_command(): ") + exception.what(), _verify_sha256_input_4);

						return false;
					}
				}
			);

			return true;
		}
		catch (const std::exception& exception)
		{
			UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_verify_command(): ") + exception.what());

			return false;
		}
	}

	bool Application::_setup_get_command()
	{
		try
		{
			CLI::App* get_command =
				_application.add_subcommand(
					"get",
					"hkcu"
				);
			
			CLI::App* get_hkcu_command =
				get_command->add_subcommand(
					"hkcu",
					"Reading key-value pairs of a selected HKCU-specific windows registry path"
				);

			get_hkcu_command
				->add_option("--sub-path",
					_view_windows_registry_input_1,
					"HKCU Windows Registry path")
				->default_val("")
				->required();
			get_hkcu_command
				->add_option("--is-verbose-logging-enabled",
					_view_windows_registry_input_2,
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["get-hkcu"] = std::make_pair(
				get_hkcu_command,
				[this]() -> bool
				{
					try
					{
						UTILITIES.log_running_timestamp_async(_view_windows_registry_input_2);

						if (_view_windows_registry_input_1.empty())
						{
							return false;
						}

						std::string output_string = "";
						std::unordered_map<std::string, std::string> items =
							QLogicaeCore::WINDOWS_REGISTRY_HKCU.get_values_via_utf8(
								_view_windows_registry_input_1
							);
						size_t index_a = 0, size_a = items.size() - 1;

						for (const auto& [key, value] : items)
						{
							output_string += key + " -> " + value + "\n";
						}
						QLogicaeCore::CLI_IO.print_async(output_string);

						UTILITIES.log_complete_timestamp_async(_view_windows_registry_input_2);

						return true;
					}
					catch (const std::exception& exception)
					{
						UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_get_command(): ") + exception.what(), _view_windows_registry_input_2);

						return false;
					}
				}
			);

			return true;
		}
		catch (const std::exception& exception)
		{
			UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_get_command(): ") + exception.what());

			return false;
		}
	}

	bool Application::_setup_set_command()
	{
		try
		{
			CLI::App* set_command =
				_application.add_subcommand(
					"set",
					"hkcu"
				);

			CLI::App* set_hkcu_command =
				set_command->add_subcommand(
					"hkcu",
					"Creates or updates a key-value pair of a selected HKCU-specific windows registry path"
				);

			set_hkcu_command
				->add_option("--sub-path",
					_set_windows_registry_input_1,
					"HKCU Windows Registry path")
				->default_val("")
				->required();

			set_hkcu_command
				->add_option("--key",
					_set_windows_registry_input_2,
					"HKCU Windows Registry key")
				->default_val("")
				->required();
			
			set_hkcu_command
				->add_option("--value",
					_set_windows_registry_input_3,
					"HKCU Windows Registry value")
				->default_val("")
				->required();
			
			set_hkcu_command
				->add_option("--is-verbose-logging-enabled",
					_set_windows_registry_input_4,
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["set-hkcu"] = std::make_pair(
				set_hkcu_command,
				[this]() -> bool
				{
					try
					{
						UTILITIES.log_running_timestamp_async(_set_windows_registry_input_4);

						bool result = QLogicaeCore::WINDOWS_REGISTRY_HKCU.set_value_via_utf8(
							_set_windows_registry_input_1,
							_set_windows_registry_input_2,
							_set_windows_registry_input_3
						);

						UTILITIES.log_complete_timestamp_async(_set_windows_registry_input_4);

						return true;
					}
					catch (const std::exception& exception)
					{
						UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_set_command(): ") + exception.what(), _set_windows_registry_input_4);

						return false;
					}
				}
			);

			return true;
		}
		catch (const std::exception& exception)
		{
			UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_set_command(): ") + exception.what());

			return false;
		}
	}
}
