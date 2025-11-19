#pragma once

#include "logger.hpp"
#include "utilities.hpp"
#include "file_system.hpp"
#include "transformer.hpp"
#include "input_cache.hpp"

#include "qlogicae_core/includes/logger.hpp"
#include "qlogicae_core/includes/cli_io.hpp"
#include "qlogicae_core/includes/utilities.hpp"
#include "qlogicae_core/includes/application.hpp"
#include "qlogicae_core/includes/log_configurations.hpp"

#include <CLI/CLI.hpp>
#include <CLI/Config.hpp>
#include <CLI/Formatter.hpp>
#include <absl/strings/str_replace.h>

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

		bool terminate();

		std::future<bool> terminate_async();

		void terminate_async(
			QLogicaeCore::Result<std::future<void>>& result
		);

		void terminate(
			QLogicaeCore::Result<void>& result
		);

		std::future<bool> terminate_async(
			const std::function<void(const bool& result)>& callback
		);

		void terminate_async(
			const std::function<void(QLogicaeCore::Result<void>& result)>& callback
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

		bool _setup_generate_command();

		bool _setup_encrypt_command();

		bool _setup_decrypt_command();

		bool _setup_hash_command();

		bool _setup_verify_command();

		bool _setup_get_command();

		bool _setup_set_command();

		bool _setup_clear_command();

		bool _setup_evaluate_command();
	};

	inline static Application& APPLICATION =
		Application::get_instance();
}
