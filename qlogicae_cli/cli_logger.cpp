#include "pch.hpp"

#include "cli_logger.hpp"

namespace QLogicaeCLI
{
	CLILogger::CLILogger()
	{

	}

	CLILogger::~CLILogger()
	{

	}

	void CLILogger::log_running(
		const bool& is_enabled
	)
	{
		QLogicaeCore::Result<void> void_result;

		QLogicaeCore::QLOGICAE_APPLICATION_LOGGER.MAIN_LOGGER.log(
			void_result,
			"Running...",
			QLogicaeCore::LogLevel::HIGHLIGHTED_INFO,
			is_enabled
		);
	}

	void CLILogger::log_complete(
		const bool& is_enabled
	)
	{
		QLogicaeCore::Result<void> void_result;

		QLogicaeCore::QLOGICAE_APPLICATION_LOGGER.MAIN_LOGGER.log(
			void_result,
			"Complete!",
			QLogicaeCore::LogLevel::HIGHLIGHTED_INFO,
			is_enabled
		);
	}

	void CLILogger::log_running_async(
		const bool& is_enabled
	)
	{
		QLogicaeCore::Result<std::future<void>> void_result;

		QLogicaeCore::QLOGICAE_APPLICATION_LOGGER.MAIN_LOGGER.log_async(
			void_result,
			"Running...",
			QLogicaeCore::LogLevel::HIGHLIGHTED_INFO,
			is_enabled
		);
	}

	void CLILogger::log_complete_async(
		const bool& is_enabled
	)
	{
		QLogicaeCore::Result<std::future<void>> void_result;

		QLogicaeCore::QLOGICAE_APPLICATION_LOGGER.MAIN_LOGGER.log_async(
			void_result,
			"Complete!",
			QLogicaeCore::LogLevel::HIGHLIGHTED_INFO,
			is_enabled
		);
	}

	CLILogger& CLILogger::get_instance()
	{
		static CLILogger instance;

		return instance;
	}

	void CLILogger::get_instance(
		QLogicaeCore::Result<CLILogger*>& result
	)
	{
		static CLILogger instance;

		result.set_to_good_status_with_value(&instance);
	}
}
