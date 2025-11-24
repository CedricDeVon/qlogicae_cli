#include "pch.hpp"

#include "../includes/application.hpp"

namespace QLogicaeCLI
{
	Application::Application()		
	{

	}

	Application::~Application()
	{

	}

	bool Application::setup(
		int argc,
		char** argv
	)
	{
		QLogicaeCore::Result<void> void_result;

		try
		{			
			setup(
				void_result,
				argc,
				argv
			);

			return void_result.is_status_safe();
		}
		catch (const std::exception& exception)
		{						
			QLogicaeCore::LOGGER.handle_exception_async(
				"QLogicaeCLI::Application::setup()",
				exception.what()
			);

			return false;
		}
	}

	std::future<bool> Application::setup_async(
		int argc,
		char** argv
	)
	{
		std::promise<bool> promise;
		auto future = promise.get_future();

		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, argc, argv,
			promise = std::move(promise)]() mutable
			{
				promise.set_value(
					setup(
						argc,
						argv
					)
				);
			}
		);

		return future;
	}

	void Application::setup_async(
		QLogicaeCore::Result<std::future<void>>& result,
		int argc,
		char** argv
	)
	{
		std::promise<void> promise;
		auto future = promise.get_future();

		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, argc, argv,
			promise = std::move(promise)]() mutable
			{
				QLogicaeCore::Result<void> result;

				setup(
					result,
					argc,
					argv
				);

				promise.set_value();
			}
		);

		result.set_to_good_status_with_value(
			std::move(future)
		);
	}
	
	void Application::setup(
		QLogicaeCore::Result<void>& result,
		int argc,
		char** argv
	)
	{
		QLogicaeCore::LogConfigurations console_log_configurations_1 =
		{
			.is_console_enabled = false,
			.is_console_format_enabled = true
		};

		QLogicaeCore::QLOGICAE_APPLICATION.setup(result);
		if (result.is_status_unsafe())
		{
			QLogicaeCore::LOGGER.handle_exception_async(
				"QLogicaeCLI::Application::setup()",
				"Setup failed"
			);

			return result.set_to_bad_status_without_value();
		}

		UTILITIES.setup(result);
		if (result.is_status_unsafe())
		{
			QLogicaeCore::LOGGER.handle_exception_async(
				"QLogicaeCLI::Application::setup()",
				"Setup failed"
			);

			return result.set_to_bad_status_without_value();
		}

		LOGGER.setup(result);
		if (result.is_status_unsafe())
		{
			QLogicaeCore::LOGGER.handle_exception_async(
				"QLogicaeCLI::Application::setup()",
				"Setup failed"
			);

			return result.set_to_bad_status_without_value();
		}

		TRANSFORMER.setup(result);
		if (result.is_status_unsafe())
		{
			QLogicaeCore::LOGGER.handle_exception_async(
				"QLogicaeCLI::Application::setup()",
				"Setup failed"
			);

			return result.set_to_bad_status_without_value();
		}

		UTILITIES.CLI_APPLICATION.name(
			UTILITIES.get_application_full_name()
		);

		if (
			!_setup_setup_command() ||
			!_setup_view_command() ||
			!_setup_build_command() ||
			!_setup_run_command() ||
			!_setup_deploy_command() ||
			!_setup_generate_command() ||
			!_setup_get_command() ||
			!_setup_set_command() ||
			!_setup_evaluate_command() ||
			!_setup_clear_command() ||
			!_setup_encrypt_command() ||
			!_setup_decrypt_command() ||
			!_setup_hash_command() ||
			!_setup_verify_command()
			)
		{
			QLogicaeCore::LOGGER.handle_exception_async(
				"QLogicaeCLI::Application::setup()",
				"Parsing Failed"
			);

			return result.set_to_bad_status_without_value();
		}
		
		try
		{
			UTILITIES.CLI_APPLICATION.parse(argc, argv);
		}
		catch (const CLI::CallForHelp& exception)
		{
			QLogicaeCore::Result<std::future<void>> future_void_result;

			QLogicaeCore::LOGGER.log_with_timestamp_to_files_async(
				future_void_result,
				"Help has been asked"
			);

			std::exit(UTILITIES.CLI_APPLICATION.exit(exception));

			return result.set_to_bad_status_without_value();
		}
		catch (const CLI::ParseError& exception)
		{
			QLogicaeCore::LOGGER.handle_exception_async(
				"QLogicaeCLI::Application::setup()",
				exception.what()
			);

			std::exit(UTILITIES.CLI_APPLICATION.exit(exception));

			return result.set_to_bad_status_without_value();
		}

		return result.set_to_good_status_without_value();
	}

	std::future<bool> Application::setup_async(
		const std::function<void(const bool& result)>& callback,
		int argc,
		char** argv
	)
	{
		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, argc, argv, callback]() mutable
			{
				callback(
					setup(
						argc,
						argv
					)
				);
			}
		);
	}

	void Application::setup_async(
		const std::function<void(QLogicaeCore::Result<void>& result)>& callback,
		int argc,
		char** argv

	)
	{
		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, argc, argv, callback]() mutable
			{
				QLogicaeCore::Result<void> result;

				setup(
					result,
					argc,
					argv
				);

				callback(
					result
				);
			}
		);
	}

	bool Application::terminate()
	{
		QLogicaeCore::Result<void> void_result;

		try
		{
			terminate(void_result);

			return void_result.is_status_safe();
		}
		catch (const std::exception& exception)
		{
			QLogicaeCore::LOGGER.handle_exception_async(
				"QLogicaeCLI::Application::terminate()",
				exception.what()
			);

			return false;
		}
	}

	std::future<bool> Application::terminate_async()
	{
		std::promise<bool> promise;
		auto future = promise.get_future();

		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this,
			promise = std::move(promise)]() mutable
			{
				promise.set_value(
					terminate()
				);
			}
		);

		return future;
	}

	void Application::terminate_async(
		QLogicaeCore::Result<std::future<void>>& result
	)
	{
		std::promise<void> promise;
		auto future = promise.get_future();

		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this,
			promise = std::move(promise)]() mutable
			{
				QLogicaeCore::Result<void> result;

				terminate(
					result
				);

				promise.set_value();
			}
		);

		result.set_to_good_status_with_value(
			std::move(future)
		);
	}

	void Application::terminate(
		QLogicaeCore::Result<void>& result
	)
	{
		QLogicaeCore::Result<void> void_result;

		QLogicaeCore::QLOGICAE_APPLICATION.terminate(result);
		if (result.is_status_unsafe())
		{
			QLogicaeCore::LOGGER.handle_exception_async(
				"QLogicaeCLI::Application::terminate()",
				"Termination failed"
			);

			return result.set_to_bad_status_without_value();
		}

		FILE_SYSTEM.terminate(result);
		if (result.is_status_unsafe())
		{
			QLogicaeCore::LOGGER.handle_exception_async(
				"QLogicaeCLI::Application::terminate()",
				"Termination failed"
			);

			return result.set_to_bad_status_without_value();
		}

		LOGGER.terminate(result);
		if (result.is_status_unsafe())
		{
			QLogicaeCore::LOGGER.handle_exception_async(
				"QLogicaeCLI::Application::terminate()",
				"Termination failed"
			);

			return result.set_to_bad_status_without_value();
		}

		TRANSFORMER.terminate(result);
		if (result.is_status_unsafe())
		{
			QLogicaeCore::LOGGER.handle_exception_async(
				"QLogicaeCLI::Application::terminate()",
				"Termination failed"
			);

			return result.set_to_bad_status_without_value();
		}

		UTILITIES.terminate(result);
		if (result.is_status_unsafe())
		{
			QLogicaeCore::LOGGER.handle_exception_async(
				"QLogicaeCLI::Application::terminate()",
				"Termination failed"
			);

			return result.set_to_bad_status_without_value();
		}

		result.set_to_good_status_without_value();
	}

	std::future<bool> Application::terminate_async(
		const std::function<void(const bool& result)>& callback
	)
	{
		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, callback]() mutable
			{
				callback(
					terminate()
				);
			}
		);
	}

	void Application::terminate_async(
		const std::function<void(QLogicaeCore::Result<void>& result)>& callback
	)
	{
		boost::asio::post(
			QLogicaeCore::UTILITIES.BOOST_ASIO_POOL,
			[this, callback]() mutable
			{
				QLogicaeCore::Result<void> result;

				terminate(result);

				callback(
					result
				);
			}
		);
	}

	bool Application::parse()
	{
		QLogicaeCore::Result<void> void_result;

		try
		{
			for (const auto& [key, value] : UTILITIES.CLI_APPLICATION_COMMANDS)
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
			QLogicaeCore::LOGGER.handle_exception_async(
				"QLogicaeCLI::Application::parse()",
				exception.what()
			);

			return false;
		}
	}

	Application& Application::get_instance()
	{
		QLogicaeCore::Result<Application*> result;

		get_instance(
			result
		);

		return *result.get_value();
	}

	void Application::get_instance(
		QLogicaeCore::Result<Application*>& result
	)
	{
		static Application instance;

		result.set_to_good_status_with_value(
			&instance
		);
	}

	bool Application::_setup_view_command()
	{
		try
		{
			CLI::App* view_command =
				UTILITIES.CLI_APPLICATION.add_subcommand(
					"view",
					"about, windows-registry, environment-variables"
				);

			CLI::App* view_about_command =
				view_command->add_subcommand(
					"about",
					"Displays application details"
				);

			view_about_command
				->add_option("--is-verbose",
					BOOLEAN_INPUTS.get("view_about", "is_verbose"),
					"Enables or disables verbose console logging")
				->default_val(false);

			UTILITIES.CLI_APPLICATION_COMMANDS["view_about"] = std::make_pair(
				view_about_command,
				[this]() -> bool
				{
					QLogicaeCore::Result<void> void_result;

					bool view_about_command__is_verbose =
						BOOLEAN_INPUTS.get(
							"view_about", "is_verbose"
						);

					QLogicaeCore::LogConfigurations console_log_configurations_1 =
					{
						.is_console_enabled = view_about_command__is_verbose,
						.is_console_format_enabled = view_about_command__is_verbose
					};

					QLogicaeCore::LogConfigurations console_log_configurations_2 =
					{
						.is_console_enabled = true,
						.is_console_format_enabled = view_about_command__is_verbose
					};

					try
					{
						LOGGER.log_running(
							void_result,
							"qlogicae_cli view about",
							console_log_configurations_1
						);

						LOGGER.log(
							void_result,
							UTILITIES.get_application_about_details(),
							console_log_configurations_2
						);

						LOGGER.log_complete(
							void_result,
							"qlogicae_cli view about",
							console_log_configurations_1
						);

						return true;
					}
					catch (const std::exception& exception)
					{
						QLogicaeCore::LOGGER.handle_exception_async(
							"QLogicaeCLI::Application::_setup_view_command()",
							exception.what()
						);

						return false;
					}
				}
			);

			CLI::App* view_windows_registy_command =
				view_command->add_subcommand(
					"windows-registry",
					"Windows registry key-value pairs used by the application"
				);

			view_windows_registy_command
				->add_option("--environment-type",
					STRING_INPUTS.get("view_windows_registy", "environment_type"),
					"An existing environment type"
				)
				->default_val("development");

			view_windows_registy_command
				->add_option("--root-path",
					STRING_INPUTS.get("view_windows_registy", "root_path"),
					"The windows registry root path"
				)
				->check(CLI::IsMember(
					QLogicaeCore::UTILITIES.WINDOWS_REGISTRY_ROOT_PATH
				))
				->default_val(QLogicaeCore::UTILITIES.WINDOWS_REGISTRY_ROOT_PATH[0]);

			view_windows_registy_command
				->add_option("--is-verbose",
					BOOLEAN_INPUTS.get("view_windows_registry", "is_verbose"),
					"Enables or disables verbose console logging")
				->default_val(false);

			UTILITIES.CLI_APPLICATION_COMMANDS["view_windows_registy"] = std::make_pair(
				view_windows_registy_command,
				[this]() -> bool
				{
					QLogicaeCore::Result<void> result;

					std::string view_windows_registy_command__environment =
						STRING_INPUTS.get(
							"view_windows_registy", "environment_type"
						);

					std::string view_windows_registy_command__root_path =
						STRING_INPUTS.get(
							"view_windows_registy", "root_path"
						);

					bool view_windows_registy_command__is_verbose =
						BOOLEAN_INPUTS.get(
							"view_windows_registry", "is_verbose"
						);

					std::string command =
						absl::StrCat(
							"powershell -ExecutionPolicy Bypass -File",
							" \"qlogicae/.qlogicae/application/scripts/windows_registry/view.ps1\"",
							" -EnvironmentType ",
							view_windows_registy_command__environment,
							" -RootPath ",
							view_windows_registy_command__root_path
						);

					QLogicaeCore::LogConfigurations console_log_configurations_1 =
					{
						.is_console_enabled = view_windows_registy_command__is_verbose,
						.is_console_format_enabled = view_windows_registy_command__is_verbose
					};

					QLogicaeCore::LogConfigurations console_log_configurations_2 =
					{
						.is_console_enabled = view_windows_registy_command__is_verbose,
						.is_console_format_enabled = view_windows_registy_command__is_verbose
					};

					try
					{
						LOGGER.log_running(
							result,
							"qlogicae_cli view windows-registy",
							console_log_configurations_1
						);

						LOGGER.log(
							result,
							"Executing '" + command + "'",
							console_log_configurations_2
						);

						system(
							command.c_str()
						);

						LOGGER.log_complete(
							result,
							"qlogicae_cli view windows-registy",
							console_log_configurations_1
						);

						return true;
					}
					catch (const std::exception& exception)
					{
						QLogicaeCore::LOGGER.handle_exception_async(
							"QLogicaeCLI::Application::_setup_view_command()",
							exception.what()
						);

						return false;
					}
				}
			);

			CLI::App* view_environment_variables_command =
				view_command->add_subcommand(
					"environment-variables",
					"Environment variable key-value pairs used by the application"
				);

			view_environment_variables_command
				->add_option("--root-path",
					STRING_INPUTS.get("view_environment_variables", "root_path"),
					"An environment variable root path"
				)
				->check(CLI::IsMember(
					QLogicaeCore::UTILITIES.ENVIRONMENT_VARIABLE_TYPES
				))
				->default_val(QLogicaeCore::UTILITIES.ENVIRONMENT_VARIABLE_TYPES[0]);

			view_environment_variables_command
				->add_option("--is-verbose",
					BOOLEAN_INPUTS.get("view_environment_variables", "is_verbose"),
					"Enables or disables verbose console logging")
				->default_val(false);

			UTILITIES.CLI_APPLICATION_COMMANDS["view_environment_variables"] = std::make_pair(
				view_environment_variables_command,
				[this]() -> bool
				{
					QLogicaeCore::Result<void> result;

					std::string view_environment_variables_command__root_path =
						STRING_INPUTS.get(
							"view_environment_variables", "root_path"
						);

					bool view_environment_variables_command__is_verbose =
						BOOLEAN_INPUTS.get(
							"view_environment_variables", "is_verbose"
						);

					std::string command =
						absl::StrCat(
							"powershell -ExecutionPolicy Bypass -File",
							" \"qlogicae/.qlogicae/application/scripts/environment_variables/view.ps1\"",
							" -RootPath ",
							view_environment_variables_command__root_path
						);

					QLogicaeCore::LogConfigurations console_log_configurations_1 =
					{
						.is_console_enabled = view_environment_variables_command__is_verbose,
						.is_console_format_enabled = view_environment_variables_command__is_verbose
					};

					QLogicaeCore::LogConfigurations console_log_configurations_2 =
					{
						.is_console_enabled = view_environment_variables_command__is_verbose,
						.is_console_format_enabled = view_environment_variables_command__is_verbose
					};

					try
					{
						LOGGER.log_running(
							result,
							"qlogicae_cli view environment-variables",
							console_log_configurations_1
						);

						LOGGER.log(
							result,
							"Executing '" + command + "'",
							console_log_configurations_2
						);
						system(
							command.c_str()
						);

						LOGGER.log_complete(
							result,
							"qlogicae_cli view environment-variables",
							console_log_configurations_1
						);

						return true;
					}
					catch (const std::exception& exception)
					{
						QLogicaeCore::LOGGER.handle_exception_async(
							"QLogicaeCLI::Application::_setup_view_command()",
							exception.what()
						);

						return false;
					}
				}
			);

			return true;
		}
		catch (const std::exception& exception)
		{

			QLogicaeCore::LOGGER.handle_exception_async(
				"QLogicaeCLI::Application::_setup_view_command()",
				exception.what()
			);

			return false;
		}
	}

	bool Application::_setup_run_command()
	{
		try
		{
			CLI::App* run_command =
				UTILITIES.CLI_APPLICATION.add_subcommand(
					"run",
					"vs2022, executable, script"
				);

			CLI::App* run_vs2022_command =
				run_command->add_subcommand(
					"vs2022",
					"Runs a Visual Studio 2022 project executable"
				);

			run_vs2022_command
				->add_option("--project-name",
					STRING_INPUTS.get("run_vs2022_command", "project_name"),
					"The selected Visual Studio 2022 project"
				)
				->default_str("");

			run_vs2022_command
				->add_option("--architecture-type",
					STRING_INPUTS.get("run_vs2022_command", "architecture_type"),
					"The Visual Studio 2022 project's instruction architecture"
				)
				->check(CLI::IsMember(
					QLogicaeCore::UTILITIES.VISUAL_STUDIO_2022_BUILD_ARCHITECTURE_TYPES
				))
				->default_val(QLogicaeCore::UTILITIES.VISUAL_STUDIO_2022_BUILD_ARCHITECTURE_TYPES[0]);

			run_vs2022_command
				->add_option("--build-type",
					STRING_INPUTS.get("run_vs2022_command", "build_type"),
					"The Visual Studio 2022 project's build type"
				)
				->check(CLI::IsMember(
					QLogicaeCore::UTILITIES.VISUAL_STUDIO_2022_BUILD_TYPES
				))
				->default_val(QLogicaeCore::UTILITIES.VISUAL_STUDIO_2022_BUILD_TYPES[0]);

			run_vs2022_command
				->add_option("--is-verbose",
					BOOLEAN_INPUTS.get("run_vs2022_command", "is_verbose"),
					"Enables or disables verbose console logging")
				->default_val(false);

			UTILITIES.CLI_APPLICATION_COMMANDS["run_vs2022"] = std::make_pair(
				run_vs2022_command,
				[this]() -> bool
				{
					QLogicaeCore::Result<void> void_result;

					std::string run_vs2022_command__project =
						STRING_INPUTS.get("run_vs2022_command", "project_name");

					std::string run_vs2022_command__architecture =
						STRING_INPUTS.get("run_vs2022_command", "architecture_type");

					std::string run_vs2022_command__build_type =
						STRING_INPUTS.get("run_vs2022_command", "build_type");

					bool run_vs2022_command__is_verbose =
						BOOLEAN_INPUTS.get("run_vs2022_command", "is_verbose");

					std::string command;

					std::string executable_name;

					QLogicaeCore::LogConfigurations console_log_configurations_1 =
					{
						.is_console_enabled = run_vs2022_command__is_verbose,
						.is_console_format_enabled = run_vs2022_command__is_verbose
					};

					QLogicaeCore::LogConfigurations console_log_configurations_2 =
					{
						.is_console_enabled = run_vs2022_command__is_verbose,
						.is_console_format_enabled = run_vs2022_command__is_verbose
					};

					try
					{
						LOGGER.log_running(
							void_result,
							"qlogicae_cli run vs2022",
							console_log_configurations_1
						);

						QLogicaeCore::JSON_FILE_IO.set_file_path(
							UTILITIES.RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_CONFIGURATIONS_QLOGICAE_FILE_PATH
						);

						if (run_vs2022_command__project.empty())
						{
							run_vs2022_command__project =
								QLogicaeCore::JSON_FILE_IO.get_string(
									{
										"application",
										"startup_project_name"
									}
								);

							LOGGER.log(
								void_result,
								"Switching to Startup Project '" + run_vs2022_command__project + "'",
								console_log_configurations_2
							);
						}

						executable_name = QLogicaeCore::JSON_FILE_IO.get_string(
							{
								"application",
								"executable_name"
							}
						);

						command = absl::StrCat(
							".\\", run_vs2022_command__architecture,
							"\\", run_vs2022_command__build_type,
							"\\", run_vs2022_command__project,
							"\\", executable_name,
							".exe"
						);

						LOGGER.log(
							void_result,
							"Executing '" + command + "'",
							console_log_configurations_2
						);

						system(
							command.c_str()
						);

						LOGGER.log_complete(
							void_result,
							"qlogicae_cli run vs2022",
							console_log_configurations_1
						);

						return true;
					}
					catch (const std::exception& exception)
					{
						QLogicaeCore::LOGGER.handle_exception_async(
							"QLogicaeCLI::Application::_setup_run_command()",
							exception.what()
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
					STRING_INPUTS.get("run_executable_command", "path"),
					"The selected path to the executable"
				)
				->required();

			run_executable_command
				->add_option("--is-verbose",
					BOOLEAN_INPUTS.get("run_executable_command", "is_verbose"),
					"Enables or disables verbose console logging")
				->default_val(false);

			UTILITIES.CLI_APPLICATION_COMMANDS["run_executable"] = std::make_pair(
				run_executable_command,
				[this]() -> bool
				{
					QLogicaeCore::Result<void> void_result;

					std::string run_executable_command__path =
						STRING_INPUTS.get(
							"run_executable_command", "path"
						);

					bool run_executable_command__is_verbose =
						BOOLEAN_INPUTS.get(
							"run_executable_command", "is_verbose"
						);

					QLogicaeCore::LogConfigurations console_log_configurations_1 =
					{
						.is_console_enabled = run_executable_command__is_verbose,
						.is_console_format_enabled = run_executable_command__is_verbose
					};

					QLogicaeCore::LogConfigurations console_log_configurations_2 =
					{
						.is_console_enabled = run_executable_command__is_verbose,
						.is_console_format_enabled = run_executable_command__is_verbose
					};

					try
					{
						LOGGER.log_running(
							void_result,
							"qlogicae_cli run executable",
							console_log_configurations_1
						);

						if (!std::filesystem::exists(run_executable_command__path))
						{
							LOGGER.log(
								void_result,
								"Executable does not exist",
								QLogicaeCore::DEFAULT_WARNING_LOG_CONFIGURATIONS
							);

							return false;
						}

						LOGGER.log(
							void_result,
							"Executing '" + run_executable_command__path + "'",
							console_log_configurations_2
						);
						system(
							run_executable_command__path.c_str()
						);

						LOGGER.log_complete(
							void_result,
							"qlogicae_cli run executable",
							console_log_configurations_1
						);

						return true;
					}
					catch (const std::exception& exception)
					{
						QLogicaeCore::LOGGER.handle_exception_async(
							"QLogicaeCLI::Application::_setup_run_command()",
							exception.what()
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
					STRING_INPUTS.get("run_script_command", "command"),
					"Selected qlogicae script command")
				->required();

			run_script_command
				->add_option("--is-verbose",
					BOOLEAN_INPUTS.get("run_script_command", "is_verbose"),
					"Enables or disables verbose console logging")
				->default_val(false);

			UTILITIES.CLI_APPLICATION_COMMANDS["run_script"] = std::make_pair(
				run_script_command,
				[this]() -> bool
				{
					QLogicaeCore::Result<void> void_result;

					std::string run_script_command__command =
						STRING_INPUTS.get(
							"run_script_command", "command"
						);

					bool run_script_command__is_verbose =
						BOOLEAN_INPUTS.get(
							"run_script_command", "is_verbose"
						);

					QLogicaeCore::LogConfigurations console_log_configurations_1 =
					{
						.is_console_enabled = run_script_command__is_verbose,
						.is_console_format_enabled = run_script_command__is_verbose
					};

					QLogicaeCore::LogConfigurations console_log_configurations_2 =
					{
						.is_console_enabled = run_script_command__is_verbose,
						.is_console_format_enabled = run_script_command__is_verbose
					};

					try
					{
						LOGGER.log_running(
							void_result,
							"qlogicae_cli run script",
							console_log_configurations_1
						);

						QLogicaeCore::JSON_FILE_IO.set_file_path(
							UTILITIES.RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_CONFIGURATIONS_QLOGICAE_FILE_PATH
						);

						std::unordered_map<std::string, std::any> scripts =
							QLogicaeCore::JSON_FILE_IO.get_object(
								{ "scripts" }
							);

						std::string script_command = std::any_cast<std::string>(
							scripts[run_script_command__command]
						);

						if (!scripts.contains(run_script_command__command))
						{
							LOGGER.log(
								void_result,
								"Script '" + run_script_command__command +
								"' does not exist",
								QLogicaeCore::DEFAULT_WARNING_LOG_CONFIGURATIONS
							);

							return false;
						}

						LOGGER.log(
							void_result,
							"Executing '" + script_command + "'",
							console_log_configurations_2
						);

						system(
							script_command.c_str()
						);

						LOGGER.log_complete(
							void_result,
							"qlogicae_cli run script",
							console_log_configurations_1
						);

						return true;
					}
					catch (const std::exception& exception)
					{
						QLogicaeCore::LOGGER.handle_exception_async(
							"QLogicaeCLI::Application::_setup_run_command()",
							exception.what()
						);

						return false;
					}
				}
			);

			return true;
		}
		catch (const std::exception& exception)
		{
			QLogicaeCore::LOGGER.handle_exception_async(
				"QLogicaeCLI::Application::_setup_run_command()",
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
				UTILITIES.CLI_APPLICATION.add_subcommand(
					"build",
					"vs2022"
				);

			CLI::App* build_vs2022_command =
				build_command->add_subcommand(
					"vs2022",
					"Builds a project via Visual Studio 2022"
				);

			build_vs2022_command
				->add_option("--project-name",
					STRING_INPUTS.get("build_vs2022_command", "project_name"),
					"The selected Visual Studio 2022 project. Defaults to the starting project"
				)
				->default_val("");

			build_vs2022_command
				->add_option("--environment-type",
					STRING_INPUTS.get("build_vs2022_command", "environment_type"),
					"The selected QLogicae environment type"
				)
				->default_val("development");

			build_vs2022_command
				->add_option("--architecture-type",
					STRING_INPUTS.get("build_vs2022_command", "architecture_type"),
					"The Visual Studio 2022 project's instruction architecture"
				)
				->check(CLI::IsMember(
					QLogicaeCore::UTILITIES.VISUAL_STUDIO_2022_BUILD_ARCHITECTURE_TYPES
				))
				->default_val(QLogicaeCore::UTILITIES.VISUAL_STUDIO_2022_BUILD_ARCHITECTURE_TYPES[0]);

			build_vs2022_command
				->add_option("--build-type",
					STRING_INPUTS.get("build_vs2022_command", "build_type"),
					"The Visual Studio 2022 project's build type"
				)
				->check(CLI::IsMember(
					QLogicaeCore::UTILITIES.VISUAL_STUDIO_2022_BUILD_TYPES
				))
				->default_val(QLogicaeCore::UTILITIES.VISUAL_STUDIO_2022_BUILD_TYPES[0]);

			build_vs2022_command
				->add_option("--is-run-enabled",
					BOOLEAN_INPUTS.get("build_vs2022_command", "is_run_enabled"),
					"Enables or disables application execution after build")
				->default_val(true);

			build_vs2022_command
				->add_option("--is-verbose",
					BOOLEAN_INPUTS.get("build_vs2022_command", "is_verbose"),
					"Enables or disables verbose console logging")
				->default_val(false);

			UTILITIES.CLI_APPLICATION_COMMANDS["build_vs2022"] = std::make_pair(
				build_vs2022_command,
				[this]() -> bool
				{
					QLogicaeCore::Result<void> void_result;

					std::string executable_name = "";

					std::string build_vs2022_command__project =
						STRING_INPUTS.get(
							"build_vs2022_command", "project_name"
						);

					std::string build_vs2022_command__environment =
						STRING_INPUTS.get(
							"build_vs2022_command", "environment_type"
						);

					std::string build_vs2022_command__architecture =
						STRING_INPUTS.get(
							"build_vs2022_command", "architecture_type"
						);

					std::string build_vs2022_command__build_type =
						STRING_INPUTS.get(
							"build_vs2022_command", "build_type"
						);

					bool build_vs2022_command__is_run_enabled =
						BOOLEAN_INPUTS.get(
							"build_vs2022_command", "is_run_enabled"
						);

					bool build_vs2022_command__is_verbose =
						BOOLEAN_INPUTS.get(
							"build_vs2022_command", "is_verbose"
						);

					QLogicaeCore::LogConfigurations console_log_configurations_1 =
					{
						.is_console_enabled = build_vs2022_command__is_verbose,
						.is_console_format_enabled = build_vs2022_command__is_verbose
					};

					QLogicaeCore::LogConfigurations console_log_configurations_2 =
					{
						.is_console_enabled = build_vs2022_command__is_verbose,
						.is_console_format_enabled = build_vs2022_command__is_verbose
					};

					try
					{
						LOGGER.log_running(
							void_result,
							"qlogicae_cli build vs2022",
							console_log_configurations_1
						);

						QLogicaeCore::JSON_FILE_IO.set_file_path(
							UTILITIES.RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_CONFIGURATIONS_QLOGICAE_FILE_PATH
						);

						executable_name =
							QLogicaeCore::JSON_FILE_IO
							.get_string(
								{ "application", "executable_name" }
							);


						if (build_vs2022_command__project.empty())
						{
							build_vs2022_command__project =
								QLogicaeCore::JSON_FILE_IO
								.get_string(
									{ "application", "startup_project_name" }
								);

							LOGGER.log(
								void_result,
								"Switching to Startup Project '" + build_vs2022_command__project + "'",
								console_log_configurations_2
							);
						}

						if (!std::filesystem::exists(build_vs2022_command__project))
						{
							LOGGER.log(
								void_result,
								"Selected Visual Studio 2022 project does not exist",
								QLogicaeCore::DEFAULT_WARNING_LOG_CONFIGURATIONS
							);

							return false;
						}

						std::string command =
							absl::StrCat(
								"powershell -ExecutionPolicy Bypass -File",
								" \"qlogicae/.qlogicae/application/scripts/visual_studio_2022/build.ps1\"",
								" -VisualStudio2022InputProject ",
								build_vs2022_command__project,
								" -EnvironmentType ",
								build_vs2022_command__environment,
								" -VisualStudio2022Architecture ",
								build_vs2022_command__architecture,
								" -VisualStudio2022Build ",
								build_vs2022_command__build_type
							);

						LOGGER.log(
							void_result,
							"Executing '" + command + "'",
							console_log_configurations_2
						);
						system(
							command.c_str()
						);

						if (build_vs2022_command__is_run_enabled)
						{
							command = absl::StrCat(
								".\\", build_vs2022_command__architecture,
								"\\", build_vs2022_command__build_type,
								"\\", build_vs2022_command__project,
								"\\", executable_name,
								".exe"
							);

							LOGGER.log(
								void_result,
								"Executing '" + command + "'",
								console_log_configurations_2
							);
							system(
								command.c_str()
							);
						}

						LOGGER.log_complete(
							void_result,
							"qlogicae_cli build vs2022",
							console_log_configurations_1
						);

						return true;
					}
					catch (const std::exception& exception)
					{
						QLogicaeCore::LOGGER.handle_exception_async(
							"QLogicaeCLI::Application::_setup_build_command()",
							exception.what()
						);

						return false;
					}
				});

			return true;
		}
		catch (const std::exception& exception)
		{
			QLogicaeCore::LOGGER.handle_exception_async(
				"QLogicaeCLI::Application::_setup_build_command()",
				exception.what()
			);

			return false;
		}
	}

	bool Application::_setup_deploy_command()
	{
		try
		{
			CLI::App* deploy_command =
				UTILITIES.CLI_APPLICATION.add_subcommand(
					"deploy",
					"vs2022"
				);

			CLI::App* deploy_vs2022_command =
				deploy_command->add_subcommand(
					"vs2022",
					"Deploys the Visual Studio 2022 project"
				);

			deploy_vs2022_command
				->add_option("--project-name",
					STRING_INPUTS.get("deploy_vs2022", "project_name"),
					"The selected Visual Studio 2022 project. Defaults to the startup project"
				)
				->default_val("");

			deploy_vs2022_command
				->add_option("--environment-type",
					STRING_INPUTS.get("deploy_vs2022", "environment_type"),
					"The selected QLogicae environment type"
				)
				->default_val("release");

			deploy_vs2022_command
				->add_option("--architecture-type",
					STRING_INPUTS.get("deploy_vs2022", "architecture_type"),
					"The Visual Studio 2022 project's instruction architecture"
				)
				->check(CLI::IsMember(
					QLogicaeCore::UTILITIES.VISUAL_STUDIO_2022_BUILD_ARCHITECTURE_TYPES
				))
				->default_val(QLogicaeCore::UTILITIES.VISUAL_STUDIO_2022_BUILD_ARCHITECTURE_TYPES[0]);

			deploy_vs2022_command
				->add_option("--build-type",
					STRING_INPUTS.get("deploy_vs2022", "build_type"),
					"The Visual Studio 2022 project's build type"
				)
				->check(CLI::IsMember(
					QLogicaeCore::UTILITIES.VISUAL_STUDIO_2022_BUILD_TYPES
				))
				->default_val(QLogicaeCore::UTILITIES.VISUAL_STUDIO_2022_BUILD_TYPES[0]);

			deploy_vs2022_command
				->add_option("--installer-type",
					STRING_INPUTS.get("deploy_vs2022", "installer_type"),
					"The selected input folder path")
				->check(CLI::IsMember(
					QLogicaeCore::UTILITIES.INSTALLER_TYPES
				))
				->default_val(QLogicaeCore::UTILITIES.INSTALLER_TYPES[0]);

			deploy_vs2022_command
				->add_option("--output-folder-path",
					STRING_INPUTS.get("deploy_vs2022", "output_folder_path"),
					"The selected output folder path of the installer"
				)
				->default_val("");

			deploy_vs2022_command
				->add_option("--is-build-enabled",
					BOOLEAN_INPUTS.get("deploy_vs2022", "is_build_enabled"),
					"Enables or disables build")
				->default_val(true);

			deploy_vs2022_command
				->add_option("--is-verbose",
					BOOLEAN_INPUTS.get("deploy_vs2022", "is_verbose"),
					"Enables or disables verbose console logging")
				->default_val(false);

			UTILITIES.CLI_APPLICATION_COMMANDS["deploy_vs2022"] = std::make_pair(
				deploy_vs2022_command,
				[this]() -> bool
				{
					QLogicaeCore::Result<void> void_result;

					std::string deploy_vs2022__project =
						STRING_INPUTS.get("deploy_vs2022", "project_name");

					std::string deploy_vs2022__environment =
						STRING_INPUTS.get("deploy_vs2022", "environment_type");

					std::string deploy_vs2022__architecture =
						STRING_INPUTS.get("deploy_vs2022", "architecture_type");

					std::string deploy_vs2022__build_type =
						STRING_INPUTS.get("deploy_vs2022", "build_type");

					std::string deploy_vs2022__installer_type =
						STRING_INPUTS.get("deploy_vs2022", "installer_type");

					std::string deploy_vs2022__output_folder_path =
						STRING_INPUTS.get("deploy_vs2022", "output_folder_path");

					bool deploy_vs2022__is_build_enabled =
						BOOLEAN_INPUTS.get("deploy_vs2022", "is_build_enabled");

					bool deploy_vs2022__is_verbose =
						BOOLEAN_INPUTS.get("deploy_vs2022", "is_verbose");

					QLogicaeCore::LogConfigurations console_log_configurations_1 =
					{
						.is_console_enabled = deploy_vs2022__is_verbose,
						.is_console_format_enabled = deploy_vs2022__is_verbose
					};

					QLogicaeCore::LogConfigurations console_log_configurations_2 =
					{
						.is_console_enabled = deploy_vs2022__is_verbose,
						.is_console_format_enabled = deploy_vs2022__is_verbose
					};

					try
					{
						LOGGER.log_running(
							void_result,
							"qlogicae_cli deploy vs2022",
							console_log_configurations_1
						);

						if (deploy_vs2022__project.empty())
						{
							LOGGER.log(
								void_result,
								"Using startup project",
								console_log_configurations_2
							);

							QLogicaeCore::JSON_FILE_IO.set_file_path(
								UTILITIES.RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_CONFIGURATIONS_QLOGICAE_FILE_PATH
							);
							deploy_vs2022__project = QLogicaeCore::JSON_FILE_IO
								.get_string(
									{ "application", "startup_project_name" }
								);
						}

						if (deploy_vs2022__output_folder_path.empty())
						{
							LOGGER.log(
								void_result,
								"Using default release folder path",
								console_log_configurations_2
							);

							QLogicaeCore::JSON_FILE_IO.set_file_path(
								UTILITIES.RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_CONFIGURATIONS_QLOGICAE_FILE_PATH
							);
							deploy_vs2022__output_folder_path =
								QLogicaeCore::JSON_FILE_IO
								.get_string(
									{ "application", "release_folder_path" }
								);
						}

						if (!std::filesystem::exists(deploy_vs2022__project))
						{
							LOGGER.log(
								void_result,
								"Selected Visual Studio 2022 project does not exist",
								console_log_configurations_2
							);

							return false;
						}

						std::string input_folder_path = absl::StrCat(
							deploy_vs2022__architecture,
							"\\", deploy_vs2022__build_type,
							"\\", deploy_vs2022__project
						);

						if (deploy_vs2022__is_build_enabled)
						{
							LOGGER.log(
								void_result,
								"Building project",
								console_log_configurations_2
							);

							system((absl::StrCat(
								"powershell -ExecutionPolicy Bypass -File",
								" \"qlogicae/.qlogicae/application/scripts/visual_studio_2022/build.ps1\"",
								" -VisualStudio2022InputProject ", deploy_vs2022__project,
								" -EnvironmentType ", deploy_vs2022__environment,
								" -VisualStudio2022Architecture ", deploy_vs2022__architecture,
								" -VisualStudio2022Build ", deploy_vs2022__build_type
							)).c_str());
						}

						if (deploy_vs2022__installer_type == QLogicaeCore::UTILITIES.INSTALLER_TYPES[0])
						{
							LOGGER.log(
								void_result,
								"Deploying project",
								console_log_configurations_2
							);

							system((absl::StrCat(
								"powershell -ExecutionPolicy Bypass -File",
								" \"qlogicae/.qlogicae/application/scripts/inno_setup/deploy.ps1\"",
								" -EnvironmentType ", deploy_vs2022__environment,
								" -ProjectName ", deploy_vs2022__project,
								" -InputFolderPath ", input_folder_path,
								" -OutputFolderPath ", deploy_vs2022__output_folder_path
							)).c_str());
						}

						LOGGER.log(
							void_result,
							"Updating ids",
							console_log_configurations_2
						);

						QLogicaeCore::JSON_FILE_IO.set_file_path(
							QLogicaeCore::UTILITIES.FULL_EXECUTED_FOLDER_PATH +
							".\\qlogicae\\.qlogicae\\application\\templates\\default\\build\\qlogicae\\application\\configurations\\qlogicae.json"
						);
						QLogicaeCore::JSON_FILE_IO.update_string(
							{ "id" },
							QLogicaeCore::GENERATOR.random_uuid4()
						);

						QLogicaeCore::JSON_FILE_IO.set_file_path(
							QLogicaeCore::UTILITIES.FULL_EXECUTED_FOLDER_PATH +
							".\\qlogicae\\.qlogicae\\application\\templates\\debug\\build\\qlogicae\\application\\configurations\\environment.json"
						);
						QLogicaeCore::JSON_FILE_IO.update_string(
							{ "id" },
							QLogicaeCore::GENERATOR.random_uuid4()
						);

						QLogicaeCore::JSON_FILE_IO.set_file_path(
							QLogicaeCore::UTILITIES.FULL_EXECUTED_FOLDER_PATH +
							".\\qlogicae\\.qlogicae\\application\\templates\\development\\build\\qlogicae\\application\\configurations\\environment.json"
						);
						QLogicaeCore::JSON_FILE_IO.update_string(
							{ "id" },
							QLogicaeCore::GENERATOR.random_uuid4()
						);

						QLogicaeCore::JSON_FILE_IO.set_file_path(
							QLogicaeCore::UTILITIES.FULL_EXECUTED_FOLDER_PATH +
							".\\qlogicae\\.qlogicae\\application\\templates\\release\\build\\qlogicae\\application\\configurations\\environment.json"
						);
						QLogicaeCore::JSON_FILE_IO.update_string(
							{ "id" },
							QLogicaeCore::GENERATOR.random_uuid4()
						);

						QLogicaeCore::JSON_FILE_IO.set_file_path(
							QLogicaeCore::UTILITIES.FULL_EXECUTED_FOLDER_PATH +
							".\\qlogicae\\.qlogicae\\application\\templates\\test\\build\\qlogicae\\application\\configurations\\environment.json"
						);
						QLogicaeCore::JSON_FILE_IO.update_string(
							{ "id" },
							QLogicaeCore::GENERATOR.random_uuid4()
						);

						LOGGER.log_complete(
							void_result,
							"qlogicae_cli deploy vs2022",
							console_log_configurations_1
						);

						return true;
					}
					catch (const std::exception& exception)
					{
						QLogicaeCore::LOGGER.handle_exception_async(
							"QLogicaeCLI::Application::_setup_deploy_command()",
							exception.what()
						);

						return false;
					}
				}
			);

			return true;
		}
		catch (const std::exception& exception)
		{
			QLogicaeCore::LOGGER.handle_exception_async(
				"QLogicaeCLI::Application::_setup_deploy_command()",
				exception.what()
			);

			return false;
		}
	}

	bool Application::_setup_setup_command()
	{
		try
		{
			CLI::App* setup_command =
				UTILITIES.CLI_APPLICATION.add_subcommand(
					"setup",
					"vs2022, windows-registry"
				);

			CLI::App* setup_windows_registry_command =
				setup_command->add_subcommand(
					"windows-registry",
					"Creates or updates windows registry key-value pairs of a selected QLogicae environment preset"
				);

			setup_windows_registry_command
				->add_option(
					"--environment-type",
					STRING_INPUTS.get("setup_windows_registry", "environment_type"),
					"HKCU Selected environment type")
				->default_val("development");

			setup_windows_registry_command
				->add_option("--is-verbose",
					BOOLEAN_INPUTS.get("setup_windows_registry", "is_verbose"),
					"Enables or disables verbose console logging")
				->default_val(false);

			UTILITIES.CLI_APPLICATION_COMMANDS["setup_windows_registry"] = std::make_pair(
				setup_windows_registry_command,
				[this]() -> bool
				{
					QLogicaeCore::Result<void> void_result;

					std::string setup_windows_registry__environment =
						STRING_INPUTS.get("setup_windows_registry", "environment_type");

					bool setup_windows_registry__is_verbose =
						BOOLEAN_INPUTS.get("setup_windows_registry", "is_verbose");

					QLogicaeCore::LogConfigurations console_log_configurations_1 =
					{
						.is_console_enabled = setup_windows_registry__is_verbose,
						.is_console_format_enabled = setup_windows_registry__is_verbose
					};

					QLogicaeCore::LogConfigurations console_log_configurations_2 =
					{
						.is_console_enabled = setup_windows_registry__is_verbose,
						.is_console_format_enabled = setup_windows_registry__is_verbose
					};

					try
					{
						LOGGER.log_running(
							void_result,
							"qlogicae_cli windows registry",
							console_log_configurations_1
						);

						std::string command =
							absl::StrCat(
								"powershell -ExecutionPolicy Bypass -File",
								" \"qlogicae/.qlogicae/application/scripts/windows_registry/setup.ps1\"",
								" -EnvironmentType ",
								setup_windows_registry__environment
							);

						LOGGER.log(
							void_result,
							command,
							console_log_configurations_2
						);

						system(command.c_str());

						LOGGER.log_complete(
							void_result,
							"qlogicae_cli windows registry",
							console_log_configurations_1
						);

						return true;
					}
					catch (const std::exception& exception)
					{
						QLogicaeCore::LOGGER.handle_exception_async(
							"QLogicaeCLI::Application::_setup_deploy_command()",
							exception.what()
						);

						return false;
					}
				}
			);

			CLI::App* setup_vs2022_command =
				setup_command->add_subcommand(
					"vs2022",
					"application, ids"
				);

			CLI::App* setup_vs2022_application_command =
				setup_vs2022_command->add_subcommand(
					"application",
					"Setup QLogicae Application Project"
				);

			setup_vs2022_application_command
				->add_option("--enable-property-setup",
					BOOLEAN_INPUTS.get("setup_vs2022_application", "enable_property_setup"),
					"Enables or disables a QLogicae project configuration input form")
				->default_val(true);

			setup_vs2022_application_command
				->add_option("--enable-full-property-setup",
					BOOLEAN_INPUTS.get("setup_vs2022_application", "enable_full_property_setup"),
					"Enables or disables the complete QLogicae project configuration input form")
				->default_val(true);

			setup_vs2022_application_command
				->add_option("--enable-filesystem-setup",
					BOOLEAN_INPUTS.get("setup_vs2022_application", "enable_filesystem_setup"),
					"Enables or disables the QLogicae file system setup")
				->default_val(true);

			setup_vs2022_application_command
				->add_option("--enable-id-setup",
					BOOLEAN_INPUTS.get("setup_vs2022_application", "enable_id_setup"),
					"Enables or disables the QLogicae configuration id setup")
				->default_val(true);

			setup_vs2022_application_command
				->add_option("--is-verbose",
					BOOLEAN_INPUTS.get("setup_vs2022_application", "is_verbose"),
					"Enables or disables verbose console logging")
				->default_val(false);

			UTILITIES.CLI_APPLICATION_COMMANDS["setup_vs2022_application"] = std::make_pair(
				setup_vs2022_application_command,
				[this]() -> bool
				{
					QLogicaeCore::Result<void> void_result;

					bool setup_vs2022_application__enable_property_setup =
						BOOLEAN_INPUTS.get("setup_vs2022_application", "enable_property_setup");

					bool setup_vs2022_application__enable_full_property_setup =
						BOOLEAN_INPUTS.get("setup_vs2022_application", "enable_full_property_setup");

					bool setup_vs2022_application__enable_filesystem_setup =
						BOOLEAN_INPUTS.get("setup_vs2022_application", "enable_filesystem_setup");

					bool setup_vs2022_application__enable_id_setup =
						BOOLEAN_INPUTS.get("setup_vs2022_application", "enable_id_setup");

					bool setup_vs2022_application__is_verbose =
						BOOLEAN_INPUTS.get("setup_vs2022_application", "is_verbose");

					QLogicaeCore::LogConfigurations console_log_configurations_1 =
					{
						.is_console_enabled = setup_vs2022_application__is_verbose,
						.is_console_format_enabled = setup_vs2022_application__is_verbose
					};

					QLogicaeCore::LogConfigurations console_log_configurations_2 =
					{
						.is_console_enabled = true,
						.is_console_format_enabled = setup_vs2022_application__is_verbose
					};

					try
					{
						LOGGER.log_running(
							void_result,
							"qlogicae_cli setup vs2022 application",
							console_log_configurations_1
						);

						bool is_running = true;
						std::string startup;
						std::string executable;
						std::string name;
						std::string version;
						std::string company;
						std::string authors;
						std::string description;
						std::string url;
						std::string architecture;
						std::string confirmation;

						std::string text;

						std::string command;

						while (
							setup_vs2022_application__enable_property_setup &&
							is_running
							)
						{
							startup = "startup_project";
							name = "Project Name";
							version = "1.0.0";
							company = "Company";
							authors = "Author";
							description = "Description";
							url = "www.google.com";
							architecture = "x64";

							executable = startup;

							LOGGER.log(
								void_result,
								"> Startup: ",
								console_log_configurations_2
							);
							startup = QLogicaeCore::CLI_IO.scan();
							executable = startup;

							if (setup_vs2022_application__enable_full_property_setup)
							{
								LOGGER.log(
									void_result,
									"> Name: ",
									console_log_configurations_2
								);
								name = QLogicaeCore::CLI_IO.scan();

								LOGGER.log(
									void_result,
									"> Version: ",
									console_log_configurations_2
								);
								version = QLogicaeCore::CLI_IO.scan();

								LOGGER.log(
									void_result,
									"> Company: ",
									console_log_configurations_2
								);
								company = QLogicaeCore::CLI_IO.scan();

								LOGGER.log(
									void_result,
									"> Authors: ",
									console_log_configurations_2
								);
								authors = QLogicaeCore::CLI_IO.scan();

								LOGGER.log(
									void_result,
									"> Description: ",
									console_log_configurations_2
								);
								description = QLogicaeCore::CLI_IO.scan();

								LOGGER.log(
									void_result,
									"> URL: ",
									console_log_configurations_2
								);
								url = QLogicaeCore::CLI_IO.scan();

								LOGGER.log(
									void_result,
									"> Architecture [x64|x86]: ",
									console_log_configurations_2
								);
								while (true)
								{
									architecture = QLogicaeCore::CLI_IO.scan();
									if (
										QLogicaeCore::UTILITIES
										.VISUAL_STUDIO_2022_BUILD_ARCHITECTURE_STRINGS.contains(
											architecture
										)
										)
									{
										break;
									}
								}
							}

							LOGGER.log(
								void_result,
								std::string("\n") +
								"- Startup: " + startup + "\n" +
								"- Name: " + name + "\n" +
								"- Version: " + version + "\n" +
								"- Company: " + company + "\n" +
								"- Authors: " + authors + "\n" +
								"- Description: " + description + "\n" +
								"- URL: " + url + "\n" +
								"- Architecture: " + architecture + "\n\n" +
								"> Confirm? [y/n] ",
								console_log_configurations_2
							);

							while (true)
							{
								confirmation = QLogicaeCore::CLI_IO.scan();
								if (confirmation == "y")
								{
									is_running = false;
									break;
								}
								else if (confirmation == "n")
								{
									break;
								}
							}
						}

						if (setup_vs2022_application__enable_filesystem_setup)
						{
							std::string root_input_folder =
								QLogicaeCore::UTILITIES.FULL_EXECUTABLE_FOLDER_PATH +
								"\\" + UTILITIES.RELATIVE_QLOGICAE_CLI_SETUP_VS2022_APPLICATION_FOLDER_PATH;

							command = "powershell -Command \"Copy-Item -Path '" +
								root_input_folder + "\\root\\*' -Destination '" +
								QLogicaeCore::UTILITIES.FULL_EXECUTED_FOLDER_PATH +
								"' -Recurse -Force\"";

							LOGGER.log(
								void_result,
								"Executing '" + command + "'",
								console_log_configurations_1
							);

							std::system(
								command.c_str()
							);

							QLogicaeCore::TEXT_FILE_IO.setup(
								QLogicaeCore::UTILITIES.FULL_EXECUTED_FOLDER_PATH +
								"\\LICENSE.txt"
							);
							QLogicaeCore::TEXT_FILE_IO.open(QLogicaeCore::FileMode::READ);
							text = QLogicaeCore::TEXT_FILE_IO.read();
							QLogicaeCore::TEXT_FILE_IO.close(QLogicaeCore::FileMode::READ);
							text = absl::StrReplaceAll(text,
								{
									{ "[placeholder__year]", absl::StrCat(static_cast<int>(QLogicaeCore::TIME.year())) },
									{ "[placeholder__company]", company }
								}
							);
							QLogicaeCore::TEXT_FILE_IO.open(QLogicaeCore::FileMode::WRITE);
							QLogicaeCore::TEXT_FILE_IO.write(text);
							QLogicaeCore::TEXT_FILE_IO.close(QLogicaeCore::FileMode::WRITE);



							QLogicaeCore::TEXT_FILE_IO.setup(
								QLogicaeCore::UTILITIES.FULL_EXECUTED_FOLDER_PATH +
								"\\README.md"
							);
							QLogicaeCore::TEXT_FILE_IO.open(QLogicaeCore::FileMode::READ);
							text = QLogicaeCore::TEXT_FILE_IO.read();
							QLogicaeCore::TEXT_FILE_IO.close(QLogicaeCore::FileMode::READ);

							text = absl::StrReplaceAll(text,
								{
									{ "[placeholder__name]", name },
									{ "[placeholder__description]", description }
								}
							);
							QLogicaeCore::TEXT_FILE_IO.open(QLogicaeCore::FileMode::WRITE);
							QLogicaeCore::TEXT_FILE_IO.write(text);
							QLogicaeCore::TEXT_FILE_IO.close(QLogicaeCore::FileMode::WRITE);
						}

						if (setup_vs2022_application__enable_property_setup)
						{
							QLogicaeCore::JSON_FILE_IO.set_file_path(
								QLogicaeCore::UTILITIES.FULL_EXECUTED_FOLDER_PATH +
								"\\" + UTILITIES.RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_CONFIGURATIONS_QLOGICAE_FILE_PATH
							);

							QLogicaeCore::JSON_FILE_IO.update_string(
								{ "application", "startup_project_name" },
								startup
							);

							QLogicaeCore::JSON_FILE_IO.update_string(
								{ "application", "executable_name" },
								executable
							);

							QLogicaeCore::JSON_FILE_IO.set_file_path(
								QLogicaeCore::UTILITIES.FULL_EXECUTED_FOLDER_PATH +
								"\\" + UTILITIES.RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_TEMPLATES_FOLDER_PATH +
								"\\default" +
								"\\" + UTILITIES.RELATIVE_BUILD_QLOGICAE_APPLICATION_CONFIGURATIONS_QLOGICAE_FILE_PATH
							);

							QLogicaeCore::JSON_FILE_IO.update_string(
								{ "name" },
								name
							);

							QLogicaeCore::JSON_FILE_IO.update_string(
								{ "version" },
								version
							);

							QLogicaeCore::JSON_FILE_IO.update_string(
								{ "company" },
								company);

							QLogicaeCore::JSON_FILE_IO.update_string(
								{ "authors" }, authors);

							QLogicaeCore::JSON_FILE_IO.update_string(
								{ "description" }, description);

							QLogicaeCore::JSON_FILE_IO.update_string(
								{ "url" }, url);

							QLogicaeCore::JSON_FILE_IO.update_string(
								{ "architecture" }, architecture);
						}

						if (setup_vs2022_application__enable_id_setup)
						{
							QLogicaeCore::JSON_FILE_IO.set_file_path(
								QLogicaeCore::UTILITIES.FULL_EXECUTED_FOLDER_PATH +
								"\\" + UTILITIES.RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_TEMPLATES_FOLDER_PATH +
								"\\default" +
								"\\" + UTILITIES.RELATIVE_BUILD_QLOGICAE_APPLICATION_CONFIGURATIONS_QLOGICAE_FILE_PATH
							);

							QLogicaeCore::JSON_FILE_IO.update_string(
								{ "id" },
								QLogicaeCore::GENERATOR.random_uuid4()
							);

							QLogicaeCore::JSON_FILE_IO.set_file_path(
								QLogicaeCore::UTILITIES.FULL_EXECUTED_FOLDER_PATH +
								"\\" + UTILITIES.RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_TEMPLATES_FOLDER_PATH +
								"\\debug" +
								"\\" + UTILITIES.RELATIVE_BUILD_QLOGICAE_APPLICATION_CONFIGURATIONS_ENVIRONMENT_FILE_PATH
							);

							QLogicaeCore::JSON_FILE_IO.update_string(
								{ "id" },
								QLogicaeCore::GENERATOR.random_uuid4()
							);

							QLogicaeCore::JSON_FILE_IO.set_file_path(
								QLogicaeCore::UTILITIES.FULL_EXECUTED_FOLDER_PATH +
								"\\" + UTILITIES.RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_TEMPLATES_FOLDER_PATH +
								"\\development" +
								"\\" + UTILITIES.RELATIVE_BUILD_QLOGICAE_APPLICATION_CONFIGURATIONS_ENVIRONMENT_FILE_PATH
							);

							QLogicaeCore::JSON_FILE_IO.update_string(
								{ "id" },
								QLogicaeCore::GENERATOR.random_uuid4()
							);

							QLogicaeCore::JSON_FILE_IO.set_file_path(
								QLogicaeCore::UTILITIES.FULL_EXECUTED_FOLDER_PATH +
								"\\" + UTILITIES.RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_TEMPLATES_FOLDER_PATH +
								"\\test" +
								"\\" + UTILITIES.RELATIVE_BUILD_QLOGICAE_APPLICATION_CONFIGURATIONS_ENVIRONMENT_FILE_PATH
							);

							QLogicaeCore::JSON_FILE_IO.update_string(
								{ "id" },
								QLogicaeCore::GENERATOR.random_uuid4()
							);

							QLogicaeCore::JSON_FILE_IO.set_file_path(
								QLogicaeCore::UTILITIES.FULL_EXECUTED_FOLDER_PATH +
								"\\" + UTILITIES.RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_TEMPLATES_FOLDER_PATH +
								"\\release" +
								"\\" + UTILITIES.RELATIVE_BUILD_QLOGICAE_APPLICATION_CONFIGURATIONS_ENVIRONMENT_FILE_PATH
							);

							QLogicaeCore::JSON_FILE_IO.update_string(
								{ "id" },
								QLogicaeCore::GENERATOR.random_uuid4()
							);
						}

						LOGGER.log_complete(
							void_result,
							"qlogicae_cli setup vs2022 application",
							console_log_configurations_1
						);

						return true;
					}
					catch (const std::exception& exception)
					{
						QLogicaeCore::LOGGER.handle_exception_async(
							"QLogicaeCLI::Application::_setup_deploy_command()",
							exception.what()
						);

						return false;
					}
				}
			);

			CLI::App* setup_vs2022_ids_command =
				setup_vs2022_command->add_subcommand(
					"ids",
					"Setup QLogicae application template environment ids"
				);

			setup_vs2022_ids_command
				->add_option("--is-verbose",
					BOOLEAN_INPUTS.get("setup_vs2022_ids", "is_verbose"),
					"Enables or disables verbose console logging")
				->default_val(false);

			UTILITIES.CLI_APPLICATION_COMMANDS["setup_vs2022_ids"] = std::make_pair(
				setup_vs2022_ids_command,
				[this]() -> bool
				{
					QLogicaeCore::Result<void> void_result;

					bool setup_vs2022_ids__is_verbose =
						BOOLEAN_INPUTS.get("setup_vs2022_ids", "is_verbose");

					QLogicaeCore::LogConfigurations console_log_configurations_1 =
					{
						.is_console_enabled = setup_vs2022_ids__is_verbose,
						.is_console_format_enabled = setup_vs2022_ids__is_verbose
					};

					QLogicaeCore::LogConfigurations console_log_configurations_2 =
					{
						.is_console_enabled = setup_vs2022_ids__is_verbose,
						.is_console_format_enabled = setup_vs2022_ids__is_verbose
					};

					try
					{
						LOGGER.log_running(
							void_result,
							"qlogicae_cli setup vs2022 ids",
							console_log_configurations_1
						);

						QLogicaeCore::JSON_FILE_IO.set_file_path(
							QLogicaeCore::UTILITIES.FULL_EXECUTED_FOLDER_PATH +
							"\\" + UTILITIES.RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_TEMPLATES_FOLDER_PATH +
							"\\default" +
							"\\" + UTILITIES.RELATIVE_BUILD_QLOGICAE_APPLICATION_CONFIGURATIONS_QLOGICAE_FILE_PATH
						);
						QLogicaeCore::JSON_FILE_IO.update_string(
							{ "id" },
							QLogicaeCore::GENERATOR.random_uuid4()
						);

						QLogicaeCore::JSON_FILE_IO.set_file_path(
							QLogicaeCore::UTILITIES.FULL_EXECUTED_FOLDER_PATH +
							"\\" + UTILITIES.RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_TEMPLATES_FOLDER_PATH +
							"\\debug" +
							"\\" + UTILITIES.RELATIVE_BUILD_QLOGICAE_APPLICATION_CONFIGURATIONS_ENVIRONMENT_FILE_PATH
						);
						QLogicaeCore::JSON_FILE_IO.update_string(
							{ "id" },
							QLogicaeCore::GENERATOR.random_uuid4()
						);

						QLogicaeCore::JSON_FILE_IO.set_file_path(
							QLogicaeCore::UTILITIES.FULL_EXECUTED_FOLDER_PATH +
							"\\" + UTILITIES.RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_TEMPLATES_FOLDER_PATH +
							"\\development" +
							"\\" + UTILITIES.RELATIVE_BUILD_QLOGICAE_APPLICATION_CONFIGURATIONS_ENVIRONMENT_FILE_PATH
						);
						QLogicaeCore::JSON_FILE_IO.update_string(
							{ "id" },
							QLogicaeCore::GENERATOR.random_uuid4()
						);

						QLogicaeCore::JSON_FILE_IO.set_file_path(
							QLogicaeCore::UTILITIES.FULL_EXECUTED_FOLDER_PATH +
							"\\" + UTILITIES.RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_TEMPLATES_FOLDER_PATH +
							"\\test" +
							"\\" + UTILITIES.RELATIVE_BUILD_QLOGICAE_APPLICATION_CONFIGURATIONS_ENVIRONMENT_FILE_PATH
						);
						QLogicaeCore::JSON_FILE_IO.update_string(
							{ "id" },
							QLogicaeCore::GENERATOR.random_uuid4()
						);

						QLogicaeCore::JSON_FILE_IO.set_file_path(
							QLogicaeCore::UTILITIES.FULL_EXECUTED_FOLDER_PATH +
							"\\" + UTILITIES.RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_TEMPLATES_FOLDER_PATH +
							"\\release" +
							"\\" + UTILITIES.RELATIVE_BUILD_QLOGICAE_APPLICATION_CONFIGURATIONS_ENVIRONMENT_FILE_PATH
						);
						QLogicaeCore::JSON_FILE_IO.update_string(
							{ "id" },
							QLogicaeCore::GENERATOR.random_uuid4()
						);

						LOGGER.log_complete(
							void_result,
							"qlogicae_cli setup vs2022 ids",
							console_log_configurations_1
						);

						return true;
					}
					catch (const std::exception& exception)
					{
						QLogicaeCore::LOGGER.handle_exception_async(
							"QLogicaeCLI::Application::_setup_deploy_command()",
							exception.what()
						);

						return false;
					}
				}
			);

			return true;
		}
		catch (const std::exception& exception)
		{
			QLogicaeCore::LOGGER.handle_exception_async(
				"QLogicaeCLI::Application::_setup_deploy_command()",
				exception.what()
			);

			return false;
		}
	}

	bool Application::_setup_generate_command()
	{
		try
		{
			CLI::App* generate_command =
				UTILITIES.CLI_APPLICATION.add_subcommand(
					"generate",
					"uuid4s, strings"
				);

			CLI::App* generate_uuid4_command =
				generate_command->add_subcommand(
					"uuid4s",
					"Random UUID4 generation"
				);

			generate_uuid4_command
				->add_option("--output-count",
					SIZE_T_INPUTS.get("generate_uuid4s", "output_count"),
					"The number of generated uuid4s")
				->check(CLI::PositiveNumber)
				->default_val(1);

			generate_uuid4_command
				->add_option("--output-file-path",
					STRING_INPUTS.get("generate_uuid4s", "output_file_path"),
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");

			generate_uuid4_command
				->add_option("--is-file-output-enabled",
					BOOLEAN_INPUTS.get("generate_uuid4s", "is_file_output_enabled"),
					"Enables or disables the option '--output-file-path'")
				->default_val(false);

			generate_uuid4_command
				->add_option("--is-verbose",
					BOOLEAN_INPUTS.get("generate_uuid4s", "is_verbose"),
					"Enables or disables verbose console logging")
				->default_val(false);

			UTILITIES.CLI_APPLICATION_COMMANDS["generate_uuid4s"] = std::make_pair(
				generate_uuid4_command,
				[this]() -> bool
				{
					QLogicaeCore::Result<void> result;

					size_t generate_uuid4__output_count =
						SIZE_T_INPUTS.get("generate_uuid4s", "output_count");

					std::string generate_uuid4__output_file_path =
						STRING_INPUTS.get("generate_uuid4s", "output_file_path");

					bool generate_uuid4__is_file_output_enabled =
						BOOLEAN_INPUTS.get("generate_uuid4s", "is_file_output_enabled");

					bool generate_uuid4__is_verbose =
						BOOLEAN_INPUTS.get("generate_uuid4s", "is_verbose");

					QLogicaeCore::LogConfigurations console_log_configurations_1 =
					{
						.is_console_enabled = generate_uuid4__is_verbose,
						.is_console_format_enabled = generate_uuid4__is_verbose
					};

					QLogicaeCore::LogConfigurations console_log_configurations_2 =
					{
						.is_console_enabled = true,
						.is_console_format_enabled = generate_uuid4__is_verbose
					};

					try
					{
						LOGGER.log_running(
							result,
							"qlogicae_cli generate uud4s",
							console_log_configurations_1
						);

						std::string output_string = "\n";
						size_t index_1, size_a = generate_uuid4__output_count - 1;

						for (index_1 = 0;
							index_1 < generate_uuid4__output_count;
							++index_1)
						{
							output_string += QLogicaeCore::GENERATOR.random_uuid4() + "\n";
						}

						output_string += "\n";

						LOGGER.log(
							result,
							output_string,
							console_log_configurations_2
						);

						if (generate_uuid4__is_file_output_enabled)
						{
							QLogicaeCore::TEXT_FILE_IO.set_file_path(
								FILE_SYSTEM.setup_result_output_file(
									generate_uuid4__output_file_path,
									"generate\\uuid4s",
									QLogicaeCore::UTILITIES.RELATIVE_DEFAULT_OUTPUT_FILE_PATH
								)
							);
							QLogicaeCore::TEXT_FILE_IO.write_async(output_string);
						}

						LOGGER.log_complete(
							result,
							"qlogicae_cli generate uud4s",
							console_log_configurations_1
						);

						return true;
					}
					catch (const std::exception& exception)
					{
						QLogicaeCore::LOGGER.handle_exception_async(
							"QLogicaeCLI::Application::_setup_generate_command()",
							exception.what()
						);

						return false;
					}
				}
			);

			CLI::App* generate_string_command =
				generate_command->add_subcommand(
					"strings",
					"Random string generation"
				);

			generate_string_command
				->add_option("--string-length",
					SIZE_T_INPUTS.get("generate_strings", "string_length"),
					"The character length of each individual string output")
				->check(CLI::PositiveNumber)
				->default_val(32);

			generate_string_command
				->add_option("--output-count",
					SIZE_T_INPUTS.get("generate_strings", "output_count"),
					"The number of generated string outputs")
				->check(CLI::PositiveNumber)
				->default_val(1);

			generate_string_command
				->add_option("--character-set",
					STRING_INPUTS.get("generate_strings", "character_set"),
					"The string of characters where each individual character can possibly be found within each string output")
				->default_val("");

			generate_string_command
				->add_option("--output-file-path",
					STRING_INPUTS.get("generate_strings", "output_file_path"),
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");

			generate_string_command
				->add_option("--is-file-output-enabled",
					BOOLEAN_INPUTS.get("generate_strings", "is_file_output_enabled"),
					"Enables or disables the option '--output-file-path'")
				->default_val(false);

			generate_string_command
				->add_option("--is-verbose",
					BOOLEAN_INPUTS.get("generate_strings", "is_verbose"),
					"Enables or disables verbose console logging")
				->default_val(false);

			UTILITIES.CLI_APPLICATION_COMMANDS["generate_strings"] = std::make_pair(
				generate_string_command,
				[this]() -> bool
				{
					QLogicaeCore::Result<void> void_result;

					size_t generate_string__length =
						SIZE_T_INPUTS.get("generate_strings", "string_length");

					size_t generate_string__output_count =
						SIZE_T_INPUTS.get("generate_strings", "output_count");

					std::string generate_string__output_file_path =
						STRING_INPUTS.get("generate_strings", "output_file_path");

					std::string generate_string__character_set =
						STRING_INPUTS.get("generate_strings", "character_set");

					bool generate_string__is_file_output_enabled =
						BOOLEAN_INPUTS.get("generate_strings", "is_file_output_enabled");

					bool generate_string__is_verbose =
						BOOLEAN_INPUTS.get("generate_strings", "is_verbose");

					QLogicaeCore::LogConfigurations console_log_configurations_1 =
					{
						.is_console_enabled = generate_string__is_verbose,
						.is_console_format_enabled = generate_string__is_verbose
					};

					QLogicaeCore::LogConfigurations console_log_configurations_2 =
					{
						.is_console_enabled = true,
						.is_console_format_enabled = generate_string__is_verbose
					};

					try
					{
						LOGGER.log_running(
							void_result,
							"qlogicae_cli generate string",
							console_log_configurations_1
						);

						size_t index_1, size_a = generate_string__output_count - 1;
						std::string output_string = "\n",
							character_set = (generate_string__character_set.empty()) ?

							QLogicaeCore::UTILITIES.FULL_VISIBLE_ASCII_CHARACTERSET :
							generate_string__character_set;

						for (index_1 = 0;
							index_1 < generate_string__output_count;
							++index_1)
						{
							output_string += QLogicaeCore::GENERATOR.random_string(
								generate_string__length,
								character_set
							) + "\n";
						}

						output_string += "\n";

						LOGGER.log(
							void_result,
							output_string,
							console_log_configurations_2
						);

						if (generate_string__is_file_output_enabled)
						{
							QLogicaeCore::TEXT_FILE_IO.set_file_path(
								FILE_SYSTEM.setup_result_output_file(
									generate_string__output_file_path,
									"generate\\strings",
									QLogicaeCore::UTILITIES.RELATIVE_DEFAULT_OUTPUT_FILE_PATH
								)
							);
							QLogicaeCore::TEXT_FILE_IO.write_async(output_string);
						}

						LOGGER.log_complete(
							void_result,
							"qlogicae_cli generate strings",
							console_log_configurations_1
						);

						return true;
					}
					catch (const std::exception exception)
					{
						QLogicaeCore::LOGGER.handle_exception_async(
							"QLogicaeCLI::Application::_setup_generate_command()",
							exception.what()
						);

						return false;
					}
				}
			);

			return true;
		}
		catch (const std::exception& exception)
		{
			QLogicaeCore::LOGGER.handle_exception_async(
				"QLogicaeCLI::Application::_setup_generate_command()",
				exception.what()
			);

			return false;
		}
	}

	bool Application::_setup_encrypt_command()
	{
		try
		{
			CLI::App* encrypt_command =
				UTILITIES.CLI_APPLICATION.add_subcommand(
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
					STRING_INPUTS.get("encrypt_xchacha20poly1305", "text"),
					"The string input to be encrypted")
				->required();

			encrypt_xchacha20poly1305_command
				->add_option("--key",
					STRING_INPUTS.get("encrypt_xchacha20poly1305", "key"),
					"Encryption key")
				->required();

			encrypt_xchacha20poly1305_command
				->add_option("--nonce",
					STRING_INPUTS.get("encrypt_xchacha20poly1305", "nonce"),
					"Encryption nonce. WARNING: Valid nonces must be 32 characters long")
				->default_val(QLogicaeCore::GENERATOR.random_string(
					32, QLogicaeCore::UTILITIES.ALPHANUMERIC_CHARACTERSET)
				);

			encrypt_xchacha20poly1305_command
				->add_option("--output-file-path",
					STRING_INPUTS.get("encrypt_xchacha20poly1305", "output_file_path"),
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");

			encrypt_xchacha20poly1305_command
				->add_option("--is-file-output-enabled",
					BOOLEAN_INPUTS.get("encrypt_xchacha20poly1305", "is_file_output_enabled"),
					"Enables or disables the option '--output-file-path'")
				->default_val(false);

			encrypt_xchacha20poly1305_command
				->add_option("--is-verbose",
					BOOLEAN_INPUTS.get("encrypt_xchacha20poly1305", "is_verbose"),
					"Enables or disables verbose console logging")
				->default_val(false);

			UTILITIES.CLI_APPLICATION_COMMANDS["encrypt_xchacha20poly1305"] = std::make_pair(
				encrypt_xchacha20poly1305_command,
				[this]() -> bool
				{
					QLogicaeCore::Result<void> void_result;

					std::string encrypt_xchacha20poly1305__text =
						STRING_INPUTS.get("encrypt_xchacha20poly1305", "text");

					std::string encrypt_xchacha20poly1305__key =
						STRING_INPUTS.get("encrypt_xchacha20poly1305", "key");

					std::string encrypt_xchacha20poly1305__nonce =
						STRING_INPUTS.get("encrypt_xchacha20poly1305", "nonce");

					std::string encrypt_xchacha20poly1305__output_file_path =
						STRING_INPUTS.get("encrypt_xchacha20poly1305", "output_file_path");

					bool encrypt_xchacha20poly1305__is_file_output_enabled =
						BOOLEAN_INPUTS.get("encrypt_xchacha20poly1305", "is_file_output_enabled");

					bool encrypt_xchacha20poly1305__is_verbose =
						BOOLEAN_INPUTS.get("encrypt_xchacha20poly1305", "is_verbose");

					QLogicaeCore::LogConfigurations console_log_configurations_1 =
					{
						.is_console_enabled = encrypt_xchacha20poly1305__is_verbose,
						.is_console_format_enabled = encrypt_xchacha20poly1305__is_verbose
					};

					QLogicaeCore::LogConfigurations console_log_configurations_2 =
					{
						.is_console_enabled = true,
						.is_console_format_enabled = encrypt_xchacha20poly1305__is_verbose
					};

					try
					{
						LOGGER.log_running(
							void_result,
							"qlogicae_cli encrypt xchacha20poly1305",
							console_log_configurations_1
						);

						if (!encrypt_xchacha20poly1305__text.length() ||
							!encrypt_xchacha20poly1305__key.length() ||
							!encrypt_xchacha20poly1305__nonce.length())
						{
							LOGGER.log_complete(
								void_result,
								"qlogicae_cli encrypt xchacha20poly1305",
								console_log_configurations_1
							);

							return false;
						}

						std::string output_string =
							QLogicaeCore::XCHACHA20_POLY1305_CIPHER_CRYPTOGRAPHER.transform(
								encrypt_xchacha20poly1305__text,
								encrypt_xchacha20poly1305__key,
								encrypt_xchacha20poly1305__nonce
							) + "\n" +
							encrypt_xchacha20poly1305__nonce;

						LOGGER.log(
							void_result,
							output_string,
							console_log_configurations_2
						);

						if (encrypt_xchacha20poly1305__is_file_output_enabled)
						{
							QLogicaeCore::TEXT_FILE_IO.set_file_path(
								FILE_SYSTEM.setup_result_output_file(
									encrypt_xchacha20poly1305__output_file_path,
									"encrypt\\xchacha20poly1305",
									QLogicaeCore::UTILITIES.RELATIVE_DEFAULT_OUTPUT_FILE_PATH
								)
							);
							QLogicaeCore::TEXT_FILE_IO.write_async(output_string);
						}

						LOGGER.log_complete(
							void_result,
							"qlogicae_cli encrypt xchacha20poly1305",
							console_log_configurations_1
						);

						return true;
					}
					catch (const std::exception exception)
					{
						QLogicaeCore::LOGGER.handle_exception_async(
							"QLogicaeCLI::Application::_setup_encrypt_command()",
							exception.what()
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
					STRING_INPUTS.get("encrypt_aes256", "text"),
					"The string input to be encrypted")
				->required();

			encrypt_aes256_command
				->add_option("--key",
					STRING_INPUTS.get("encrypt_aes256", "key"),
					"Encryption key")
				->required();

			encrypt_aes256_command
				->add_option("--nonce",
					STRING_INPUTS.get("encrypt_aes256", "nonce"),
					"Encryption nonce. WARNING: Valid nonces must be 32 characters long")
				->default_val(QLogicaeCore::GENERATOR.random_string(
					32, QLogicaeCore::UTILITIES.ALPHANUMERIC_CHARACTERSET)
				);

			encrypt_aes256_command
				->add_option("--output-file-path",
					STRING_INPUTS.get("encrypt_aes256", "output_file_path"),
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");

			encrypt_aes256_command
				->add_option("--is-file-output-enabled",
					BOOLEAN_INPUTS.get("encrypt_aes256", "is_file_output_enabled"),
					"Enables or disables the option '--output-file-path'")
				->default_val(false);

			encrypt_aes256_command
				->add_option("--is-verbose",
					BOOLEAN_INPUTS.get("encrypt_aes256", "is_verbose"),
					"Enables or disables verbose console logging")
				->default_val(false);

			UTILITIES.CLI_APPLICATION_COMMANDS["encrypt_aes256"] = std::make_pair(
				encrypt_aes256_command,
				[this]() -> bool
				{
					QLogicaeCore::Result<void> void_result;

					std::string encrypt_aes256__text =
						STRING_INPUTS.get("encrypt_aes256", "text");

					std::string encrypt_aes256__key =
						STRING_INPUTS.get("encrypt_aes256", "key");

					std::string encrypt_aes256__nonce =
						STRING_INPUTS.get("encrypt_aes256", "nonce");

					std::string encrypt_aes256__output_file_path =
						STRING_INPUTS.get("encrypt_aes256", "output_file_path");

					bool encrypt_aes256__is_file_output_enabled =
						BOOLEAN_INPUTS.get("encrypt_aes256", "is_file_output_enabled");

					bool encrypt_aes256__is_verbose =
						BOOLEAN_INPUTS.get("encrypt_aes256", "is_verbose");

					QLogicaeCore::LogConfigurations console_log_configurations_1 =
					{
						.is_console_enabled = encrypt_aes256__is_verbose,
						.is_console_format_enabled = encrypt_aes256__is_verbose
					};

					QLogicaeCore::LogConfigurations console_log_configurations_2 =
					{
						.is_console_enabled = true,
						.is_console_format_enabled = encrypt_aes256__is_verbose
					};

					try
					{
						LOGGER.log_running(
							void_result,
							"qlogicae_cli encrypt aes256",
							console_log_configurations_1
						);

						if (!encrypt_aes256__text.length() ||
							!encrypt_aes256__key.length() ||
							!encrypt_aes256__nonce.length())
						{
							LOGGER.log_complete(
								void_result,
								"qlogicae_cli encrypt aes256",
								console_log_configurations_1
							);

							return false;
						}

						std::string output_string =
							QLogicaeCore::AES256_CIPHER_CRYPTOGRAPHER.transform(
								encrypt_aes256__text,
								encrypt_aes256__key,
								encrypt_aes256__nonce
							) + "\n" +
							encrypt_aes256__nonce;

						LOGGER.log(
							void_result,
							output_string,
							console_log_configurations_2
						);

						if (encrypt_aes256__is_file_output_enabled)
						{
							QLogicaeCore::TEXT_FILE_IO.set_file_path(
								FILE_SYSTEM.setup_result_output_file(
									encrypt_aes256__output_file_path,
									"encrypt\\aes256",
									QLogicaeCore::UTILITIES.RELATIVE_DEFAULT_OUTPUT_FILE_PATH
								)
							);
							QLogicaeCore::TEXT_FILE_IO.write_async(output_string);
						}

						LOGGER.log_complete(
							void_result,
							"qlogicae_cli encrypt aes256",
							console_log_configurations_1
						);

						return true;
					}
					catch (const std::exception exception)
					{
						QLogicaeCore::LOGGER.handle_exception_async(
							"QLogicaeCLI::Application::_setup_encrypt_command()",
							exception.what()
						);

						return false;
					}
				}
			);

			return true;
		}
		catch (const std::exception& exception)
		{
			QLogicaeCore::LOGGER.handle_exception_async(
				"QLogicaeCLI::Application::_setup_encrypt_command()",
				exception.what()
			);

			return false;
		}
	}

	bool Application::_setup_decrypt_command()
	{
		try
		{
			CLI::App* decrypt_command =
				UTILITIES.CLI_APPLICATION.add_subcommand(
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
					STRING_INPUTS.get("decrypt_xchacha20poly1305", "text"),
					"The string input to be encrypted")
				->required();

			decrypt_xchacha20poly1305_command
				->add_option("--key",
					STRING_INPUTS.get("decrypt_xchacha20poly1305", "key"),
					"Encryption key")
				->required();

			decrypt_xchacha20poly1305_command
				->add_option("--nonce",
					STRING_INPUTS.get("decrypt_xchacha20poly1305", "nonce"),
					"Encryption nonce. WARNING: Valid nonces must be 32 characters long")
				->default_val(QLogicaeCore::GENERATOR.random_string(
					32, QLogicaeCore::UTILITIES.ALPHANUMERIC_CHARACTERSET)
				);

			decrypt_xchacha20poly1305_command
				->add_option("--output-file-path",
					STRING_INPUTS.get("decrypt_xchacha20poly1305", "output_file_path"),
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");

			decrypt_xchacha20poly1305_command
				->add_option("--is-file-output-enabled",
					BOOLEAN_INPUTS.get("decrypt_xchacha20poly1305", "is_file_output_enabled"),
					"Enables or disables the option '--output-file-path'")
				->default_val(false);

			decrypt_xchacha20poly1305_command
				->add_option("--is-verbose",
					BOOLEAN_INPUTS.get("decrypt_xchacha20poly1305", "is_verbose"),
					"Enables or disables verbose console logging")
				->default_val(false);

			UTILITIES.CLI_APPLICATION_COMMANDS["decrypt_xchacha20poly1305"] = std::make_pair(
				decrypt_xchacha20poly1305_command,
				[this]() -> bool
				{
					QLogicaeCore::Result<void> void_result;

					std::string decrypt_xchacha20poly1305__text =
						STRING_INPUTS.get("decrypt_xchacha20poly1305", "text");

					std::string decrypt_xchacha20poly1305__key =
						STRING_INPUTS.get("decrypt_xchacha20poly1305", "key");

					std::string decrypt_xchacha20poly1305__nonce =
						STRING_INPUTS.get("decrypt_xchacha20poly1305", "nonce");

					std::string decrypt_xchacha20poly1305__output_file_path =
						STRING_INPUTS.get("decrypt_xchacha20poly1305", "output_file_path");

					bool decrypt_xchacha20poly1305__is_file_output_enabled =
						BOOLEAN_INPUTS.get("decrypt_xchacha20poly1305", "is_file_output_enabled");

					bool decrypt_xchacha20poly1305__is_verbose =
						BOOLEAN_INPUTS.get("decrypt_xchacha20poly1305", "is_verbose");

					QLogicaeCore::LogConfigurations console_log_configurations_1 =
					{
						.is_console_enabled = decrypt_xchacha20poly1305__is_verbose,
						.is_console_format_enabled = decrypt_xchacha20poly1305__is_verbose
					};

					QLogicaeCore::LogConfigurations console_log_configurations_2 =
					{
						.is_console_enabled = true,
						.is_console_format_enabled = decrypt_xchacha20poly1305__is_verbose
					};

					try
					{
						LOGGER.log_running(
							void_result,
							"qlogicae_cli decrypt xchacha20poly1305",
							console_log_configurations_1
						);

						if (!decrypt_xchacha20poly1305__text.length() ||
							!decrypt_xchacha20poly1305__key.length() ||
							!decrypt_xchacha20poly1305__nonce.length())
						{
							LOGGER.log_complete(
								void_result,
								"qlogicae_cli decrypt xchacha20poly1305",
								console_log_configurations_1
							);

							return false;
						}

						std::string output_string =
							QLogicaeCore::XCHACHA20_POLY1305_CIPHER_CRYPTOGRAPHER.reverse(
								decrypt_xchacha20poly1305__text,
								decrypt_xchacha20poly1305__key,
								decrypt_xchacha20poly1305__nonce
							);

						LOGGER.log(
							void_result,
							output_string,
							console_log_configurations_2
						);

						if (decrypt_xchacha20poly1305__is_file_output_enabled)
						{
							QLogicaeCore::TEXT_FILE_IO.set_file_path(
								FILE_SYSTEM.setup_result_output_file(
									decrypt_xchacha20poly1305__output_file_path,
									"decrypt\\xchacha20poly1305",
									QLogicaeCore::UTILITIES.RELATIVE_DEFAULT_OUTPUT_FILE_PATH
								)
							);
							QLogicaeCore::TEXT_FILE_IO.write_async(output_string);
						}

						LOGGER.log_complete(
							void_result,
							"qlogicae_cli decrypt xchacha20poly1305",
							console_log_configurations_1
						);

						return true;
					}
					catch (const std::exception exception)
					{
						QLogicaeCore::LOGGER.handle_exception_async(
							"QLogicaeCLI::Application::_setup_decrypt_command()",
							exception.what()
						);

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
					STRING_INPUTS.get("decrypt_aes256", "text"),
					"The string input to be encrypted")
				->required();

			decrypt_aes256_command
				->add_option("--key",
					STRING_INPUTS.get("decrypt_aes256", "key"),
					"Encryption key")
				->required();

			decrypt_aes256_command
				->add_option("--nonce",
					STRING_INPUTS.get("decrypt_aes256", "nonce"),
					"Encryption nonce. WARNING: Valid nonces must be 32 characters long")
				->default_val(QLogicaeCore::GENERATOR.random_string(
					32, QLogicaeCore::UTILITIES.ALPHANUMERIC_CHARACTERSET)
				);

			decrypt_aes256_command
				->add_option("--output-file-path",
					STRING_INPUTS.get("decrypt_aes256", "output_file_path"),
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");

			decrypt_aes256_command
				->add_option("--is-file-output-enabled",
					BOOLEAN_INPUTS.get("decrypt_aes256", "is_file_output_enabled"),
					"Enables or disables the option '--output-file-path'")
				->default_val(false);

			decrypt_aes256_command
				->add_option("--is-verbose",
					BOOLEAN_INPUTS.get("decrypt_aes256", "is_verbose"),
					"Enables or disables verbose console logging")
				->default_val(false);

			UTILITIES.CLI_APPLICATION_COMMANDS["decrypt_aes256"] = std::make_pair(
				decrypt_aes256_command,
				[this]() -> bool
				{
					QLogicaeCore::Result<void> void_result;

					std::string decrypt_aes256__text =
						STRING_INPUTS.get("decrypt_aes256", "text");

					std::string decrypt_aes256__key =
						STRING_INPUTS.get("decrypt_aes256", "key");

					std::string decrypt_aes256__nonce =
						STRING_INPUTS.get("decrypt_aes256", "nonce");

					std::string decrypt_aes256__output_file_path =
						STRING_INPUTS.get("decrypt_aes256", "output_file_path");

					bool decrypt_aes256__is_file_output_enabled =
						BOOLEAN_INPUTS.get("decrypt_aes256", "is_file_output_enabled");

					bool decrypt_aes256__is_verbose =
						BOOLEAN_INPUTS.get("decrypt_aes256", "is_verbose");

					QLogicaeCore::LogConfigurations console_log_configurations_1 =
					{
						.is_console_enabled = decrypt_aes256__is_verbose,
						.is_console_format_enabled = decrypt_aes256__is_verbose
					};

					QLogicaeCore::LogConfigurations console_log_configurations_2 =
					{
						.is_console_enabled = true,
						.is_console_format_enabled = decrypt_aes256__is_verbose
					};

					try
					{
						LOGGER.log_running(
							void_result,
							"qlogicae_cli decrypt aes256",
							console_log_configurations_1
						);

						if (!decrypt_aes256__text.length() ||
							!decrypt_aes256__key.length() ||
							!decrypt_aes256__nonce.length())
						{
							LOGGER.log_complete(
								void_result,
								"qlogicae_cli decrypt aes256",
								console_log_configurations_1
							);

							return false;
						}

						std::string output_string =
							QLogicaeCore::AES256_CIPHER_CRYPTOGRAPHER.reverse(
								decrypt_aes256__text,
								decrypt_aes256__key,
								decrypt_aes256__nonce
							);

						LOGGER.log(
							void_result,
							output_string,
							console_log_configurations_2
						);

						if (decrypt_aes256__is_file_output_enabled)
						{
							QLogicaeCore::TEXT_FILE_IO.set_file_path(
								FILE_SYSTEM.setup_result_output_file(
									decrypt_aes256__output_file_path,
									"decrypt\\aes256",
									QLogicaeCore::UTILITIES.RELATIVE_DEFAULT_OUTPUT_FILE_PATH
								)
							);
							QLogicaeCore::TEXT_FILE_IO.write_async(output_string);
						}

						LOGGER.log_complete(
							void_result,
							"qlogicae_cli decrypt aes256",
							console_log_configurations_1
						);

						return true;
					}
					catch (const std::exception exception)
					{
						QLogicaeCore::LOGGER.handle_exception_async(
							"QLogicaeCLI::Application::_setup_decrypt_command()",
							exception.what()
						);

						return false;
					}
				}
			);

			return true;
		}
		catch (const std::exception& exception)
		{
			QLogicaeCore::LOGGER.handle_exception_async(
				"QLogicaeCLI::Application::_setup_decrypt_command()",
				exception.what()
			);

			return false;
		}
	}

	bool Application::_setup_hash_command()
	{
		try
		{
			CLI::App* hash_command =
				UTILITIES.CLI_APPLICATION.add_subcommand(
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
					STRING_INPUTS.get("hash_argon2id", "text"),
					"The string text to be hashed")
				->required();

			hash_argon2id_command
				->add_option("--output-file-path",
					STRING_INPUTS.get("hash_argon2id", "output_file_path"),
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");

			hash_argon2id_command
				->add_option("--is-file-output-enabled",
					BOOLEAN_INPUTS.get("hash_argon2id", "is_file_output_enabled"),
					"Enables or disables the option '--output-file-path'")
				->default_val(false);

			hash_argon2id_command
				->add_option("--is-verbose",
					BOOLEAN_INPUTS.get("hash_argon2id", "is_verbose"),
					"Enables or disables verbose console logging")
				->default_val(false);

			UTILITIES.CLI_APPLICATION_COMMANDS["hash_argon2id"] = std::make_pair(
				hash_argon2id_command,
				[this]() -> bool
				{
					QLogicaeCore::Result<void> void_result;

					std::string hash_argon2id__text =
						STRING_INPUTS.get("hash_argon2id", "text");

					std::string hash_argon2id__output_file_path =
						STRING_INPUTS.get("hash_argon2id", "output_file_path");

					bool hash_argon2id__is_file_output_enabled =
						BOOLEAN_INPUTS.get("hash_argon2id", "is_file_output_enabled");

					bool hash_argon2id__is_verbose =
						BOOLEAN_INPUTS.get("hash_argon2id", "is_verbose");

					QLogicaeCore::LogConfigurations console_log_configurations_1 =
					{
						.is_console_enabled = hash_argon2id__is_verbose,
						.is_console_format_enabled = hash_argon2id__is_verbose
					};

					QLogicaeCore::LogConfigurations console_log_configurations_2 =
					{
						.is_console_enabled = true,
						.is_console_format_enabled = hash_argon2id__is_verbose
					};

					try
					{
						LOGGER.log_running(
							void_result,
							"qlogicae_cli hash argon2id",
							console_log_configurations_1
						);

						std::string output_string =
							QLogicaeCore::ARGON2ID_HASH_CRYPTOGRAPHER.transform(
								hash_argon2id__text
							);

						LOGGER.log(
							void_result,
							output_string,
							console_log_configurations_2
						);

						if (hash_argon2id__is_file_output_enabled)
						{
							QLogicaeCore::TEXT_FILE_IO.set_file_path(
								FILE_SYSTEM.setup_result_output_file(
									hash_argon2id__output_file_path,
									"hash\\argon2id",
									QLogicaeCore::UTILITIES.RELATIVE_DEFAULT_OUTPUT_FILE_PATH
								)
							);
							QLogicaeCore::TEXT_FILE_IO.write_async(output_string);
						}

						LOGGER.log_complete(
							void_result,
							"qlogicae_cli hash argon2id",
							console_log_configurations_1
						);

						return true;
					}
					catch (const std::exception exception)
					{
						QLogicaeCore::LOGGER.handle_exception_async(
							"QLogicaeCLI::Application::_setup_hash_command()",
							exception.what()
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
					STRING_INPUTS.get("hash_sha256", "text"),
					"The string text to be hashed")
				->required();

			hash_sha256_command
				->add_option("--output-file-path",
					STRING_INPUTS.get("hash_sha256", "output_file_path"),
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");

			hash_sha256_command
				->add_option("--is-file-output-enabled",
					BOOLEAN_INPUTS.get("hash_sha256", "is_file_output_enabled"),
					"Enables or disables the option '--output-file-path'")
				->default_val(false);

			hash_sha256_command
				->add_option("--is-verbose",
					BOOLEAN_INPUTS.get("hash_sha256", "is_verbose"),
					"Enables or disables verbose console logging")
				->default_val(false);

			UTILITIES.CLI_APPLICATION_COMMANDS["hash_sha256"] = std::make_pair(
				hash_sha256_command,
				[this]() -> bool
				{
					QLogicaeCore::Result<void> void_result;

					std::string hash_sha256__text =
						STRING_INPUTS.get("hash_sha256", "text");

					std::string hash_sha256__output_file_path =
						STRING_INPUTS.get("hash_sha256", "output_file_path");

					bool hash_sha256__is_file_output_enabled =
						BOOLEAN_INPUTS.get("hash_sha256", "is_file_output_enabled");

					bool hash_sha256__is_verbose =
						BOOLEAN_INPUTS.get("hash_sha256", "is_verbose");

					QLogicaeCore::LogConfigurations console_log_configurations_1 =
					{
						.is_console_enabled = hash_sha256__is_verbose,
						.is_console_format_enabled = hash_sha256__is_verbose
					};

					QLogicaeCore::LogConfigurations console_log_configurations_2 =
					{
						.is_console_enabled = true,
						.is_console_format_enabled = hash_sha256__is_verbose
					};

					try
					{
						LOGGER.log_running(
							void_result,
							"qlogicae_cli hash sha256",
							console_log_configurations_1
						);

						std::string output_string =
							QLogicaeCore::SHA256_HASH_CRYPTOGRAPHER.transform(
								hash_sha256__text
							);

						LOGGER.log(
							void_result,
							output_string,
							console_log_configurations_2
						);

						if (hash_sha256__is_file_output_enabled)
						{
							QLogicaeCore::TEXT_FILE_IO.set_file_path(
								FILE_SYSTEM.setup_result_output_file(
									hash_sha256__output_file_path,
									"hash\\sha256",
									QLogicaeCore::UTILITIES.RELATIVE_DEFAULT_OUTPUT_FILE_PATH
								)
							);
							QLogicaeCore::TEXT_FILE_IO.write_async(output_string);
						}

						LOGGER.log_complete(
							void_result,
							"qlogicae_cli hash sha256",
							console_log_configurations_1
						);

						return true;
					}
					catch (const std::exception exception)
					{
						QLogicaeCore::LOGGER.handle_exception_async(
							"QLogicaeCLI::Application::_setup_hash_command()",
							exception.what()
						);

						return false;
					}
				}
			);

			return true;
		}
		catch (const std::exception& exception)
		{
			QLogicaeCore::LOGGER.handle_exception_async(
				"QLogicaeCLI::Application::_setup_hash_command()",
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
				UTILITIES.CLI_APPLICATION.add_subcommand(
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
					STRING_INPUTS.get("verify_argon2id", "hash"),
					"The string hash to be verified")
				->required();

			verify_argon2id_command
				->add_option("--key",
					STRING_INPUTS.get("verify_argon2id", "key"),
					"The original text to be compared with the hash")
				->required();

			verify_argon2id_command
				->add_option("--output-file-path",
					STRING_INPUTS.get("verify_argon2id", "output_file_path"),
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");

			verify_argon2id_command
				->add_option("--is-file-output-enabled",
					BOOLEAN_INPUTS.get("verify_argon2id", "is_file_output_enabled"),
					"Enables or disables the option '--output-file-path'")
				->default_val(false);

			verify_argon2id_command
				->add_option("--is-verbose",
					BOOLEAN_INPUTS.get("verify_argon2id", "is_verbose"),
					"Enables or disables verbose console logging")
				->default_val(false);

			UTILITIES.CLI_APPLICATION_COMMANDS["verify_argon2id"] = std::make_pair(
				verify_argon2id_command,
				[this]() -> bool
				{
					QLogicaeCore::Result<void> void_result;

					std::string verify_argon2id__hash =
						STRING_INPUTS.get("verify_argon2id", "hash");

					std::string verify_argon2id__key =
						STRING_INPUTS.get("verify_argon2id", "key");

					std::string verify_argon2id__output_file_path =
						STRING_INPUTS.get("verify_argon2id", "output_file_path");

					bool verify_argon2id__is_file_output_enabled =
						BOOLEAN_INPUTS.get("verify_argon2id", "is_file_output_enabled");

					bool verify_argon2id__is_verbose =
						BOOLEAN_INPUTS.get("verify_argon2id", "is_verbose");

					QLogicaeCore::LogConfigurations console_log_configurations_1 =
					{
						.is_console_enabled = verify_argon2id__is_verbose,
						.is_console_format_enabled = verify_argon2id__is_verbose
					};

					QLogicaeCore::LogConfigurations console_log_configurations_2 =
					{
						.is_console_enabled = true,
						.is_console_format_enabled = verify_argon2id__is_verbose
					};

					try
					{
						LOGGER.log_running(
							void_result,
							"qlogicae_cli verify argon2id",
							console_log_configurations_1
						);

						if (!verify_argon2id__hash.length() ||
							!verify_argon2id__key.length())
						{
							LOGGER.log_complete(
								void_result,
								"qlogicae_cli verify argon2id",
								console_log_configurations_1
							);

							return false;
						}

						std::string output_string =
							(QLogicaeCore::ARGON2ID_HASH_CRYPTOGRAPHER.reverse(
								verify_argon2id__hash,
								verify_argon2id__key
							)) ? "true" : "false";

						LOGGER.log(
							void_result,
							output_string,
							console_log_configurations_2
						);

						if (verify_argon2id__is_file_output_enabled)
						{
							QLogicaeCore::TEXT_FILE_IO.set_file_path(
								FILE_SYSTEM.setup_result_output_file(
									verify_argon2id__output_file_path,
									"verify\\argon2id",
									QLogicaeCore::UTILITIES.RELATIVE_DEFAULT_OUTPUT_FILE_PATH
								)
							);
							QLogicaeCore::TEXT_FILE_IO.write_async(output_string);
						}

						LOGGER.log_complete(
							void_result,
							"qlogicae_cli verify argon2id",
							console_log_configurations_1
						);

						return true;
					}
					catch (const std::exception exception)
					{
						QLogicaeCore::LOGGER.handle_exception_async(
							"QLogicaeCLI::Application::_setup_verify_command()",
							exception.what()
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
					STRING_INPUTS.get("verify_sha256", "hash"),
					"The string hash to be verified")
				->required();

			verify_sha256_command
				->add_option("--key",
					STRING_INPUTS.get("verify_sha256", "key"),
					"The original text to be compared with the hash")
				->required();

			verify_sha256_command
				->add_option("--output-file-path",
					STRING_INPUTS.get("verify_sha256", "output_file_path"),
					"Enabled with the option --is-file-output-enabled='true'")
				->default_val("");

			verify_sha256_command
				->add_option("--is-file-output-enabled",
					BOOLEAN_INPUTS.get("verify_sha256", "is_file_output_enabled"),
					"Enables or disables the option '--output-file-path'")
				->default_val(false);

			verify_sha256_command
				->add_option("--is-verbose",
					BOOLEAN_INPUTS.get("verify_sha256", "is_verbose"),
					"Enables or disables verbose console logging")
				->default_val(false);

			UTILITIES.CLI_APPLICATION_COMMANDS["verify_sha256"] = std::make_pair(
				verify_sha256_command,
				[this]() -> bool
				{
					QLogicaeCore::Result<void> void_result;

					std::string verify_sha256__hash =
						STRING_INPUTS.get("verify_sha256", "hash");

					std::string verify_sha256__key =
						STRING_INPUTS.get("verify_sha256", "key");

					std::string verify_sha256__output_file_path =
						STRING_INPUTS.get("verify_sha256", "output_file_path");

					bool verify_sha256__is_file_output_enabled =
						BOOLEAN_INPUTS.get("verify_sha256", "is_file_output_enabled");

					bool verify_sha256__is_verbose =
						BOOLEAN_INPUTS.get("verify_sha256", "is_verbose");

					QLogicaeCore::LogConfigurations console_log_configurations_1 =
					{
						.is_console_enabled = verify_sha256__is_verbose,
						.is_console_format_enabled = verify_sha256__is_verbose
					};

					QLogicaeCore::LogConfigurations console_log_configurations_2 =
					{
						.is_console_enabled = true,
						.is_console_format_enabled = verify_sha256__is_verbose
					};

					try
					{
						LOGGER.log_running(
							void_result,
							"qlogicae_cli verify sha256",
							console_log_configurations_1
						);

						if (!verify_sha256__hash.length() ||
							!verify_sha256__key.length())
						{
							LOGGER.log_complete(
								void_result,
								"qlogicae_cli verify sha256",
								console_log_configurations_1
							);

							return false;
						}

						std::string output_string =
							(QLogicaeCore::SHA256_HASH_CRYPTOGRAPHER.reverse(
								verify_sha256__hash,
								verify_sha256__key
							)) ? "true" : "false";

						LOGGER.log(
							void_result,
							output_string,
							console_log_configurations_2
						);

						if (verify_sha256__is_file_output_enabled)
						{
							QLogicaeCore::TEXT_FILE_IO.set_file_path(
								FILE_SYSTEM.setup_result_output_file(
									verify_sha256__output_file_path,
									"verify\\sha256",
									QLogicaeCore::UTILITIES.RELATIVE_DEFAULT_OUTPUT_FILE_PATH
								)
							);
							QLogicaeCore::TEXT_FILE_IO.write_async(output_string);
						}

						LOGGER.log_complete(
							void_result,
							"qlogicae_cli verify sha256",
							console_log_configurations_1
						);

						return true;
					}
					catch (const std::exception exception)
					{
						QLogicaeCore::LOGGER.handle_exception_async(
							"QLogicaeCLI::Application::_setup_verify_command()",
							exception.what()
						);

						return false;
					}
				}
			);

			return true;
		}
		catch (const std::exception& exception)
		{
			QLogicaeCore::LOGGER.handle_exception_async(
				"QLogicaeCLI::Application::_setup_verify_command()",
				exception.what()
			);

			return false;
		}
	}

	bool Application::_setup_get_command()
	{
		try
		{
			CLI::App* get_command =
				UTILITIES.CLI_APPLICATION.add_subcommand(
					"get",
					"windows-registry, environment-variables"
				);

			CLI::App* get_windows_registry_command =
				get_command->add_subcommand(
					"windows-registry",
					"Gets a key-value pair of a selected windows registry path"
				);

			get_windows_registry_command
				->add_option("--root-path",
					STRING_INPUTS.get("get_windows_registry_command", "root_path"),
					"Windows registry root path")
				->check(CLI::IsMember(
					QLogicaeCore::UTILITIES.WINDOWS_REGISTRY_ROOT_PATH
				))
				->default_val(QLogicaeCore::UTILITIES.WINDOWS_REGISTRY_ROOT_PATH[0]);

			get_windows_registry_command
				->add_option("--sub-path",
					STRING_INPUTS.get("get_windows_registry_command", "sub_path"),
					"Windows registry sub path")
				->required();

			get_windows_registry_command
				->add_option("--key",
					STRING_INPUTS.get("get_windows_registry_command", "key"),
					"Windows registry key")
				->required();

			get_windows_registry_command
				->add_option("--is-verbose",
					BOOLEAN_INPUTS.get("get_windows_registry_command", "is_verbose"),
					"Enables or disables verbose console logging")
				->default_val(false);

			UTILITIES.CLI_APPLICATION_COMMANDS["get_windows_registry"] = std::make_pair(
				get_windows_registry_command,
				[this]() -> bool
				{
					QLogicaeCore::Result<void> void_result;

					std::string get_windows_registry_command__root_path =
						STRING_INPUTS.get("get_windows_registry_command", "root_path");

					std::string get_windows_registry_command__sub_path =
						STRING_INPUTS.get("get_windows_registry_command", "sub_path");

					std::string get_windows_registry_command__key =
						STRING_INPUTS.get("get_windows_registry_command", "key");

					bool get_windows_registry_command__is_verbose =
						BOOLEAN_INPUTS.get("get_windows_registry_command", "is_verbose");

					QLogicaeCore::LogConfigurations console_log_configurations_1 =
					{
						.is_console_enabled = get_windows_registry_command__is_verbose,
						.is_console_format_enabled = get_windows_registry_command__is_verbose
					};

					QLogicaeCore::LogConfigurations console_log_configurations_2 =
					{
						.is_console_enabled = get_windows_registry_command__is_verbose,
						.is_console_format_enabled = get_windows_registry_command__is_verbose
					};

					try
					{
						LOGGER.log_running(
							void_result,
							"qlogicae_cli get windows-registry",
							console_log_configurations_1
						);

						std::string command =
							absl::StrCat(
								"powershell -ExecutionPolicy Bypass -File",
								" \"qlogicae/.qlogicae/application/scripts/windows_registry/get.ps1\"",
								" -RootPath ",
								get_windows_registry_command__root_path,
								" -SubPath ",
								get_windows_registry_command__sub_path,
								" -Key ",
								get_windows_registry_command__key
							);

						LOGGER.log(
							void_result,
							"Executing '" + command + "'",
							console_log_configurations_2
						);

						system(
							command.c_str()
						);


						LOGGER.log_complete(
							void_result,
							"qlogicae_cli get windows-registry",
							console_log_configurations_1
						);

						return true;
					}
					catch (const std::exception& exception)
					{
						QLogicaeCore::LOGGER.handle_exception_async(
							"QLogicaeCLI::Application::_setup_get_command()",
							exception.what()
						);

						return false;
					}
				}
			);

			CLI::App* get_environment_variables_command =
				get_command->add_subcommand(
					"environment-variables",
					"Gets a key-value pair of a selected environment variable"
				);

			get_environment_variables_command
				->add_option("--root-path",
					STRING_INPUTS.get("get_environment_variables_command", "root_path"),
					"Environment variable root path")
				->check(CLI::IsMember(
					QLogicaeCore::UTILITIES.ENVIRONMENT_VARIABLE_TYPES
				))
				->default_val(QLogicaeCore::UTILITIES.ENVIRONMENT_VARIABLE_TYPES[0]);

			get_environment_variables_command
				->add_option("--key",
					STRING_INPUTS.get("get_environment_variables_command", "key"),
					"Environment variable key")
				->required();

			get_environment_variables_command
				->add_option("--is-verbose",
					BOOLEAN_INPUTS.get("get_environment_variables_command", "is_verbose"),
					"Enables or disables verbose console logging")
				->default_val(false);

			UTILITIES.CLI_APPLICATION_COMMANDS["get_environment_variables"] = std::make_pair(
				get_environment_variables_command,
				[this]() -> bool
				{
					QLogicaeCore::Result<void> void_result;

					std::string get_environment_variables_command__root_path =
						STRING_INPUTS.get("get_environment_variables_command", "root_path");

					std::string get_environment_variables_command__key =
						STRING_INPUTS.get("get_environment_variables_command", "key");

					bool get_environment_variables_command__is_verbose =
						BOOLEAN_INPUTS.get("get_environment_variables_command", "is_verbose");

					QLogicaeCore::LogConfigurations console_log_configurations_1 =
					{
						.is_console_enabled = get_environment_variables_command__is_verbose,
						.is_console_format_enabled = get_environment_variables_command__is_verbose
					};

					QLogicaeCore::LogConfigurations console_log_configurations_2 =
					{
						.is_console_enabled = get_environment_variables_command__is_verbose,
						.is_console_format_enabled = get_environment_variables_command__is_verbose
					};

					try
					{
						LOGGER.log_running(
							void_result,
							"qlogicae_cli get environment-variables",
							console_log_configurations_1
						);

						std::string command =
							absl::StrCat(
								"powershell -ExecutionPolicy Bypass -File",
								" \"qlogicae/.qlogicae/application/scripts/environment_variables/get.ps1\"",
								" -RootPath ",
								get_environment_variables_command__root_path,
								" -Key ",
								get_environment_variables_command__key
							);

						LOGGER.log(
							void_result,
							"Executing '" + command + "'",
							console_log_configurations_2
						);

						system(
							command.c_str()
						);

						LOGGER.log_complete(
							void_result,
							"qlogicae_cli get environment-variables",
							console_log_configurations_1
						);

						return true;
					}
					catch (const std::exception& exception)
					{
						QLogicaeCore::LOGGER.handle_exception_async(
							"QLogicaeCLI::Application::_setup_get_command()",
							exception.what()
						);

						return false;
					}
				}
			);

			return true;
		}
		catch (const std::exception& exception)
		{
			QLogicaeCore::LOGGER.handle_exception_async(
				"QLogicaeCLI::Application::_setup_get_command()",
				exception.what()
			);

			return false;
		}
	}

	bool Application::_setup_set_command()
	{
		try
		{
			CLI::App* set_command =
				UTILITIES.CLI_APPLICATION.add_subcommand(
					"set",
					"windows-registry, environment-variables"
				);

			CLI::App* set_windows_registry_command =
				set_command->add_subcommand(
					"windows-registry",
					"Creates or updates a key-value pair of a windows registry path"
				);

			set_windows_registry_command
				->add_option("--root-path",
					STRING_INPUTS.get("set_windows_registry_command", "root_path"),
					"Windows registry root path")
				->check(CLI::IsMember(
					QLogicaeCore::UTILITIES.WINDOWS_REGISTRY_ROOT_PATH
				))
				->default_val(QLogicaeCore::UTILITIES.WINDOWS_REGISTRY_ROOT_PATH[0]);

			set_windows_registry_command
				->add_option("--sub-path",
					STRING_INPUTS.get("set_windows_registry_command", "sub_path"),
					"Windows registry sub path")
				->required();

			set_windows_registry_command
				->add_option("--key",
					STRING_INPUTS.get("set_windows_registry_command", "key"),
					"Windows registry key")
				->required();

			set_windows_registry_command
				->add_option("--value",
					STRING_INPUTS.get("set_windows_registry_command", "value"),
					"Windows registry value")
				->required();

			set_windows_registry_command
				->add_option("--is-verbose",
					BOOLEAN_INPUTS.get("set_windows_registry_command", "is_verbose"),
					"Enables or disables verbose console logging")
				->default_val(false);

			UTILITIES.CLI_APPLICATION_COMMANDS["set_windows_registry"] = std::make_pair(
				set_windows_registry_command,
				[this]() -> bool
				{
					QLogicaeCore::Result<void> void_result;

					std::string set_windows_registry_command__root_path =
						STRING_INPUTS.get("set_windows_registry_command", "root_path");

					std::string set_windows_registry_command__sub_path =
						STRING_INPUTS.get("set_windows_registry_command", "sub_path");

					std::string set_windows_registry_command__key =
						STRING_INPUTS.get("set_windows_registry_command", "key");

					std::string set_windows_registry_command__value =
						STRING_INPUTS.get("set_windows_registry_command", "value");

					bool set_windows_registry_command__is_verbose =
						BOOLEAN_INPUTS.get("set_windows_registry_command", "is_verbose");

					QLogicaeCore::LogConfigurations console_log_configurations_1 =
					{
						.is_console_enabled = set_windows_registry_command__is_verbose,
						.is_console_format_enabled = set_windows_registry_command__is_verbose
					};

					QLogicaeCore::LogConfigurations console_log_configurations_2 =
					{
						.is_console_enabled = set_windows_registry_command__is_verbose,
						.is_console_format_enabled = set_windows_registry_command__is_verbose
					};

					try
					{
						LOGGER.log_running(
							void_result,
							"qlogicae_cli set windows-registry",
							console_log_configurations_1
						);

						std::string command =
							absl::StrCat(
								"powershell -ExecutionPolicy Bypass -File",
								" \"qlogicae/.qlogicae/application/scripts/windows_registry/set.ps1\"",
								" -RootPath ",
								set_windows_registry_command__root_path,
								" -SubPath ",
								set_windows_registry_command__sub_path,
								" -Key ",
								set_windows_registry_command__key,
								" -Value ",
								set_windows_registry_command__value
							);

						LOGGER.log(
							void_result,
							"Executing '" + command + "'",
							console_log_configurations_2
						);

						system(command.c_str());

						LOGGER.log_complete(
							void_result,
							"qlogicae_cli set windows-registry",
							console_log_configurations_1
						);

						return true;
					}
					catch (const std::exception& exception)
					{
						QLogicaeCore::LOGGER.handle_exception_async(
							"QLogicaeCLI::Application::_setup_set_command()",
							exception.what()
						);

						return false;
					}
				}
			);

			CLI::App* set_environment_variables_command =
				set_command->add_subcommand(
					"environment-variables",
					"Creates or updates a key-value pair of an environment variable"
				);

			set_environment_variables_command
				->add_option("--root-path",
					STRING_INPUTS.get("set_environment_variables_command", "root_path"),
					"Windows registry root path")
				->check(CLI::IsMember(
					QLogicaeCore::UTILITIES.ENVIRONMENT_VARIABLE_TYPES
				))
				->default_val(QLogicaeCore::UTILITIES.ENVIRONMENT_VARIABLE_TYPES[0]);

			set_environment_variables_command
				->add_option("--key",
					STRING_INPUTS.get("set_environment_variables_command", "key"),
					"Windows registry key")
				->required();

			set_environment_variables_command
				->add_option("--value",
					STRING_INPUTS.get("set_environment_variables_command", "value"),
					"Windows registry value")
				->required();

			set_environment_variables_command
				->add_option("--is-verbose",
					BOOLEAN_INPUTS.get("set_environment_variables_command", "is_verbose"),
					"Enables or disables verbose console logging")
				->default_val(false);

			UTILITIES.CLI_APPLICATION_COMMANDS["set_environment_variables"] = std::make_pair(
				set_environment_variables_command,
				[this]() -> bool
				{
					QLogicaeCore::Result<void> void_result;

					std::string set_environment_variables_command__root_path =
						STRING_INPUTS.get("set_environment_variables_command", "root_path");

					std::string set_environment_variables_command__key =
						STRING_INPUTS.get("set_environment_variables_command", "key");

					std::string set_environment_variables_command__value =
						STRING_INPUTS.get("set_environment_variables_command", "value");

					bool set_environment_variables_command__is_verbose =
						BOOLEAN_INPUTS.get("set_environment_variables_command", "is_verbose");

					QLogicaeCore::LogConfigurations console_log_configurations_1 =
					{
						.is_console_enabled = set_environment_variables_command__is_verbose,
						.is_console_format_enabled = set_environment_variables_command__is_verbose
					};

					QLogicaeCore::LogConfigurations console_log_configurations_2 =
					{
						.is_console_enabled = set_environment_variables_command__is_verbose,
						.is_console_format_enabled = set_environment_variables_command__is_verbose
					};

					try
					{
						LOGGER.log_running(
							void_result,
							"qlogicae_cli set environment-variables",
							console_log_configurations_1
						);

						std::string command =
							absl::StrCat(
								"powershell -ExecutionPolicy Bypass -File",
								" \"qlogicae/.qlogicae/application/scripts/environment_variables/set.ps1\"",
								" -RootPath ",
								set_environment_variables_command__root_path,
								" -Key ",
								set_environment_variables_command__key,
								" -Value ",
								set_environment_variables_command__value
							);

						LOGGER.log(
							void_result,
							"Executing '" + command + "'",
							console_log_configurations_2
						);

						system(
							command.c_str()
						);

						LOGGER.log_complete(
							void_result,
							"qlogicae_cli set environment-variables",
							console_log_configurations_1
						);

						return true;
					}
					catch (const std::exception& exception)
					{
						QLogicaeCore::LOGGER.handle_exception_async(
							"QLogicaeCLI::Application::_setup_set_command()",
							exception.what()
						);

						return false;
					}
				}
			);

			return true;
		}
		catch (const std::exception& exception)
		{
			QLogicaeCore::LOGGER.handle_exception_async(
				"QLogicaeCLI::Application::_setup_set_command()",
				exception.what()
			);

			return false;
		}
	}

	bool Application::_setup_clear_command()
	{
		try
		{
			CLI::App* clear_command =
				UTILITIES.CLI_APPLICATION.add_subcommand(
					"clear",
					"appdata, caches, logs"
				);

			CLI::App* clear_appdata_command =
				clear_command->add_subcommand(
					"appdata",
					"Clears all QLogicae CLI appdata files"
				);

			clear_appdata_command
				->add_option("--is-verbose",
					BOOLEAN_INPUTS.get("clear_appdata_command", "is_verbose"),
					"Enables or disables verbose console logging")
				->default_val(false);

			UTILITIES.CLI_APPLICATION_COMMANDS["clear_appdata"] = std::make_pair(
				clear_appdata_command,
				[this]() -> bool
				{

					QLogicaeCore::Result<void> void_result;

					bool clear_appdata_command__is_verbose =
						BOOLEAN_INPUTS.get("clear_appdata_command", "is_verbose");

					QLogicaeCore::LogConfigurations console_log_configurations_1 =
					{
						.is_console_enabled = clear_appdata_command__is_verbose,
						.is_console_format_enabled = clear_appdata_command__is_verbose
					};

					QLogicaeCore::LogConfigurations console_log_configurations_2 =
					{
						.is_console_enabled = clear_appdata_command__is_verbose,
						.is_console_format_enabled = clear_appdata_command__is_verbose
					};

					try
					{
						std::string command =
							absl::StrCat(
								"powershell.exe -NoProfile -NoLogo -Command "
								"\"Get-ChildItem -LiteralPath '" + QLogicaeCore::QLOGICAE_APPLICATION_UTILITIES.CONFIGURATIONS_ENVIRONMENT_LOGGER.relative_root_folder_path +
								"' -Recurse -File | Remove-Item -Force\""
							);

						LOGGER.log(
							void_result,
							"Executing '" + command + "'",
							console_log_configurations_2
						);

						system(
							command.c_str()
						);

						return true;
					}
					catch (const std::exception& exception)
					{
						QLogicaeCore::LOGGER.handle_exception_async(
							"QLogicaeCLI::Application::_setup_clear_command()",
							exception.what()
						);

						return false;
					}
				}
			);

			CLI::App* clear_cache_command =
				clear_command->add_subcommand(
					"caches",
					"Clears all QLogicae CLI caches"
				);

			clear_cache_command
				->add_option("--is-verbose",
					BOOLEAN_INPUTS.get("clear_cache_command", "is_verbose"),
					"Enables or disables verbose console logging")
				->default_val(false);

			UTILITIES.CLI_APPLICATION_COMMANDS["clear_cache"] = std::make_pair(
				clear_cache_command,
				[this]() -> bool
				{
					QLogicaeCore::Result<void> void_result;

					bool clear_cache_command__is_verbose =
						BOOLEAN_INPUTS.get("clear_cache_command", "is_verbose");

					QLogicaeCore::LogConfigurations console_log_configurations_1 =
					{
						.is_console_enabled = clear_cache_command__is_verbose,
						.is_console_format_enabled = clear_cache_command__is_verbose
					};

					QLogicaeCore::LogConfigurations console_log_configurations_2 =
					{
						.is_console_enabled = true,
						.is_console_format_enabled = clear_cache_command__is_verbose
					};

					try
					{
						LOGGER.log_running(
							void_result,
							"qlogicae_cli clear caches",
							console_log_configurations_1
						);

						LOGGER.log_complete(
							void_result,
							"qlogicae_cli clear caches",
							console_log_configurations_1
						);

						return true;
					}
					catch (const std::exception& exception)
					{
						QLogicaeCore::LOGGER.handle_exception_async(
							"QLogicaeCLI::Application::_setup_clear_command()",
							exception.what()
						);

						return false;
					}
				}
			);

			CLI::App* clear_logs_command =
				clear_command->add_subcommand(
					"logs",
					"Clears all QLogicae CLI logs"
				);

			clear_logs_command
				->add_option("--is-verbose",
					BOOLEAN_INPUTS.get("clear_logs_command", "is_verbose"),
					"Enables or disables verbose console logging")
				->default_val(false);

			UTILITIES.CLI_APPLICATION_COMMANDS["clear_logs"] = std::make_pair(
				clear_logs_command,
				[this]() -> bool
				{
					QLogicaeCore::Result<void> void_result;

					bool clear_logs_command__is_verbose =
						BOOLEAN_INPUTS.get("clear_logs_command", "is_verbose");

					QLogicaeCore::LogConfigurations console_log_configurations_1 =
					{
						.is_console_enabled = clear_logs_command__is_verbose,
						.is_console_format_enabled = clear_logs_command__is_verbose
					};

					QLogicaeCore::LogConfigurations console_log_configurations_2 =
					{
						.is_console_enabled = clear_logs_command__is_verbose,
						.is_console_format_enabled = clear_logs_command__is_verbose
					};

					try
					{
						std::string command =
							absl::StrCat(
								"powershell.exe -NoProfile -NoLogo -Command "
								"\"Get-ChildItem -LiteralPath '" + QLogicaeCore::QLOGICAE_APPLICATION_UTILITIES.CONFIGURATIONS_ENVIRONMENT_LOGGER.relative_root_folder_path +
								"' -Recurse -File | Remove-Item -Force\""
							);

						LOGGER.log(
							void_result,
							"Executing '" + command + "'",
							console_log_configurations_2
						);

						system(
							command.c_str()
						);
						
						return true;
					}
					catch (const std::exception& exception)
					{
						QLogicaeCore::LOGGER.handle_exception_async(
							"QLogicaeCLI::Application::_setup_clear_command()",
							exception.what()
						);

						return false;
					}
				}
			);

			return true;
		}
		catch (const std::exception& exception)
		{
			QLogicaeCore::LOGGER.handle_exception_async(
				"QLogicaeCLI::Application::_setup_clear_command()",
				exception.what()
			);

			return false;
		}

		return true;
	}

	bool Application::_setup_evaluate_command()
	{
		try
		{
			CLI::App* evaluate_command =
				UTILITIES.CLI_APPLICATION.add_subcommand(
					"evaluate",
					"vs2022"
				);

			CLI::App* evaluate_vs2022_command =
				evaluate_command->add_subcommand(
					"vs2022",
					"filesystem"
				);

			CLI::App* evaluate_vs2022_filesystem_command =
				evaluate_vs2022_command->add_subcommand(
					"filesystem",
					"Visual Studio 2022 file system-related analytics"
				);

			evaluate_vs2022_filesystem_command
				->add_option("--is-verbose",
					BOOLEAN_INPUTS.get("evaluate_vs2022_filesystem_command", "is_verbose"),
					"Enables or disables verbose console logging")
				->default_val(false);

			UTILITIES.CLI_APPLICATION_COMMANDS["evaluate_vs2022_filesystem"] = std::make_pair(
				evaluate_vs2022_filesystem_command,
				[this]() -> bool
				{
					QLogicaeCore::Result<void> void_result;

					bool evaluate_vs2022_filesystem_command__is_verbose =
						BOOLEAN_INPUTS.get("evaluate_vs2022_filesystem_command", "is_verbose");

					QLogicaeCore::LogConfigurations console_log_configurations_1 =
					{
						.is_console_enabled = evaluate_vs2022_filesystem_command__is_verbose,
						.is_console_format_enabled = evaluate_vs2022_filesystem_command__is_verbose
					};

					QLogicaeCore::LogConfigurations console_log_configurations_2 =
					{
						.is_console_enabled = true,
						.is_console_format_enabled = evaluate_vs2022_filesystem_command__is_verbose
					};

					try
					{					
						LOGGER.log_running(
							void_result,
							"qlogicae_cli evaluate vs2022 filesystem",
							console_log_configurations_1
						);

						LOGGER.log_complete(
							void_result,
							"qlogicae_cli evaluate vs2022 filesystem",
							console_log_configurations_1
						);
						
						return true;
					}
					catch (const std::exception& exception)
					{
						QLogicaeCore::LOGGER.handle_exception_async(
							"QLogicaeCLI::Application::_setup_evaluate_command()",
							exception.what()
						);

						return false;
					}
				}
			);

			return true;
		}
		catch (const std::exception& exception)
		{
			QLogicaeCore::LOGGER.handle_exception_async(
				"QLogicaeCLI::Application::_setup_evaluate_command()",
				exception.what()
			);

			return false;
		}

		return true;
	}
}
