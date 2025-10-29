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
            const bool& is_enabled
        );

        std::future<void> log_running_async(
            const bool& is_enabled
        );
		
		void log_running_async(
			const std::function<void()>& callback,
			const bool& is_enabled
		);

		void log_running(
			QLogicaeCore::Result<void>& result,
			const bool& is_enabled
		);

		void log_running_async(
			QLogicaeCore::Result<std::future<void>>& result,
			const bool& is_enabled
		);

		void log_running_async(
			const std::function<void(QLogicaeCore::Result<void>& result)>& callback,
			const bool& is_enabled
		);

		void log(
			const bool& is_enabled,
			const std::string& text
		);

		std::future<void> log_async(
			const bool& is_enabled,
			const std::string& text
		);

		void log_async(
			const std::function<void()>& callback,
			const bool& is_enabled,
			const std::string& text
		);

		void log(
			QLogicaeCore::Result<void>& result,
			const bool& is_enabled,
			const std::string& text
		);

		void log_async(
			QLogicaeCore::Result<std::future<void>>& result,
			const bool& is_enabled,
			const std::string& text
		);

		void log_async(
			const std::function<void(QLogicaeCore::Result<void>& result)>& callback,
			const bool& is_enabled,
			const std::string& text
		);

		void log_complete(
			const bool& is_enabled
		);

		std::future<void> log_complete_async(
			const bool& is_enabled
		);

		void log_complete_async(
			const std::function<void()>& callback,
			const bool& is_enabled
		);

		void log_complete(
			QLogicaeCore::Result<void>& result,
			const bool& is_enabled
		);

		void log_complete_async(
			QLogicaeCore::Result<std::future<void>>& result,
			const bool& is_enabled
		);

		void log_complete_async(
			const std::function<void(QLogicaeCore::Result<void>& result)>& callback,
			const bool& is_enabled
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
