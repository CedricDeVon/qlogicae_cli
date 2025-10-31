#pragma once

#include "utilities.hpp"
#include "cli_logger.hpp"
#include "cli_file_system.hpp"
#include "cli_transformer.hpp"
#include "cli_input_cache.hpp"

#include "qlogicae_core/logger.hpp"
#include "qlogicae_core/cli_io.hpp"
#include "qlogicae_core/utilities.hpp"
#include "qlogicae_core/application.hpp"
#include "qlogicae_core/log_configurations.hpp"

#include <CLI/CLI.hpp>

namespace QLogicaeCLI
{
	class Application
	{
	public:
		bool setup(
			int charc,
			char** argv
		);

		std::future<bool> setup_async(
			int charc,
			char** argv
		);

		void setup_async(
			QLogicaeCore::Result<std::future<void>>& result,
			int charc,
			char** argv
		);

		void setup(
			QLogicaeCore::Result<void>& result,
			int charc,
			char** argv
		);

		std::future<bool> setup_async(
			const std::function<void(const bool& result)>& callback,
			int charc,
			char** argv
		);

		void setup_async(
			const std::function<void(QLogicaeCore::Result<void>& result)>& callback,
			int charc,
			char** argv
		);

		bool parse();

		static Application& get_instance();

		static void get_instance(
			QLogicaeCore::Result<Application*>& result
		);

	protected:
		Application();

		~Application();
		
		Application(
			const Application& instance
		) = delete;
		
		Application(
			Application&& instance
		) noexcept = delete;
		
		Application& operator = (
			Application&& instance
		) = delete;
		
		Application& operator = (
			const Application& instance
		) = delete;

		CLI::App _application;
		
		std::unordered_map<std::string, std::pair<CLI::App*, std::function<bool()>>> _commands;

		bool _setup_view_command();

		bool _setup_run_command();

		bool _setup_build_command();

		bool _setup_setup_command();

		bool _setup_deploy_command();
	};
}

/*
* 
		
bool _setup_generate_command();

bool _setup_encrypt_command();

bool _setup_decrypt_command();
		
bool _setup_hash_command();

bool _setup_verify_command();

bool _setup_get_command();

bool _setup_set_command();


std::unordered_map<std::string_view, bool> _boolean_inputs;

std::unordered_map<std::string_view, size_t> _size_t_inputs;

std::unordered_map<std::string_view, double> _double_inputs;

std::unordered_map<std::string_view, std::string> _string_inputs;

*/
