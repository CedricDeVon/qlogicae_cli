#pragma once

#include "qlogicae_core/result.hpp"
#include "qlogicae_core/logger.hpp"
#include "qlogicae_core/transformer.hpp"

namespace QLogicaeCLI
{	
	class CLILogger
	{
	public:
		bool setup();

		std::future<bool> setup_async();

		void setup_async(
			QLogicaeCore::Result<std::future<void>>& result
		);

		void setup(
			QLogicaeCore::Result<void>& result
		);

		void setup_async(
			const std::function<void(const bool& result)>& callback
		);

		void setup_async(
			const std::function<void(QLogicaeCore::Result<void>& result)>& callback
		);

        void log_running(
			const std::string& command_name,
			QLogicaeCore::LogConfigurations& log_configurations =
				QLogicaeCore::DEFAULT_LOG_CONFIGURATIONS
			);

		std::future<void> log_running_async(
			const std::string& command_name,
			QLogicaeCore::LogConfigurations& log_configurations =
				QLogicaeCore::DEFAULT_LOG_CONFIGURATIONS
			);

		void log_running_async(
			const std::function<void()>& callback,
			const std::string& command_name,
			QLogicaeCore::LogConfigurations& log_configurations =
				QLogicaeCore::DEFAULT_LOG_CONFIGURATIONS
			);

		void log_running(
			QLogicaeCore::Result<void>& result,
			const std::string& command_name,
			QLogicaeCore::LogConfigurations& log_configurations =
				QLogicaeCore::DEFAULT_LOG_CONFIGURATIONS
			);

		void log_running_async(
			QLogicaeCore::Result<std::future<void>>& result,
			const std::string& command_name,
			QLogicaeCore::LogConfigurations& log_configurations =
				QLogicaeCore::DEFAULT_LOG_CONFIGURATIONS
			);

		void log_running_async(
			const std::function<void(QLogicaeCore::Result<void>& result)>& callback,
			const std::string& command_name,
			QLogicaeCore::LogConfigurations& log_configurations =
				QLogicaeCore::DEFAULT_LOG_CONFIGURATIONS
			);

		void log(
			const std::string& text,
			QLogicaeCore::LogConfigurations& log_configurations =
				QLogicaeCore::DEFAULT_LOG_CONFIGURATIONS
		);

		std::future<void> log_async(
			const std::string& text,
			QLogicaeCore::LogConfigurations& log_configurations =
				QLogicaeCore::DEFAULT_LOG_CONFIGURATIONS
		);

		void log_async(
			const std::function<void()>& callback,
			const std::string& text,
			QLogicaeCore::LogConfigurations& log_configurations =
				QLogicaeCore::DEFAULT_LOG_CONFIGURATIONS
		);

		void log(
			QLogicaeCore::Result<void>& result,
			const std::string& text,
			QLogicaeCore::LogConfigurations& log_configurations =
				QLogicaeCore::DEFAULT_LOG_CONFIGURATIONS
		);

		void log_async(
			QLogicaeCore::Result<std::future<void>>& result,
			const std::string& text,
			QLogicaeCore::LogConfigurations& log_configurations =
				QLogicaeCore::DEFAULT_LOG_CONFIGURATIONS
		);

		void log_async(
			const std::function<void(QLogicaeCore::Result<void>& result)>& callback,
			const std::string& text,
			QLogicaeCore::LogConfigurations& log_configurations =
				QLogicaeCore::DEFAULT_LOG_CONFIGURATIONS
		);

		void log_complete(
			const std::string& command_name,
			QLogicaeCore::LogConfigurations& log_configurations =
				QLogicaeCore::DEFAULT_LOG_CONFIGURATIONS
			);

		std::future<void> log_complete_async(
			const std::string& command_name,
			QLogicaeCore::LogConfigurations& log_configurations =
				QLogicaeCore::DEFAULT_LOG_CONFIGURATIONS
			);

		void log_complete_async(
			const std::function<void()>& callback,
			const std::string& command_name,
			QLogicaeCore::LogConfigurations& log_configurations =
				QLogicaeCore::DEFAULT_LOG_CONFIGURATIONS
			);

		void log_complete(
			QLogicaeCore::Result<void>& result,
			const std::string& command_name,
			QLogicaeCore::LogConfigurations& log_configurations =
				QLogicaeCore::DEFAULT_LOG_CONFIGURATIONS
			);

		void log_complete_async(
			QLogicaeCore::Result<std::future<void>>& result,
			const std::string& command_name,
			QLogicaeCore::LogConfigurations& log_configurations =
				QLogicaeCore::DEFAULT_LOG_CONFIGURATIONS
			);

		void log_complete_async(
			const std::function<void(QLogicaeCore::Result<void>& result)>& callback,
			const std::string& command_name,
			QLogicaeCore::LogConfigurations& log_configurations =
				QLogicaeCore::DEFAULT_LOG_CONFIGURATIONS
		);

		static CLILogger& get_instance();

		static void get_instance(
			QLogicaeCore::Result<CLILogger*>& result
		);

	protected:
		CLILogger();

		~CLILogger();

		CLILogger(
			const CLILogger& instance
		) = delete;

		CLILogger(
			CLILogger&& instance
		) noexcept = delete;

		CLILogger& operator = (
			CLILogger&& instance
		) = delete;

		CLILogger& operator = (
			const CLILogger& instance
		) = delete;
	};

	static inline CLILogger& CLI_LOGGER =
		CLILogger::get_instance();
}
