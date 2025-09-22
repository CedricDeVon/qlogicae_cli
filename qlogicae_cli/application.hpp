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

		std::unordered_map<std::string_view, bool> _boolean_inputs;
		std::unordered_map<std::string_view, size_t> _size_t_inputs;
		std::unordered_map<std::string_view, double> _double_inputs;
		std::unordered_map<std::string_view, std::string> _string_inputs;

		CLI::App _application;
		std::unordered_map<std::string, std::pair<CLI::App*, std::function<bool()>>> _commands;

		bool _setup_view_command();
		
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
