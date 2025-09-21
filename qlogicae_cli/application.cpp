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
			if (!UTILITIES.is_qlogicae_project_found() ||
				!_setup_view_command() ||
				!_setup_build_command() ||
				!_setup_deploy_command() ||
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

	bool Application::_setup_view_command()
	{
		try
		{
			CLI::App* view_command =
				_application.add_subcommand(
					"view",
					"about"
				);
			
			CLI::App* view_about_command =
				view_command->add_subcommand(
					"about",
					"Project and application details"
				);

			_commands["view-about"] = std::make_pair(
				view_about_command,
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
			CLI::App* run_command =
				_application.add_subcommand(
					"run",
					"vs2022, executable, script"
				);

			CLI::App* run_vs2022_command =
				run_command->add_subcommand(
					"vs2022",
					"Runs a Visual Studio 2022 project executable"
				);

			run_vs2022_command
				->add_option("--project",
					_string_inputs["run_vs2022__project"],
					"A Visual Studio 2022 project"
				)
				->default_str("");

			run_vs2022_command
				->add_option("--architecture",
					_string_inputs["run_vs2022__architecture"],
					"A Visual Studio 2022 project's instruction architecture"
				)
				->check(CLI::IsMember(
					UTILITIES.VISUAL_STUDIO_2022_BUILD_ARCHITECTURE_TYPES
				))
				->default_val(UTILITIES.VISUAL_STUDIO_2022_BUILD_ARCHITECTURE_TYPES[0]);

			run_vs2022_command
				->add_option("--build-type",
					_string_inputs["run_vs2022__build_type"],
					"A Visual Studio 2022 project's build type"
				)
				->check(CLI::IsMember(
					UTILITIES.VISUAL_STUDIO_2022_BUILD_TYPES
				))
				->default_val(UTILITIES.VISUAL_STUDIO_2022_BUILD_TYPES[0]);

			run_vs2022_command
				->add_option("--is-verbose-logging-enabled",
					_boolean_inputs["run_vs2022__is_verbose_logging_enabled"],
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["run-vs2022"] = std::make_pair(
				run_vs2022_command,
				[this]() -> bool
				{
					std::string run_vs2022__project =
						_string_inputs["run_vs2022__project"];
					std::string run_vs2022__architecture =
						_string_inputs["run_vs2022__architecture"];
					std::string run_vs2022__build_type =
						_string_inputs["run_vs2022__build_type"];
					bool run_vs2022__is_verbose_logging_enabled =
						_boolean_inputs["run_vs2022__is_verbose_logging_enabled"];

					try
					{
						UTILITIES.log_running_timestamp_async(
							run_vs2022__is_verbose_logging_enabled
						);

						if (run_vs2022__project.empty())
						{
							UTILITIES.CLIENT_DOT_QLOGICAE_APPLICATION_CONFIGURATION_FILE.set_file_path(
								UTILITIES.RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_CONFIGURATIONS_QLOGICAE_FILE_PATH
							);

							run_vs2022__project =
								UTILITIES.CLIENT_DOT_QLOGICAE_APPLICATION_CONFIGURATION_FILE.get_string(
									{
										"visual_studio_2022",
										"startup_project_name"
									}
								);
						}

						system((absl::StrCat(
							".\\", run_vs2022__architecture,
							"\\", run_vs2022__build_type,
							"\\", run_vs2022__project,
							"\\", run_vs2022__project,
							".exe"
						)).c_str());

						UTILITIES.log_complete_timestamp_async(
							run_vs2022__is_verbose_logging_enabled
						);

						return true;
					}
					catch (const std::exception& exception)
					{
						UTILITIES.log_exception_timestamp_async(
							std::string("Exception at Application::_setup_run_command(): ") +
							exception.what(),
							run_vs2022__is_verbose_logging_enabled
						);

						return false;
					}
				}
			);

			CLI::App* run_executable_command =
				run_command->add_subcommand(
					"executable",
					"Runs an executable"
				);

			run_executable_command
				->add_option("--path",
					_string_inputs["run_executable__path"],
					"A selected path to an executable"
				)
				->required();

			run_executable_command
				->add_option("--is-verbose-logging-enabled",
					_boolean_inputs["run_executable__is_verbose_logging_enabled"],
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["run-executable"] = std::make_pair(
				run_executable_command,
				[this]() -> bool
				{
					std::string run_executable__path =
						_string_inputs["run_executable__path"];
					bool run_executable__is_verbose_logging_enabled =
						_boolean_inputs["run_executable__is_verbose_logging_enabled"];

					try
					{
						UTILITIES.log_running_timestamp_async(
							run_executable__is_verbose_logging_enabled
						);

						if (!std::filesystem::exists(run_executable__path))
						{
							UTILITIES.log_exception_timestamp_async("Exception at Application::_setup_run_command(): Executable does not exist");

							return false;
						}

						system(run_executable__path.c_str());

						UTILITIES.log_complete_timestamp_async(
							run_executable__is_verbose_logging_enabled
						);

						return true;
					}
					catch (const std::exception& exception)
					{
						UTILITIES.log_exception_timestamp_async(
							std::string("Exception at Application::_setup_run_command(): ") +
							exception.what(),
							run_executable__is_verbose_logging_enabled
						);

						return false;
					}
				}
			);

			CLI::App* run_script_command =
				run_command->add_subcommand(
					"script",
					"Runs one or more QLogicae-defined script"
				);

			run_script_command
				->add_option("--command",
					_string_inputs["run_script__command"],
					"Selected script command")
				->required();

			run_script_command
				->add_option("--is-verbose-logging-enabled",
					_boolean_inputs["run_script__is_verbose_logging_enabled"],
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["run-script"] = std::make_pair(
				run_script_command,
				[this]() -> bool
				{
					std::string run_script__command =
						_string_inputs["run_script__command"];
					bool run_script__is_verbose_logging_enabled =
						_boolean_inputs["run_script__is_verbose_logging_enabled"];

					try
					{
						UTILITIES.log_running_timestamp_async(run_script__is_verbose_logging_enabled);

						UTILITIES.CLIENT_DOT_QLOGICAE_APPLICATION_CONFIGURATION_FILE.set_file_path(
							UTILITIES.RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_CONFIGURATIONS_QLOGICAE_FILE_PATH
						);
						std::unordered_map<std::string, std::any> scripts =
							UTILITIES.CLIENT_DOT_QLOGICAE_APPLICATION_CONFIGURATION_FILE
								.get_object({ "scripts" }
						);
						std::string script_command = std::any_cast<std::string>(
							scripts[run_script__command]
						);

						if (!scripts.contains(run_script__command))
						{
							UTILITIES.log_warning_timestamp_async(
								"Script '" + run_script__command +
								"' does not exist",
								run_script__is_verbose_logging_enabled
							);

							return false;
						}
						
						system(script_command.c_str());

						UTILITIES.log_complete_timestamp_async(run_script__is_verbose_logging_enabled);

						return true;
					}
					catch (const std::exception& exception)
					{
						UTILITIES.log_exception_timestamp_async(
							std::string("Exception at Application::_setup_run_command(): ") +
							exception.what(),
							run_script__is_verbose_logging_enabled
						);

						return false;
					}
				}
			);

			return true;
		}
		catch (const std::exception& exception)
		{
			UTILITIES.log_exception_timestamp_async(
				std::string("Exception at Application::_setup_run_command(): ") +
				exception.what()
			);

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
					_string_inputs["build_vs2022__project"],
					"An existing Visual Studio 2022 project"
				)
				->required();

			build_vs2022_command
				->add_option("--environment",
					_string_inputs["build_vs2022__environment"],
					"A QLogicae environment type"
				)
				->default_val("development");

			build_vs2022_command
				->add_option("--architecture",
					_string_inputs["build_vs2022__architecture"],
					"A Visual Studio 2022 project's instruction architecture"
				)
				->check(CLI::IsMember(
					UTILITIES.VISUAL_STUDIO_2022_BUILD_ARCHITECTURE_TYPES
				))
				->default_val(UTILITIES.VISUAL_STUDIO_2022_BUILD_ARCHITECTURE_TYPES[0]);

			build_vs2022_command
				->add_option("--build-type",
					_string_inputs["build_vs2022__build_type"],
					"A Visual Studio 2022 project's build type"
				)
				->check(CLI::IsMember(
					UTILITIES.VISUAL_STUDIO_2022_BUILD_TYPES
				))
				->default_val(UTILITIES.VISUAL_STUDIO_2022_BUILD_TYPES[0]);

			build_vs2022_command
				->add_option("--is-verbose-logging-enabled",
					_boolean_inputs["build_vs2022__is_verbose_logging_enabled"],
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["build-vs2022"] = std::make_pair(
				build_vs2022_command,
				[this]() -> bool
				{
					std::string build_vs2022__project =
						_string_inputs["build_vs2022__project"];
					std::string build_vs2022__environment =
						_string_inputs["build_vs2022__environment"];
					std::string build_vs2022__architecture =
						_string_inputs["build_vs2022__architecture"];
					std::string build_vs2022__build_type =
						_string_inputs["build_vs2022__build_type"];
					bool build_vs2022__is_verbose_logging_enabled =
						_boolean_inputs["build_vs2022__is_verbose_logging_enabled"];

					try
					{
						UTILITIES.log_running_timestamp_async(
							build_vs2022__is_verbose_logging_enabled
						);

						system((absl::StrCat(
							"powershell -ExecutionPolicy Bypass -File",
							" \"qlogicae/.qlogicae/application/visual_studio_2022/build.ps1\"",
							" -VisualStudio2022InputProject ",
							build_vs2022__project,
							" -EnvironmentType ",
							build_vs2022__environment,
							" -VisualStudio2022Architecture ",
							build_vs2022__architecture,
							" -VisualStudio2022Build ",
							build_vs2022__build_type
						)).c_str());

						UTILITIES.log_complete_timestamp_async(
							build_vs2022__is_verbose_logging_enabled
						);

						return true;
					}
					catch (const std::exception& exception)
					{
						UTILITIES.log_exception_timestamp_async(
							std::string("Exception at Application::_setup_build_command(): ") +
							exception.what(),
							build_vs2022__is_verbose_logging_enabled
						);

						return false;
					}
				});

			return true;
		}
		catch (const std::exception& exception)
		{
			UTILITIES.log_exception_timestamp_async(
				std::string("Exception at Application::_setup_build_command(): ") +
				exception.what()
			);

			return false;
		}
	}

	bool Application::_setup_deploy_command()
	{
		try
		{
			/*
			CLI::App* deploy_command =
				_application.add_subcommand(
					"deploy",
					"vs2022"
				);

			deploy_command
				->add_option("--installer-type",
					_deploy_vs2022_input_1,
					"Selected input folder path")
				->check(CLI::IsMember(
					UTILITIES.INSTALLER_TYPES
				))
				->default_val(UTILITIES.INSTALLER_TYPES[0]);

			deploy_command
				->add_option("--input-folder-path",
					_deploy_vs2022_input_2,
					"Selected input folder path")
				->default_val("");

			deploy_command
				->add_option("--output-folder-path",
					_deploy_vs2022_input_3,
					"Selected output folder path")
				->default_val("");

			deploy_command
				->add_option("--is-verbose-logging-enabled",
					_deploy_vs2022_input_4,
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["deploy"] = std::make_pair(
				deploy_command,
				[this]() -> bool
				{
					try
					{
						UTILITIES.log_running_timestamp_async(_deploy_vs2022_input_4);

						if (_deploy_vs2022_input_1 == UTILITIES.IDE_TYPES[0] &&
							_deploy_vs2022_input_2 == UTILITIES.INSTALLER_TYPES[0])
						{

						}


						UTILITIES.log_complete_timestamp_async(_deploy_vs2022_input_4);

						return true;
					}
					catch (const std::exception& exception)
					{
						UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_deploy_command(): ") + exception.what(), _deploy_vs2022_input_4);

						return false;
					}
				}
			);
			*/

			return true;
		}
		catch (const std::exception& exception)
		{
			UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_deploy_command(): ") + exception.what());

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
					_size_t_inputs["generate_uuid4__count"],
					"The number of generated uuid4s")
				->check(CLI::PositiveNumber)
				->default_val(1);

			generate_uuid4_command
				->add_option("--output-file-path",
					_string_inputs["generate_uuid4__output_file_path"],
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");

			generate_uuid4_command
				->add_option("--is-file-output-enabled",
					_boolean_inputs["generate_uuid4__is_file_output_enabled"],
					"Enables or disables the option '--output-file-path'")
				->default_val(false);

			generate_uuid4_command
				->add_option("--is-verbose-logging-enabled",
					_boolean_inputs["generate_uuid4__is_verbose_logging_enabled"],
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["generate-uuid4"] = std::make_pair(
				generate_uuid4_command,
				[this]() -> bool
				{
					size_t generate_uuid4__count =
						_size_t_inputs["generate_uuid4__count"];
					std::string generate_uuid4__output_file_path =
						_string_inputs["generate_uuid4__output_file_path"];
					bool generate_uuid4__is_file_output_enabled =
						_boolean_inputs["generate_uuid4__is_file_output_enabled"];
					bool generate_uuid4__is_verbose_logging_enabled =
						_boolean_inputs["generate_uuid4__is_verbose_logging_enabled"];

					try
					{
						UTILITIES.log_running_timestamp_async(
							generate_uuid4__is_verbose_logging_enabled
						);

						std::string output_string = "";
						size_t index_1, size_a = generate_uuid4__count - 1;

						for (index_1 = 0;
							index_1 < generate_uuid4__count;
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

						if (generate_uuid4__is_file_output_enabled)
						{
							UTILITIES.TEXT_FILE_IO.set_file_path(
								UTILITIES.setup_result_output_file(
									generate_uuid4__output_file_path,
									"generate\\uuid4",
									UTILITIES.RELATIVE_DEFAULT_OUTPUT_FILE_PATH
								)
							);
							UTILITIES.TEXT_FILE_IO.write_async(output_string);
						}

						UTILITIES.log_complete_timestamp_async(
							generate_uuid4__is_verbose_logging_enabled
						);

						return true;
					}
					catch (const std::exception& exception)
					{
						UTILITIES.log_exception_timestamp_async(
							std::string("Exception at Application::_setup_generate_command(): ") +
							exception.what(),
							generate_uuid4__is_verbose_logging_enabled
						);

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
					_size_t_inputs["generate_string__length"],
					"The character length of each individual string output")
				->check(CLI::PositiveNumber)
				->default_val(32);
			generate_string_command
				->add_option("--count",
					_size_t_inputs["generate_string__count"],
					"The number of generated string outputs")
				->check(CLI::PositiveNumber)
				->default_val(1);
			generate_string_command
				->add_option("--character-set",
					_string_inputs["generate_string__character_set"],
					"A string of characters where each individual character can possibly be found within each string output")
				->default_val("");
			generate_string_command
				->add_option("--output-file-path",
					_string_inputs["generate_string__output_file_path"],
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");
			generate_string_command
				->add_option("--is-file-output-enabled",
					_boolean_inputs["generate_string__is_file_output_enabled"],
					"Enables or disables the option '--output-file-path'")
				->default_val(false);
			generate_string_command
				->add_option("--is-verbose-logging-enabled",
					_boolean_inputs["generate_string__is_verbose_logging_enabled"],
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["generate-string"] = std::make_pair(
				generate_string_command,
				[this]() -> bool
				{
					size_t generate_string__length =
						_size_t_inputs["generate_string__length"];
					size_t generate_string__count =
						_size_t_inputs["generate_string__count"];
					std::string generate_string__output_file_path =
						_string_inputs["generate_string__character_set"];
					std::string generate_string__character_set =
						_string_inputs["generate_string__output_file_path"];
					bool generate_string__is_file_output_enabled =
						_boolean_inputs["generate_string__is_file_output_enabled"];
					bool generate_string__is_verbose_logging_enabled =
						_boolean_inputs["generate_string__is_verbose_logging_enabled"];

					try
					{
						UTILITIES.log_running_timestamp_async(
							generate_string__is_verbose_logging_enabled
						);

						size_t index_1, size_a = generate_string__count - 1;
						std::string output_string = "",
							character_set = (generate_string__character_set.empty()) ?

							QLogicaeCore::Constants::FULL_VISIBLE_ASCII_CHARACTERSET.data() :
							generate_string__character_set;

						for (index_1 = 0;
							index_1 < generate_string__count;
							++index_1)
						{
							output_string += QLogicaeCore::GENERATOR.random_string(
								generate_string__length,
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

						if (generate_string__is_file_output_enabled)
						{
							UTILITIES.TEXT_FILE_IO.set_file_path(
								UTILITIES.setup_result_output_file(
									generate_string__output_file_path,
									"generate\\string",
									UTILITIES.RELATIVE_DEFAULT_OUTPUT_FILE_PATH
								)
							);
							UTILITIES.TEXT_FILE_IO.write_async(output_string);
						}

						UTILITIES.log_complete_timestamp_async(
							generate_string__is_verbose_logging_enabled
						);

						return true;
					}
					catch (const std::exception exception)
					{
						UTILITIES.log_exception_timestamp_async(
							std::string("Exception at Application::_setup_generate_command(): ") +
							exception.what(),
							generate_string__is_verbose_logging_enabled
						);

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
					_string_inputs["encrypt_xchacha20poly1305__text"],
					"The string input to be encrypted")
				->required();
			
			encrypt_xchacha20poly1305_command
				->add_option("--key",
					_string_inputs["encrypt_xchacha20poly1305__key"],
					"Encryption key")
				->required();
			
			encrypt_xchacha20poly1305_command
				->add_option("--nonce",
					_string_inputs["encrypt_xchacha20poly1305__nonce"],
					"Encryption nonce. WARNING: Nonces must be 32 characters long")
				->default_val(QLogicaeCore::GENERATOR.random_string(
					32, QLogicaeCore::Constants::ALPHA_NUMERIC_CHARACTERS)
				);
			
			encrypt_xchacha20poly1305_command
				->add_option("--output-file-path",
					_string_inputs["encrypt_xchacha20poly1305__output_file_path"],
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");
			
			encrypt_xchacha20poly1305_command
				->add_option("--is-file-output-enabled",
					_boolean_inputs["encrypt_xchacha20poly1305__is_file_output_enabled"],
					"Enables or disables the option '--output-file-path'")
				->default_val(false);
			
			encrypt_xchacha20poly1305_command
				->add_option("--is-verbose-logging-enabled",
					_boolean_inputs["encrypt_xchacha20poly1305__is_verbose_logging_enabled"],
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["xchacha20poly1305-encrypt"] = std::make_pair(
				encrypt_xchacha20poly1305_command,
				[this]() -> bool
				{
					std::string encrypt_xchacha20poly1305__text =
						_string_inputs["encrypt_xchacha20poly1305__text"];
					std::string encrypt_xchacha20poly1305__key =
						_string_inputs["encrypt_xchacha20poly1305__key"];
					std::string encrypt_xchacha20poly1305__nonce =
						_string_inputs["encrypt_xchacha20poly1305__nonce"];
					std::string encrypt_xchacha20poly1305__output_file_path =
						_string_inputs["encrypt_xchacha20poly1305__output_file_path"];
					bool encrypt_xchacha20poly1305__is_file_output_enabled =
						_boolean_inputs["encrypt_xchacha20poly1305__is_file_output_enabled"];
					bool encrypt_xchacha20poly1305__is_verbose_logging_enabled =
						_boolean_inputs["encrypt_xchacha20poly1305__is_verbose_logging_enabled"];

					try
					{
						UTILITIES.log_running_timestamp_async(
							encrypt_xchacha20poly1305__is_file_output_enabled
						);

						if (!encrypt_xchacha20poly1305__text.length() ||
							!encrypt_xchacha20poly1305__key.length() ||
							!encrypt_xchacha20poly1305__nonce.length())
						{
							UTILITIES.log_complete_timestamp_async(
								encrypt_xchacha20poly1305__is_file_output_enabled
							);

							return false;
						}

						std::string output_string =
							UTILITIES.CRYPTOGRAPHER_1.transform(
								encrypt_xchacha20poly1305__text,
								encrypt_xchacha20poly1305__key,
								encrypt_xchacha20poly1305__nonce
							) + "\n" +
							encrypt_xchacha20poly1305__nonce;

						QLogicaeCore::CLI_IO.print_with_new_line_async(
							output_string
						);

						if (encrypt_xchacha20poly1305__is_verbose_logging_enabled)
						{
							UTILITIES.TEXT_FILE_IO.set_file_path(
								UTILITIES.setup_result_output_file(
									encrypt_xchacha20poly1305__output_file_path,
									"encrypt\\xchacha20poly1305",
									UTILITIES.RELATIVE_DEFAULT_OUTPUT_FILE_PATH
								)
							);
							UTILITIES.TEXT_FILE_IO.write_async(output_string);
						}

						UTILITIES.log_complete_timestamp_async(
							encrypt_xchacha20poly1305__is_file_output_enabled
						);

						return true;
					}
					catch (const std::exception exception)
					{
						UTILITIES.log_exception_timestamp_async(std::string(
							"Exception at Application::_setup_encrypt_command(): ") +
							exception.what(),
							encrypt_xchacha20poly1305__is_file_output_enabled
						);

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
					_string_inputs["encrypt_aes256__text"],
					"The string input to be encrypted")
				->required();

			encrypt_aes256_command
				->add_option("--key",
					_string_inputs["encrypt_aes256__key"],
					"Encryption key")
				->required();

			encrypt_aes256_command
				->add_option("--nonce",
					_string_inputs["encrypt_aes256__nonce"],
					"Encryption nonce. WARNING: Nonces must be 32 characters long")
				->default_val(QLogicaeCore::GENERATOR.random_string(
					32, QLogicaeCore::Constants::ALPHA_NUMERIC_CHARACTERS)
				);

			encrypt_aes256_command
				->add_option("--output-file-path",
					_string_inputs["encrypt_aes256__output_file_path"],
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");

			encrypt_aes256_command
				->add_option("--is-file-output-enabled",
					_boolean_inputs["encrypt_aes256__is_file_output_enabled"],
					"Enables or disables the option '--output-file-path'")
				->default_val(false);

			encrypt_aes256_command
				->add_option("--is-verbose-logging-enabled",
					_boolean_inputs["encrypt_aes256__is_verbose_logging_enabled"],
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["aes256-encrypt"] = std::make_pair(
				encrypt_aes256_command,
				[this]() -> bool
				{
					std::string encrypt_aes256__text =
						_string_inputs["encrypt_aes256__text"];
					std::string encrypt_aes256__key =
						_string_inputs["encrypt_aes256__key"];
					std::string encrypt_aes256__nonce =
						_string_inputs["encrypt_aes256__nonce"];
					std::string encrypt_aes256__output_file_path =
						_string_inputs["encrypt_aes256__output_file_path"];
					bool encrypt_aes256__is_file_output_enabled =
						_boolean_inputs["encrypt_aes256__is_file_output_enabled"];
					bool encrypt_aes256__is_verbose_logging_enabled =
						_boolean_inputs["encrypt_aes256__is_verbose_logging_enabled"];

					try
					{
						UTILITIES.log_running_timestamp_async(
							encrypt_aes256__is_file_output_enabled
						);

						if (!encrypt_aes256__text.length() ||
							!encrypt_aes256__key.length() ||
							!encrypt_aes256__nonce.length())
						{
							UTILITIES.log_complete_timestamp_async(
								encrypt_aes256__is_file_output_enabled
							);

							return false;
						}

						std::string output_string =
							UTILITIES.CRYPTOGRAPHER_2.transform(
								encrypt_aes256__text,
								encrypt_aes256__key,
								encrypt_aes256__nonce
							) + "\n" +
							encrypt_aes256__nonce;

						QLogicaeCore::CLI_IO.print_with_new_line_async(
							output_string
						);

						if (encrypt_aes256__is_verbose_logging_enabled)
						{
							UTILITIES.TEXT_FILE_IO.set_file_path(
								UTILITIES.setup_result_output_file(
									encrypt_aes256__output_file_path,
									"encrypt\\aes256",
									UTILITIES.RELATIVE_DEFAULT_OUTPUT_FILE_PATH
								)
							);
							UTILITIES.TEXT_FILE_IO.write_async(output_string);
						}

						UTILITIES.log_complete_timestamp_async(
							encrypt_aes256__is_file_output_enabled
						);

						return true;
					}
					catch (const std::exception exception)
					{
						UTILITIES.log_exception_timestamp_async(std::string(
							"Exception at Application::_setup_encrypt_command(): ") +
							exception.what(),
							encrypt_aes256__is_file_output_enabled
						);

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
				->add_option("--text",
					_string_inputs["decrypt_xchacha20poly1305__text"],
					"The string input to be encrypted")
				->required();

			decrypt_xchacha20poly1305_command
				->add_option("--key",
					_string_inputs["decrypt_xchacha20poly1305__key"],
					"Encryption key")
				->required();

			decrypt_xchacha20poly1305_command
				->add_option("--nonce",
					_string_inputs["decrypt_xchacha20poly1305__nonce"],
					"Encryption nonce. WARNING: Nonces must be 32 characters long")
				->default_val(QLogicaeCore::GENERATOR.random_string(
					32, QLogicaeCore::Constants::ALPHA_NUMERIC_CHARACTERS)
				);

			decrypt_xchacha20poly1305_command
				->add_option("--output-file-path",
					_string_inputs["decrypt_xchacha20poly1305__output_file_path"],
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");

			decrypt_xchacha20poly1305_command
				->add_option("--is-file-output-enabled",
					_boolean_inputs["decrypt_xchacha20poly1305__is_file_output_enabled"],
					"Enables or disables the option '--output-file-path'")
				->default_val(false);

			decrypt_xchacha20poly1305_command
				->add_option("--is-verbose-logging-enabled",
					_boolean_inputs["decrypt_xchacha20poly1305__is_verbose_logging_enabled"],
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["decrypt-xchacha20poly1305"] = std::make_pair(
				decrypt_xchacha20poly1305_command,
				[this]() -> bool
				{
					std::string decrypt_xchacha20poly1305__text =
						_string_inputs["decrypt_xchacha20poly1305__text"];
					std::string decrypt_xchacha20poly1305__key =
						_string_inputs["decrypt_xchacha20poly1305__key"];
					std::string decrypt_xchacha20poly1305__nonce =
						_string_inputs["decrypt_xchacha20poly1305__nonce"];
					std::string decrypt_xchacha20poly1305__output_file_path =
						_string_inputs["decrypt_xchacha20poly1305__output_file_path"];
					bool decrypt_xchacha20poly1305__is_file_output_enabled =
						_boolean_inputs["decrypt_xchacha20poly1305__is_file_output_enabled"];
					bool decrypt_xchacha20poly1305__is_verbose_logging_enabled =
						_boolean_inputs["decrypt_xchacha20poly1305__is_verbose_logging_enabled"];

					try
					{
						UTILITIES.log_running_timestamp_async(
							decrypt_xchacha20poly1305__is_verbose_logging_enabled
						);

						if (!decrypt_xchacha20poly1305__text.length() ||
							!decrypt_xchacha20poly1305__key.length() ||
							!decrypt_xchacha20poly1305__nonce.length())
						{
							UTILITIES.log_complete_timestamp_async(
								decrypt_xchacha20poly1305__is_verbose_logging_enabled
							);

							return false;
						}

						std::string output_string =
							UTILITIES.CRYPTOGRAPHER_1.reverse(
								decrypt_xchacha20poly1305__text,
								decrypt_xchacha20poly1305__key,
								decrypt_xchacha20poly1305__nonce
							);

						QLogicaeCore::CLI_IO.print_with_new_line_async(
							output_string
						);

						if (decrypt_xchacha20poly1305__is_file_output_enabled)
						{
							UTILITIES.TEXT_FILE_IO.set_file_path(
								UTILITIES.setup_result_output_file(
									decrypt_xchacha20poly1305__output_file_path,
									"decrypt\\xchacha20poly1305",
									UTILITIES.RELATIVE_DEFAULT_OUTPUT_FILE_PATH
								)
							);
							UTILITIES.TEXT_FILE_IO.write_async(output_string);
						}

						UTILITIES.log_complete_timestamp_async(
							decrypt_xchacha20poly1305__is_verbose_logging_enabled
						);

						return true;
					}
					catch (const std::exception exception)
					{
						UTILITIES.log_exception_timestamp_async(
							std::string("Exception at Application::_setup_decrypt_command(): ") +
							exception.what(),
							decrypt_xchacha20poly1305__is_verbose_logging_enabled);

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
				->add_option("--text",
					_string_inputs["decrypt_aes256__text"],
					"The string input to be encrypted")
				->required();

			decrypt_aes256_command
				->add_option("--key",
					_string_inputs["decrypt_aes256__key"],
					"Encryption key")
				->required();

			decrypt_aes256_command
				->add_option("--nonce",
					_string_inputs["decrypt_aes256__nonce"],
					"Encryption nonce. WARNING: Nonces must be 32 characters long")
				->default_val(QLogicaeCore::GENERATOR.random_string(
					32, QLogicaeCore::Constants::ALPHA_NUMERIC_CHARACTERS)
				);

			decrypt_aes256_command
				->add_option("--output-file-path",
					_string_inputs["decrypt_aes256__output_file_path"],
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");

			decrypt_aes256_command
				->add_option("--is-file-output-enabled",
					_boolean_inputs["decrypt_aes256__is_file_output_enabled"],
					"Enables or disables the option '--output-file-path'")
				->default_val(false);

			decrypt_aes256_command
				->add_option("--is-verbose-logging-enabled",
					_boolean_inputs["decrypt_aes256__is_verbose_logging_enabled"],
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["decrypt-aes256"] = std::make_pair(
				decrypt_aes256_command,
				[this]() -> bool
				{
					std::string decrypt_aes256__text =
						_string_inputs["decrypt_aes256__text"];
					std::string decrypt_aes256__key =
						_string_inputs["decrypt_aes256__key"];
					std::string decrypt_aes256__nonce =
						_string_inputs["decrypt_aes256__nonce"];
					std::string decrypt_aes256__output_file_path =
						_string_inputs["decrypt_aes256__output_file_path"];
					bool decrypt_aes256__is_file_output_enabled =
						_boolean_inputs["decrypt_aes256__is_file_output_enabled"];
					bool decrypt_aes256__is_verbose_logging_enabled =
						_boolean_inputs["decrypt_aes256__is_verbose_logging_enabled"];

					try
					{
						UTILITIES.log_running_timestamp_async(decrypt_aes256__is_verbose_logging_enabled);

						if (!decrypt_aes256__text.length() ||
							!decrypt_aes256__key.length() ||
							!decrypt_aes256__nonce.length())
						{
							UTILITIES.log_complete_timestamp_async(decrypt_aes256__is_verbose_logging_enabled);

							return false;
						}

						std::string output_string =
							UTILITIES.CRYPTOGRAPHER_2.reverse(
								decrypt_aes256__text,
								decrypt_aes256__key,
								decrypt_aes256__nonce
							);

						QLogicaeCore::CLI_IO.print_with_new_line_async(
							output_string
						);

						if (decrypt_aes256__is_file_output_enabled)
						{
							UTILITIES.TEXT_FILE_IO.set_file_path(
								UTILITIES.setup_result_output_file(
									decrypt_aes256__output_file_path,
									"decrypt\\aes256",
									UTILITIES.RELATIVE_DEFAULT_OUTPUT_FILE_PATH
								)
							);
							UTILITIES.TEXT_FILE_IO.write_async(output_string);
						}

						UTILITIES.log_complete_timestamp_async(decrypt_aes256__is_verbose_logging_enabled);

						return true;
					}
					catch (const std::exception exception)
					{
						UTILITIES.log_exception_timestamp_async(std::string("Exception at Application::_setup_decrypt_command(): ") + exception.what(), decrypt_aes256__is_verbose_logging_enabled);

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
			CLI::App* hash_command =
				_application.add_subcommand(
					"hash",
					"argon2id, sha256"
				);

			CLI::App* hash_argon2id_command =
				hash_command->add_subcommand(
					"argon2id",
					"Hash Argon2ID creation"
				);

			hash_argon2id_command
				->add_option("--text",
					_string_inputs["hash_argon2id__text"],
					"The string text to be hashed")
				->required();

			hash_argon2id_command
				->add_option("--output-file-path",
					_string_inputs["hash_argon2id__output_file_path"],
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");

			hash_argon2id_command
				->add_option("--is-file-output-enabled",
					_boolean_inputs["hash_argon2id__is_file_output_enabled"],
					"Enables or disables the option '--output-file-path'")
				->default_val(false);

			hash_argon2id_command
				->add_option("--is-verbose-logging-enabled",
					_boolean_inputs["hash_argon2id__is_verbose_logging_enabled"],
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["hash-argon2id"] = std::make_pair(
				hash_argon2id_command,
				[this]() -> bool
				{
					std::string hash_argon2id__text =
						_string_inputs["hash_argon2id__text"];
					std::string hash_argon2id__output_file_path =
						_string_inputs["hash_argon2id__output_file_path"];
					bool hash_argon2id__is_file_output_enabled =
						_boolean_inputs["hash_argon2id__is_file_output_enabled"];
					bool hash_argon2id__is_verbose_logging_enabled =
						_boolean_inputs["hash_argon2id__is_verbose_logging_enabled"];

					try
					{
						UTILITIES.log_running_timestamp_async(
							hash_argon2id__is_verbose_logging_enabled
						);

						std::string output_string =
							UTILITIES.CRYPTOGRAPHER_3.transform(
								hash_argon2id__text
							);

						QLogicaeCore::CLI_IO.print_with_new_line_async(
							output_string
						);

						if (hash_argon2id__is_file_output_enabled)
						{
							UTILITIES.TEXT_FILE_IO.set_file_path(
								UTILITIES.setup_result_output_file(
									hash_argon2id__output_file_path,
									"hash\\argon2id",
									UTILITIES.RELATIVE_DEFAULT_OUTPUT_FILE_PATH
								)
							);
							UTILITIES.TEXT_FILE_IO.write_async(output_string);
						}

						UTILITIES.log_complete_timestamp_async(
							hash_argon2id__is_verbose_logging_enabled
						);

						return true;
					}
					catch (const std::exception exception)
					{
						UTILITIES.log_exception_timestamp_async(
							std::string("Exception at Application::_setup_hash_command(): ") +
							exception.what(),
							hash_argon2id__is_verbose_logging_enabled
						);

						return false;
					}
				}
			);

			CLI::App* hash_sha256_command =
				hash_command->add_subcommand(
					"sha256",
					"Hash SHA256 creation"
				);

			hash_sha256_command
				->add_option("--text",
					_string_inputs["hash_sha256__text"],
					"The string text to be hashed")
				->required();

			hash_sha256_command
				->add_option("--output-file-path",
					_string_inputs["hash_sha256__output_file_path"],
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");

			hash_sha256_command
				->add_option("--is-file-output-enabled",
					_boolean_inputs["hash_sha256__is_file_output_enabled"],
					"Enables or disables the option '--output-file-path'")
				->default_val(false);

			hash_sha256_command
				->add_option("--is-verbose-logging-enabled",
					_boolean_inputs["hash_sha256__is_verbose_logging_enabled"],
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["hash-sha256"] = std::make_pair(
				hash_sha256_command,
				[this]() -> bool
				{
					std::string hash_sha256__text =
						_string_inputs["hash_sha256__text"];
					std::string hash_sha256__output_file_path =
						_string_inputs["hash_sha256__output_file_path"];
					bool hash_sha256__is_file_output_enabled =
						_boolean_inputs["hash_sha256__is_file_output_enabled"];
					bool hash_sha256__is_verbose_logging_enabled =
						_boolean_inputs["hash_sha256__is_verbose_logging_enabled"];

					try
					{
						UTILITIES.log_running_timestamp_async(
							hash_sha256__is_verbose_logging_enabled
						);

						std::string output_string =
							UTILITIES.CRYPTOGRAPHER_4.transform(
								hash_sha256__text
							);

						QLogicaeCore::CLI_IO.print_with_new_line_async(
							output_string
						);

						if (hash_sha256__is_file_output_enabled)
						{
							UTILITIES.TEXT_FILE_IO.set_file_path(
								UTILITIES.setup_result_output_file(
									hash_sha256__output_file_path,
									"hash\\sha256",
									UTILITIES.RELATIVE_DEFAULT_OUTPUT_FILE_PATH
								)
							);
							UTILITIES.TEXT_FILE_IO.write_async(output_string);
						}

						UTILITIES.log_complete_timestamp_async(
							hash_sha256__is_verbose_logging_enabled
						);

						return true;
					}
					catch (const std::exception exception)
					{
						UTILITIES.log_exception_timestamp_async(
							std::string("Exception at Application::_setup_hash_command(): ") +
							exception.what(),
							hash_sha256__is_verbose_logging_enabled
						);

						return false;
					}
				}
			);

			return true;
		}
		catch (const std::exception& exception)
		{
			UTILITIES.log_exception_timestamp_async(
				std::string("Exception at Application::_setup_hash_command(): ") +
				exception.what()
			);

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
					_string_inputs["verify_argon2id__hash"],
					"The string hash to be verified")
				->required();

			verify_argon2id_command
				->add_option("--key",
					_string_inputs["verify_argon2id__key"],
					"The original text to be compared with the hash")
				->required();
			
			verify_argon2id_command
				->add_option("--output-file-path",
					_string_inputs["verify_argon2id__output_file_path"],
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");
			
			verify_argon2id_command
				->add_option("--is-file-output-enabled",
					_boolean_inputs["verify_argon2id__is_file_output_enabled"],
					"Enables or disables the option '--output-file-path'")
				->default_val(false);
			
			verify_argon2id_command
				->add_option("--is-verbose-logging-enabled",
					_boolean_inputs["verify_argon2id__is_verbose_logging_enabled"],
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["verify-argon2id"] = std::make_pair(
				verify_argon2id_command,
				[this]() -> bool
				{
					std::string verify_argon2id__hash =
						_string_inputs["verify_argon2id__hash"];
					std::string verify_argon2id__key =
						_string_inputs["verify_argon2id__key"];
					std::string verify_argon2id__output_file_path =
						_string_inputs["verify_argon2id__output_file_path"];
					bool verify_argon2id__is_file_output_enabled =
						_boolean_inputs["verify_argon2id__is_file_output_enabled"];
					bool verify_argon2id__is_verbose_logging_enabled =
						_boolean_inputs["verify_argon2id__is_verbose_logging_enabled"];

					try
					{
						UTILITIES.log_running_timestamp_async(
							verify_argon2id__is_verbose_logging_enabled
						);

						if (!verify_argon2id__hash.length() ||
							!verify_argon2id__key.length())
						{
							UTILITIES.log_complete_timestamp_async(
								verify_argon2id__is_verbose_logging_enabled
							);

							return false;
						}

						std::string output_string =
							(UTILITIES.CRYPTOGRAPHER_3.reverse(
								verify_argon2id__hash,
								verify_argon2id__key
							)) ? "true" : "false";

						QLogicaeCore::CLI_IO.print_with_new_line_async(
							output_string
						);

						if (verify_argon2id__is_file_output_enabled)
						{
							UTILITIES.TEXT_FILE_IO.set_file_path(
								UTILITIES.setup_result_output_file(
									verify_argon2id__output_file_path,
									"verify\\argon2id",
									UTILITIES.RELATIVE_DEFAULT_OUTPUT_FILE_PATH
								)
							);
							UTILITIES.TEXT_FILE_IO.write_async(output_string);
						}

						UTILITIES.log_complete_timestamp_async(
							verify_argon2id__is_verbose_logging_enabled
						);

						return true;
					}
					catch (const std::exception exception)
					{
						UTILITIES.log_exception_timestamp_async(
							std::string("Exception at Application::_setup_verify_command(): ") +
							exception.what(),
							verify_argon2id__is_verbose_logging_enabled
						);

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
					_string_inputs["verify_sha256__hash"],
					"The string hash to be verified")
				->required();

			verify_sha256_command
				->add_option("--key",
					_string_inputs["verify_sha256__key"],
					"The original text to be compared with the hash")
				->required();

			verify_sha256_command
				->add_option("--output-file-path",
					_string_inputs["verify_sha256__output_file_path"],
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");

			verify_sha256_command
				->add_option("--is-file-output-enabled",
					_boolean_inputs["verify_sha256__is_file_output_enabled"],
					"Enables or disables the option '--output-file-path'")
				->default_val(false);

			verify_sha256_command
				->add_option("--is-verbose-logging-enabled",
					_boolean_inputs["verify_sha256__is_verbose_logging_enabled"],
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["verify-sha256"] = std::make_pair(
				verify_sha256_command,
				[this]() -> bool
				{
					std::string verify_sha256__hash =
						_string_inputs["verify_sha256__hash"];
					std::string verify_sha256__key =
						_string_inputs["verify_sha256__key"];
					std::string verify_sha256__output_file_path =
						_string_inputs["verify_sha256__output_file_path"];
					bool verify_sha256__is_file_output_enabled =
						_boolean_inputs["verify_sha256__is_file_output_enabled"];
					bool verify_sha256__is_verbose_logging_enabled =
						_boolean_inputs["verify_sha256__is_verbose_logging_enabled"];

					try
					{
						UTILITIES.log_running_timestamp_async(
							verify_sha256__is_verbose_logging_enabled
						);

						if (!verify_sha256__hash.length() ||
							!verify_sha256__key.length())
						{
							UTILITIES.log_complete_timestamp_async(
								verify_sha256__is_verbose_logging_enabled
							);

							return false;
						}

						std::string output_string =
							(UTILITIES.CRYPTOGRAPHER_4.reverse(
								verify_sha256__hash,
								verify_sha256__key
							)) ? "true" : "false";

						QLogicaeCore::CLI_IO.print_with_new_line_async(
							output_string
						);

						if (verify_sha256__is_file_output_enabled)
						{
							UTILITIES.TEXT_FILE_IO.set_file_path(
								UTILITIES.setup_result_output_file(
									verify_sha256__output_file_path,
									"verify\\argon2id",
									UTILITIES.RELATIVE_DEFAULT_OUTPUT_FILE_PATH
								)
							);
							UTILITIES.TEXT_FILE_IO.write_async(output_string);
						}

						UTILITIES.log_complete_timestamp_async(
							verify_sha256__is_verbose_logging_enabled
						);

						return true;
					}
					catch (const std::exception exception)
					{
						UTILITIES.log_exception_timestamp_async(
							std::string("Exception at Application::_setup_verify_command(): ") +
							exception.what(),
							verify_sha256__is_verbose_logging_enabled
						);

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
					"windows-registry"
				);
			
			CLI::App* get_windows_registry_command =
				get_command->add_subcommand(
					"windows-registry",
					"hkcu"
				);

			CLI::App* get_windows_registry_hkcu_command =
				get_windows_registry_command->add_subcommand(
					"hkcu",
					"Creates or updates a key-value pair of a selected HKCU-specific windows registry path"
				);

			get_windows_registry_hkcu_command
				->add_option("--sub-path",
					_string_inputs["get_windows_registry_hkcu__sub_path"],
					"HKCU Windows Registry path")
				->default_val("")
				->required();

			get_windows_registry_hkcu_command
				->add_option("--is-verbose-logging-enabled",
					_boolean_inputs["get_windows_registry_hkcu__is_verbose_logging_enabled"],
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["get-windows-registry-hkcu"] = std::make_pair(
				get_windows_registry_hkcu_command,
				[this]() -> bool
				{
					std::string get_windows_registry_hkcu__sub_path =
						_string_inputs["get_windows_registry_hkcu__sub_path"];
					bool get_windows_registry_hkcu__is_verbose_logging_enabled =
						_boolean_inputs["get_windows_registry_hkcu__is_verbose_logging_enabled"];

					try
					{
						UTILITIES.log_running_timestamp_async(
							get_windows_registry_hkcu__is_verbose_logging_enabled
						);

						if (get_windows_registry_hkcu__sub_path.empty())
						{
							return false;
						}

						std::string output_string = "";
						std::unordered_map<std::string, std::string> items =
							QLogicaeCore::WINDOWS_REGISTRY_HKCU.get_values_via_utf8(
								get_windows_registry_hkcu__sub_path
							);
						size_t index_a = 0, size_a = items.size() - 1;

						for (const auto& [key, value] : items)
						{
							output_string += key + " -> " + value + "\n";
						}
						QLogicaeCore::CLI_IO.print_async(output_string);

						UTILITIES.log_complete_timestamp_async(
							get_windows_registry_hkcu__is_verbose_logging_enabled
						);

						return true;
					}
					catch (const std::exception& exception)
					{
						UTILITIES.log_exception_timestamp_async(
							std::string("Exception at Application::_setup_get_command(): ") +
							exception.what(),
							get_windows_registry_hkcu__is_verbose_logging_enabled
						);

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
					"windows-registry"
				);

			CLI::App* set_windows_registry_command =
				set_command->add_subcommand(
					"windows-registry",
					"hkcu"
				);

			CLI::App* set_windows_registry_hkcu_command =
				set_windows_registry_command->add_subcommand(
					"hkcu",
					"Creates or updates a key-value pair of a selected HKCU-specific windows registry path"
				);

			set_windows_registry_hkcu_command
				->add_option("--sub-path",
					_string_inputs["set_windows_registry_hkcu__sub_path"],
					"HKCU Windows Registry path")
				->default_val("")
				->required();

			set_windows_registry_hkcu_command
				->add_option("--key",
					_string_inputs["set_windows_registry_hkcu__key"],
					"HKCU Windows Registry key")
				->default_val("")
				->required();
			
			set_windows_registry_hkcu_command
				->add_option("--value",
					_string_inputs["set_windows_registry_hkcu__value"],
					"HKCU Windows Registry value")
				->default_val("")
				->required();
			
			set_windows_registry_hkcu_command
				->add_option("--is-verbose-logging-enabled",
					_boolean_inputs["set_windows_registry_hkcu__is_verbose_logging_enabled"],
					"Enables or disables verbose console logging")
				->default_val(false);

			_commands["set-windows-registry-hkcu"] = std::make_pair(
				set_windows_registry_hkcu_command,
				[this]() -> bool
				{
					std::string set_windows_registry_hkcu__sub_path =
						_string_inputs["set_windows_registry_hkcu__sub_path"];
					std::string set_windows_registry_hkcu__key =
						_string_inputs["set_windows_registry_hkcu__key"];
					std::string set_windows_registry_hkcu__value =
						_string_inputs["set_windows_registry_hkcu__value"];
					bool set_windows_registry_hkcu__is_verbose_logging_enabled =
						_boolean_inputs["set_windows_registry_hkcu__is_verbose_logging_enabled"];

					try
					{
						UTILITIES.log_running_timestamp_async(
							set_windows_registry_hkcu__is_verbose_logging_enabled
						);

						bool result = QLogicaeCore::WINDOWS_REGISTRY_HKCU.set_value_via_utf8(
							set_windows_registry_hkcu__sub_path,
							set_windows_registry_hkcu__key,
							set_windows_registry_hkcu__value
						);

						UTILITIES.log_complete_timestamp_async(
							set_windows_registry_hkcu__is_verbose_logging_enabled
						);

						return true;
					}
					catch (const std::exception& exception)
					{
						UTILITIES.log_exception_timestamp_async(
							std::string("Exception at Application::_setup_set_command(): ") +
							exception.what(),
							set_windows_registry_hkcu__is_verbose_logging_enabled
						);

						return false;
					}
				}
			);

			return true;
		}
		catch (const std::exception& exception)
		{
			UTILITIES.log_exception_timestamp_async(
				std::string("Exception at Application::_setup_set_command(): ") +
				exception.what()
			);

			return false;
		}
	}
}
