#include "pch.hpp"

#include "cli_transformer.hpp"

namespace QLogicaeCLI
{
	CLITransformer::CLITransformer()
	{

	}

	CLITransformer::~CLITransformer()
	{

	}

	bool CLITransformer::setup()
	{
		return true;
	}

	void CLITransformer::setup(
		QLogicaeCore::Result<void>& result
	)
	{
		result.set_to_good_status_without_value();
	}

	std::string CLITransformer::to_log_running_timestamp(
		const bool& is_enabled
	)
	{
		if (is_enabled)
		{
			return QLogicaeCore::TRANSFORMER.to_log_format(
				"Running...",
				QLogicaeCore::LogLevel::HIGHLIGHTED_INFO
			);
		}

		return "";
	}

	std::string CLITransformer::to_log_complete_timestamp(
		const bool& is_enabled
	)
	{
		if (is_enabled)
		{
			return QLogicaeCore::TRANSFORMER.to_log_format(
				"Complete!",
				QLogicaeCore::LogLevel::HIGHLIGHTED_INFO
			);
		}

		return "";
	}

	std::string CLITransformer::to_log_info_timestamp(
		const std::string& text,
		const bool& is_enabled
	)
	{
		if (is_enabled)
		{
			return QLogicaeCore::TRANSFORMER.to_log_format(
				text,
				QLogicaeCore::LogLevel::INFO
			);
		}

		return "";
	}

	std::string CLITransformer::to_log_success_timestamp(
		const std::string& text,
		const bool& is_enabled
	)
	{
		if (is_enabled)
		{
			return QLogicaeCore::TRANSFORMER.to_log_format(
				text,
				QLogicaeCore::LogLevel::SUCCESS
			);
		}

		return "";
	}

	std::string CLITransformer::to_log_warning_timestamp(
		const std::string& text,
		const bool& is_enabled
	)
	{
		if (is_enabled)
		{
			return QLogicaeCore::TRANSFORMER.to_log_format(
				text,
				QLogicaeCore::LogLevel::WARNING
			);
		}

		return "";
	}

	std::string CLITransformer::to_log_exception_timestamp(
		const std::string& text, const bool& is_enabled
	)
	{
		if (is_enabled)
		{
			return QLogicaeCore::TRANSFORMER.to_log_format(
				text,
				QLogicaeCore::LogLevel::EXCEPTION
			);
		}

		return "";
	}

	std::string CLITransformer::to_input_command_path(
		const std::string command_path,
		const std::string command_key
	)
	{
		return command_path +
			"___" + command_key;
	}

	void CLITransformer::to_input_command_path(
		QLogicaeCore::Result<std::string>& result,
		const std::string command_path,
		const std::string command_key
	)
	{
		result.set_to_good_status_with_value(
			command_path +
			"___" + command_key
		);
	}

	CLITransformer& CLITransformer::get_instance()
	{
		static CLITransformer instance;

		return instance;
	}

	void CLITransformer::get_instance(
		QLogicaeCore::Result<CLITransformer*>& result
	)
	{
		static CLITransformer instance;

		result.set_to_good_status_with_value(&instance);
	}
}
